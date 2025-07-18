/*
 * SPDX-FileCopyrightText: Copyright (c) 1993-2025 NVIDIA CORPORATION & AFFILIATES. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "sampleUtils.h"
#include "bfloat16.h"
#include "common.h"
#include "half.h"
#include <cuda.h>
#include <type_traits>

#if CUDA_VERSION >= 11060
#include <cuda_fp8.h>
#endif

using namespace nvinfer1;

namespace sample
{

int64_t volume(nvinfer1::Dims const& dims, nvinfer1::Dims const& strides, int32_t vecDim, int32_t comps, int32_t batch)
{
    int64_t maxNbElems = 1;
    for (int32_t i = 0; i < dims.nbDims; ++i)
    {
        // Get effective length of axis.
        int64_t d = dims.d[i];
        // Any dimension is 0, it is an empty tensor.
        if (d == 0)
        {
            return 0;
        }
        if (i == vecDim)
        {
            d = samplesCommon::divUp(d, comps);
        }
        maxNbElems = std::max(maxNbElems, d * strides.d[i]);
    }
    return maxNbElems * batch * (vecDim < 0 ? 1 : comps);
}

nvinfer1::Dims toDims(std::vector<int64_t> const& vec)
{
    int32_t limit = static_cast<int32_t>(nvinfer1::Dims::MAX_DIMS);
    if (static_cast<int32_t>(vec.size()) > limit)
    {
        sample::gLogWarning << "Vector too long, only first 8 elements are used in dimension." << std::endl;
    }
    // Pick first nvinfer1::Dims::MAX_DIMS elements
    nvinfer1::Dims dims{std::min(static_cast<int32_t>(vec.size()), limit), {}};
    std::copy_n(vec.begin(), dims.nbDims, std::begin(dims.d));
    return dims;
}

void loadFromFile(std::string const& fileName, char* dst, size_t size)
{
    ASSERT(dst);

    std::ifstream file(fileName, std::ios::in | std::ios::binary);
    if (file.is_open())
    {
        file.seekg(0, std::ios::end);
        int64_t fileSize = static_cast<int64_t>(file.tellg());
        // Due to change from int32_t to int64_t VC engines created with earlier versions
        // may expect input of the half of the size
        if (fileSize != static_cast<int64_t>(size) && fileSize != static_cast<int64_t>(size * 2))
        {
            std::ostringstream msg;
            msg << "Unexpected file size for input file: " << fileName << ". Note: Input binding size is: " << size
                << " bytes but the file size is " << fileSize
                << " bytes. Double check the size and datatype of the provided data.";
            throw std::invalid_argument(msg.str());
        }
        // Move file pointer back to the beginning after reading file size.
        file.seekg(0, std::ios::beg);
        file.read(dst, size);
        size_t const nbBytesRead = file.gcount();
        file.close();
        if (nbBytesRead != size)
        {
            std::ostringstream msg;
            msg << "Unexpected file size for input file: " << fileName << ". Note: Expected: " << size
                << " bytes but only read: " << nbBytesRead << " bytes";
            throw std::invalid_argument(msg.str());
        }
    }
    else
    {
        std::ostringstream msg;
        msg << "Cannot open file " << fileName << "!";
        throw std::invalid_argument(msg.str());
    }
}

// Check if the file at the given path can be written to.
bool canWriteFile(const std::string& path)
{
    // Verify that the target directory exists
    namespace fs = std::filesystem;
    fs::path p(path);
    fs::path dir = p.has_parent_path() ? p.parent_path() : fs::current_path();
    if (!fs::exists(dir) || !fs::is_directory(dir))
    {
        return false;
    }

    // Try creating and writing to a temporary file in the directory
    const fs::path tempFilePath = dir / ".writetest.tmp";
    std::ofstream test(tempFilePath.string(), std::ios::out | std::ios::trunc);
    if (!test.is_open())
    {
        return false;
    }
    test << "test";
    const bool ok = test.good();
    test.close();

    // Clean up the temporary file without throwing on failure
    std::error_code ec;
    fs::remove(tempFilePath, ec);

    return ok;
}

std::vector<std::string> splitToStringVec(std::string const& s, char separator, int64_t maxSplit)
{
    std::vector<std::string> splitted;

    for (size_t start = 0; start < s.length();)
    {
        // If maxSplit is specified and we have reached maxSplit, emplace back the rest of the string and break the
        // loop.
        if (maxSplit >= 0 && static_cast<int64_t>(splitted.size()) == maxSplit)
        {
            splitted.emplace_back(s.substr(start, s.length() - start));
            break;
        }

        size_t separatorIndex = s.find(separator, start);
        if (separatorIndex == std::string::npos)
        {
            separatorIndex = s.length();
        }
        splitted.emplace_back(s.substr(start, separatorIndex - start));

        // If the separator is the last character, then we should push an empty string at the end.
        if (separatorIndex == s.length() - 1)
        {
            splitted.emplace_back("");
        }

        start = separatorIndex + 1;
    }

    return splitted;
}

bool broadcastIOFormats(std::vector<IOFormat> const& formats, size_t nbBindings, bool isInput /*= true*/)
{
    bool broadcast = formats.size() == 1;
    bool validFormatsCount = broadcast || (formats.size() == nbBindings);
    if (!formats.empty() && !validFormatsCount)
    {
        if (isInput)
        {
            throw std::invalid_argument(
                "The number of inputIOFormats must match network's inputs or be one for broadcasting.");
        }

        throw std::invalid_argument(
            "The number of outputIOFormats must match network's outputs or be one for broadcasting.");
    }
    return broadcast;
}

