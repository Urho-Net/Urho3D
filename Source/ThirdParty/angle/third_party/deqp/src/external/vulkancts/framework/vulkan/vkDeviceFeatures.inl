/* WARNING: This is auto-generated file. Do not modify, since changes will
 * be lost! Modify the generating script instead.
 */
#include "vkDeviceFeatures.hpp"

namespace vk
{
#define VK_KHR_16BIT_STORAGE_EXTENSION_NAME "VK_KHR_16bit_storage"
#define VK_KHR_MULTIVIEW_EXTENSION_NAME   "VK_KHR_multiview"
#define VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME "VK_KHR_variable_pointers"
#define DECL_PROTECTED_MEMORY_EXTENSION_NAME "not_existent_feature"
#define VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME "VK_KHR_sampler_ycbcr_conversion"
#define VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME "VK_KHR_shader_draw_parameters"
#define VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME "VK_EXT_transform_feedback"
#define VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME "VK_EXT_conditional_rendering"
#define VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME "VK_KHR_shader_float16_int8"
#define VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME "VK_EXT_depth_clip_enable"
#define VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME "VK_EXT_inline_uniform_block"
#define VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME "VK_EXT_blend_operation_advanced"
#define VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME "VK_EXT_descriptor_indexing"
#define VK_KHR_8BIT_STORAGE_EXTENSION_NAME "VK_KHR_8bit_storage"
#define VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME "VK_KHR_shader_atomic_int64"
#define VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME "VK_EXT_vertex_attribute_divisor"
#define VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME "VK_KHR_vulkan_memory_model"
#define VK_EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME "VK_EXT_scalar_block_layout"
#define VK_EXT_MEMORY_PRIORITY_EXTENSION_NAME "VK_EXT_memory_priority"
#define VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME "VK_EXT_buffer_device_address"
#define VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME "VK_KHR_uniform_buffer_standard_layout"
#define VK_NV_COOPERATIVE_MATRIX_EXTENSION_NAME "VK_NV_cooperative_matrix"
#define VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME "VK_EXT_host_query_reset"


template<> FeatureDesc makeFeatureDesc<VkPhysicalDevice16BitStorageFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES, VK_KHR_16BIT_STORAGE_EXTENSION_NAME, VK_KHR_16BIT_STORAGE_SPEC_VERSION, 23); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceMultiviewFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES, VK_KHR_MULTIVIEW_EXTENSION_NAME, VK_KHR_MULTIVIEW_SPEC_VERSION, 22); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVariablePointersFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES, VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME, VK_KHR_VARIABLE_POINTERS_SPEC_VERSION, 21); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceProtectedMemoryFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES, DECL_PROTECTED_MEMORY_EXTENSION_NAME, 0, 20); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceSamplerYcbcrConversionFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES, VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME, VK_KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION, 19); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderDrawParametersFeatures>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES, VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME, VK_KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION, 18); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceTransformFeedbackFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT, VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME, VK_EXT_TRANSFORM_FEEDBACK_SPEC_VERSION, 17); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceConditionalRenderingFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT, VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME, VK_EXT_CONDITIONAL_RENDERING_SPEC_VERSION, 16); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceFloat16Int8FeaturesKHR>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR, VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME, VK_KHR_SHADER_FLOAT16_INT8_SPEC_VERSION, 15); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceDepthClipEnableFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION, 14); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceInlineUniformBlockFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT, VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME, VK_EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION, 13); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION, 12); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceDescriptorIndexingFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT, VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME, VK_EXT_DESCRIPTOR_INDEXING_SPEC_VERSION, 11); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDevice8BitStorageFeaturesKHR>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR, VK_KHR_8BIT_STORAGE_EXTENSION_NAME, VK_KHR_8BIT_STORAGE_SPEC_VERSION, 10); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceShaderAtomicInt64FeaturesKHR>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR, VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME, VK_KHR_SHADER_ATOMIC_INT64_SPEC_VERSION, 9); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION, 8); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceVulkanMemoryModelFeaturesKHR>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR, VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME, VK_KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION, 7); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceScalarBlockLayoutFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT, VK_EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME, VK_EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION, 6); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceMemoryPriorityFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT, VK_EXT_MEMORY_PRIORITY_EXTENSION_NAME, VK_EXT_MEMORY_PRIORITY_SPEC_VERSION, 5); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT, VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME, VK_EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION, 4); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR, VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME, VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION, 3); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceCooperativeMatrixFeaturesNV>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV, VK_NV_COOPERATIVE_MATRIX_EXTENSION_NAME, VK_NV_COOPERATIVE_MATRIX_SPEC_VERSION, 2); }
template<> FeatureDesc makeFeatureDesc<VkPhysicalDeviceHostQueryResetFeaturesEXT>(void) { return FeatureDesc(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT, VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME, VK_EXT_HOST_QUERY_RESET_SPEC_VERSION, 1); }


