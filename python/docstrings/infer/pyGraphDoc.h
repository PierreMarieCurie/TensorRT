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

// This file contains all INetworkDefinition related docstrings, since these are typically too long to keep in the
// binding code.
#pragma once

namespace tensorrt
{
namespace LayerTypeDoc
{

constexpr const char* descr = R"trtdoc(Type of Layer)trtdoc";
constexpr const char* CONVOLUTION = R"trtdoc(Convolution layer)trtdoc";
constexpr const char* GRID_SAMPLE = R"trtdoc(Grid sample layer)trtdoc";
constexpr const char* NMS = R"trtdoc(NMS layer)trtdoc";
constexpr const char* ACTIVATION = R"trtdoc(Activation layer)trtdoc";
constexpr const char* POOLING = R"trtdoc(Pooling layer)trtdoc";
constexpr const char* LRN = R"trtdoc(LRN layer)trtdoc";
constexpr const char* SCALE = R"trtdoc(Scale layer)trtdoc";
constexpr const char* SOFTMAX = R"trtdoc(Softmax layer)trtdoc";
constexpr const char* DECONVOLUTION = R"trtdoc(Deconvolution layer)trtdoc";
constexpr const char* CONCATENATION = R"trtdoc(Concatenation layer)trtdoc";
constexpr const char* ELEMENTWISE = R"trtdoc(Elementwise layer)trtdoc";
constexpr const char* PLUGIN = R"trtdoc(Plugin layer)trtdoc";
constexpr const char* UNARY = R"trtdoc(Unary layer)trtdoc";
constexpr const char* PADDING = R"trtdoc(Padding layer)trtdoc";
constexpr const char* SHUFFLE = R"trtdoc(Shuffle layer)trtdoc";
constexpr const char* REDUCE = R"trtdoc(Reduce layer)trtdoc";
constexpr const char* TOPK = R"trtdoc(TopK layer)trtdoc";
constexpr const char* GATHER = R"trtdoc(Gather layer)trtdoc";
constexpr const char* MATRIX_MULTIPLY = R"trtdoc(Matrix multiply layer)trtdoc";
constexpr const char* RAGGED_SOFTMAX = R"trtdoc(Ragged softmax layer)trtdoc";
constexpr const char* CONSTANT = R"trtdoc(Constant layer)trtdoc";
constexpr const char* IDENTITY = R"trtdoc(Identity layer)trtdoc";
constexpr const char* CAST = R"trtdoc(Cast layer)trtdoc";
constexpr const char* PLUGIN_V2 = R"trtdoc(PluginV2 layer)trtdoc";
constexpr const char* SLICE = R"trtdoc(Slice layer)trtdoc";
constexpr const char* SHAPE = R"trtdoc(Shape layer)trtdoc";
constexpr const char* PARAMETRIC_RELU = R"trtdoc(Parametric ReLU layer)trtdoc";
constexpr const char* RESIZE = R"trtdoc(Resize layer)trtdoc";
constexpr const char* TRIP_LIMIT = R"trtdoc(Loop Trip limit layer)trtdoc";
constexpr const char* RECURRENCE = R"trtdoc(Loop Recurrence layer)trtdoc";
constexpr const char* ITERATOR = R"trtdoc(Loop Iterator layer)trtdoc";
constexpr const char* LOOP_OUTPUT = R"trtdoc(Loop output layer)trtdoc";
constexpr const char* SELECT = R"trtdoc(Select layer)trtdoc";
constexpr const char* ASSERTION = R"trtdoc(Assertion layer)trtdoc";
constexpr const char* FILL = R"trtdoc(Fill layer)trtdoc";
constexpr const char* QUANTIZE = R"trtdoc(Quantize layer)trtdoc";
constexpr const char* DEQUANTIZE = R"trtdoc(Dequantize layer)trtdoc";
constexpr const char* SCATTER = R"trtdoc(Scatter layer)trtdoc";
constexpr const char* CONDITION = R"trtdoc(If-conditional Condition layer)trtdoc";
constexpr const char* CONDITIONAL_OUTPUT = R"trtdoc(If-conditional output layer)trtdoc";
constexpr const char* CONDITIONAL_INPUT = R"trtdoc(If-conditional input layer)trtdoc";
constexpr const char* EINSUM = R"trtdoc(Einsum layer)trtdoc";
constexpr const char* ONE_HOT = R"trtdoc(OneHot layer)trtdoc";
constexpr char const* NON_ZERO = R"trtdoc(NonZero layer)trtdoc";
constexpr char const* REVERSE_SEQUENCE = R"trtdoc(ReverseSequence layer)trtdoc";
constexpr char const* NORMALIZATION = R"trtdoc(Normalization layer)trtdoc";
constexpr const char* PLUGIN_V3 = R"trtdoc(PluginV3 layer)trtdoc";
constexpr const char* SQUEEZE = R"trtdoc(Squeeze layer)trtdoc";
constexpr const char* UNSQUEEZE = R"trtdoc(Unsqueeze layer)trtdoc";
constexpr const char* CUMULATIVE = R"trtdoc(Cumulative layer)trtdoc";
constexpr const char* DYNAMIC_QUANTIZE = R"trtdoc(DynamicQuantize layer)trtdoc";
constexpr const char* SPLIT_TO_RAGGED = R"trtdoc(SplitToRagged layer)trtdoc";
constexpr const char* CONCAT_FROM_RAGGED = R"trtdoc(ConcatFromRagged layer)trtdoc";
} // namespace LayerTypeDoc

namespace TensorFormatDoc
{
constexpr const char* descr = R"trtdoc(
    Format of the input/output tensors.

    This enum is used by both plugins and network I/O tensors.

    For more information about data formats, see the topic "Data Format Description" located in the
    TensorRT Developer Guide (https://docs.nvidia.com/deeplearning/sdk/tensorrt-developer-guide/index.html).
)trtdoc";

constexpr const char* LINEAR = R"trtdoc(
    Row major linear format.

    For a tensor with dimensions {N, C, H, W}, the W axis always has unit stride, and the stride of every other axis is at least the product of the next dimension times the next stride. the strides are the same as for a C array with dimensions [N][C][H][W].
)trtdoc";

constexpr const char* CHW2 = R"trtdoc(
    Two wide channel vectorized row major format.

    This format is bound to FP16 and BF16. It is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to a C array with dimensions [N][(C+1)/2][H][W][2], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][c/2][h][w][c%2].
)trtdoc";

constexpr const char* HWC8 = R"trtdoc(
    Eight channel format where C is padded to a multiple of 8.

    This format is bound to FP16 and BF16. It is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to the array with dimensions [N][H][W][(C+7)/8*8], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][h][w][c].
)trtdoc";

constexpr const char* CHW4 = R"trtdoc(
    Four wide channel vectorized row major format.
    This format is bound to INT8. It is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to a C array with dimensions [N][(C+3)/4][H][W][4], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][c/4][h][w][c%4].
)trtdoc";

constexpr const char* CHW16 = R"trtdoc(
    Sixteen wide channel vectorized row major format.

    This format is only supported by DLA and requires FP16. It is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to a C array with dimensions [N][(C+15)/16][H][W][16], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][c/16][h][w][c%16].
)trtdoc";

constexpr const char* CHW32 = R"trtdoc(
    Thirty-two wide channel vectorized row major format.

    This format is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to a C array with dimensions [N][(C+31)/32][H][W][32], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][c/32][h][w][c%32].
)trtdoc";

constexpr const char* DHWC8 = R"trtdoc(
    Eight channel format where C is padded to a multiple of 8.

    This format is bound to FP16 and BF16, and it is only available for dimensions >= 4.

    For a tensor with dimensions {N, C, D, H, W}, the memory layout is equivalent to an array with dimensions [N][D][H][W][(C+7)/8*8], with the tensor coordinates (n, c, d, h, w) mapping to array subscript [n][d][h][w][c].
)trtdoc";

constexpr const char* CDHW32 = R"trtdoc(
    Thirty-two wide channel vectorized row major format with 3 spatial dimensions.

    This format is bound to FP16 and INT8. It is only available for dimensions >= 4.

    For a tensor with dimensions {N, C, D, H, W}, the memory layout is equivalent to a C array with dimensions [N][(C+31)/32][D][H][W][32], with the tensor coordinates (n, d, c, h, w) mapping to array subscript [n][c/32][d][h][w][c%32].
)trtdoc";

constexpr const char* HWC = R"trtdoc(
    Non-vectorized channel-last format.
    This format is bound to FP32, FP16, INT8, INT64 and BF16, and is only available for dimensions >= 3.
)trtdoc";

constexpr const char* DLA_LINEAR = R"trtdoc(
    DLA planar format. Row major format. The stride for stepping along the H axis is rounded up to 64 bytes.

    This format is bound to FP16/Int8 and is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to a C array with dimensions [N][C][H][roundUp(W, 64/elementSize)] where elementSize is 2 for FP16 and 1 for Int8, with the tensor coordinates (n, c, h, w) mapping to array subscript [n][c][h][w].
)trtdoc";

constexpr const char* DLA_HWC4 = R"trtdoc(
    DLA image format. channel-last format. C can only be 1, 3, 4. If C == 3 it will be rounded to 4. The stride for stepping along the H axis is rounded up to 32 bytes.

    This format is bound to FP16/Int8 and is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, with C’ is 1, 4, 4 when C is 1, 3, 4 respectively, the memory layout is equivalent to a C array with dimensions [N][H][roundUp(W, 32/C'/elementSize)][C'] where elementSize is 2 for FP16 and 1 for Int8, C' is the rounded C. The tensor coordinates (n, c, h, w) maps to array subscript [n][h][w][c].
)trtdoc";

constexpr const char* HWC16 = R"trtdoc(
    Sixteen channel format where C is padded to a multiple of 16. This format is bound to FP16/INT8/FP8. It is only available for dimensions >= 3.

    For a tensor with dimensions {N, C, H, W}, the memory layout is equivalent to the array with dimensions [N][H][W][(C+15)/16*16], with the tensor coordinates (n, c, h, w) mapping to array subscript [n][h][w][c].
)trtdoc";

constexpr const char* DHWC = R"trtdoc(
    Non-vectorized channel-last format. This format is bound to FP32.  It is only available for dimensions >= 4.
)trtdoc";

} // namespace TensorFormatDoc

namespace ITensorDoc
{
constexpr const char* descr = R"trtdoc(
    A tensor in an :class:`INetworkDefinition` .

    :ivar name: :class:`str` The tensor name. For a network input, the name is assigned by the application. For tensors which are layer outputs, a default name is assigned consisting of the layer name followed by the index of the output in brackets. Each network input and output tensor must have a unique name.

    :ivar shape: :class:`Dims` The shape of a tensor. For a network input the shape is assigned by the application. For a network output it is computed based on the layer parameters and the inputs to the layer. If a tensor size or a parameter is modified in the network, the shape of all dependent tensors will be recomputed. This call is only legal for network input tensors, since the shape of layer output tensors are inferred based on layer inputs and parameters.

    :ivar dtype: :class:`DataType` The data type of a tensor. The type is unchanged if the type is invalid for the given tensor.

    :ivar broadcast_across_batch: :class:`bool` [DEPRECATED] Deprecated in TensorRT 10.0. Always false since the implicit batch dimensions support has been removed.

    :ivar location: :class:`TensorLocation` The storage location of a tensor.
    :ivar is_network_input: :class:`bool` Whether the tensor is a network input.
    :ivar is_network_output: :class:`bool` Whether the tensor is a network output.
    :ivar dynamic_range: :class:`Tuple[float, float]` [DEPRECATED] Deprecated in TensorRT 10.1. Superseded by explicit quantization. A tuple containing the [minimum, maximum] of the dynamic range, or :class:`None` if the range was not set.
    :ivar is_shape: :class:`bool` Whether the tensor is a shape tensor.
    :ivar allowed_formats: :class:`int32` The allowed set of TensorFormat candidates. This should be an integer consisting of one or more :class:`TensorFormat` s, combined via bitwise OR after bit shifting. For example, ``1 << int(TensorFormat.CHW4) | 1 << int(TensorFormat.CHW32)``.
)trtdoc"
    ;

constexpr const char* set_dynamic_range = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.1. Superseded by explicit quantization.
    Set dynamic range for the tensor.
    NOTE: It is suggested to use ``tensor.dynamic_range = (min, max)`` instead.

    :arg min: Minimum of the dynamic range.
    :arg max: Maximum of the dyanmic range.
    :returns: true if succeed in setting range. Otherwise false.
)trtdoc";

constexpr const char* get_dynamic_range = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.1. Superseded by explicit quantization.
    Get dynamic range for the tensor.
    NOTE: It is suggested to use ``tensor.dynamic_range`` instead, which is a tuple including both the minimum and maximum of the dynamic range.

    :returns: The absolute maximum of the dynamic range.
)trtdoc";

constexpr const char* reset_dynamic_range = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.1. Superseded by explicit quantization.
    Undo the effect of setting the dynamic range.
)trtdoc";

constexpr const char* set_dimension_name = R"trtdoc(
    Name a dimension of an input tensor.

    Associate a runtime dimension of an input tensor with a symbolic name.
    Dimensions with the same non-empty name must be equal at runtime.
    Knowing this equality for runtime dimensions may help the TensorRT optimizer.
    Both runtime and build-time dimensions can be named.
    If the function is called again, with the same index, it will overwrite the previous name.
    If None is passed as name, it will clear the name of the dimension.

    For example, setDimensionName(0, "n") associates the symbolic name "n" with the leading dimension.

    :arg index: index of the dimension.
    :arg name: name of the dimension.
)trtdoc";

constexpr const char* get_dimension_name = R"trtdoc(
    Get the name of an input dimension.

    :arg index: index of the dimension.
    :returns: name of the dimension, or null if dimension is unnamed.
)trtdoc";

} // namespace ITensorDoc

namespace ILayerDoc
{
constexpr const char* descr = R"trtdoc(
    Base class for all layer classes in an :class:`INetworkDefinition` .

    :ivar name: :class:`str` The name of the layer.
    :ival metadata: :class:`str` The per-layer metadata.
    :ivar type: :class:`LayerType` The type of the layer.
    :ivar num_inputs: :class:`int` The number of inputs of the layer.
    :ivar num_outputs: :class:`int` The number of outputs of the layer.
    :ivar precision: :class:`DataType` The computation precision.
    :ivar precision_is_set: :class:`bool` Whether the precision is set or not.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Set the layer input corresponding to the given index.

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

constexpr const char* get_input = R"trtdoc(
    Get the layer input corresponding to the given index.