void sparsifyMatMulKernelWeights(nvinfer1::INetworkDefinition& network, std::vector<std::vector<int8_t>>& sparseWeights)
{
    using TensorToLayer = std::unordered_map<nvinfer1::ITensor*, nvinfer1::ILayer*>;
    using LayerToTensor = std::unordered_map<nvinfer1::ILayer*, nvinfer1::ITensor*>;

    // 1. Collect layers and tensors information from the network.
    TensorToLayer matmulI2L;
    TensorToLayer constO2L;
    TensorToLayer shuffleI2L;
    LayerToTensor shuffleL2O;
    auto collectMappingInfo = [&](int32_t const idx) {
        ILayer* l = network.getLayer(idx);
        switch (l->getType())
        {
        case nvinfer1::LayerType::kMATRIX_MULTIPLY:
        {
            // assume weights on the second input.
            matmulI2L.insert({l->getInput(1), l});
            break;
        }
        case nvinfer1::LayerType::kCONSTANT:
        {
            DataType const dtype = static_cast<nvinfer1::IConstantLayer*>(l)->getWeights().type;
            if (dtype == nvinfer1::DataType::kFLOAT || dtype == nvinfer1::DataType::kHALF)
            {
                // Sparsify float only.
                constO2L.insert({l->getOutput(0), l});
            }
            break;
        }
        case nvinfer1::LayerType::kSHUFFLE:
        {
            shuffleI2L.insert({l->getInput(0), l});
            shuffleL2O.insert({l, l->getOutput(0)});
            break;
        }
        default: break;
        }
    };
    int32_t const nbLayers = network.getNbLayers();
    for (int32_t i = 0; i < nbLayers; ++i)
    {
        collectMappingInfo(i);
    }
    if (matmulI2L.size() == 0 || constO2L.size() == 0)
    {
        // No MatrixMultiply or Constant layer found, no weights to sparsify.
        return;
    }

    // Helper for analysis
    auto isTranspose
        = [](nvinfer1::Permutation const& perm) -> bool { return (perm.order[0] == 1 && perm.order[1] == 0); };
    auto is2D = [](nvinfer1::Dims const& dims) -> bool { return dims.nbDims == 2; };
    auto isIdenticalReshape = [](nvinfer1::Dims const& dims) -> bool {
        for (int32_t i = 0; i < dims.nbDims; ++i)
        {
            if (dims.d[i] != i || dims.d[i] != -1)
            {
                return false;
            }
        }
        return true;
    };
    auto tensorReachedViaTranspose = [&](nvinfer1::ITensor* t, bool& needTranspose) -> ITensor* {
        while (shuffleI2L.find(t) != shuffleI2L.end())
        {
            nvinfer1::IShuffleLayer* s = static_cast<nvinfer1::IShuffleLayer*>(shuffleI2L.at(t));
            if (!is2D(s->getInput(0)->getDimensions()) || !is2D(s->getReshapeDimensions())
                || !isIdenticalReshape(s->getReshapeDimensions()))
            {
                break;
            }

            if (isTranspose(s->getFirstTranspose()))
            {
                needTranspose = !needTranspose;
            }
            if (isTranspose(s->getSecondTranspose()))
            {
                needTranspose = !needTranspose;
            }

            t = shuffleL2O.at(s);
        }
        return t;
    };

    // 2. Forward analysis to collect the Constant layers connected to MatMul via Transpose
    std::unordered_map<nvinfer1::IConstantLayer*, bool> constantLayerToSparse;
    for (auto& o2l : constO2L)
    {
        // If need to transpose the weights of the Constant layer.
        // Need to transpose by default due to semantic difference.
        bool needTranspose{true};
        ITensor* t = tensorReachedViaTranspose(o2l.first, needTranspose);
        if (matmulI2L.find(t) == matmulI2L.end())
        {
            continue;
        }

        // check MatMul params...
        IMatrixMultiplyLayer* mm = static_cast<nvinfer1::IMatrixMultiplyLayer*>(matmulI2L.at(t));
        bool const twoInputs = mm->getNbInputs() == 2;
        bool const all2D = is2D(mm->getInput(0)->getDimensions()) && is2D(mm->getInput(1)->getDimensions());
        bool const isSimple = mm->getOperation(0) == nvinfer1::MatrixOperation::kNONE
            && mm->getOperation(1) != nvinfer1::MatrixOperation::kVECTOR;
        if (!(twoInputs && all2D && isSimple))
        {
            continue;
        }
        if (mm->getOperation(1) == nvinfer1::MatrixOperation::kTRANSPOSE)
        {
            needTranspose = !needTranspose;
        }

        constantLayerToSparse.insert({static_cast<IConstantLayer*>(o2l.second), needTranspose});
    }

    // 3. Finally, sparsify the weights
    auto sparsifyConstantWeights = [&sparseWeights](nvinfer1::IConstantLayer* layer, bool const needTranspose) {
        Dims dims = layer->getOutput(0)->getDimensions();
        ASSERT(dims.nbDims == 2);
        int32_t const idxN = needTranspose ? 1 : 0;
        int32_t const n = dims.d[idxN];
        int32_t const k = dims.d[1 - idxN];
        sparseWeights.emplace_back();
        std::vector<int8_t>& spw = sparseWeights.back();
        Weights w = layer->getWeights();
        DataType const dtype = w.type;
        ASSERT(dtype == nvinfer1::DataType::kFLOAT
            || dtype == nvinfer1::DataType::kHALF); // non-float weights should have been ignored.

        if (needTranspose)
        {
            if (dtype == nvinfer1::DataType::kFLOAT)
            {
                spw.resize(w.count * sizeof(float));
                transpose2DWeights<float>(spw.data(), w.values, k, n);
            }
            else if (dtype == nvinfer1::DataType::kHALF)
            {
                spw.resize(w.count * sizeof(half_float::half));
                transpose2DWeights<half_float::half>(spw.data(), w.values, k, n);
            }

            w.values = spw.data();
            std::vector<int8_t> tmpW;
            sparsify(w, n, 1, tmpW);

            if (dtype == nvinfer1::DataType::kFLOAT)
            {
                transpose2DWeights<float>(spw.data(), tmpW.data(), n, k);
            }
            else if (dtype == nvinfer1::DataType::kHALF)
            {
                transpose2DWeights<half_float::half>(spw.data(), tmpW.data(), n, k);
            }
        }
        else
        {
            sparsify(w, n, 1, spw);
        }

        w.values = spw.data();
        layer->setWeights(w);
    };
    for (auto& l : constantLayerToSparse)
    {
        sparsifyConstantWeights(l.first, l.second);
    }
}

