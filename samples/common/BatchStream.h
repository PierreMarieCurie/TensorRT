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
#ifndef BATCH_STREAM_H
#define BATCH_STREAM_H

#include "NvInfer.h"
#include "common.h"
#include <algorithm>
#include <stdio.h>
#include <vector>

class IBatchStream
{
public:
    virtual void reset(int firstBatch) = 0;
    virtual bool next() = 0;
    virtual void skip(int skipCount) = 0;
    virtual float* getBatch() = 0;
    virtual float* getLabels() = 0;
    virtual int getBatchesRead() const = 0;
    virtual int getBatchSize() const = 0;
    virtual nvinfer1::Dims getDims() const = 0;
};

class MNISTBatchStream : public IBatchStream
{
public:
    MNISTBatchStream(int batchSize, int maxBatches, const std::string& dataFile, const std::string& labelsFile,
        const std::vector<std::string>& directories)
        : mBatchSize{batchSize}
        , mMaxBatches{maxBatches}
        , mDims{3, {1, 28, 28}} //!< We already know the dimensions of MNIST images.
    {
        readDataFile(samplesCommon::locateFile(dataFile, directories));
        readLabelsFile(samplesCommon::locateFile(labelsFile, directories));
    }

    void reset(int firstBatch) override
    {
        mBatchCount = firstBatch;
    }

    bool next() override
    {
        if (mBatchCount >= mMaxBatches)
        {
            return false;
        }
        ++mBatchCount;
        return true;
    }

    void skip(int skipCount) override
    {
        mBatchCount += skipCount;
    }

    float* getBatch() override
    {
        return mData.data() + (mBatchCount * mBatchSize * samplesCommon::volume(mDims));
    }

    float* getLabels() override
    {
        return mLabels.data() + (mBatchCount * mBatchSize);
    }

    int getBatchesRead() const override
    {
        return mBatchCount;
    }

    int getBatchSize() const override
    {
        return mBatchSize;
    }

    nvinfer1::Dims getDims() const override
    {
        return nvinfer1::Dims{4, {mBatchSize, mDims.d[0], mDims.d[1], mDims.d[2]}};
    }

private:
    void readDataFile(const std::string& dataFilePath)
    {
        std::ifstream file{dataFilePath.c_str(), std::ios::binary};

        int magicNumber, numImages, imageH, imageW;
        file.read(reinterpret_cast<char*>(&magicNumber), sizeof(magicNumber));
        // All values in the MNIST files are big endian.
        magicNumber = samplesCommon::swapEndianness(magicNumber);
        ASSERT(magicNumber == 2051 && "Magic Number does not match the expected value for an MNIST image set");

        // Read number of images and dimensions
        file.read(reinterpret_cast<char*>(&numImages), sizeof(numImages));
        file.read(reinterpret_cast<char*>(&imageH), sizeof(imageH));
        file.read(reinterpret_cast<char*>(&imageW), sizeof(imageW));

        numImages = samplesCommon::swapEndianness(numImages);
        imageH = samplesCommon::swapEndianness(imageH);
        imageW = samplesCommon::swapEndianness(imageW);

        // The MNIST data is made up of unsigned bytes, so we need to cast to float and normalize.
        int numElements = numImages * imageH * imageW;
        std::vector<uint8_t> rawData(numElements);
        file.read(reinterpret_cast<char*>(rawData.data()), numElements * sizeof(uint8_t));
        mData.resize(numElements);
        std::transform(
            rawData.begin(), rawData.end(), mData.begin(), [](uint8_t val) { return static_cast<float>(val) / 255.F; });
    }

    void readLabelsFile(const std::string& labelsFilePath)
    {
        std::ifstream file{labelsFilePath.c_str(), std::ios::binary};
        int magicNumber, numImages;
        file.read(reinterpret_cast<char*>(&magicNumber), sizeof(magicNumber));
        // All values in the MNIST files are big endian.
        magicNumber = samplesCommon::swapEndianness(magicNumber);
        ASSERT(magicNumber == 2049 && "Magic Number does not match the expected value for an MNIST labels file");

        file.read(reinterpret_cast<char*>(&numImages), sizeof(numImages));
        numImages = samplesCommon::swapEndianness(numImages);

        std::vector<uint8_t> rawLabels(numImages);
        file.read(reinterpret_cast<char*>(rawLabels.data()), numImages * sizeof(uint8_t));
        mLabels.resize(numImages);
        std::transform(
            rawLabels.begin(), rawLabels.end(), mLabels.begin(), [](uint8_t val) { return static_cast<float>(val); });
    }