    :arg index: The index of the input tensor.

    :returns: The input tensor, or :class:`None` if the index is out of range.
)trtdoc";

constexpr const char* get_output = R"trtdoc(
    Get the layer output corresponding to the given index.

    :arg index: The index of the output tensor.

    :returns: The output tensor, or :class:`None` if the index is out of range.
)trtdoc";

constexpr const char* reset_precision = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.12. Superseded by strong typing.
    Reset the computation precision of the layer.
)trtdoc";

constexpr const char* set_output_type = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.12. Superseded by strong typing.
    Constraint layer to generate output data with given type.
    Note that this method cannot be used to set the data type
    of the second output tensor of the topK layer. The data
    type of the second output tensor of the topK layer is always :class:`int32` .

    :arg index: The index of the output tensor to set the type.
    :arg dtype: DataType of the output.
)trtdoc";

constexpr const char* get_output_type = R"trtdoc(
    Get the output type of the layer.

    :arg index: The index of the output tensor.

    :returns: The output precision. Default : DataType.FLOAT.
)trtdoc";

constexpr const char* output_type_is_set = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.12. Superseded by strong typing.
    Whether the output type has been set for this layer.

    :arg index: The index of the output.

    :returns: Whether the output type has been explicitly set.
)trtdoc";

constexpr const char* reset_output_type = R"trtdoc(
    [DEPRECATED] Deprecated in TensorRT 10.12. Superseded by strong typing.
    Reset output type of this layer.

    :arg index: The index of the output.
)trtdoc";

} // namespace ILayerDoc

namespace PaddingModeDoc
{
constexpr const char* descr = R"trtdoc(
    Enumerates types of padding available in convolution, deconvolution and pooling layers.
    Padding mode takes precedence if both :attr:`padding_mode` and :attr:`pre_padding` are set.

    |  EXPLICIT* corresponds to explicit padding.
    |  SAME* implicitly calculates padding such that the output dimensions are the same as the input dimensions. For convolution and pooling,
        output dimensions are determined by ceil(input dimensions, stride).
    |  CAFFE* corresponds to symmetric padding.
)trtdoc";

constexpr const char* EXPLICIT_ROUND_DOWN = R"trtdoc(Use explicit padding, rounding the output size down)trtdoc";
constexpr const char* EXPLICIT_ROUND_UP = R"trtdoc(Use explicit padding, rounding the output size up)trtdoc";
constexpr const char* SAME_UPPER = R"trtdoc(Use SAME padding, with :attr:`pre_padding` <= :attr:`post_padding` )trtdoc";
constexpr const char* SAME_LOWER = R"trtdoc(Use SAME padding, with :attr:`pre_padding` >= :attr:`post_padding` )trtdoc";

} // namespace PaddingModeDoc

namespace IConvolutionLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A convolution layer in an :class:`INetworkDefinition` .

    This layer performs a correlation operation between 3 or 4 dimensional filter with a 4 or 5 dimensional tensor to produce another 4 or 5 dimensional tensor.

    An optional bias argument is supported, which adds a per-channel constant to each value in the output.

    :ivar num_output_maps: :class:`int` The number of output maps for the convolution.
    :ivar pre_padding: :class:`DimsHW` The pre-padding. The start of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar post_padding: :class:`DimsHW` The post-padding. The end of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar padding_mode: :class:`PaddingMode` The padding mode. Padding mode takes precedence if both :attr:`IConvolutionLayer.padding_mode` and either :attr:`IConvolutionLayer.pre_padding` or :attr:`IConvolutionLayer.post_padding` are set.
    :ivar num_groups: :class:`int` The number of groups for a convolution. The input tensor channels are divided into this many groups, and a convolution is executed for each group, using a filter per group. The results of the group convolutions are concatenated to form the output. **Note** When using groups in int8 mode, the size of the groups (i.e. the channel count divided by the group count) must be a multiple of 4 for both input and output. Default: 1.
    :ivar kernel: :class:`Weights` The kernel weights for the convolution. The weights are specified as a contiguous array in `GKCRS` order, where `G` is the number of groups, `K` the number of output feature maps, `C` the number of input channels, and `R` and `S` are the height and width of the filter.
    :ivar bias: :class:`Weights` The bias weights for the convolution. Bias is optional. To omit bias, set this to an empty :class:`Weights` object. The bias is applied per-channel, so the number of weights (if non-zero) must be equal to the number of output feature maps.
    :ivar kernel_size_nd: :class:`Dims` The multi-dimension kernel size of the convolution.
    :ivar stride_nd: :class:`Dims` The multi-dimension stride of the convolution. Default: (1, ..., 1)
    :ivar padding_nd: :class:`Dims` The multi-dimension padding of the convolution. The input will be zero-padded by this number of elements in each dimension. If the padding is asymmetric, this value corresponds to the pre-padding. Default: (0, ..., 0)
    :ivar dilation_nd: :class:`Dims` The multi-dimension dilation for the convolution. Default: (1, ..., 1)
)trtdoc";
} // namespace IConvolutionLayerDoc

namespace ActivationTypeDoc
{
constexpr const char* descr = R"trtdoc(The type of activation to perform.)trtdoc";

constexpr const char* RELU = R"trtdoc(Rectified Linear activation)trtdoc";
constexpr const char* SIGMOID = R"trtdoc(Sigmoid activation)trtdoc";
constexpr const char* TANH = R"trtdoc(Hyperbolic Tangent activation)trtdoc";
constexpr const char* LEAKY_RELU
    = R"trtdoc(Leaky Relu activation: f(x) = x if x >= 0, f(x) = alpha * x if x < 0)trtdoc";
constexpr const char* ELU = R"trtdoc(Elu activation: f(x) = x if x >= 0, f(x) = alpha * (exp(x) - 1) if x < 0)trtdoc";
constexpr const char* SELU
    = R"trtdoc(Selu activation: f(x) = beta * x if x > 0, f(x) = beta * (alpha * exp(x) - alpha) if x <= 0)trtdoc";
constexpr const char* SOFTSIGN = R"trtdoc(Softsign activation: f(x) = x / (1 + abs(x)))trtdoc";
constexpr const char* SOFTPLUS = R"trtdoc(Softplus activation: f(x) = alpha * log(exp(beta * x) + 1))trtdoc";
constexpr const char* CLIP = R"trtdoc(Clip activation: f(x) = max(alpha, min(beta, x)))trtdoc";
constexpr const char* HARD_SIGMOID = R"trtdoc(Hard sigmoid activation: f(x) = max(0, min(1, alpha * x + beta)))trtdoc";
constexpr const char* SCALED_TANH = R"trtdoc(Scaled Tanh activation: f(x) = alpha * tanh(beta * x))trtdoc";
constexpr const char* THRESHOLDED_RELU
    = R"trtdoc(Thresholded Relu activation: f(x) = x if x > alpha, f(x) = 0 if x <= alpha)trtdoc";
constexpr const char* GELU_ERF = R"trtdoc(GELU erf activation: 0.5 * x * (1 + erf(sqrt(0.5) * x)))trtdoc";
constexpr const char* GELU_TANH
    = R"trtdoc(GELU tanh activation: 0.5 * x * (1 + tanh(sqrt(2/pi) * (0.044715F * pow(x, 3) + x))))trtdoc";
} // namespace ActivationTypeDoc

namespace IActivationLayerDoc
{
constexpr const char* descr = R"trtdoc(
    An Activation layer in an :class:`INetworkDefinition` . This layer applies a per-element activation function to its input. The output has the same shape as the input.

    :ivar type: :class:`ActivationType` The type of activation to be performed.
    :ivar alpha: :class:`float` The alpha parameter that is used by some parametric activations (LEAKY_RELU, ELU, SELU, SOFTPLUS, CLIP, HARD_SIGMOID, SCALED_TANH). Other activations ignore this parameter.
    :ivar beta: :class:`float` The beta parameter that is used by some parametric activations (SELU, SOFTPLUS, CLIP, HARD_SIGMOID, SCALED_TANH). Other activations ignore this parameter.
)trtdoc";
} // namespace IActivationLayerDoc

namespace PoolingTypeDoc
{
constexpr const char* descr = R"trtdoc(The type of pooling to perform in a pooling layer.)trtdoc";

constexpr const char* MAX = R"trtdoc(Maximum over elements)trtdoc";
constexpr const char* AVERAGE
    = R"trtdoc(Average over elements. If the tensor is padded, the count includes the padding)trtdoc";
constexpr const char* MAX_AVERAGE_BLEND
    = R"trtdoc(Blending between the max pooling and average pooling: `(1-blendFactor)*maxPool + blendFactor*avgPool`)trtdoc";
} // namespace PoolingTypeDoc

namespace IPoolingLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Pooling layer in an :class:`INetworkDefinition` . The layer applies a reduction operation within a window over the input.

    :ivar type: :class:`PoolingType` The type of pooling to be performed.
    :ivar pre_padding: :class:`DimsHW` The pre-padding. The start of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar post_padding: :class:`DimsHW` The post-padding. The end of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar padding_mode: :class:`PaddingMode` The padding mode. Padding mode takes precedence if both :attr:`IPoolingLayer.padding_mode` and either :attr:`IPoolingLayer.pre_padding` or :attr:`IPoolingLayer.post_padding` are set.
    :ivar blend_factor: :class:`float` The blending factor for the max_average_blend mode: :math:`max_average_blendPool = (1-blendFactor)*maxPool + blendFactor*avgPool` . ``blend_factor`` is a user value in [0,1] with the default value of 0.0. This value only applies for the :const:`PoolingType.MAX_AVERAGE_BLEND` mode.
    :ivar average_count_excludes_padding: :class:`bool` Whether average pooling uses as a denominator the overlap area between the window and the unpadded input. If this is not set, the denominator is the overlap between the pooling window and the padded input. Default: True
    :ivar window_size_nd: :class:`Dims` The multi-dimension window size for pooling.
    :ivar stride_nd: :class:`Dims` The multi-dimension stride for pooling. Default: (1, ..., 1)
    :ivar padding_nd: :class:`Dims` The multi-dimension padding for pooling. Default: (0, ..., 0)
)trtdoc";
} // namespace IPoolingLayerDoc

namespace ILRNLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A LRN layer in an :class:`INetworkDefinition` . The output size is the same as the input size.

    :ivar window_size: :class:`int` The LRN window size. The window size must be odd and in the range of [1, 15].
    :ivar alpha: :class:`float` The LRN alpha value. The valid range is [-1e20, 1e20].
    :ivar beta: :class:`float` The LRN beta value. The valid range is [0.01, 1e5f].
    :ivar k: :class:`float` The LRN K value. The valid range is [1e-5, 1e10].
)trtdoc";
} // namespace ILRNLayerDoc

namespace ScaleModeDoc
{
constexpr const char* descr = R"trtdoc(Controls how scale is applied in a Scale layer.)trtdoc";

constexpr const char* UNIFORM = R"trtdoc(Identical coefficients across all elements of the tensor.)trtdoc";
constexpr const char* CHANNEL
    = R"trtdoc(Per-channel coefficients. The channel dimension is assumed to be the third to last dimension.)trtdoc";
constexpr const char* ELEMENTWISE = R"trtdoc(Elementwise coefficients.)trtdoc";
} // namespace ScaleModeDoc

namespace IScaleLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Scale layer in an :class:`INetworkDefinition` .

    This layer applies a per-element computation to its input:

    :math:`output = (input * scale + shift) ^ {power}`

    The coefficients can be applied on a per-tensor, per-channel, or per-element basis.

    **Note**
    If the number of weights is 0, then a default value is used for shift, power, and scale. The default shift is 0, the default power is 1, and the default scale is 1.

    The output size is the same as the input size.

    **Note**
    The input tensor for this layer is required to have a minimum of 3 dimensions.

    :ivar mode: :class:`ScaleMode` The scale mode.
    :ivar shift: :class:`Weights` The shift value.
    :ivar scale: :class:`Weights` The scale value.
    :ivar power: :class:`Weights` The power value.
    :ivar channel_axis: :class:`int` The channel axis.
)trtdoc";
} // namespace IScaleLayerDoc

namespace ISoftMaxLayerDoc
{
// TODO: Figure out how to do preformatted text inside :ivar:s
constexpr const char* descr = R"trtdoc(
    A Softmax layer in an :class:`INetworkDefinition` .

    This layer applies a per-channel softmax to its input.

    The output size is the same as the input size.

    :ivar axes: :class:`int` The axis along which softmax is computed. Currently, only one axis can be set.

    The axis is specified by setting the bit corresponding to the axis to 1, as a bit mask.

    For example, consider an NCHW tensor as input (three non-batch dimensions).

    By default, softmax is performed on the axis which is the number of axes minus three. It is 0 if there are fewer than 3 non-batch axes. For example, if the input is NCHW, the default axis is C. If the input is NHW, then the default axis is H.

    |  Bit 0 corresponds to the N dimension boolean.
    |  Bit 1 corresponds to the C dimension boolean.
    |  Bit 2 corresponds to the H dimension boolean.
    |  Bit 3 corresponds to the W dimension boolean.
    |  By default, softmax is performed on the axis which is the number of axes minus three. It is 0 if
    |  there are fewer than 3 axes. For example, if the input is NCHW, the default axis is C. If the input
    |  is NHW, then the default axis is N.
    |
    |  For example, to perform softmax on axis R of a NPQRCHW input, set bit 3.

    The following constraints must be satisfied to execute this layer on DLA:

    - Axis must be one of the channel or spatial dimensions.
    - There are two classes of supported input sizes:

       * Non-axis, non-batch dimensions are all 1 and the axis dimension is at most 8192. This is the recommended case for using softmax since it is the most accurate.
       * At least one non-axis, non-batch dimension greater than 1 and the axis dimension is at most 1024. Note that in this case, there may be some approximation error as the axis dimension size approaches the upper bound. See the TensorRT Developer Guide for more details on the approximation error.
)trtdoc";
} // namespace ISoftMaxLayerDoc

namespace IConcatenationLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A concatenation layer in an :class:`INetworkDefinition` .

    The output channel size is the sum of the channel sizes of the inputs.
    The other output sizes are the same as the other input sizes, which must all match.

    :ivar axis: :class:`int` The axis along which concatenation occurs. The default axis is the number of tensor dimensions minus three, or zero if the tensor has fewer than three dimensions. For example, for a tensor with dimensions NCHW, it is C.
)trtdoc";
} // namespace IConcatenationLayerDoc