template <typename L>
void setSparseWeights(L& l, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights)
{
    auto weights = l.getKernelWeights();
    sparsify(weights, k, trs, sparseWeights);
    weights.values = sparseWeights.data();
    l.setKernelWeights(weights);
}

// Explicit instantiation
template void setSparseWeights<IConvolutionLayer>(
    IConvolutionLayer& l, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights);

void sparsify(nvinfer1::INetworkDefinition& network, std::vector<std::vector<int8_t>>& sparseWeights)
{
    for (int32_t l = 0; l < network.getNbLayers(); ++l)
    {
        auto* layer = network.getLayer(l);
        auto const t = layer->getType();
        if (t == nvinfer1::LayerType::kCONVOLUTION)
        {
            auto& conv = *static_cast<IConvolutionLayer*>(layer);
            auto const& dims = conv.getKernelSizeNd();
            ASSERT(dims.nbDims == 2 || dims.nbDims == 3);
            auto const k = conv.getNbOutputMaps();
            auto const trs = std::accumulate(dims.d, dims.d + dims.nbDims, 1, std::multiplies<int32_t>());
            sparseWeights.emplace_back();
            setSparseWeights(conv, k, trs, sparseWeights.back());
        }
    }

    sparsifyMatMulKernelWeights(network, sparseWeights);
    sample::gLogVerbose << "--sparsity=force pruned " << sparseWeights.size() << " weights to be sparsity pattern."
                        << std::endl;
    sample::gLogVerbose << "--sparsity=force has been deprecated. Please use <polygraphy surgeon prune> to rewrite the "
                           "weights to a sparsity pattern and then run with --sparsity=enable"
                        << std::endl;
}

