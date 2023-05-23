/*
 * Copyright 2015 Google Inc. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package cherry

import (
	"testing"
)

func TestPrefixEncoder (t *testing.T) {
	caseList := []string {
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_constant_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_src_alpha_one_minus_constant_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_zero",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_constant_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.dst_alpha_one_minus_constant_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_zero",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_src_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_dst_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_src_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_dst_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_constant_color",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_constant_alpha",
		"dEQP-GLES2.functional.fragment_ops.blend.rgb_func_alpha_func.dst.one_minus_dst_alpha_one_minus_constant_alpha",
	}
	encoded := prefixEncode(caseList)
	reference := "{dEQP-GLES2{functional{fragment_ops{blend{rgb_func_alpha_func{dst{one_minus_src_alpha_src_color,one_minus_src_alpha_one_minus_src_color,one_minus_src_alpha_dst_color,one_minus_src_alpha_one_minus_dst_color,one_minus_src_alpha_src_alpha,one_minus_src_alpha_one_minus_src_alpha,one_minus_src_alpha_dst_alpha,one_minus_src_alpha_one_minus_dst_alpha,one_minus_src_alpha_constant_color,one_minus_src_alpha_one_minus_constant_color,one_minus_src_alpha_constant_alpha,one_minus_src_alpha_one_minus_constant_alpha,dst_alpha_zero,dst_alpha_one,dst_alpha_src_color,dst_alpha_one_minus_src_color,dst_alpha_dst_color,dst_alpha_one_minus_dst_color,dst_alpha_src_alpha,dst_alpha_one_minus_src_alpha,dst_alpha_dst_alpha,dst_alpha_one_minus_dst_alpha,dst_alpha_constant_color,dst_alpha_one_minus_constant_color,dst_alpha_constant_alpha,dst_alpha_one_minus_constant_alpha,one_minus_dst_alpha_zero,one_minus_dst_alpha_one,one_minus_dst_alpha_src_color,one_minus_dst_alpha_one_minus_src_color,one_minus_dst_alpha_dst_color,one_minus_dst_alpha_one_minus_dst_color,one_minus_dst_alpha_src_alpha,one_minus_dst_alpha_one_minus_src_alpha,one_minus_dst_alpha_dst_alpha,one_minus_dst_alpha_one_minus_dst_alpha,one_minus_dst_alpha_constant_color,one_minus_dst_alpha_one_minus_constant_color,one_minus_dst_alpha_constant_alpha,one_minus_dst_alpha_one_minus_constant_alpha}}}}}}}"

	if encoded != reference {
		t.Errorf("prefixEncode() failed:\ngot: '%s'\nexpected: '%s'\n", encoded, reference)
	}
}
