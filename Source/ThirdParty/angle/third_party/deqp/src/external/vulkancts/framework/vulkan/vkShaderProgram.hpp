#ifndef _VKSHADERPROGRAM_HPP
#define _VKSHADERPROGRAM_HPP
/*-------------------------------------------------------------------------
 * Vulkan CTS Framework
 * --------------------
 *
 * Copyright (c) 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *//*!
 * \file
 * \brief Shader (GLSL/HLSL) source program.
 *//*--------------------------------------------------------------------*/

#include "vkDefs.hpp"
#include "gluShaderProgram.hpp"
#include "vkValidatorOptions.hpp"

#include <string>

namespace tcu
{
class TestLog;
} // tcu

namespace vk
{

struct ShaderBuildOptions
{
	enum Flags
	{
		FLAG_USE_STORAGE_BUFFER_STORAGE_CLASS	= (1u<<0),
		FLAG_ALLOW_RELAXED_OFFSETS				= (1u<<1),	// allow block offsets to follow VK_KHR_relaxed_block_layout
		FLAG_ALLOW_SCALAR_OFFSETS				= (1u<<2),	// allow block offsets to follow VK_EXT_scalar_block_layout
		FLAG_ALLOW_STD430_UBOS					= (1u<<3)	// allow block offsets to follow VK_EXT_uniform_buffer_standard_layout
	};

	deUint32		vulkanVersion;
	SpirvVersion	targetVersion;
	deUint32		flags;

	ShaderBuildOptions (deUint32 vulkanVersion_, SpirvVersion targetVersion_, deUint32 flags_)
		: vulkanVersion	(vulkanVersion_)
		, targetVersion	(targetVersion_)
		, flags			(flags_)
	{}

	ShaderBuildOptions (void)
		: vulkanVersion	(VK_MAKE_VERSION(1, 0, 0))
		, targetVersion	(SPIRV_VERSION_1_0)
		, flags			(0u)
	{}

	SpirvValidatorOptions getSpirvValidatorOptions() const
	{
		SpirvValidatorOptions::BlockLayoutRules rules = SpirvValidatorOptions::kDefaultBlockLayout;

		if (flags & FLAG_ALLOW_SCALAR_OFFSETS)
		{
			rules = SpirvValidatorOptions::kScalarBlockLayout;
		}
		else if (flags & FLAG_ALLOW_STD430_UBOS)
		{
			rules = SpirvValidatorOptions::kUniformStandardLayout;
		}
		else if (flags & FLAG_ALLOW_RELAXED_OFFSETS)
		{
			rules = SpirvValidatorOptions::kRelaxedBlockLayout;
		}

		return SpirvValidatorOptions(vulkanVersion, rules);
	}
};

enum ShaderLanguage
{
	SHADER_LANGUAGE_GLSL = 0,
	SHADER_LANGUAGE_HLSL,

	SHADER_LANGUAGE_LAST
};

struct GlslSource
{
	static const ShaderLanguage	shaderLanguage = SHADER_LANGUAGE_GLSL;
	std::vector<std::string>	sources[glu::SHADERTYPE_LAST];
	ShaderBuildOptions			buildOptions;

	GlslSource&					operator<<		(const glu::ShaderSource& shaderSource);
	GlslSource&					operator<<		(const ShaderBuildOptions& buildOptions_);
};

struct HlslSource
{
	static const ShaderLanguage	shaderLanguage = SHADER_LANGUAGE_HLSL;
	std::vector<std::string>	sources[glu::SHADERTYPE_LAST];
	ShaderBuildOptions			buildOptions;

	HlslSource&					operator<<		(const glu::ShaderSource& shaderSource);
	HlslSource&					operator<<		(const ShaderBuildOptions& buildOptions_);
};

tcu::TestLog&	operator<<		(tcu::TestLog& log, const GlslSource& shaderSource);
tcu::TestLog&	operator<<		(tcu::TestLog& log, const HlslSource& shaderSource);

} // vk

#endif // _VKSHADERPROGRAM_HPP