void sparsify(Weights const& weights, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights)
{
    switch (weights.type)
    {
    case DataType::kFLOAT:
        sparsify(static_cast<float const*>(weights.values), weights.count, k, trs, sparseWeights);
        break;
    case DataType::kHALF:
        sparsify(static_cast<half_float::half const*>(weights.values), weights.count, k, trs, sparseWeights);
        break;
    case DataType::kBF16:
        sparsify(static_cast<BFloat16 const*>(weights.values), weights.count, k, trs, sparseWeights);
        break;
    case DataType::kINT8:
    case DataType::kINT32:
    case DataType::kUINT8:
    case DataType::kBOOL:
    case DataType::kINT4:
    case DataType::kFP8:
    case DataType::kINT64:
    case DataType::kFP4: ASSERT(false && "Unsupported data type");
    case DataType::kE8M0: ASSERT(false && "E8M0 is not supported");
    }
}

template <typename T>
void print(std::ostream& os, T v)
{
    os << v;
}

void print(std::ostream& os, int8_t v)
{
    os << static_cast<int32_t>(v);
}

void print(std::ostream& os, __half v)
{
    os << static_cast<float>(v);
}

#if CUDA_VERSION >= 11060
void print(std::ostream& os, __nv_fp8_e4m3 v)
{
    os << static_cast<float>(v);
}
#endif

int32_t dataOffsetFromDims(int64_t v, Dims const& dims, Dims const& strides, int32_t vectorDim, int32_t spv)
{
    int32_t dataOffset = 0;
    for (int32_t dimIndex = dims.nbDims - 1; dimIndex >= 0; --dimIndex)
    {
        int32_t dimVal = v % dims.d[dimIndex];
        if (dimIndex == vectorDim)
        {
            dataOffset += (dimVal / spv) * strides.d[dimIndex] * spv + dimVal % spv;
        }
        else
        {
            dataOffset += dimVal * strides.d[dimIndex] * (vectorDim == -1 ? 1 : spv);
        }
        v /= dims.d[dimIndex];
        ASSERT(v >= 0);
    }

    return dataOffset;
}

template <typename T>
void dumpBuffer(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv)
{
    auto const vol = volume(dims);
    T const* typedBuffer = static_cast<T const*>(buffer);
    for (int64_t v = 0; v < vol; ++v)
    {
        int32_t dataOffset = dataOffsetFromDims(v, dims, strides, vectorDim, spv);
        if (v > 0)
        {
            os << separator;
        }
        print(os, typedBuffer[dataOffset]);
    }
}

void dumpInt4Buffer(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv)
{
    auto const vol = volume(dims);
    uint8_t const* typedBuffer = static_cast<uint8_t const*>(buffer);
    for (int64_t v = 0; v < vol; ++v)
    {
        int32_t dataOffset = dataOffsetFromDims(v, dims, strides, vectorDim, spv);
        if (v > 0)
        {
            os << separator;
        }

        auto value = typedBuffer[dataOffset / 2];
        if (dataOffset % 2 == 0)
        {
            // Cast to int8_t before right shift, so right-shift will sign-extend.
            // Left shift on int8_t can be undefined behaviour, must perform left shift on uint8_t.
            os << (static_cast<int8_t>(value << 4) >> 4);
        }
        else
        {
            os << (static_cast<int8_t>(value) >> 4);
        }
    }
}

// Explicit instantiation
template void dumpBuffer<bool>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<int32_t>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<int8_t>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<float>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<__half>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<BFloat16>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
#if CUDA_VERSION >= 11060
template void dumpBuffer<__nv_fp8_e4m3>(void const* buffer, std::string const& separator, std::ostream& os,
    Dims const& dims, Dims const& strides, int32_t vectorDim, int32_t spv);
#endif
template void dumpBuffer<uint8_t>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);
template void dumpBuffer<int64_t>(void const* buffer, std::string const& separator, std::ostream& os, Dims const& dims,
    Dims const& strides, int32_t vectorDim, int32_t spv);