namespace IDeconvolutionLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A deconvolution layer in an :class:`INetworkDefinition` .

    :ivar num_output_maps: :class:`int` The number of output feature maps for the deconvolution.
    :ivar pre_padding: :class:`DimsHW` The pre-padding. The start of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar post_padding: :class:`DimsHW` The post-padding. The end of input will be zero-padded by this number of elements in the height and width directions. Default: (0, 0)
    :ivar padding_mode: :class:`PaddingMode` The padding mode. Padding mode takes precedence if both :attr:`IDeconvolutionLayer.padding_mode` and either :attr:`IDeconvolutionLayer.pre_padding` or :attr:`IDeconvolutionLayer.post_padding` are set.
    :ivar num_groups: :class:`int` The number of groups for a deconvolution. The input tensor channels are divided into this many groups, and a deconvolution is executed for each group, using a filter per group. The results of the group convolutions are concatenated to form the output. **Note** When using groups in int8 mode, the size of the groups (i.e. the channel count divided by the group count) must be a multiple of 4 for both input and output. Default: 1
    :ivar kernel: :class:`Weights` The kernel weights for the deconvolution. The weights are specified as a contiguous array in `CKRS` order, where `C` the number of input channels, `K` the number of output feature maps, and `R` and `S` are the height and width of the filter.
    :ivar bias: :class:`Weights` The bias weights for the deconvolution. Bias is optional. To omit bias, set this to an empty :class:`Weights` object. The bias is applied per-feature-map, so the number of weights (if non-zero) must be equal to the number of output feature maps.
    :ivar kernel_size_nd: :class:`Dims` The multi-dimension kernel size of the convolution.
    :ivar stride_nd: :class:`Dims` The multi-dimension stride of the deconvolution. Default: (1, ..., 1)
    :ivar padding_nd: :class:`Dims` The multi-dimension padding of the deconvolution. The input will be zero-padded by this number of elements in each dimension. Padding is symmetric. Default: (0, ..., 0)
)trtdoc";
} // namespace IDeconvolutionLayerDoc

namespace ElementWiseOperationDoc
{
constexpr const char* descr = R"trtdoc(The binary operations that may be performed by an ElementWise layer.)trtdoc";

constexpr const char* SUM = R"trtdoc(Sum of the two elements)trtdoc";
constexpr const char* PROD = R"trtdoc(Product of the two elements)trtdoc";
constexpr const char* MAX = R"trtdoc(Max of the two elements)trtdoc";
constexpr const char* MIN = R"trtdoc(Min of the two elements)trtdoc";
constexpr const char* SUB = R"trtdoc(Subtract the second element from the first)trtdoc";
constexpr const char* DIV = R"trtdoc(Divide the first element by the second)trtdoc";
constexpr const char* POW = R"trtdoc(The first element to the power of the second element)trtdoc";
constexpr const char* FLOOR_DIV = R"trtdoc(Floor division of the first element by the second)trtdoc";
constexpr const char* AND = R"trtdoc(Logical AND of two elements)trtdoc";
constexpr const char* OR = R"trtdoc(Logical OR of two elements)trtdoc";
constexpr const char* XOR = R"trtdoc(Logical XOR of two elements)trtdoc";
constexpr const char* EQUAL = R"trtdoc(Check if two elements are equal)trtdoc";
constexpr const char* GREATER
    = R"trtdoc(Check if element in first tensor is greater than corresponding element in second tensor)trtdoc";
constexpr const char* LESS
    = R"trtdoc(Check if element in first tensor is less than corresponding element in second tensor)trtdoc";
} // namespace ElementWiseOperationDoc

namespace IElementWiseLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A elementwise layer in an :class:`INetworkDefinition` .

    This layer applies a per-element binary operation between corresponding elements of two tensors.

    The input dimensions of the two input tensors must be equal, and the output tensor is the same size as each input.

    :ivar op: :class:`ElementWiseOperation` The binary operation for the layer.
)trtdoc";
} // namespace IElementWiseLayerDoc

namespace IGatherLayerDoc
{
// TODO: Add better description here.
constexpr const char* descr = R"trtdoc(
    A gather layer in an :class:`INetworkDefinition` .

    :ivar axis: :class:`int` The non-batch dimension axis to gather on. The axis must be less than the number of non-batch dimensions in the data input.
    :ivar num_elementwise_dims: :class:`int` The number of leading dimensions of indices tensor to be handled elementwise. For `GatherMode.DEFAULT`, it can be 0 or 1. For `GatherMode::kND`, it can be between 0 and one less than rank(data). For `GatherMode::kELEMENT`, it must be 0.
    :ivar mode: :class:`GatherMode` The gather mode.
)trtdoc";
} // namespace IGatherLayerDoc

namespace ScatterModeDoc
{
constexpr const char* descr = R"trtdoc(The scatter mode to be done by the scatter layer.)trtdoc";

constexpr const char* ELEMENT = R"trtdoc(Scatter Element mode)trtdoc";
constexpr const char* ND = R"trtdoc(Scatter ND mode)trtdoc";
} // namespace ScatterModeDoc

namespace IScatterLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Scatter layer as in :class:`INetworkDefinition`.
    :ivar axis: axis to scatter on when using Scatter Element mode (ignored in ND mode)
    :ivar mode: :class:`ScatterMode` The operation mode of the scatter.
)trtdoc";
} // namespace IScatterLayerDoc

namespace GatherModeDoc
{
constexpr const char* descr = R"trtdoc(Controls how IGatherLayer gathers data)trtdoc";

constexpr const char* DEFAULT = R"trtdoc(Similar to ONNX Gather. This is the default.)trtdoc";
constexpr const char* ELEMENT = R"trtdoc(Similar to ONNX GatherElements.)trtdoc";
constexpr const char* ND = R"trtdoc(Similar to ONNX GatherND.)trtdoc";
} // namespace GatherModeDoc

namespace IPluginV2LayerDoc
{
constexpr const char* descr = R"trtdoc(
        A plugin layer in an :class:`INetworkDefinition` .

        :ivar plugin: :class:`IPluginV2` The plugin for the layer.
)trtdoc";
} // namespace IPluginV2LayerDoc

namespace IPluginV3LayerDoc
{
constexpr const char* descr = R"trtdoc(
        A plugin layer in an :class:`INetworkDefinition` .

        :ivar plugin: :class:`IPluginV3` The plugin for the layer.
)trtdoc";
} // namespace IPluginV3LayerDoc

namespace UnaryOperationDoc
{
constexpr const char* descr = R"trtdoc(The unary operations that may be performed by a Unary layer.)trtdoc";

constexpr const char* EXP = R"trtdoc(Exponentiation)trtdoc";
constexpr const char* LOG = R"trtdoc(Log (base e))trtdoc";
constexpr const char* SQRT = R"trtdoc(Square root)trtdoc";
constexpr const char* RECIP = R"trtdoc(Reciprocal)trtdoc";
constexpr const char* ABS = R"trtdoc(Absolute value)trtdoc";
constexpr const char* NEG = R"trtdoc(Negation)trtdoc";
constexpr const char* SIN = R"trtdoc(Sine)trtdoc";
constexpr const char* COS = R"trtdoc(Cosine)trtdoc";
constexpr const char* TAN = R"trtdoc(Tangent)trtdoc";
constexpr const char* SINH = R"trtdoc(Hyperbolic sine)trtdoc";
constexpr const char* COSH = R"trtdoc(Hyperbolic cosine)trtdoc";
constexpr const char* ASIN = R"trtdoc(Inverse sine)trtdoc";
constexpr const char* ACOS = R"trtdoc(Inverse cosine)trtdoc";
constexpr const char* ATAN = R"trtdoc(Inverse tangent)trtdoc";
constexpr const char* ASINH = R"trtdoc(Inverse hyperbolic sine)trtdoc";
constexpr const char* ACOSH = R"trtdoc(Inverse hyperbolic cosine)trtdoc";
constexpr const char* ATANH = R"trtdoc(Inverse hyperbolic tangent)trtdoc";
constexpr const char* CEIL = R"trtdoc(Ceiling)trtdoc";
constexpr const char* FLOOR = R"trtdoc(Floor)trtdoc";
constexpr const char* ERF = R"trtdoc(Gauss error function)trtdoc";
constexpr const char* NOT = R"trtdoc(Not)trtdoc";
constexpr const char* SIGN
    = R"trtdoc(Sign. If input > 0, output 1; if input < 0, output -1; if input == 0, output 0.)trtdoc";
constexpr const char* ROUND = R"trtdoc(Round to nearest even for floating-point data type.)trtdoc";
constexpr const char* ISINF
    = R"trtdoc(Return true if the input value equals +/- infinity for floating-point data type.)trtdoc";
constexpr const char* ISNAN
    = R"trtdoc(Return true if the input value equals NaN for floating-point data type.)trtdoc";
} // namespace UnaryOperationDoc

namespace IUnaryLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A unary layer in an :class:`INetworkDefinition` .

    :ivar op: :class:`UnaryOperation` The unary operation for the layer. When running this layer on DLA, only ``UnaryOperation.ABS`` is supported.
)trtdoc";
} // namespace IUnaryLayerDoc

namespace ReduceOperationDoc
{
constexpr const char* descr = R"trtdoc(The reduce operations that may be performed by a Reduce layer)trtdoc";

constexpr const char* SUM = R"trtdoc()trtdoc";
constexpr const char* PROD = R"trtdoc()trtdoc";
constexpr const char* MAX = R"trtdoc()trtdoc";
constexpr const char* MIN = R"trtdoc()trtdoc";
constexpr const char* AVG = R"trtdoc()trtdoc";
} // namespace ReduceOperationDoc

namespace IReduceLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A reduce layer in an :class:`INetworkDefinition` .

    :ivar op: :class:`ReduceOperation` The reduce operation for the layer.
    :ivar axes: :class:`int` The axes over which to reduce.
    :ivar keep_dims: :class:`bool` Specifies whether or not to keep the reduced dimensions for the layer.
)trtdoc";
} // namespace IReduceLayerDoc

namespace IPaddingLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A padding layer in an :class:`INetworkDefinition` .

    :ivar pre_padding_nd: :class:`Dims` The padding that is applied at the start of the tensor. Negative padding results in trimming the edge by the specified amount. Only 2 dimensions currently supported.
    :ivar post_padding_nd: :class:`Dims` The padding that is applied at the end of the tensor. Negative padding results in trimming the edge by the specified amount. Only 2 dimensions currently supported.
)trtdoc";
} // namespace IPaddingLayerDoc

namespace PermutationDoc
{
constexpr const char* descr = R"trtdoc(
    The elements of the permutation. The permutation is applied as outputDimensionIndex = permutation[inputDimensionIndex], so to permute from CHW order to HWC order, the required permutation is [1, 2, 0], and to permute from HWC to CHW, the required permutation is [2, 0, 1].

    It supports iteration and indexing and is implicitly convertible to/from Python iterables (like :class:`tuple` or :class:`list` ). Therefore, you can use those classes in place of :class:`Permutation` .
)trtdoc";
} // namespace PermutationDoc

namespace IShuffleLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A shuffle layer in an :class:`INetworkDefinition` .

    This class shuffles data by applying in sequence: a transpose operation, a reshape operation and a second transpose operation. The dimension types of the output are those of the reshape dimension.

    :ivar first_transpose: :class:`Permutation` The permutation applied by the first transpose operation. Default: Identity Permutation
    :ivar reshape_dims: :class:`Dims` The reshaped dimensions.
        Two special values can be used as dimensions.
        Value 0 copies the corresponding dimension from input. This special value can be used more than once in the dimensions. If number of reshape dimensions is less than input, 0s are resolved by aligning the most significant dimensions of input.
        Value -1 infers that particular dimension by looking at input and rest of the reshape dimensions. Note that only a maximum of one dimension is permitted to be specified as -1.
        The product of the new dimensions must be equal to the product of the old.
    :ivar second_transpose: :class:`Permutation` The permutation applied by the second transpose operation. Default: Identity Permutation
    :ivar zero_is_placeholder: :class:`bool` The meaning of 0 in reshape dimensions.
        If true, then a 0 in the reshape dimensions denotes copying the corresponding
        dimension from the first input tensor.  If false, then a 0 in the reshape
        dimensions denotes a zero-length dimension.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index. The index must be 0 for a static shuffle layer.
    A static shuffle layer is converted to a dynamic shuffle layer by calling :func:`set_input` with an index 1.
    A dynamic shuffle layer cannot be converted back to a static shuffle layer.

    For a dynamic shuffle layer, the values 0 and 1 are valid.
    The indices in the dynamic case are as follows:

    ======= ========================================================================
     Index   Description
    ======= ========================================================================
        0     Data or Shape tensor to be shuffled.
        1     The dimensions for the reshape operation, as a 1D :class:`int32` shape tensor.
    ======= ========================================================================

    If this function is called with a value 1, then :attr:`num_inputs` changes
    from 1 to 2.

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace IShuffleLayerDoc