    int mBatchSize{0};
    int mBatchCount{0}; //!< The batch that will be read on the next invocation of next()
    int mMaxBatches{0};
    nvinfer1::Dims mDims{};
    std::vector<float> mData{};
    std::vector<float> mLabels{};
};

class BatchStream : public IBatchStream
{
public:
    BatchStream(int batchSize, int maxBatches, std::string const& prefix, std::string const& suffix,
        std::vector<std::string> const& directories)
        : mBatchSize(batchSize)
        , mMaxBatches(maxBatches)
        , mPrefix(prefix)
        , mSuffix(suffix)
        , mDataDir(directories)
    {
        std::ifstream file(
            samplesCommon::locateFile(mPrefix + std::string("0") + mSuffix, mDataDir).c_str(), std::ios::binary);
        ASSERT(file.good());
        int d[4];
        file.read(reinterpret_cast<char*>(d), 4 * sizeof(int32_t));
        mDims.nbDims = 4;  // The number of dimensions.
        mDims.d[0] = d[0]; // Batch Size
        mDims.d[1] = d[1]; // Channels
        mDims.d[2] = d[2]; // Height
        mDims.d[3] = d[3]; // Width
        ASSERT(mDims.d[0] > 0 && mDims.d[1] > 0 && mDims.d[2] > 0 && mDims.d[3] > 0);

        mImageSize = mDims.d[1] * mDims.d[2] * mDims.d[3];
        mBatch.resize(mBatchSize * mImageSize, 0);
        mLabels.resize(mBatchSize, 0);
        mFileBatch.resize(mDims.d[0] * mImageSize, 0);
        mFileLabels.resize(mDims.d[0], 0);
    }

    BatchStream(int batchSize, int maxBatches, std::string const& prefix, std::vector<std::string> const& directories)
        : BatchStream(batchSize, maxBatches, prefix, ".batch", directories)
    {
    }

    BatchStream(int batchSize, int maxBatches, nvinfer1::Dims const& dims, std::string const& listFile,
        std::vector<std::string> const& directories)
        : mBatchSize(batchSize)
        , mMaxBatches(maxBatches)
        , mDims(dims)
        , mListFile(listFile)
        , mDataDir(directories)
    {
        mImageSize = mDims.d[1] * mDims.d[2] * mDims.d[3];
        mBatch.resize(mBatchSize * mImageSize, 0);
        mLabels.resize(mBatchSize, 0);
        mFileBatch.resize(mDims.d[0] * mImageSize, 0);
        mFileLabels.resize(mDims.d[0], 0);
    }

    // Resets data members
    void reset(int firstBatch) override
    {
        mBatchCount = 0;
        mFileCount = 0;
        mFileBatchPos = mDims.d[0];
        skip(firstBatch);
    }

    // Advance to next batch and return true, or return false if there is no batch left.
    bool next() override
    {
        if (mBatchCount == mMaxBatches)
        {
            return false;
        }

        for (int64_t csize = 1, batchPos = 0; batchPos < mBatchSize; batchPos += csize, mFileBatchPos += csize)
        {
            ASSERT(mFileBatchPos > 0 && mFileBatchPos <= mDims.d[0]);
            if (mFileBatchPos == mDims.d[0] && !update())
            {
                return false;
            }

            // copy the smaller of: elements left to fulfill the request, or elements left in the file buffer.
            csize = std::min<int64_t>(mBatchSize - batchPos, mDims.d[0] - mFileBatchPos);
            std::copy_n(
                getFileBatch() + mFileBatchPos * mImageSize, csize * mImageSize, getBatch() + batchPos * mImageSize);
            std::copy_n(getFileLabels() + mFileBatchPos, csize, getLabels() + batchPos);
        }
        mBatchCount++;
        return true;
    }