template <typename T>
void sparsify(T const* values, int64_t count, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights)
{
    auto const c = count / (k * trs);
    sparseWeights.resize(count * sizeof(T));
    auto* sparseValues = reinterpret_cast<T*>(sparseWeights.data());

    constexpr int32_t window = 4;
    constexpr int32_t nonzeros = 2;

    int32_t const crs = c * trs;
    auto const getIndex = [=](int32_t ki, int32_t ci, int32_t rsi) { return ki * crs + ci * trs + rsi; };

    for (int64_t ki = 0; ki < k; ++ki)
    {
        for (int64_t rsi = 0; rsi < trs; ++rsi)
        {
            int32_t w = 0;
            int32_t nz = 0;
            for (int64_t ci = 0; ci < c; ++ci)
            {
                auto const index = getIndex(ki, ci, rsi);
                if (nz < nonzeros)
                {
                    sparseValues[index] = values[index];
                    ++nz;
                }
                else
                {
                    sparseValues[index] = 0;
                }
                if (++w == window)
                {
                    w = 0;
                    nz = 0;
                }
            }
        }
    }
}

// Explicit instantiation
template void sparsify<float>(
    float const* values, int64_t count, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights);
template void sparsify<half_float::half>(
    half_float::half const* values, int64_t count, int32_t k, int32_t trs, std::vector<int8_t>& sparseWeights);

template <typename T>
void transpose2DWeights(void* dst, void const* src, int32_t const m, int32_t const n)
{
    ASSERT(dst != src);
    T* tdst = reinterpret_cast<T*>(dst);
    T const* tsrc = reinterpret_cast<T const*>(src);
    for (int32_t mi = 0; mi < m; ++mi)
    {
        for (int32_t ni = 0; ni < n; ++ni)
        {
            int32_t const isrc = mi * n + ni;
            int32_t const idst = ni * m + mi;
            tdst[idst] = tsrc[isrc];
        }
    }
}

// Explicit instantiation
template void transpose2DWeights<float>(void* dst, void const* src, int32_t const m, int32_t const n);
template void transpose2DWeights<half_float::half>(void* dst, void const* src, int32_t const m, int32_t const n);

template <typename T, typename std::enable_if_t<std::is_integral_v<T>, bool>>
void fillBuffer(void* buffer, int64_t volume, int32_t min, int32_t max)
{
    T* typedBuffer = static_cast<T*>(buffer);
    std::default_random_engine engine;
    std::uniform_int_distribution<int32_t> distribution(min, max);
    auto generator = [&engine, &distribution]() { return static_cast<T>(distribution(engine)); };
    std::generate(typedBuffer, typedBuffer + volume, generator);
}

template <typename T, typename std::enable_if_t<!std::is_integral_v<T>, bool>>
void fillBuffer(void* buffer, int64_t volume, float min, float max)
{
    T* typedBuffer = static_cast<T*>(buffer);
    std::default_random_engine engine;
    std::uniform_real_distribution<float> distribution(min, max);
    auto generator = [&engine, &distribution]() { return static_cast<T>(distribution(engine)); };
    std::generate(typedBuffer, typedBuffer + volume, generator);
}

// Explicit instantiation
template void fillBuffer<bool>(void* buffer, int64_t volume, int32_t min, int32_t max);
template void fillBuffer<int32_t>(void* buffer, int64_t volume, int32_t min, int32_t max);
template void fillBuffer<int8_t>(void* buffer, int64_t volume, int32_t min, int32_t max);
template void fillBuffer<float>(void* buffer, int64_t volume, float min, float max);
template void fillBuffer<__half>(void* buffer, int64_t volume, float min, float max);
template void fillBuffer<BFloat16>(void* buffer, int64_t volume, float min, float max);
#if CUDA_VERSION >= 11060
template void fillBuffer<__nv_fp8_e4m3>(void* buffer, int64_t volume, float min, float max);
#endif
template void fillBuffer<uint8_t>(void* buffer, int64_t volume, int32_t min, int32_t max);
template void fillBuffer<int64_t>(void* buffer, int64_t volume, int32_t min, int32_t max);

bool matchStringWithOneWildcard(std::string const& pattern, std::string const& target)
{
    auto const splitPattern = splitToStringVec(pattern, '*', 1);

    // If there is no wildcard, return if the two strings match exactly.
    if (splitPattern.size() == 1)
    {
        return pattern == target;
    }

    // Otherwise, target must follow prefix+anything+postfix pattern.
    return target.size() >= (splitPattern[0].size() + splitPattern[1].size()) && target.find(splitPattern[0]) == 0
        && target.rfind(splitPattern[1]) == (target.size() - splitPattern[1].size());
}

} // namespace sample