namespace ISliceLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A slice layer in an :class:`INetworkDefinition` .

    The slice layer has two variants, static and dynamic.
    Static slice specifies the start, size, and stride dimensions at layer creation time via :class:`Dims` and can use the get/set accessor functions of the :class:`ISliceLayer` .
    Dynamic slice specifies one or more of start, size, stride, or axes as :class:`ITensor`s, by using :func:`ILayer.set_input` to add a second, third, fourth, or sixth input respectively.
    The corresponding :class:`Dims` are used if an input is missing or null.

    An application can determine if the :class:`ISliceLayer` has a dynamic output shape based on whether the size or axes input is present and non-null.

    The slice layer selects for each dimension a start location from within the input tensor, and copies elements to the output tensor using the specified stride across the input tensor.
    Start, size, and stride tensors must be 1-D integer-typed shape tensors if not specified via :class:`Dims` .

    An example of using slice on a tensor:
    input = {{0, 2, 4}, {1, 3, 5}}
    start = {1, 0}
    size = {1, 2}
    stride = {1, 2}
    output = {{1, 5}}

    If axes is provided then starts, ends, and strides must have the same length as axes and specifies a subset of dimensions to slice. If axes is not provided, starts, ends, and strides
    must be of the same length as the rank of the input tensor.

    An example of using slice on a tensor with axes specified:
    input = {{0, 2, 4}, {1, 3, 5}}
    start = {1}
    size = {2}
    stride = {1}
    axes = {1}
    output = {{2, 4}, {3, 5}}

    When the sampleMode is :const:`SampleMode.CLAMP` or :const:`SampleMode.REFLECT` , for each input dimension, if its size is 0 then the corresponding output dimension must be 0 too.

    When the sampleMode is :const:`SampleMode.FILL`, the fifth input to the slice layer is used to determine the value to fill in out-of-bound indices. It is an error to specify the fifth input in any other sample mode.

    A slice layer can produce a shape tensor if the following conditions are met:

    * ``start``, ``size``, and ``stride`` are build time constants, either as static :class:`Dims` or as constant input tensors.
    * ``axes``, if provided, is a build time constant, either as static :class:`Dims` or as a constant input tensor.
    * The number of elements in the output tensor does not exceed 2 * :const:`Dims.MAX_DIMS` .

    The input tensor is a shape tensor if the output is a shape tensor.

    The following constraints must be satisfied to execute this layer on DLA:
    * ``start``, ``size``, and ``stride`` are build time constants, either as static :class:`Dims` or as constant input tensors.
    * ``axes``, if provided, is a build time constant, either as static :class:`Dims` or as a constant input tensor.
    * sampleMode is :const:`SampleMode.DEFAULT` , :const:`SampleMode.WRAP` , or :const:`SampleMode.FILL` .
    * Strides are 1 for all dimensions.
    * Slicing is not performed on the first dimension.
    * The input tensor has four dimensions.
    * For :const:`SliceMode.FILL` , the fill value input is a scalar output of an :class:`IConstantLayer` with value 0 that is not consumed by any other layer.

    :ivar start: :class:`Dims` The start offset.
    :ivar shape: :class:`Dims` The output dimensions.
    :ivar stride: :class:`Dims` The slicing stride.
    :ivar mode: :class:`SampleMode` Controls how :class:`ISliceLayer` handles out of bounds coordinates.
    :ivar axes: :class:`Dims` The axes that starts, sizes, and strides correspond to.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index. The index must be 0 or 4 for a static slice layer.
    A static slice layer is converted to a dynamic slice layer by calling :func:`set_input` with an index between 1 and 3.
    A dynamic slice layer cannot be converted back to a static slice layer.

    The indices are as follows:

    =====   ==================================================================================
    Index   Description
    =====   ==================================================================================
        0     Data or Shape tensor to be sliced.
        1     The start tensor to begin slicing, N-dimensional for Data, and 1-D for Shape.
        2     The size tensor of the resulting slice, N-dimensional for Data, and 1-D for Shape.
        3     The stride of the slicing operation, N-dimensional for Data, and 1-D for Shape.
        4     Value for the :const:`SampleMode.FILL` slice mode. Disallowed for other modes.
        5     The axes tensor indicating the axes that starts, sizes, and strides correspond to. Must be a 1-D tensor.
    =====   ==================================================================================

    If this function is called with a value greater than 0, then :attr:`num_inputs` changes
    from 1 to index + 1.

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace ISliceLayerDoc

namespace SampleModeDoc
{
constexpr const char* descr
    = R"trtdoc(Controls how ISliceLayer and IGridSample handles out of bounds coordinates)trtdoc";

constexpr const char* STRICT_BOUNDS = R"trtdoc(Fail with error when the coordinates are out of bounds.)trtdoc";
constexpr const char* WRAP = R"trtdoc(Coordinates wrap around periodically.)trtdoc";
constexpr const char* CLAMP = R"trtdoc(Out of bounds indices are clamped to bounds)trtdoc";
constexpr const char* FILL = R"trtdoc(Use fill input value when coordinates are out of bounds.)trtdoc";
constexpr const char* REFLECT = R"trtdoc(Coordinates reflect.)trtdoc";
} // namespace SampleModeDoc

namespace IShapeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A shape layer in an :class:`INetworkDefinition` . Used for getting the shape of a tensor.
    This class sets the output to a one-dimensional tensor with the dimensions of the input tensor.

    For example, if the input is a four-dimensional tensor (of any type) with
    dimensions [2,3,5,7], the output tensor is a one-dimensional :class:`int64` tensor
    of length 4 containing the sequence 2, 3, 5, 7.
)trtdoc";

} // namespace IShapeLayerDoc

namespace TopKOperationDoc
{
constexpr const char* descr = R"trtdoc(The operations that may be performed by a TopK layer)trtdoc";

constexpr const char* MAX = R"trtdoc(Maximum of the elements)trtdoc";
constexpr const char* MIN = R"trtdoc(Minimum of the elements)trtdoc";
} // namespace TopKOperationDoc

namespace ITopKLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A TopK layer in an :class:`INetworkDefinition` .

    :ivar op: :class:`TopKOperation` The operation for the layer.
    :ivar k: :class:`TopKOperation` the k value for the layer. Currently only values up to 3840 are supported.
        Use the set_input() method with index 1 to pass in dynamic k as a tensor.
    :ivar axes: :class:`TopKOperation` The axes along which to reduce.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index. The index must be 0 or 1 for a TopK layer.

    The indices are as follows:

    =====   ==================================================================================
    Index   Description
    =====   ==================================================================================
        0     Input data tensor.
        1     A scalar Int32 tensor containing a positive value corresponding to the number
                of top elements to retrieve. Values larger than 3840 will result in a runtime
                error. If provided, this will override the static k value in calculations.
    =====   ==================================================================================

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace ITopKLayerDoc

namespace MatrixOperationDoc
{
constexpr const char* descr = R"trtdoc(The matrix operations that may be performed by a Matrix layer)trtdoc";

constexpr const char* NONE = R"trtdoc()trtdoc";
constexpr const char* TRANSPOSE = R"trtdoc(Transpose each matrix)trtdoc";
constexpr const char* VECTOR = R"trtdoc(Treat operand as collection of vectors)trtdoc";
} // namespace MatrixOperationDoc

namespace IMatrixMultiplyLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A matrix multiply layer in an :class:`INetworkDefinition` .

    Let A be op(getInput(0)) and B be op(getInput(1)) where
    op(x) denotes the corresponding MatrixOperation.

    When A and B are matrices or vectors, computes the inner product A * B:

    |   matrix * matrix -> matrix
    |   matrix * vector -> vector
    |   vector * matrix -> vector
    |   vector * vector -> scalar

    Inputs of higher rank are treated as collections of matrices or vectors.
    The output will be a corresponding collection of matrices, vectors, or scalars.

    :ivar op0: :class:`MatrixOperation` How to treat the first input.
    :ivar op1: :class:`MatrixOperation` How to treat the second input.
)trtdoc";
} // namespace IMatrixMultiplyLayerDoc

namespace IRaggedSoftMaxLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A ragged softmax layer in an :class:`INetworkDefinition` .

    This layer takes a ZxS input tensor and an additional Zx1 bounds tensor holding the lengths of the Z sequences.

    This layer computes a softmax across each of the Z sequences.

    The output tensor is of the same size as the input tensor.
)trtdoc";
} // namespace IRaggedSoftMaxLayerDoc

namespace IIdentityLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A layer that represents the identity function.

    If tensor precision is explicitly specified, it can be used to transform from one precision to another.

    Other than conversions between the same type (``float32`` -> ``float32`` for example), the only valid conversions are:

    (``float32`` | ``float16`` | ``int32`` | ``bool``) -> (``float32`` | ``float16`` | ``int32`` | ``bool``)

    (``float32`` | ``float16``) -> ``uint8``

    ``uint8`` -> (``float32`` | ``float16``)
)trtdoc";
} // namespace IIdentityLayerDoc

namespace ICastLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A layer that represents the cast function.

    This layer casts the element of a given input tensor to a specified data type and returns an output tensor of the same shape in the converted type.

    Conversions between all types except FP8 is supported.

    :ivar to_type: :class:`DataType` The specified data type of the output tensor.
)trtdoc";
} // namespace ICastLayerDoc

namespace IConstantLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A constant layer in an :class:`INetworkDefinition` .

    Note: This layer does not support boolean and uint8 types.

    :ivar weights: :class:`Weights` The weights for the layer.
    :ivar shape: :class:`Dims` The shape of the layer.
)trtdoc";
} // namespace IConstantLayerDoc

namespace IParametricReLULayerDoc
{
constexpr const char* descr = R"trtdoc(
    A parametric ReLU layer in an :class:`INetworkDefinition` .

    This layer applies a parametric ReLU activation to an input tensor (first input), with slopes taken from a
    slopes tensor (second input). This can be viewed as a leaky ReLU operation where the negative slope differs
    from element to element (and can in fact be learned).

    The slopes tensor must be unidirectional broadcastable to the input tensor: the rank of the two tensors must
    be the same, and all dimensions of the slopes tensor must either equal the input tensor or be 1.
    The output tensor has the same shape as the input tensor.
)trtdoc";
} // namespace IParametricReLULayerDoc

namespace InterpolationModeDoc
{
constexpr const char* descr = R"trtdoc(Various modes of interpolation, used in resize and grid_sample layers.)trtdoc";

constexpr const char* NEAREST = R"trtdoc(1D, 2D, and 3D nearest neighbor interpolation.)trtdoc";
constexpr const char* LINEAR = R"trtdoc(Supports linear, bilinear, trilinear interpolation.)trtdoc";
constexpr const char* CUBIC = R"trtdoc(Supports bicubic interpolation.)trtdoc";
} // namespace InterpolationModeDoc

namespace ResizeCoordinateTransformationDoc
{
constexpr const char* descr
    = R"trtdoc(Various modes of how to map the resized coordinate back to the original coordinate.)trtdoc";

constexpr const char* ALIGN_CORNERS
    = R"trtdoc(In this mode, map the resized coordinate back to the original coordinate by the formula: x_original = x_resized * (length_original - 1) / (length_resized - 1).)trtdoc";
constexpr const char* ASYMMETRIC
    = R"trtdoc(In this mode, map the resized coordinate back to the original coordinate by the formula: x_original = x_resized * (length_original / length_resized).)trtdoc";
constexpr const char* HALF_PIXEL
    = R"trtdoc(In this mode, map the resized coordinate back to the original coordinate by the formula: x_original = (x_resized + 0.5) * (length_original / length_resized) - 0.5.)trtdoc";
} // namespace ResizeCoordinateTransformationDoc

namespace ResizeSelectorDoc
{
constexpr const char* descr
    = R"trtdoc(Decides whether the original coordinate is 0 given a resize coordinate less than 2.)trtdoc";

constexpr const char* FORMULA = R"trtdoc(Use the transformation formula to calculate the original coordinate.)trtdoc";
constexpr const char* UPPER
    = R"trtdoc(Return the original coordinate index as 0 given a resize coordinate is less than 2.)trtdoc";
} // namespace ResizeSelectorDoc

namespace ResizeRoundModeDoc
{
constexpr const char* descr = R"trtdoc(Rounding modes available for the resize layer.)trtdoc";

constexpr const char* HALF_UP
    = R"trtdoc(Round original floating-point coordinate to the nearest integer value, with halfway cases rounded up.)trtdoc";
constexpr const char* HALF_DOWN
    = R"trtdoc(Round original floating-point coordinate to the nearest integer value, with halfway cases rounded down.)trtdoc";
constexpr const char* FLOOR
    = R"trtdoc(Round original floating-point coordinate to the nearest integer value less than it.)trtdoc";
constexpr const char* CEIL
    = R"trtdoc(Round original floating-point coordinate to the nearest integer value larger than it.)trtdoc";
} // namespace ResizeRoundModeDoc

namespace IResizeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A resize layer in an :class:`INetworkDefinition` .

    Resize layer can be used for resizing a N-D tensor.

    Resize layer currently supports the following configurations:

    * InterpolationMode.NEAREST - resizes innermost `m` dimensions of N-D, where 0 < m <= min(3, N) and N > 0.
    * InterpolationMode.LINEAR - resizes innermost `m` dimensions of N-D, where 0 < m <= min(3, N) and N > 0.
    * InterpolationMode.CUBIC - resizes innermost `2` dimensions of N-D, N >= 2.

    Default resize mode is InterpolationMode.NEAREST.

    Resize layer provides two ways to resize tensor dimensions:

    * Set output dimensions directly. It can be done for static as well as dynamic resize layer.
        Static resize layer requires output dimensions to be known at build-time.
        Dynamic resize layer requires output dimensions to be set as one of the input tensors.

    * Set scales for resize. Each output dimension is calculated as floor(input dimension * scale).
        Only static resize layer allows setting scales where the scales are known at build-time.

    If executing this layer on DLA, the following combinations of parameters are supported:

    - In NEAREST mode:

       * (ResizeCoordinateTransformation.ASYMMETRIC, ResizeSelector.FORMULA, ResizeRoundMode.FLOOR)
       * (ResizeCoordinateTransformation.HALF_PIXEL, ResizeSelector.FORMULA, ResizeRoundMode.HALF_DOWN)
       * (ResizeCoordinateTransformation.HALF_PIXEL, ResizeSelector.FORMULA, ResizeRoundMode.HALF_UP)

    - In LINEAR and CUBIC mode:

       * (ResizeCoordinateTransformation.HALF_PIXEL, ResizeSelector.FORMULA)
       * (ResizeCoordinateTransformation.HALF_PIXEL, ResizeSelector.UPPER)


    :ivar shape: :class:`Dims` The output dimensions. Must to equal to input dimensions size.
    :ivar scales: :class:`List[float]` List of resize scales.
        If executing this layer on DLA, there are three restrictions:
        1. ``len(scales)`` has to be exactly 4.
        2. The first two elements in scales need to be exactly 1 (for unchanged batch and channel dimensions).
        3. The last two elements in scales, representing the scale values along height and width dimensions,
        respectively, need to be integer values in the range of [1, 32] for NEAREST mode and [1, 4] for LINEAR.
        Example of DLA-supported scales: [1, 1, 2, 2].
    :ivar resize_mode: :class:`InterpolationMode` Resize mode can be Linear, Cubic or Nearest.
    :ivar coordinate_transformation: :class:`ResizeCoordinateTransformationDoc` Supported resize coordinate transformation modes are ALIGN_CORNERS, ASYMMETRIC and HALF_PIXEL.
    :ivar selector_for_single_pixel: :class:`ResizeSelector` Supported resize selector modes are FORMULA and UPPER.
    :ivar nearest_rounding: :class:`ResizeRoundMode` Supported resize Round modes are HALF_UP, HALF_DOWN, FLOOR and CEIL.
    :ivar exclude_outside: :class:`int` If set to 1, the weight of sampling locations outside the input tensor will be set to 0, and the weight will be renormalized so that their sum is 1.0.
    :ivar cubic_coeff: :class:`float` coefficient 'a' used in cubic interpolation.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index.

    If index == 1 and num_inputs == 1, num_inputs changes to 2.
    Once such additional input is set, resize layer works in dynamic mode.
    When index == 1 and num_inputs == 1, the output dimensions are used from
    the input tensor, overriding the dimensions supplied by `shape`.

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";
} // namespace IResizeLayerDoc