    // Skips the batches
    void skip(int skipCount) override
    {
        if (mBatchSize >= mDims.d[0] && mBatchSize % mDims.d[0] == 0 && mFileBatchPos == mDims.d[0])
        {
            mFileCount += skipCount * mBatchSize / mDims.d[0];
            return;
        }

        int x = mBatchCount;
        for (int i = 0; i < skipCount; i++)
        {
            next();
        }
        mBatchCount = x;
    }

    float* getBatch() override
    {
        return mBatch.data();
    }

    float* getLabels() override
    {
        return mLabels.data();
    }

    int getBatchesRead() const override
    {
        return mBatchCount;
    }

    int getBatchSize() const override
    {
        return mBatchSize;
    }

    nvinfer1::Dims getDims() const override
    {
        return mDims;
    }

private:
    float* getFileBatch()
    {
        return mFileBatch.data();
    }

    float* getFileLabels()
    {
        return mFileLabels.data();
    }

    bool update()
    {
        if (mListFile.empty())
        {
            std::string inputFileName
                = samplesCommon::locateFile(mPrefix + std::to_string(mFileCount++) + mSuffix, mDataDir);
            std::ifstream file(inputFileName.c_str(), std::ios::binary);
            if (!file)
            {
                return false;
            }
            int d[4];
            file.read(reinterpret_cast<char*>(d), 4 * sizeof(int32_t));
            ASSERT(mDims.d[0] == d[0] && mDims.d[1] == d[1] && mDims.d[2] == d[2] && mDims.d[3] == d[3]);
            file.read(reinterpret_cast<char*>(getFileBatch()), sizeof(float) * mDims.d[0] * mImageSize);
            file.read(reinterpret_cast<char*>(getFileLabels()), sizeof(float) * mDims.d[0]);
        }
        else
        {
            std::vector<std::string> fNames;
            std::ifstream file(samplesCommon::locateFile(mListFile, mDataDir), std::ios::binary);
            if (!file)
            {
                return false;
            }

            sample::gLogInfo << "Batch #" << mFileCount << std::endl;
            file.seekg(((mBatchCount * mBatchSize)) * 7);

            for (int i = 1; i <= mBatchSize; i++)
            {
                std::string sName;
                std::getline(file, sName);
                sName = sName + ".ppm";
                sample::gLogInfo << "Calibrating with file " << sName << std::endl;
                fNames.emplace_back(sName);
            }

            mFileCount++;

            const int imageC = 3;
            const int imageH = 300;
            const int imageW = 300;
            std::vector<samplesCommon::PPM<imageC, imageH, imageW>> ppms(fNames.size());
            for (uint32_t i = 0; i < fNames.size(); ++i)
            {
                readPPMFile(samplesCommon::locateFile(fNames[i], mDataDir), ppms[i]);
            }

            std::vector<float> data(samplesCommon::volume(mDims));
            const float scale = 2.0 / 255.0;
            const float bias = 1.0;
            long int volChl = mDims.d[2] * mDims.d[3];

            // Normalize input data
            for (int i = 0, volImg = mDims.d[1] * mDims.d[2] * mDims.d[3]; i < mBatchSize; ++i)
            {
                for (int c = 0; c < mDims.d[1]; ++c)
                {
                    for (int j = 0; j < volChl; ++j)
                    {
                        data[i * volImg + c * volChl + j] = scale * float(ppms[i].buffer[j * mDims.d[1] + c]) - bias;
                    }
                }
            }

            std::copy_n(data.data(), mDims.d[0] * mImageSize, getFileBatch());
        }

        mFileBatchPos = 0;
        return true;
    }

    int64_t mBatchSize{0};
    int mMaxBatches{0};
    int mBatchCount{0};
    int mFileCount{0};
    int mFileBatchPos{0};
    int mImageSize{0};
    std::vector<float> mBatch;         //!< Data for the batch
    std::vector<float> mLabels;        //!< Labels for the batch
    std::vector<float> mFileBatch;     //!< List of image files
    std::vector<float> mFileLabels;    //!< List of label files
    std::string mPrefix;               //!< Batch file name prefix
    std::string mSuffix;               //!< Batch file name suffix
    nvinfer1::Dims mDims;              //!< Input dimensions
    std::string mListFile;             //!< File name of the list of image names
    std::vector<std::string> mDataDir; //!< Directories where the files can be found
};

#endif