static const FeatureStructMapItem featureStructCreatorMap[] =
{
	{ createFeatureStructWrapper<VkPhysicalDevice16BitStorageFeatures>, VK_KHR_16BIT_STORAGE_EXTENSION_NAME, VK_KHR_16BIT_STORAGE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceMultiviewFeatures>, VK_KHR_MULTIVIEW_EXTENSION_NAME, VK_KHR_MULTIVIEW_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVariablePointersFeatures>, VK_KHR_VARIABLE_POINTERS_EXTENSION_NAME, VK_KHR_VARIABLE_POINTERS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceProtectedMemoryFeatures>, DECL_PROTECTED_MEMORY_EXTENSION_NAME, 0 },
	{ createFeatureStructWrapper<VkPhysicalDeviceSamplerYcbcrConversionFeatures>, VK_KHR_SAMPLER_YCBCR_CONVERSION_EXTENSION_NAME, VK_KHR_SAMPLER_YCBCR_CONVERSION_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderDrawParametersFeatures>, VK_KHR_SHADER_DRAW_PARAMETERS_EXTENSION_NAME, VK_KHR_SHADER_DRAW_PARAMETERS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceTransformFeedbackFeaturesEXT>, VK_EXT_TRANSFORM_FEEDBACK_EXTENSION_NAME, VK_EXT_TRANSFORM_FEEDBACK_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceConditionalRenderingFeaturesEXT>, VK_EXT_CONDITIONAL_RENDERING_EXTENSION_NAME, VK_EXT_CONDITIONAL_RENDERING_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceFloat16Int8FeaturesKHR>, VK_KHR_SHADER_FLOAT16_INT8_EXTENSION_NAME, VK_KHR_SHADER_FLOAT16_INT8_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceDepthClipEnableFeaturesEXT>, VK_EXT_DEPTH_CLIP_ENABLE_EXTENSION_NAME, VK_EXT_DEPTH_CLIP_ENABLE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceInlineUniformBlockFeaturesEXT>, VK_EXT_INLINE_UNIFORM_BLOCK_EXTENSION_NAME, VK_EXT_INLINE_UNIFORM_BLOCK_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT>, VK_EXT_BLEND_OPERATION_ADVANCED_EXTENSION_NAME, VK_EXT_BLEND_OPERATION_ADVANCED_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceDescriptorIndexingFeaturesEXT>, VK_EXT_DESCRIPTOR_INDEXING_EXTENSION_NAME, VK_EXT_DESCRIPTOR_INDEXING_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDevice8BitStorageFeaturesKHR>, VK_KHR_8BIT_STORAGE_EXTENSION_NAME, VK_KHR_8BIT_STORAGE_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceShaderAtomicInt64FeaturesKHR>, VK_KHR_SHADER_ATOMIC_INT64_EXTENSION_NAME, VK_KHR_SHADER_ATOMIC_INT64_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT>, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_EXTENSION_NAME, VK_EXT_VERTEX_ATTRIBUTE_DIVISOR_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceVulkanMemoryModelFeaturesKHR>, VK_KHR_VULKAN_MEMORY_MODEL_EXTENSION_NAME, VK_KHR_VULKAN_MEMORY_MODEL_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceScalarBlockLayoutFeaturesEXT>, VK_EXT_SCALAR_BLOCK_LAYOUT_EXTENSION_NAME, VK_EXT_SCALAR_BLOCK_LAYOUT_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceMemoryPriorityFeaturesEXT>, VK_EXT_MEMORY_PRIORITY_EXTENSION_NAME, VK_EXT_MEMORY_PRIORITY_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceBufferDeviceAddressFeaturesEXT>, VK_EXT_BUFFER_DEVICE_ADDRESS_EXTENSION_NAME, VK_EXT_BUFFER_DEVICE_ADDRESS_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR>, VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_EXTENSION_NAME, VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceCooperativeMatrixFeaturesNV>, VK_NV_COOPERATIVE_MATRIX_EXTENSION_NAME, VK_NV_COOPERATIVE_MATRIX_SPEC_VERSION },
	{ createFeatureStructWrapper<VkPhysicalDeviceHostQueryResetFeaturesEXT>, VK_EXT_HOST_QUERY_RESET_EXTENSION_NAME, VK_EXT_HOST_QUERY_RESET_SPEC_VERSION },
};
} // vk