namespace LoopOutputDoc
{
constexpr const char* descr = R"trtdoc(Describes kinds of loop outputs.)trtdoc";

constexpr const char* LAST_VALUE = R"trtdoc(Output value is value of tensor for last iteration.)trtdoc";
constexpr const char* CONCATENATE
    = R"trtdoc(Output value is concatenation of values of tensor for each iteration, in forward order.)trtdoc";
constexpr const char* REVERSE
    = R"trtdoc(Output value is concatenation of values of tensor for each iteration, in reverse order.)trtdoc";
} // namespace LoopOutputDoc

namespace TripLimitDoc
{
constexpr const char* descr = R"trtdoc(Describes kinds of trip limits.)trtdoc";

constexpr const char* COUNT = R"trtdoc(Tensor is a scalar of type :class:`int32` that contains the trip count.)trtdoc";
constexpr const char* WHILE
    = R"trtdoc(Tensor is a scalar of type :class:`bool`. Loop terminates when its value is false.)trtdoc";

} // namespace TripLimitDoc

namespace ILoopBoundaryLayerDoc
{
constexpr const char* descr = R"trtdoc(
    :ivar loop: :class:`ILoop` associated with this boundary layer.
)trtdoc";

} // namespace ILoopBoundaryLayerDoc

namespace IRecurrenceLayerDoc
{
constexpr const char* descr = R"trtdoc()trtdoc";
constexpr const char* set_input = R"trtdoc(
    Set the first or second input.
    If index==1 and the number of inputs is one, the input is appended.
    The first input specifies the initial output value, and must come from outside the loop.
    The second input specifies the next output value, and must come from inside the loop.
    The two inputs must have the same dimensions.

    :param index: The index of the input to set.
    :param tensor: The input tensor.
)trtdoc";
} // namespace IRecurrenceLayerDoc

namespace ILoopOutputLayerDoc
{
constexpr const char* descr = R"trtdoc(
    An :class:`ILoopOutputLayer` is the sole way to get output from a loop.

    The first input tensor must be defined inside the loop; the output tensor is outside the loop.
    The second input tensor, if present, must be defined outside the loop.

    If :attr:`kind` is ``LAST_VALUE``, a single input must be provided.

    If :attr:`kind` is ``CONCATENATE`` or ``REVERSE``, a second input must be provided.
    The second input must be a scalar “shape tensor”, defined before the loop commences,
    that specifies the concatenation length of the output.

    The output tensor has j more dimensions than the input tensor, where
    j == 0 if :attr:`kind` is ``LAST_VALUE``
    j == 1 if :attr:`kind` is ``CONCATENATE`` or ``REVERSE``.

    :ivar axis: The contenation axis. Ignored if :attr:`kind` is ``LAST_VALUE``.
        For example, if the input tensor has dimensions [b,c,d],
        and :attr:`kind` is  ``CONCATENATE``, the output has four dimensions.
        Let a be the value of the second input.
        axis=0 causes the output to have dimensions [a,b,c,d].
        axis=1 causes the output to have dimensions [b,a,c,d].
        axis=2 causes the output to have dimensions [b,c,a,d].
        axis=3 causes the output to have dimensions [b,c,d,a].
        Default is axis is 0.
    :ivar kind: The kind of loop output. See :class:`LoopOutput`
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Like :func:`ILayer.set_input`, but additionally works if index==1, :attr:`num_inputs`==1, in which case :attr:`num_inputs` changes to 2.
)trtdoc";

} // namespace ILoopOutputLayerDoc

namespace ITripLimitLayerDoc
{
constexpr const char* descr = R"trtdoc(
    :ivar kind: The kind of trip limit. See :class:`TripLimit`
)trtdoc";
} // namespace ITripLimitLayerDoc

namespace IIteratorLayerDoc
{
constexpr const char* descr = R"trtdoc(
    :ivar axis: The axis to iterate over
    :ivar reverse: For reverse=false, the layer is equivalent to add_gather(tensor, I, 0) where I is a
        scalar tensor containing the loop iteration number.
        For reverse=true, the layer is equivalent to add_gather(tensor, M-1-I, 0) where M is the trip count
        computed from TripLimits of kind ``COUNT``.
        The default is reverse=false.
)trtdoc";
} // namespace IIteratorLayerDoc

namespace ILoopDoc
{
constexpr const char* descr = R"trtdoc(
    Helper for creating a recurrent subgraph.

    :ivar name: The name of the loop. The name is used in error diagnostics.
)trtdoc";

constexpr const char* add_recurrence = R"trtdoc(
    Create a recurrence layer for this loop with initial_value as its first input.

    :param initial_value: The initial value of the recurrence layer.

    :returns: The added :class:`IRecurrenceLayer` , or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_trip_limit = R"trtdoc(
    Add a trip-count limiter, based on the given tensor.

    There may be at most one ``COUNT`` and one ``WHILE`` limiter for a loop.
    When both trip limits exist, the loop exits when the
    count is reached or condition is falsified.
    It is an error to not add at least one trip limiter.

    For ``WHILE``, the input tensor must be the output of a subgraph that contains
    only layers that are not :class:`ITripLimitLayer` , :class:`IIteratorLayer` or :class:`ILoopOutputLayer` .
    Any :class:`IRecurrenceLayer` s in the subgraph must belong to the same loop as the
    :class:`ITripLimitLayer` . A trivial example of this rule is that the input to the ``WHILE``
    is the output of an :class:`IRecurrenceLayer` for the same loop.


    :param tensor: The input tensor. Must be available before the loop starts.
    :param kind: The kind of trip limit. See :class:`TripLimit`

    :returns: The added :class:`ITripLimitLayer` , or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_iterator = R"trtdoc(
    Return layer that subscripts tensor by loop iteration.

    For reverse=false, this is equivalent to add_gather(tensor, I, 0) where I is a
    scalar tensor containing the loop iteration number.
    For reverse=true, this is equivalent to add_gather(tensor, M-1-I, 0) where M is the trip count
    computed from TripLimits of kind ``COUNT``.

    :param tensor: The tensor to iterate over.
    :param axis: The axis along which to iterate.
    :param reverse: Whether to iterate in the reverse direction.

    :returns: The :class:`IIteratorLayer` , or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_loop_output = R"trtdoc(
    Make an output for this loop, based on the given tensor.

    If ``kind`` is ``CONCATENATE`` or ``REVERSE``, a second input specifying the
    concatenation dimension must be added via method :func:`ILoopOutputLayer.set_input` .

    :param kind: The kind of loop output. See :class:`LoopOutput`
    :param axis: The axis for concatenation (if using ``kind`` of ``CONCATENATE`` or ``REVERSE``).

    :returns: The added :class:`ILoopOutputLayer` , or :class:`None` if it could not be created.
)trtdoc";

} // namespace ILoopDoc

namespace IOneHotLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A OneHot layer in a network definition.

    The OneHot layer has three input tensors: Indices, Values, and Depth, one output tensor,
    Output, and an axis attribute.
    :ivar indices: is an Int32 tensor that determines which locations in Output to set as on_value.
    :ivar values: is a two-element (rank=1) tensor that consists of [off_value, on_value]
    :ivar depth: is an Int32 shape tensor of rank 0, which contains the depth (number of classes) of the one-hot encoding.
    The depth tensor must be a build-time constant, and its value should be positive.
    :returns: a tensor with rank = rank(indices)+1, where the added dimension contains the one-hot encoding.
    :param axis: specifies to which dimension of the output one-hot encoding is added.

    The data types of Output shall be equal to the Values data type.
    The output is computed by copying off_values to all output elements, then setting on_value on the indices
    specified by the indices tensor.

    when axis = 0:
    output[indices[i, j, k], i, j, k] = on_value for all i, j, k and off_value otherwise.

    when axis = -1:
    output[i, j, k, indices[i, j, k]] = on_value for all i, j, k and off_value otherwise.

)trtdoc";
} // namespace IOneHotLayerDoc

namespace ISelectLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A select layer in an :class:`INetworkDefinition` .

    This layer implements an element-wise ternary conditional operation. Wherever ``condition`` is ``True``, elements are taken from the first input, and wherever ``condition`` is ``False``, elements are taken from the second input.
)trtdoc";
} // namespace ISelectLayerDoc

namespace IAssertionLayerDoc
{
constexpr const char* descr = R"trtdoc(
    An assertion layer in an :class:`INetworkDefinition` .

    This layer implements assertions. The input must be a boolean shape tensor. If any element of it is ``False``, a build-time or run-time error occurs. Asserting equality of input dimensions may help the optimizer.

    :ivar message: :class:`string` Message to print if the assertion fails.
)trtdoc";
} // namespace IAssertionLayerDoc

namespace IGridSampleLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A grid sample layer in an :class:`INetworkDefinition` .

    This layer uses an input tensor and a grid tensor to produce an interpolated output tensor.
    The input and grid tensors must shape tensors of rank 4. The only supported `SampleMode` s are
    trt.samplemode.CLAMP, trt.samplemode.FILL, and trt.samplemode.REFLECT.

    :ivar interpolation_mode: class:`InterpolationMode` The interpolation type to use. Defaults to LINEAR.
    :ivar align_corners: class:`bool` the align mode to use. Defaults to False.
    :ivar sample_mode: :class:`SampleMode` The sample mode to use. Defaults to FILL.
)trtdoc";
} // namespace IGridSampleLayerDoc

namespace BoundingBoxFormatDoc
{
constexpr const char* descr = R"trtdoc(
    Enumerates bounding box data formats used for the Boxes input tensor in the NMS layer.
)trtdoc";

constexpr const char* CORNER_PAIRS
    = R"trtdoc((x1, y1, x2, y2) where (x1, y1) and (x2, y2) are any pair of diagonal corners)trtdoc";
constexpr const char* CENTER_SIZES
    = R"trtdoc((x_center, y_center, width, height) where (x_center, y_center) is the center point of the box)trtdoc";

} // namespace BoundingBoxFormatDoc

namespace INMSLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A non-maximum suppression layer in an :class:`INetworkDefinition` .

    Boxes: The input boxes tensor to the layer.
    This tensor contains the input bounding boxes. It is a linear tensor of type ``float32`` or ``float16``.
    It has shape [batchSize, numInputBoundingBoxes, numClasses, 4] if the boxes are per class, or
    [batchSize, numInputBoundingBoxes, 4] if the same boxes are to be used for each class.

    Scores: The input scores tensor to the layer.
    This tensor contains the per-box scores. It is a linear tensor of the same type as the boxes tensor.
    It has shape [batchSize, numInputBoundingBoxes, numClasses].

    MaxOutputBoxesPerClass: The input maxOutputBoxesPerClass tensor to the layer.
    This tensor contains the maximum number of output boxes per batch item per class.
    It is a scalar (0D tensor) of type ``int32``.

    IoUThreshold is the maximum IoU for selected boxes.
    It is a scalar (0D tensor) of type ``float32`` in the range [0.0, 1.0].
    It is an optional input with default 0.0.
    Use :func:`set_input` to add this optional tensor.

    ScoreThreshold is the value that a box score must exceed in order to be selected.
    It is a scalar (0D tensor) of type ``float32``. It is an optional input with default 0.0.
    Use :func:`set_input` to add this optional tensor.

    The SelectedIndices output tensor contains the indices of the selected boxes.
    It is a linear tensor of type ``int32``. It has shape [NumOutputBoxes, 3].]
    Each row contains a (batchIndex, classIndex, boxIndex) tuple.
    The output boxes are sorted in order of increasing batchIndex and then in order of decreasing score within each batchIndex.
    For each batchIndex, the ordering of output boxes with the same score is unspecified.
    If MaxOutputBoxesPerClass is a constant input, the maximum number of output boxes is
    batchSize * numClasses * min(numInputBoundingBoxes, MaxOutputBoxesPerClass).
    Otherwise, the maximum number of output boxes is batchSize * numClasses * numInputBoundingBoxes.
    The maximum number of output boxes is used to determine the upper-bound on allocated memory for this output tensor.

    The NumOutputBoxes output tensor contains the number of output boxes in selectedIndices.
    It is a scalar (0D tensor) of type ``int32``.

    The NMS algorithm iterates through a set of bounding boxes and their confidence scores,
    in decreasing order of score. Boxes are selected if their score is above a given threshold,
    and their intersection-over-union (IoU) with previously selected boxes is less than or equal
    to a given threshold.
    This layer implements NMS per batch item and per class.

    For each batch item, the ordering of candidate bounding boxes with the same score is unspecified.

    :ivar bounding_box_format: :class:`BoundingBoxFormat` The bounding box format used by the layer. Default is CORNER_PAIRS.
    :ivar topk_box_limit: :class:`int` The maximum number of filtered boxes considered for selection. Default is 2000 for SM 5.3 and 6.2 devices, and 5000 otherwise. The TopK box limit must be less than or equal to {2000 for SM 5.3 and 6.2 devices, 5000 otherwise}.
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index.
    The indices are as follows:

    ======= ========================================================================
     Index   Description
    ======= ========================================================================
        0     The required Boxes tensor.
        1     The required Scores tensor.
        2     The required MaxOutputBoxesPerClass tensor.
        3     The optional IoUThreshold tensor.
        4     The optional ScoreThreshold tensor.
    ======= ========================================================================

    If this function is called for an index greater or equal to :attr:`num_inputs`,
    then afterwards :attr:`num_inputs` returns index + 1, and any missing intervening
    inputs are set to null. Note that only optional inputs can be missing.

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace INMSLayerDoc

namespace FillOperationDoc
{
constexpr const char* descr = R"trtdoc(The tensor fill operations that may performed by an Fill layer.)trtdoc";

constexpr const char* LINSPACE = R"trtdoc(Generate evenly spaced numbers over a specified interval)trtdoc";
constexpr const char* RANDOM_UNIFORM
    = R"trtdoc(Generate a tensor with random values drawn from a uniform distribution)trtdoc";
constexpr const char* RANDOM_NORMAL
    = R"trtdoc(Generate a tensor with random values drawn from a normal distribution)trtdoc";
} // namespace FillOperationDoc

namespace IFillLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A fill layer in an :class:`INetworkDefinition` .

    The data type of the output tensor can be specified by :attr:`to_type`. Supported output types for each fill operation is as follows.

    ================   =====================
    Operation          to_type
    ================   =====================
    kLINSPACE          int32, int64, float32
    kRANDOM_UNIFORM    float16, float32
    kRANDOM_NORMAL     float16, float32
    ================   =====================

    :ivar to_type: :class:`DataType` The specified data type of the output tensor. Defaults to tensorrt.float32.
)trtdoc";

