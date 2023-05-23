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
	"fmt"
	"testing"
	"time"
	"strings"
)

func TestConfigLoader (t *testing.T) {
	var gles2Xml = `<?xml version="1.0" encoding="UTF-8"?>
<TestCaseList>
 <TestCase Name="info" CaseType="TestGroup" Description="Platform information queries">
  <TestCase Name="vendor" CaseType="SelfValidate" Description="Vendor String" />
  <TestCase Name="renderer" CaseType="SelfValidate" Description="Renderer String" />
  <TestCase Name="version" CaseType="SelfValidate" Description="Version String" />
  <TestCase Name="shading_language_version" CaseType="SelfValidate" Description="Shading Language Version String" />
  <TestCase Name="extensions" CaseType="SelfValidate" Description="Supported Extensions" />
  <TestCase Name="render_target" CaseType="SelfValidate" Description="Render Target Info" />
</TestCase>
</TestCaseList>`

	tree, err := importTestCaseTree(strings.NewReader(gles2Xml), "dEQP-GLES2")
	if err != nil {
		t.Errorf("importTestCaseTree() failed: %s\n", err)
	}

	start := time.Now()
	linear := tree.GetLinearizedList()
	fmt.Printf("time to linearize test case list: %v\n", time.Now().Sub(start))
	for _, testCasePath := range linear {
		fmt.Printf("  %s\n", testCasePath)
	}
}
