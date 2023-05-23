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
	"reflect"
	"testing"
)

func TestTreeNodeExtractor (t *testing.T) {
	testCasePaths := []string {
		"GLES2.fragment_ops.blend.src.src_color",
		"GLES2.fragment_ops.blend.src.one_minus_src_color",
		"GLES2.fragment_ops.blend.src.dst_color",
		"GLES2.fragment_ops.blend.dst.src_alpha",
		"GLES2.vertex_ops.blend.src.src_color",
		"GLES2.vertex_ops.blend.dst.src_alpha",
	}

	reference := []treeNodeInfo {
		treeNodeInfo{ "", []string{ "GLES2" }, 6 },
		treeNodeInfo{ "GLES2", []string{ "GLES2.fragment_ops", "GLES2.vertex_ops" }, 6 },
		treeNodeInfo{ "GLES2.fragment_ops", []string{ "GLES2.fragment_ops.blend" }, 4 },
		treeNodeInfo{ "GLES2.fragment_ops.blend", []string{ "GLES2.fragment_ops.blend.src", "GLES2.fragment_ops.blend.dst" }, 4 },
		treeNodeInfo{ "GLES2.fragment_ops.blend.src", []string{ "GLES2.fragment_ops.blend.src.src_color", "GLES2.fragment_ops.blend.src.one_minus_src_color", "GLES2.fragment_ops.blend.src.dst_color" }, 3 },
		treeNodeInfo{ "GLES2.fragment_ops.blend.dst", []string{ "GLES2.fragment_ops.blend.dst.src_alpha" }, 1 },
		treeNodeInfo{ "GLES2.vertex_ops", []string{ "GLES2.vertex_ops.blend" }, 2 },
		treeNodeInfo{ "GLES2.vertex_ops.blend", []string{ "GLES2.vertex_ops.blend.src", "GLES2.vertex_ops.blend.dst" }, 2 },
		treeNodeInfo{ "GLES2.vertex_ops.blend.src", []string{ "GLES2.vertex_ops.blend.src.src_color" }, 1 },
		treeNodeInfo{ "GLES2.vertex_ops.blend.dst", []string{ "GLES2.vertex_ops.blend.dst.src_alpha" }, 1 },
	}

	nodePaths := computeTestCaseTreeNodes(testCasePaths)

	if !reflect.DeepEqual(nodePaths, reference) {
		t.Errorf("invalid result\ngot: %v\nexpected: %v\n", nodePaths, reference)
	}

/*	fmt.Printf("%d nodes:\n", len(nodePaths))
	for _, path := range nodePaths {
		fmt.Printf("  %v\n", path)
	}*/
}