constexpr const char* set_dimensions = R"trtdoc(
    set the output tensor's dimensions.

    :arg dims: the output tensor's dimensions.
)trtdoc";

constexpr const char* get_dimensions = R"trtdoc(
    get the output tensor's dimensions.
)trtdoc";

constexpr const char* set_operation = R"trtdoc(
    set the fill operation for the layer.

    :arg operation: the fill operation for the layer.
)trtdoc";

constexpr const char* get_operation = R"trtdoc(
    get the fill operation for the layer.
)trtdoc";

constexpr const char* set_to_type = R"trtdoc(
    set the output data type for the layer.
    only applied if alpha and beta are static.

    :arg to_type: the output data type for the layer.
)trtdoc";

constexpr const char* get_to_type = R"trtdoc(
    get the user specified output data type for the layer.
)trtdoc";

constexpr const char* set_alpha = R"trtdoc(
    set the alpha parameter (must be finite).

    ==============   ==================
    Operation        Usage
    ==============   ==================
    kLINSPACE         the start value;
    kRANDOM_UNIFORM   the minimum value;
    kRANDOM_NORMAL    the mean of the normal distribution;
    ==============   ==================

    :arg alpha: has different meanings for each operators.
)trtdoc";

constexpr const char* get_alpha = R"trtdoc(
    get the alpha parameter.
    see :meth:`IFillLayer.set_alpha()` for details
)trtdoc";

constexpr const char* set_beta = R"trtdoc(
    set the beta parameter (must be finite).

    ===============  ==================
    Operation        Usage
    ===============  ===================
    kLINSPACE        the delta value;
    kRANDOM_UNIFORM   the maximal value;
    kRANDOM_NORMAL    the standard deviation of the normal distribution;
    ===============  ===================

    :arg beta: has different meanings for each operators.
)trtdoc";

constexpr const char* get_beta = R"trtdoc(
    get the beta parameter.
    see :meth:`IFillLayer.set_beta()` for details
)trtdoc";

constexpr const char* set_input = R"trtdoc(
    replace an input of this layer with a specific tensor.

    =====   ==========================================================================================================
    Index   Description for kLINSPACE
    =====   ==========================================================================================================
        0     Shape tensor, represents the output tensor's dimensions.
        1     Start, a scalar, represents the start value.
        2     Delta, a 1D tensor, length equals to shape tensor's nbDims, represents the delta value for each dimension.
    =====   ==========================================================================================================

    =====   ========================================================
    Index   Description for kRANDOM_UNIFORM
    =====   ========================================================
        0     Shape tensor, represents the output tensor's dimensions.
        1     Minimum, a scalar, represents the minimum random value.
        2     Maximum, a scalar, represents the maximal random value.
    =====   ========================================================

    =====   ========================================================
    Index   Description for kRANDOM_NORMAL
    =====   ========================================================
        0     Shape tensor, represents the output tensor's dimensions.
        1     Mean, a scalar, represents the mean of the normal distribution.
        2     Scale, a scalar, represents the standard deviation of the normal distribution.
    =====   ========================================================

    :arg index: the index of the input to modify.
    :arg tensor: the input tensor.
)trtdoc";
} // namespace IFillLayerDoc

namespace IQuantizeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Quantize layer in an :class:`INetworkDefinition` .

    This layer accepts a floating-point data input tensor, and uses the scale and zeroPt inputs to

    quantize the data to an 8-bit signed integer according to:

    :math:`output = clamp(round(input / scale) + zeroPt)`

    Rounding type is rounding-to-nearest ties-to-even (https://en.wikipedia.org/wiki/Rounding#Round_half_to_even).

    Clamping is in the range [-128, 127].

    The first input (index 0) is the tensor to be quantized.
    The second (index 1) and third (index 2) are the scale and zero point respectively.
    Each of scale and zeroPt must be either a scalar, or a 1D tensor.

    The zeroPt tensor is optional, and if not set, will be assumed to be zero.  Its data type must be
    tensorrt.int8. zeroPt must only contain zero-valued coefficients, because only symmetric quantization is
    supported.
    The scale value must be either a scalar for per-tensor quantization, or a 1D tensor for per-axis
    quantization. The size of the 1-D scale tensor must match the size of the quantization axis. The size of the
    scale must match the size of the zeroPt.

    The subgraph which terminates with the scale tensor must be a build-time constant.  The same restrictions apply
    to the zeroPt.
    The output type, if constrained, must be constrained to tensorrt.int8 or tensorrt.fp8. The input type, if constrained, must be
    constrained to tensorrt.float32, tensorrt.float16 or tensorrt.bfloat16.
    The output size is the same as the input size.

    IQuantizeLayer supports tensorrt.float32, tensorrt.float16 and tensorrt.bfloat16 precision and will default to tensorrt.float32 precision during instantiation.
    IQuantizeLayer supports tensorrt.int8, tensorrt.float8, tensorrt.int4 and tensorrt.fp4 output.

    :ivar axis: :class:`int` The axis along which quantization occurs. The quantization axis is in reference to the input tensor's dimensions.

    :ivar to_type: :class:`DataType` The specified data type of the output tensor. Must be tensorrt.int8 or tensorrt.float8.
)trtdoc";
} // namespace IQuantizeLayerDoc

namespace IDequantizeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Dequantize layer in an :class:`INetworkDefinition` .

    This layer accepts a signed 8-bit integer input tensor, and uses the configured scale and zeroPt inputs to
    dequantize the input according to:
    :math:`output = (input - zeroPt) * scale`

    The first input (index 0) is the tensor to be quantized.
    The second (index 1) and third (index 2) are the scale and zero point respectively.
    Each of scale and zeroPt must be either a scalar, or a 1D tensor.

    The zeroPt tensor is optional, and if not set, will be assumed to be zero.  Its data type must be
    tensorrt.int8. zeroPt must only contain zero-valued coefficients, because only symmetric quantization is
    supported.
    The scale value must be either a scalar for per-tensor quantization, or a 1D tensor for per-axis
    quantization. The size of the 1-D scale tensor must match the size of the quantization axis. The size of the
    scale must match the size of the zeroPt.

    The subgraph which terminates with the scale tensor must be a build-time constant.  The same restrictions apply
    to the zeroPt.
    The output type, if constrained, must be constrained to tensorrt.int8 or tensorrt.fp8. The input type, if constrained, must be
    constrained to tensorrt.float32, tensorrt.float16 or tensorrt.bfloat16.
    The output size is the same as the input size.

    IDequantizeLayer supports tensorrt.int8, tensorrt.float8, tensorrt.int4 and tensorrt.fp4 precision and will default to tensorrt.int8 precision during instantiation.
    IDequantizeLayer supports tensorrt.float32, tensorrt.float16 and tensorrt.bfloat16 output.

    :ivar axis: :class:`int` The axis along which dequantization occurs. The dequantization axis is in reference to the input tensor's dimensions.

    :ivar to_type: :class:`DataType` The specified data type of the output tensor. Must be tensorrt.float32 or tensorrt.float16.
)trtdoc";
} // namespace IDequantizeLayerDoc

namespace IDynamicQuantizeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A DynamicQuantize layer in an :class:`INetworkDefinition` .

    This layer performs dynamic block quantization of its input tensor and outputs the quantized data and the computed block scale-factors.
    The size of the blocked axis must be divisible by the block size.

    The first input (index 0) is the tensor to be quantized. Its data type must be one of DataType::kFLOAT,
    DataType::kHALF, or DataType::kBF16. Currently only 2D and 3D inputs are supported.

    The second input (index 1) is the double quantization scale factor. It is a scalar scale factor used to quantize the computed block scales-factors.

    :ivar axis: :class:`int` The axis that is sliced into blocks. The axis must be the last dimension or the second to last dimension.
    :ivar block_size: :class:`int` The number of elements that are quantized using a shared scale factor. Supports block sizes of 16 with NVFP4 quantization and 32 with MXFP8 quantization.
    :ivar output_type: :class:`DataType` The data type of the quantized output tensor, must be either DataType::kFP4 (NVFP4 quantization) or DataType::kFP8 (MXFP8 quantization).
    :ivar scale_type: :class:`DataType` The data type of the scale factor used for quantizing the input data, must be DataType::kFP8 (NVFP4 quantization) or DataType::kE8M0 (MXFP8 quantization).
)trtdoc";
} // namespace IDynamicQuantizeLayerDoc

namespace ISplitToRaggedLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A SplitToRagged layer in an :class:`INetworkDefinition` .

    Split a tensor into a ragged tensor along the specified 'axis'.

    :ivar axis: :class:`int`

)trtdoc";
} // namespace ISplitToRaggedLayerDoc

namespace IConcatFromRaggedLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A ConcatFromRagged layer in an :class:`INetworkDefinition` .

    Concatenate a ragged tensor to a regular tensor.

    :ivar axis: :class:`int`
)trtdoc";
} // namespace IConcatFromRaggedLayerDoc

namespace IIfConditionalBoundaryLayerDoc
{
constexpr const char* descr = R"trtdoc(
    :ivar conditional: :class:`IIfConditional` associated with this boundary layer.
)trtdoc";
} // namespace IIfConditionalBoundaryLayerDoc

namespace IConditionLayerDoc
{
constexpr const char* descr = R"trtdoc(Describes the boolean condition of an if-conditional.)trtdoc";
} // namespace IConditionLayerDoc

namespace IIfConditionalInputLayerDoc
{
constexpr const char* descr = R"trtdoc(Describes kinds of if-conditional inputs.)trtdoc";
} // namespace IIfConditionalInputLayerDoc

namespace IIfConditionalOutputLayerDoc
{
constexpr const char* descr = R"trtdoc(Describes kinds of if-conditional outputs.)trtdoc";
} // namespace IIfConditionalOutputLayerDoc

namespace IIfConditionalDoc
{
constexpr const char* descr = R"trtdoc(
    Helper for constructing conditionally-executed subgraphs.

    An If-conditional conditionally executes (lazy evaluation) part of the network according
    to the following pseudo-code:

    .. code-block:: none

        If condition is true Then:
            output = trueSubgraph(trueInputs);
        Else:
            output = falseSubgraph(falseInputs);
        Emit output

    Condition is a 0D boolean tensor (representing a scalar).
    trueSubgraph represents a network subgraph that is executed when condition is evaluated to True.
    falseSubgraph represents a network subgraph that is executed when condition is evaluated to False.

    The following constraints apply to If-conditionals:
    - Both the trueSubgraph and falseSubgraph must be defined.
    - The number of output tensors in both subgraphs is the same.
    - The type and shape of each output tensor from the true/false subgraphs are the same, except that the shapes are allowed to differ if the condition is a build-time constant.

)trtdoc";

constexpr const char* set_condition = R"trtdoc(
    Set the condition tensor for this If-Conditional construct.

    The ``condition`` tensor must be a 0D data tensor (scalar) with type :class:`bool`.

    :param condition: The condition tensor that will determine which subgraph to execute.

    :returns: The :class:`IConditionLayer` , or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_output = R"trtdoc(
    Make an output for this if-conditional, based on the given tensors.

    Each output layer of the if-conditional represents a single output of either the true-subgraph or the
    false-subgraph of the if-conditional, depending on which subgraph was executed.

    :param true_subgraph_output: The output of the subgraph executed when this conditional's condition input evaluates to true.
    :param false_subgraph_output: The output of the subgraph executed when this conditional's condition input evaluates to false.

    :returns: The :class:`IIfConditionalOutputLayer` , or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_input = R"trtdoc(
    Make an input for this if-conditional, based on the given tensor.

    :param input: An input to the conditional that can be used by either or both of the conditional’s subgraphs.
)trtdoc";

} // namespace IIfConditionalDoc

namespace IEinsumLayerDoc
{
constexpr const char* descr = R"trtdoc(
    An Einsum layer in an :class:`INetworkDefinition` .

    This layer implements a summation over the elements of the inputs along dimensions specified by the equation parameter, based on the Einstein summation convention.
    The layer can have one or more inputs of rank >= 0. All the inputs must be of same data type. This layer supports all TensorRT data types except :class:`bool`.
    There is one output tensor of the same type as the input tensors. The shape of output tensor is determined by the equation.

    The equation specifies ASCII lower-case letters for each dimension in the inputs in the same order as the dimensions, separated by comma for each input.
    The dimensions labeled with the same subscript must match or be broadcastable.
    Repeated subscript labels in one input take the diagonal.
    Repeating a label across multiple inputs means that those axes will be multiplied.
    Omitting a label from the output means values along those axes will be summed.
    In implicit mode, the indices which appear once in the expression will be part of the output in increasing alphabetical order.
    In explicit mode, the output can be controlled by specifying output subscript labels by adding an arrow (‘->’) followed by subscripts for the output.
    For example, “ij,jk->ik” is equivalent to “ij,jk”.
    Ellipsis (‘...’) can be used in place of subscripts to broadcast the dimensions.
    See the TensorRT Developer Guide for more details on equation syntax.

    Many common operations can be expressed using the Einsum equation.
    For example:
    Matrix Transpose:             ij->ji
    Sum:                          ij->
    Matrix-Matrix Multiplication: ik,kj->ij
    Dot Product:                  i,i->
    Matrix-Vector Multiplication: ik,k->i
    Batch Matrix Multiplication:  ijk,ikl->ijl
    Batch Diagonal:               ...ii->...i

    Note that TensorRT does not support ellipsis or diagonal operations.

    :ivar equation: :class:`str` The Einsum equation of the layer.
        The equation is a comma-separated list of subscript labels, where each label refers to a dimension of the corresponding tensor.

)trtdoc";
} // namespace IEinsumLayerDoc

namespace INonZeroLayerDoc
{
constexpr char const* descr = R"trtdoc(
    A NonZero layer in an :class:`INetworkDefinition` .

    Computes the indices of the input tensor where the value is non-zero. The returned indices are in row-major order.

    The output shape is always `{D, C}`, where `D` is the number of dimensions of the input and `C` is the number of non-zero values.
)trtdoc";
} // namespace INonZeroLayerDoc

namespace IReverseSequenceLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A ReverseSequence layer in an :class:`INetworkDefinition` .

    This layer performs batch-wise reversal, which slices the input tensor along the axis ``batch_axis``. For the
    ``i``-th slice, the operation reverses the first ``N`` elements, specified by the corresponding ``i``-th value
    in ``sequence_lens``, along ``sequence_axis`` and keeps the remaining elements unchanged. The output tensor will
    have the same shape as the input tensor.

    :ivar batch_axis: :class:`int` The batch axis. Default: 1.
    :ivar sequence_axis: :class:`int` The sequence axis. Default: 0.
)trtdoc";
} // namespace IReverseSequenceLayerDoc

