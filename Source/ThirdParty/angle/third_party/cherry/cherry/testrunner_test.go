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

func TestCaseSummaryParser (t *testing.T) {
	logText := `
		<?xml version="1.0" encoding="UTF-8"?>
		<TestCaseResult Version="0.3.3" CasePath="dEQP-GLES2.info.vendor" CaseType="SelfValidate">
		 <Text>NVIDIA Corporation</Text>
		 <Number Name="TestDuration" Description="Test case duration in microseconds" Tag="Time" Unit="us">889</Number>
		 <Text>Multisampling state reset failed: glGetError() returned GL_INVALID_ENUM at gluStateReset.cpp:112</Text>
		 <Text>Error in state reset, test program will terminate.</Text>
		 <Result StatusCode="Pass">Pass</Result>
		</TestCaseResult>`
	summary := parseTestCaseSummary(logText)

	if summary.caseType != TEST_CASE_TYPE_SELF_VALIDATE {
		t.Errorf("got wrong case type: %s, expected: %s\n", summary.caseType, TEST_CASE_TYPE_SELF_VALIDATE)
	}

	if summary.status != TEST_STATUS_CODE_PASS {
		t.Errorf("got wrong case type: %s, expected: %s\n", summary.status, TEST_STATUS_CODE_PASS)
	}

	if summary.result != "Pass" {
		t.Errorf("got wrong result: %s, expected: %s\n", summary.result, "Pass")
	}
}
