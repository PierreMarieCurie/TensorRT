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

#ifndef TRT_SAMPLE_INFERENCE_H
#define TRT_SAMPLE_INFERENCE_H

#include "debugTensorWriter.h"
#include "sampleDevice.h"
#include "sampleEngines.h"
#include "sampleReporting.h"
#include "sampleUtils.h"

#include <functional>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <vector>

namespace sample
{

struct InferenceEnvironment
{
    InferenceEnvironment() = delete;
    InferenceEnvironment(InferenceEnvironment const& other) = delete;
    InferenceEnvironment(InferenceEnvironment&& other) = delete;
    InferenceEnvironment(BuildEnvironment& bEnv)
        : engine(std::move(bEnv.engine))
        , safe(bEnv.engine.isSafe())
        , cmdline(bEnv.cmdline)
    {
    }

    LazilyDeserializedEngine engine;
    std::unique_ptr<Profiler> profiler;
    std::vector<std::unique_ptr<nvinfer1::IExecutionContext>> contexts;
    std::vector<TrtDeviceBuffer>
        deviceMemory; //< Device memory used for inference when the allocation strategy is not static.
    std::vector<std::unique_ptr<Bindings>> bindings;
    std::unique_ptr<DebugTensorWriter> listener;
    bool error{false};

    bool safe{false};
    std::string cmdline;

    inline nvinfer1::IExecutionContext* getContext(int32_t streamIdx);

    //! Storage for input shape tensors.
    //!
    //! It's important that the addresses of the data do not change between the calls to
    //! setTensorAddress/setInputShape (which tells TensorRT where the input shape tensor is)
    //! and enqueueV3 (when TensorRT might use the input shape tensor).
    //!
    //! The input shape tensors could alternatively be handled via member bindings,
    //! but it simplifies control-flow to store the data here since it's shared across
    //! the bindings.
    std::list<std::vector<int64_t>> inputShapeTensorValues;
};

inline nvinfer1::IExecutionContext* InferenceEnvironment::getContext(int32_t streamIdx)
{
    return contexts[streamIdx].get();
}

//!
//! \brief Set up contexts and bindings for inference
//!
bool setUpInference(InferenceEnvironment& iEnv, InferenceOptions const& inference, SystemOptions const& system);

//!
//! \brief Deserialize the engine and time how long it takes.
//!
bool timeDeserialize(InferenceEnvironment& iEnv, SystemOptions const& sys);

//!
//! \brief Run inference and collect timing, return false if any error hit during inference
//!
bool runInference(
    InferenceOptions const& inference, InferenceEnvironment& iEnv, int32_t device, std::vector<InferenceTrace>& trace,
    ReportingOptions const& reporting);

//!
//! \brief Get layer information of the engine.
//!
std::string getLayerInformation(
    nvinfer1::ICudaEngine* engine, nvinfer1::IExecutionContext* context, nvinfer1::LayerInformationFormat format);

struct Binding
{
    bool isInput{false};
    std::unique_ptr<IMirroredBuffer> buffer;
    std::unique_ptr<OutputAllocator> outputAllocator;
    int64_t volume{0};
    nvinfer1::DataType dataType{nvinfer1::DataType::kFLOAT};

    void fill(std::string const& fileName);

    void fill();

    void dump(std::ostream& os, nvinfer1::Dims dims, nvinfer1::Dims strides, int32_t vectorDim, int32_t spv,
        std::string const separator = " ") const;
};

struct TensorInfo
{
    int32_t bindingIndex{-1};
    char const* name{nullptr};
    nvinfer1::Dims dims{};
    bool isDynamic{};
    int32_t comps{-1};
    nvinfer1::Dims strides{};
    int32_t vectorDimIndex{-1};
    bool isInput{};
    nvinfer1::DataType dataType{};
    int64_t vol{-1};

    void updateVolume(int32_t batch)
    {
        vol = volume(dims, strides, vectorDimIndex, comps, batch);
    }
};

class Bindings
{
public:
    Bindings() = delete;
    explicit Bindings(bool useManaged)
        : mUseManaged(useManaged)
    {
    }

    void addBinding(TensorInfo const& tensorInfo, std::string const& fileName = "");

    void** getDeviceBuffers();

    void transferInputToDevice(TrtCudaStream& stream);

    void transferOutputToHost(TrtCudaStream& stream);

    void fill(int binding, std::string const& fileName)
    {
        mBindings[binding].fill(fileName);
    }

    void fill(int binding)
    {
        mBindings[binding].fill();
    }

    void dumpBindingDimensions(
        std::string const& name, nvinfer1::IExecutionContext const& context, std::ostream& os) const;

    void dumpBindingValues(nvinfer1::IExecutionContext const& context, int32_t binding, std::ostream& os,
        std::string const& separator = " ", int32_t batch = 1) const;

    void dumpRawBindingToFiles(nvinfer1::IExecutionContext const& context, std::ostream& os) const;

    void dumpInputs(nvinfer1::IExecutionContext const& context, std::ostream& os) const
    {
        auto isInput = [](Binding const& b) { return b.isInput; };
        dumpBindings(context, isInput, os);
    }

    void dumpOutputs(nvinfer1::IExecutionContext const& context, std::ostream& os) const;

    void dumpBindings(nvinfer1::IExecutionContext const& context, std::ostream& os) const
    {
        auto all = [](Binding const& b) { return true; };
        dumpBindings(context, all, os);
    }

    void dumpBindings(nvinfer1::IExecutionContext const& context, std::function<bool(Binding const&)> predicate,
        std::ostream& os) const
    {
        for (auto const& n : mNames)
        {
            auto const name = n.first;
            auto const binding = n.second;
            if (predicate(mBindings[binding]))
            {
                os << n.first << ": (";
                dumpBindingDimensions(name, context, os);
                os << ")" << std::endl;

                dumpBindingValues(context, binding, os);
                os << std::endl;
            }
        }
    }

    std::unordered_map<std::string, int> getInputBindings() const
    {
        auto isInput = [](Binding const& b) { return b.isInput; };
        return getBindings(isInput);
    }

    std::unordered_map<std::string, int> getOutputBindings() const
    {
        auto isOutput = [](Binding const& b) { return !b.isInput; };
        return getBindings(isOutput);
    }

    std::unordered_map<std::string, int> getBindings() const
    {
        auto all = [](Binding const& b) { return true; };
        return getBindings(all);
    }

    std::unordered_map<std::string, int> getBindings(std::function<bool(Binding const&)> predicate) const;

    bool setTensorAddresses(nvinfer1::IExecutionContext& context) const;

private:
    std::unordered_map<std::string, int32_t> mNames;
    std::vector<Binding> mBindings;
    std::vector<void*> mDevicePointers;
    bool mUseManaged{false};
};

struct TaskInferenceEnvironment
{
    TaskInferenceEnvironment(std::string engineFile, InferenceOptions const& inference,
        ReportingOptions const& reporting, int32_t deviceId = 0,
        int32_t DLACore = -1, int32_t bs = batchNotProvided);
    InferenceOptions iOptions{};
    ReportingOptions rOptions{};
    int32_t device{defaultDevice};
    int32_t batch{batchNotProvided};
    std::unique_ptr<InferenceEnvironment> iEnv;
    std::vector<InferenceTrace> trace;
};

bool runMultiTasksInference(std::vector<std::unique_ptr<TaskInferenceEnvironment>>& tEnvList);

} // namespace sample

#endif // TRT_SAMPLE_INFERENCE_H