namespace INormalizationLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Normalization layer in an :class:`INetworkDefinition` .

    The normalization layer performs the following operation:

    X - input Tensor
    Y - output Tensor
    S - scale Tensor
    B - bias Tensor

    Y = (X - Mean(X, axes)) / Sqrt(Variance(X) + epsilon) * S + B

    Where Mean(X, axes) is a reduction over a set of axes, and Variance(X) = Mean((X - Mean(X, axes)) ^ 2, axes).

    :ivar epsilon: :class:`float` The epsilon value used for the normalization calculation. Default: 1e-5F.
    :ivar axes: :class:`int` The reduction axes for the normalization calculation.
    :ivar num_groups: :class:`int` The number of groups to split the channels into for the normalization calculation. Default: 1.
    :ivar compute_precision: :class:`DataType` The datatype used for the compute precision of this layer. By default TensorRT will run the normalization computation in DataType.kFLOAT32 even in mixed precision mode regardless of any set builder flags to avoid overflow errors. ILayer.precision and ILayer.set_output_type can still be set to control input and output types of this layer. Only DataType.kFLOAT32 and DataType.kHALF are valid for this member. Default: Datatype.FLOAT.
)trtdoc";
} // namespace INormalizationLayerDoc

namespace ISqueezeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A Squeeze layer in an :class:`INetworkDefinition` .

    This layer represents a squeeze operation, removing unit dimensions of the input tensor on a set of axes.

    Axes must be resolvable to a constant Int32 or Int64 1D shape tensor.
    Values in axes must be unique and in the range of [-r, r-1], where r is the rank of the input tensor.
    For each axis value, the corresponding dimension in the input tensor must be one.

)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index. The index must be 0 or 1 for a Squeeze layer.

    The indices are as follows:

    =====   ==================================================================================
    Index   Description
    =====   ==================================================================================
        0     Input data tensor.
        1     The axes to remove. Must be resolvable to a constant Int32 or Int64 1D shape tensor.
    =====   ==================================================================================

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace ISqueezeLayerDoc

namespace IUnsqueezeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    An Unsqueeze layer in an :class:`INetworkDefinition` .

    This layer represents an unsqueeze operation, which reshapes the input tensor by inserting unit-length dimensions at specified axes of the output.

    Axes must be resolvable to a constant Int32 or Int64 shape tensor.
    Values in axes must be unique and in the range of [-r_final, r_final-1], where r_final is the sum of rank(input) and len(axes).

    r_final must be less than Dims.MAX_DIMS.

)trtdoc";

constexpr const char* set_input = R"trtdoc(
    Sets the input tensor for the given index. The index must be 0 or 1 for an Unsqueeze layer.

    The indices are as follows:

    =====   ==================================================================================
    Index   Description
    =====   ==================================================================================
        0     Input data tensor.
        1     The axes to add. Must be resolvable to a constant Int32 or Int64 1D shape tensor.
    =====   ==================================================================================

    :arg index: The index of the input tensor.
    :arg tensor: The input tensor.
)trtdoc";

} // namespace IUnsqueezeLayerDoc


namespace CumulativeOperationDoc
{
constexpr const char* descr = R"trtdoc(The cumulative operations that may be performed by a Cumulative layer)trtdoc";
constexpr const char* SUM = R"trtdoc()trtdoc";
} // namespace CumulativeOperationDoc

namespace ICumulativeLayerDoc
{
constexpr const char* descr = R"trtdoc(
    A cumulative layer in an :class:`INetworkDefinition` .

    This layer represents a cumulative operation across a tensor.

    It computes successive reductions across an axis of a tensor. The output
    always has the same shape as the input.

    If the reduction operation is summation, then this is also known as
    prefix-sum or cumulative sum.

    The operation has forward vs. reverse variants, and inclusive vs. exclusive variants.

    For example, let the input be a vector x of length n and the output be vector y.
    Then y[j] = sum(x[...]) where ... denotes a sequence of indices from this list:

    - inclusive + forward:   0..j
    - inclusive + reverse:   j..n-1
    - exclusive + forward:   0..j-1
    - exclusive + reverse: j+1..n-1

    For multidimensional tensors, the cumulative applies across a specified axis. For
    example, given a 2D input, a forward inclusive cumulative across axis 0 generates
    cumulative sums within each column.

    :ivar op: :class:`CumulativeOperation` The cumulative operation for the layer.
    :ivar exclusive: :class:`bool` Specifies whether it is an exclusive cumulative or inclusive cumulative.
    :ivar reverse: :class:`bool` Specifies whether the cumulative operation should be applied backward.

)trtdoc";
} // namespace ICumulativeLayerDoc

namespace INetworkDefinitionDoc
{
constexpr const char* descr = R"trtdoc(
    Represents a TensorRT Network from which the Builder can build an Engine

    :ivar num_layers: :class:`int` The number of layers in the network.
    :ivar num_inputs: :class:`int` The number of inputs of the network.
    :ivar num_outputs: :class:`int` The number of outputs of the network.
    :ivar name: :class:`str` The name of the network. This is used so that it can be associated with a built engine. The name must be at most 128 characters in length. TensorRT makes no use of this string except storing it as part of the engine so that it may be retrieved at runtime. A name unique to the builder will be generated by default.
    :ivar has_implicit_batch_dimension: :class:`bool` [DEPRECATED] Deprecated in TensorRT 10.0. Always flase since the implicit batch dimensions support has been removed.
    :ivar error_recorder: :class:`IErrorRecorder` Application-implemented error reporting interface for TensorRT objects.
    :flags: :int: A bitset of the ``NetworkDefinitionCreationFlag`` s set for this network.
)trtdoc";

constexpr const char* get_flag = R"trtdoc(
    Returns true if the specified ``NetworkDefinitionCreationFlag`` is set.

    :arg flag: The ``NetworkDefinitionCreationFlag`` .

    :returns: Whether the flag is set.
)trtdoc";

constexpr const char* add_input = R"trtdoc(
    Adds an input to the network.

    :arg name: The name of the tensor. Each input and output tensor must have a unique name.
    :arg dtype: The data type of the tensor.
    :arg shape: The dimensions of the tensor.

    :returns: The newly added Tensor.
)trtdoc";

constexpr const char* mark_output = R"trtdoc(
    Mark a tensor as an output.

    :arg tensor: The tensor to mark.
)trtdoc";

constexpr const char* mark_weights_refittable = R"trtdoc(
    Mark a weight as refittable.

    :arg name: The weight to mark.
)trtdoc";

constexpr const char* are_weights_marked_refittable = R"trtdoc(
    Whether the weight has been marked as refittable.

    :arg name: The name of the weights to check.
)trtdoc";

constexpr const char* mark_debug = R"trtdoc(
    Mark a tensor as a debug tensor in the network.

    :arg tensor: The tensor to be marked as debug tensor.

    :returns: True on success, False otherwise.
)trtdoc";

constexpr const char* unmark_weights_refittable = R"trtdoc(
    Unmark a weight as refittable.

    :arg name: The weight to unmark.
)trtdoc";

constexpr const char* unmark_debug = R"trtdoc(
    Unmark a tensor as a debug tensor in the network.

    :arg tensor: The tensor to be unmarked as debug tensor.

    :returns: True on success, False otherwise.
)trtdoc";

constexpr const char* is_debug_tensor = R"trtdoc(
    Check if a tensor is marked as debug.

    :arg tensor: The tensor to be checked.
)trtdoc";

constexpr const char* mark_unfused_tensors_as_debug_tensors = R"trtdoc(
    Mark unfused tensors as debug tensors.

    Debug tensors can be optionally emitted at runtime.
    Tensors that are fused by the optimizer will not be emitted.
    Tensors marked this way will not prevent fusion like mark_debug() does, thus preserving performance.

    Tensors marked this way cannot be detected by is_debug_tensor().
    DebugListener can only get internal tensor names instead of the original tensor names in the NetworkDefinition for tensors marked this way. 
    But the names correspond to the names obtained by IEngineInspector.
    There is no guarantee that all unfused tensors are marked.

    :returns: True if tensors were successfully marked (or were already marked), false otherwise.

)trtdoc";

constexpr const char* unmark_unfused_tensors_as_debug_tensors = R"trtdoc(
    Undo the marking of unfused tensor as debug tensors.

    This has no effect on tensors marked by mark_debug().

    :returns: True if tensor successfully unmarked (or was already unmarked), false otherwise.
)trtdoc";

