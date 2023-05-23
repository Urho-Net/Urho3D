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
	"errors"
	"io"
	"../rtdb"
)

type BatchResultExportWriter interface {
	io.Writer
	SetFilename (string)
}

func WriteBatchResultExport (dst BatchResultExportWriter, rtdbServer *rtdb.Server, batchResultId string) error {
	versionView := rtdbServer.NewVersionView()
	defer rtdbServer.ReleaseVersionView(versionView)

	var batchResult BatchResult
	err := rtdbServer.GetVersionViewedObject(batchResultId, &batchResult, versionView)
	if err != nil || batchResult.Status == BATCH_STATUS_CODE_INITIALIZING || batchResult.Status == BATCH_STATUS_CODE_IMPORTING {
		return errors.New("Couldn't get batch result")
	}

	var deviceConfig DeviceConfig
	err = rtdbServer.GetVersionViewedObject(batchResult.ExecParams.DeviceId, &deviceConfig, versionView)
	if err != nil {
		return errors.New("Couldn't get device config")
	}

	dst.SetFilename(batchResult.Name + ".qpa")

	var testCaseList TestCaseList
	err = rtdbServer.GetVersionViewedObject(batchResultId, &testCaseList, versionView)
	if err != nil { return errors.New("Couldn't get test case list") }

	writer := CreateLogContainerWriter(dst)
	err = writer.BeginSession(batchResult, deviceConfig)
	if err != nil { return err }
	for _, casePath := range testCaseList.Paths {
		var testCaseHeader TestCaseHeader
		err = rtdbServer.GetVersionViewedObject(batchResultId + "/" + casePath, &testCaseHeader, versionView)
		if err != nil { return errors.New("Couldn't get test case header") }

		var testCaseResult TestCaseResult
		err = rtdbServer.GetVersionViewedObject(batchResultId + "/" + casePath, &testCaseResult, versionView)
		if err != nil { return errors.New("Couldn't get test case result") }

		err = writer.WriteTestCaseResult(testCaseHeader, testCaseResult)
		if err != nil { return err }
	}

	err = writer.EndSession()
	if err != nil { return err }
	return nil
}