constexpr const char* add_convolution_nd = R"trtdoc(
    Add a multi-dimension convolution layer to the network.
    See :class:`IConvolutionLayer` for more information.

    :arg input: The input tensor to the convolution.
    :arg num_output_maps: The number of output feature maps for the convolution.
    :arg kernel_shape: The dimensions of the convolution kernel.
    :arg kernel: The kernel weights for the convolution.
    :arg bias: The optional bias weights for the convolution.

    :returns: The new convolution layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_activation = R"trtdoc(
    Add an activation layer to the network.
    See :class:`IActivationLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg type: The type of activation function to apply.

    :returns: The new activation layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_pooling_nd = R"trtdoc(
    Add a multi-dimension pooling layer to the network.
    See :class:`IPoolingLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg type: The type of pooling to apply.
    :arg window_size: The size of the pooling window.

    :returns: The new pooling layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_lrn = R"trtdoc(
    Add a LRN layer to the network.
    See :class:`ILRNLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg window: The size of the window.
    :arg alpha: The alpha value for the LRN computation.
    :arg beta: The beta value for the LRN computation.
    :arg k: The k value for the LRN computation.

    :returns: The new LRN layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_scale = R"trtdoc(
    Add a scale layer to the network.
    See :class:`IScaleLayer` for more information.

    :arg input: The input tensor to the layer. This tensor is required to have a minimum of 3 dimensions.
    :arg mode: The scaling mode.
    :arg shift: The shift value.
    :arg scale: The scale value.
    :arg power: The power value.

    If the weights are available, then the size of weights are dependent on the ScaleMode.
    For UNIFORM, the number of weights is equal to 1.
    For CHANNEL, the number of weights is equal to the channel dimension.
    For ELEMENTWISE, the number of weights is equal to the volume of the input.

    :returns: The new scale layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_scale_nd = R"trtdoc(
    Add a multi-dimension scale layer to the network.
    See :class:`IScaleLayer` for more information.

    :arg input: The input tensor to the layer. This tensor is required to have a minimum of 3 dimensions.
    :arg mode: The scaling mode.
    :arg shift: The shift value.
    :arg scale: The scale value.
    :arg power: The power value.
    :arg channel_axis: The channel dimension axis.

    If the weights are available, then the size of weights are dependent on the ScaleMode.
    For UNIFORM, the number of weights is equal to 1.
    For CHANNEL, the number of weights is equal to the channel dimension.
    For ELEMENTWISE, the number of weights is equal to the volume of the input.

    :returns: The new scale layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_softmax = R"trtdoc(
    Add a softmax layer to the network.
    See :class:`ISoftMaxLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: The new softmax layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_concatenation = R"trtdoc(
    Add a concatenation layer to the network. Note that all tensors must have the same dimension except for the Channel dimension.
    See :class:`IConcatenationLayer` for more information.

    :arg inputs: The input tensors to the layer.

    :returns: The new concatenation layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_deconvolution_nd = R"trtdoc(
    Add a multi-dimension deconvolution layer to the network.
    See :class:`IDeconvolutionLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg num_output_maps: The number of output feature maps.
    :arg kernel_shape: The dimensions of the convolution kernel.
    :arg kernel: The kernel weights for the convolution.
    :arg bias: The optional bias weights for the convolution.

    :returns: The new deconvolution layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_elementwise = R"trtdoc(
    Add an elementwise layer to the network.
    See :class:`IElementWiseLayer` for more information.

    :arg input1: The first input tensor to the layer.
    :arg input2: The second input tensor to the layer.
    :arg op: The binary operation that the layer applies.

    The input tensors must have the same number of dimensions.
    For each dimension, their lengths must match, or one of them must be one.
    In the latter case, the tensor is broadcast along that axis.

    The output tensor has the same number of dimensions as the inputs.
    For each dimension, its length is the maximum of the lengths of the
    corresponding input dimension.

    :returns: The new element-wise layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_unary = R"trtdoc(
    Add a unary layer to the network.
    See :class:`IUnaryLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg op: The operation to apply.

    :returns: The new unary layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_padding_nd = R"trtdoc(
    Add a multi-dimensional padding layer to the network.
    See :class:`IPaddingLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg pre_padding: The padding to apply to the start of the tensor.
    :arg post_padding: The padding to apply to the end of the tensor.

    :returns: The new padding layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_shuffle = R"trtdoc(
    Add a shuffle layer to the network.
    See :class:`IShuffleLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: The new shuffle layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_slice = R"trtdoc(
    Add a slice layer to the network.
    See :class:`ISliceLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg start: The start offset.
    :arg shape: The output shape.
    :arg stride: The slicing stride. Positive, negative, zero stride values, and combinations of them in different dimensions are allowed.

    :returns: The new slice layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_reduce = R"trtdoc(
    Add a reduce layer to the network.
    See :class:`IReduceLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg op: The reduction operation to perform.
    :arg axes: The reduction dimensions.
        The bit in position i of bitmask axes corresponds to explicit dimension i of the result.
        E.g., the least significant bit corresponds to the first explicit dimension and the next to least
        significant bit corresponds to the second explicit dimension.
    :arg keep_dims: The boolean that specifies whether or not to keep the reduced dimensions in the output of the layer.

    :returns: The new reduce layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_topk = R"trtdoc(
    Add a TopK layer to the network.
    See :class:`ITopKLayer` for more information.

    The TopK layer has two outputs of the same dimensions. The first contains data values, the second contains index positions for the values. Output values are sorted, largest first for operation :const:`TopKOperation.MAX` and smallest first for operation :const:`TopKOperation.MIN` .

    Currently only values of K up to 3840 are supported.

    :arg input: The input tensor to the layer.
    :arg op: Operation to perform.
    :arg k: Number of elements to keep.

    :arg axes: The reduction dimensions.
        The bit in position i of bitmask axes corresponds to explicit dimension i of the result.
        E.g., the least significant bit corresponds to the first explicit dimension and the next to least
        significant bit corresponds to the second explicit dimension.
        Currently axes must specify exactly one dimension, and it must be one of the last four dimensions.

    :returns: The new TopK layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_gather = R"trtdoc(
    Add a gather layer to the network.
    See :class:`IGatherLayer` for more information.

    :arg input: The tensor to gather values from.
    :arg indices: The tensor to get indices from to populate the output tensor.
    :arg axis: The non-batch dimension axis in the data tensor to gather on.

    :returns: The new gather layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_gather_v2 = R"trtdoc(
    Add a gather layer to the network.
    See :class:`IGatherLayer` for more information.

    :arg input: The tensor to gather values from.
    :arg indices: The tensor to get indices from to populate the output tensor.
    :arg mode: The gather mode.

    :returns: The new gather layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_scatter = R"trtdoc(
    Add a scatter layer to the network.
    See :class:`IScatterLayer` for more information.

    :arg data: The tensor to get default values from.
    :arg indices: The tensor to get indices from to populate the output tensor.
    :arg updates: The tensor to get values from to populate the output tensor.
    :arg mode: operation mode see IScatterLayer for more info

    :returns: The new Scatter layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_ragged_softmax = R"trtdoc(
    Add a ragged softmax layer to the network.
    See :class:`IRaggedSoftMaxLayer` for more information.

    :arg input: The ZxS input tensor.
    :arg bounds: The Zx1 bounds tensor.

    :returns: The new ragged softmax layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_matrix_multiply = R"trtdoc(
    Add a matrix multiply layer to the network.
    See :class:`IMatrixMultiplyLayer` for more information.

    :arg input0: The first input tensor (commonly A).
    :arg op0: Whether to treat input0 as matrices, transposed matrices, or vectors.
    :arg input1: The second input tensor (commonly B).
    :arg op1:  Whether to treat input1 as matrices, transposed matrices, or vectors.

    :returns: The new matrix multiply layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_matrix_multiply_deprecated = R"trtdoc(
    Add a matrix multiply layer to the network.
    See :class:`IMatrixMultiplyLayer` for more information.

    :arg input0: The first input tensor (commonly A).
    :arg transpose0: If true, op(input0)=transpose(input0), else op(input0)=input0.
    :arg input1: The second input tensor (commonly B).
    :arg transpose1: If true, op(input1)=transpose(input1), else op(input1)=input1.

    :returns: The new matrix multiply layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_constant = R"trtdoc(
    Add a constant layer to the network.
    See :class:`IConstantLayer` for more information.

    :arg shape: The shape of the constant.
    :arg weights: The constant value, represented as weights.

    :returns: The new constant layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_identity = R"trtdoc(
    Add an identity layer.
    See :class:`IIdentityLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: The new identity layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_cast = R"trtdoc(
    Add a cast layer.
    See :class:`ICastLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg to_type: The data type the output tensor should be cast into.

    :returns: The new cast layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_parametric_relu = R"trtdoc(
        Add a parametric ReLU layer.
        See :class:`IParametricReLULayer` for more information.

        :arg input: The input tensor to the layer.
        :arg slopes: The slopes tensor (input elements are multiplied with the slopes where the input is negative).

        :returns: The new parametric ReLU layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_resize = R"trtdoc(
    Add a resize layer.
    See :class:`IResizeLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: The new resize layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_loop = R"trtdoc(
    Adds a loop to the network, which provides a way to specify a recurrent subgraph.
    See :class:`ILoop` for more information.

    :returns: The new loop layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_shape = R"trtdoc(
    Add a shape layer to the network.
    See :class:`IShapeLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: The new shape layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_select = R"trtdoc(
    Add a select layer.
    See :class:`ISelectLayer` for more information.

    :arg condition: The condition tensor to the layer.
    :arg then_input: The then input tensor to the layer.
    :arg else_input: The else input tensor to the layer.

    :returns: The new select layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_assertion = R"trtdoc(
    Add a assertion layer.
    See :class:`IAssertionLayer` for more information.

    :arg condition: The condition tensor to the layer.
    :arg message: The message to print if the assertion fails.

    :returns: The new assertion layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_grid_sample = R"trtdoc(
    Creates a GridSample layer with a trt.InterpolationMode.LINEAR, unaligned corners, and trt.SampleMode.FILL for 4d-shape input tensors.
    See :class:`IGridSampleLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg grid: The grid tensor to the layer.
    :ivar interpolation_mode: class:`InterpolationMode` The interpolation mode to use in the layer. Default is LINEAR.
    :ivar align_corners: class:`bool` the align mode to use in the layer. Default is False.
    :ivar padding_mode: :class:`SampleMode` The padding mode to use in the layer. Default is FILL.

    :returns: The new grid sample layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_nms = R"trtdoc(
    Add a non-maximum suppression layer to the network.
    See :class:`INMSLayer` for more information.

    :arg boxes: The input boxes tensor to the layer.
    :arg scores: The input scores tensor to the layer.
    :arg max_output_boxes_per_class: The maxOutputBoxesPerClass tensor to the layer.
    :ivar bounding_box_format: :class:`BoundingBoxFormat` The bounding box format used by the layer. Default is CORNER_PAIRS.
    :ivar topk_box_limit: :class:`int` The maximum number of filtered boxes considered for selection per batch item. Default is 2000 for SM 5.3 and 6.2 devices, and 5000 otherwise. The TopK box limit must be less than or equal to {2000 for SM 5.3 and 6.2 devices, 5000 otherwise}.

    :returns: The new NMS layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_fill = R"trtdoc(
    Add a fill layer.
    See :class:`IFillLayer` for more information.

    :arg dimensions: The output tensor dimensions.
    :arg op: The fill operation that the layer applies.
    :arg output_type: The datatype of the output tensor. Specifying output_type is optional (default value tensorrt.float32).

    :returns: The new fill layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_one_hot = R"trtdoc(
    Add a OneHot layer to the network.
    See :class:`IOneHotLayer` for more information.

    :arg indices: The tensor to get indices from to populate the output tensor.
    :arg values: The tensor to get off (cold) value and on (hot) value
    :arg depth: The tensor to get depth (number of classes) of one-hot encoding
    :arg axis: The axis to append the one-hot encoding to

    :returns: The new OneHot layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* set_weights_name = R"trtdoc(
    Associate a name with all current uses of the given weights.

    The name must be set after the Weights are used in the network.
    Lookup is associative. The name applies to all Weights with matching
    type, value pointer, and count. If Weights with a matching value
    pointer, but different type or count exists in the network, an
    error message is issued, the name is rejected, and return false.
    If the name has already been used for other weights,
    return false. None causes the weights to become unnamed,
    i.e. clears any previous name.

    :arg weights: The weights to be named.
    :arg name: The name to associate with the weights.

    :returns: true on success.
)trtdoc";

constexpr const char* remove_tensor = R"trtdoc(
        Remove a tensor from the network.

        :arg tensor: The tensor to remove

        It is illegal to remove a tensor that is the input or output of a layer.
        if this method is called with such a tensor, a warning will be emitted on the log
        and the call will be ignored.
)trtdoc";

constexpr const char* unmark_output = R"trtdoc(
        Unmark a tensor as a network output.

        :arg tensor: The tensor to unmark as an output tensor.
)trtdoc";

constexpr const char* mark_output_for_shapes = R"trtdoc(
    Enable tensor's value to be computed by :func:`IExecutionContext.get_shape_binding`.

    :arg tensor: The tensor to unmark as an output tensor. The tensor must be of type :class:`int32` and have no more than one dimension.

    :returns: :class:`True` if successful, :class:`False` if tensor is already marked as an output.
)trtdoc";

constexpr const char* unmark_output_for_shapes = R"trtdoc(
    Undo :func:`mark_output_for_shapes` .

    :arg tensor: The tensor to unmark as an output tensor.

    :returns: :class:`True` if successful, :class:`False` if tensor is not marked as an output.

)trtdoc";

constexpr const char* add_plugin_v2 = R"trtdoc(
    Add a plugin layer to the network using an :class:`IPluginV2` interface.
    See :class:`IPluginV2` for more information.

    :arg inputs: The input tensors to the layer.
    :arg plugin: The layer plugin.

    :returns: The new plugin layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_plugin = R"trtdoc(
    Add a plugin layer to the network with a tuple of (inputs, shape_inputs, plugin). :func:`add_plugin_v3` can be thought of as an "unpacked tuple" version of this function.

    Primarily intended to be used when using the `tensorrt.plugin` module to implement the plugin.

    :arg tuple: A tuple of (inputs, shape_inputs, plugin).

    :returns: The new plugin layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_plugin_v3 = R"trtdoc(
    Add a plugin layer to the network using an :class:`IPluginV3` interface.
    See :class:`IPluginV3` for more information.

    :arg inputs: The input tensors to the layer.
    :arg shape_inputs: The shape input tensors to the layer.
    :arg plugin: The layer plugin.

    :returns: The new plugin layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* get_layer = R"trtdoc(
    Get the layer specified by the given index.

    :arg index: The index of the layer.

    :returns: The layer, or :class:`None` if it is out of range.
)trtdoc";

constexpr const char* get_input = R"trtdoc(
    Get the input tensor specified by the given index.

    :arg index: The index of the input tensor.

    :returns: The tensor, or :class:`None` if it is out of range.
)trtdoc";

constexpr const char* get_output = R"trtdoc(
    Get the output tensor specified by the given index.

    :arg index: The index of the output tensor.

    :returns: The tensor, or :class:`None` if it is out of range.
)trtdoc";

constexpr const char* builder = R"trtdoc(
    The builder from which this INetworkDefinition was created.

    See :class:`IBuilder` for more information.
)trtdoc";

constexpr const char* serialize = R"trtdoc(
    Serialize the network to a stream.

    :returns: An :class:`IHostMemory` object containing the serialized :class:`INetworkDefinition` .
)trtdoc";

constexpr const char* add_quantize = R"trtdoc(
    Add a quantization layer to the network.
    See :class:`IQuantizeLayer` for more information.

    :arg input: A tensor to quantize.
    :arg scale: A tensor with the scale coefficients.
    :arg output_type: The datatype of the output tensor. Specifying output_type is optional (default value tensorrt.int8).

    :returns: The new quantization layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_dequantize = R"trtdoc(
    Add a dequantization layer to the network.
    See :class:`IDequantizeLayer` for more information.

    :arg input: A tensor to quantize.
    :arg scale: A tensor with the scale coefficients.
    :arg output_type: The datatype of the output tensor. Specifying output_type is optional (default value tensorrt.float32).

    :returns: The new dequantization layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_dynamic_quantize = R"trtdoc(
    Add a dynamic quantization layer to the network.
    See :class:`IDynamicQuantizeLayer` for more information.

    :arg input: A tensor to quantize.
    :arg axis: The axis that is sliced into blocks.
    :arg block_size: The number of elements that are quantized using a shared scale factor.
    :arg output_type: The data type of the quantized output tensor.
    :arg scale_type: The data type of the scale factor used for quantizing the input data.

    :returns: The new DynamicQuantization layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_split_to_ragged = R"trtdoc(
    Add a dynamic quantization layer to the network.
    See :class:`IDynamicQuantizeLayer` for more information.

    :arg input: A tensor to quantize.
    :arg axis: The axis that is sliced into blocks.

    :returns: The new SplitToRagged layer, or :class:`None` if it could not be created.
)trtdoc";
constexpr const char* add_concat_from_ragged = R"trtdoc(
    Add a dynamic quantization layer to the network.
    See :class:`IDynamicQuantizeLayer` for more information.

    :arg input: A tensor to quantize.
    :arg axis: The axis that is sliced into blocks.

    :returns: The new ConcatFromRagged layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_if_conditional = R"trtdoc(
    Adds an if-conditional to the network, which provides a way to specify subgraphs that will be conditionally executed using lazy evaluation.
    See :class:`IIfConditional` for more information.

    :returns: The new if-condtional, or :class:`None` if it could not be created.
)trtdoc";

constexpr const char* add_einsum = R"trtdoc(
    Adds an Einsum layer to the network.
    See :class:`IEinsumLayer` for more information.

    :arg inputs: The input tensors to the layer.
    :arg equation: The Einsum equation of the layer.

    :returns: the new Einsum layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr char const* add_non_zero = R"trtdoc(
    Adds an NonZero layer to the network.
    See :class:`INonZeroLayer` for more information.

    :arg input: The input tensor to the layer.

    :returns: the new NonZero layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr char const* add_reverse_sequence = R"trtdoc(
    Adds a ReverseSequence layer to the network.
    See :class:`IReverseSequenceLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg sequence_lens: 1D tensor specifying lengths of sequences to reverse in a batch. The length of ``sequence_lens`` must be equal to the size of the dimension in ``input`` specified by ``batch_axis``.

    :returns: the new ReverseSequence layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr char const* add_normalization = R"trtdoc(
    Adds a Normalization layer to the network.
    See :class:`Normalization` for more information.

    :arg input: The input tensor to the layer.
    :arg scale: The scale tensor used to scale the normalized output.
    :arg bias: The bias tensor used to scale the normalized output.
    :arg axesMask: The axes on which to perform mean calculations.
        The bit in position i of bitmask axes corresponds to explicit dimension i of the result.
        E.g., the least significant bit corresponds to the first explicit dimension and the next to least
        significant bit corresponds to the second explicit dimension.

    :returns: the new Normalization layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr char const* add_squeeze = R"trtdoc(
    Adds a Squeeze layer to the network.
    See :class:`ISqueezeLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg axes: The tensor containing axes to remove. Must be resolvable to a constant Int32 or Int64 1D shape tensor.

    :returns: the new Squeeze layer, or :class:`None` if it could not be created.
)trtdoc";

constexpr char const* add_unsqueeze = R"trtdoc(
    Adds an Unsqueeze layer to the network.
    See :class:`IUnsqueezeLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg axes: The tensor containing axes to add. Must be resolvable to a constant Int32 or Int64 1D shape tensor.

    :returns: the new Unsqueeze layer, or :class:`None` if it could not be created.
)trtdoc";


constexpr const char* add_cumulative = R"trtdoc(
    Add a cumulative layer to the network.
    See :class:`ICumulativeLayer` for more information.

    :arg input: The input tensor to the layer.
    :arg axis: The axis tensor to apply the cumulative operation on. Currently, it must be a build-time constant 0-D shape tensor.
    :arg op: The reduction operation to perform.
    :arg exclusive: The boolean that specifies whether it is an exclusive cumulative or inclusive cumulative.
    :arg reverse: The boolean that specifies whether the cumulative should be applied backward.

    :returns: The new cumulative layer, or :class:`None` if it could not be created.
)trtdoc";

} // namespace INetworkDefinitionDoc

} // namespace tensorrt
