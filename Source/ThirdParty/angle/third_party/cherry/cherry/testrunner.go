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
	"encoding/xml"
	"log"
	"../rtdb"
	"strings"
	"time"
	"fmt"
	"mime/multipart"
	"unicode/utf8"
	"strconv"
	"bufio"
	"bytes"
	"os"
	"regexp"
)

// Util

func btoi (v bool) int {
	if v {
		return 1
	} else {
		return 0
	}
}

// TestPackageInfo
// \todo [petri] get rid of binaryName, binaryDir if/when all modules in same executable?

type TestPackageInfo struct {
	name			string
	binaryName		string
	binaryDir		string
	testCaseTree	*TestCaseTree
	testCaseList	[]string		// linearized test case list
}

// Descriptor for load list.
type TestPackageDescriptor struct {
	packageName			string
	binaryName			string
	binaryDir			string
	testCaseFileName	string
}

// TestRunner

type TestRunner struct {
	rtdbServer			*rtdb.Server

	// \todo [petri] these should be dynamic, not loaded at init time!
	testPackages		map[string]TestPackageInfo
	fullTestCaseList	[]string
	// Control channel for batch executions, read in runner.handleQueue().
	queueControl		chan<- batchExecQueueControl

	// Control channel for batch imports, read in runner.handleImports().
	importControl		chan<- batchImportControl
}

type testCaseSummary struct {
	caseType	TestCaseType
	status		TestStatusCode
	result		string
}

func parseTestCaseType (caseTypeString string) TestCaseType {
	switch caseTypeString {
		case string(TEST_CASE_TYPE_SELF_VALIDATE):	return TEST_CASE_TYPE_SELF_VALIDATE
		case string(TEST_CASE_TYPE_PERFORMANCE):	return TEST_CASE_TYPE_PERFORMANCE
		case string(TEST_CASE_TYPE_ACCURACY):		return TEST_CASE_TYPE_ACCURACY
		case string(TEST_CASE_TYPE_CAPABILITY):		return TEST_CASE_TYPE_CAPABILITY
		default:									return TestCaseType("")
	}
}

func parseTestCaseSummary (logText string) testCaseSummary {
	type XmlResult struct {
		Value			string		`xml:",chardata"`
		StatusCode		string		`xml:"StatusCode,attr"`
	}

	type xmlRoot struct {
		XMLName			xml.Name	`xml:"TestCaseResult"`
		Version			string		`xml:"Version,attr"`
		CaseType		string		`xml:"CaseType,attr"`
		Result			XmlResult	`xml:"Result"`
	}

	// Just for the sake of the XML parser, replace invalid UTF-8 with something valid.
	logTextBytes := []byte(logText)
	for ndx := 0; ndx < len(logText); {
		r, size := utf8.DecodeRune(logTextBytes[ndx:])
		if r == utf8.RuneError && size == 1 {
			logTextBytes[ndx] = '?';
		}
		ndx += size
	}

	var root xmlRoot
	err := xml.Unmarshal(logTextBytes, &root)
	if err == nil {
		return testCaseSummary {
			caseType:	parseTestCaseType(root.CaseType),
			status:		parseTestStatusCode(root.Result.StatusCode),
			result:		root.Result.Value,
		}
	}

	log.Printf("[runner] Test log was not well-formed XML, fallback to manual parsing\n")

	// Parsing XML failed. Maybe the generating process terminated abnormally and
	// the resulting xml is not well-formed. Try to recover by using a regexp.
	var regexPattern = `<TestCaseResult [^>]*CaseType="([^"]*)"[^>]*>` +
					   `(?s).*` +
					   `<Result StatusCode="([^"]*)">([^<]*)</Result>`
	var resultParserRegex = regexp.MustCompile(regexPattern)
	resultParserRegex.Longest();
	matches := resultParserRegex.FindSubmatch(logTextBytes)

	if matches != nil {
		return testCaseSummary {
			caseType:	parseTestCaseType(string(matches[1])),
			status:		parseTestStatusCode(string(matches[2])),
			result:		string(matches[3]),
		}
	}

	// Fallback failed too
	log.Printf("[runner] fallback parsing failed\n")
	return testCaseSummary{}
}

// Read the log of the test case result and return a test case header and result with appropriate case type
// and status fields.
func augmentTestCaseInfo (testCaseInfo EventTestCaseFinished) (retHeader TestCaseHeader, retResult TestCaseResult) {
	summary			:= parseTestCaseSummary(testCaseInfo.log)

	resultStatus	:= testCaseInfo.status
	resultCaseType	:= summary.caseType

	// If no status in testResult, must be in the xml.
	if resultStatus == TestStatusCode("") {
		if summary.status == TestStatusCode("") {
			resultStatus = TEST_STATUS_CODE_INTERNAL_ERROR
		} else {
			resultStatus = summary.status
		}
	}

	if resultCaseType == TestCaseType("") {
		resultCaseType = TEST_CASE_TYPE_SELF_VALIDATE
	}

	retHeader = TestCaseHeader {
		CaseType:	resultCaseType,
		Status:		resultStatus,
		Result:		summary.result,
	}

	retResult = TestCaseResult {
		Path:	testCaseInfo.path,
		Log:	testCaseInfo.log,
	}

	return
}

func testStatusCodeStatsDelta (status TestStatusCode) (delta TestCaseTreeGroupStatusDelta) {
	return TestCaseTreeGroupStatusDelta {
		DeltaSuccess:				btoi(status == TEST_STATUS_CODE_PASS),
		DeltaFailure:				btoi(status == TEST_STATUS_CODE_FAIL),
		DeltaCrash:					btoi(status == TEST_STATUS_CODE_CRASH),
		DeltaTimeout:				btoi(status == TEST_STATUS_CODE_TIMEOUT),
		DeltaQualityWarning:		btoi(status == TEST_STATUS_CODE_QUALITY_WARNING),
		DeltaCompatibilityWarning:	btoi(status == TEST_STATUS_CODE_COMPATIBILITY_WARNING),
		DeltaNotSupported:			btoi(status == TEST_STATUS_CODE_NOT_SUPPORTED),
		DeltaResourceError:			btoi(status == TEST_STATUS_CODE_RESOURCE_ERROR),
		DeltaInternalError:			btoi(status == TEST_STATUS_CODE_INTERNAL_ERROR),
	}
}

func (runner *TestRunner) finishTestCase (batchResultId string, testCaseInfo EventTestCaseFinished) {
	testHeader, testResult := augmentTestCaseInfo(testCaseInfo)

	// Upload test case result to rtdb.
	log.Printf("[runner] finishTestCase(%q, %s, %s)\n", testResult.Path, testHeader.Status, testHeader.Result)
	opSet := rtdb.NewOpSet()
	objId := batchResultId + "/" + testResult.Path
	opSet.Call(typeTestCaseHeader, objId, "SetResult", testHeader.CaseType, testHeader.Status, testHeader.Result)
	opSet.Call(typeTestCaseResult, objId, "SetLog", testResult.Log)

	// Update all test case groups along the way to root.
	parts := strings.Split(testResult.Path, ".")
	for ndx := 0; ndx < len(parts); ndx++ {
		groupPath := strings.Join(parts[0:ndx], ".")
		statsDelta := testStatusCodeStatsDelta(testHeader.Status)
		groupObjId := batchResultId + "/" + groupPath
		opSet.Call(typeTestCaseTreeGroup, groupObjId, "UpdateStats", statsDelta)
	}

	err := runner.rtdbServer.ExecuteOpSet(opSet)
	if err != nil { panic(err) }
}

func (runner *TestRunner) setTestCaseStatus (batchResultId string, casePath string, status TestStatusCode) {
	objId := batchResultId + "/" + casePath
	opSet := rtdb.NewOpSet()
	opSet.Call(typeTestCaseHeader, objId, "SetStatus", status)
	err := runner.rtdbServer.ExecuteOpSet(opSet)
	if err != nil { panic(err) }
}

func intMin (a int, b int) int {
	if a <= b {
		return a
	} else {
		return b
	}
}

func getNextTestCaseBatch (testCasePaths []string) (string, []string) {
	// \note Only launch at most some constant amount of cases at a time.
	//		 This is because transmitting the test case list (trie) can
	//		 cause trouble if it's very big.
	// \note All test cases must have same package.
	maxBatchSize := intMin(1000, len(testCasePaths))
	packageName := strings.Split(testCasePaths[0], ".")[0]
	batchSize := 1
	for ; batchSize < maxBatchSize; batchSize++ {
		pkgName := strings.Split(testCasePaths[batchSize], ".")[0]
		if pkgName != packageName {
			break
		}
	}

	return packageName, testCasePaths[0:batchSize]
}

// Execute a batch that has been initialized - i.e., the batch result and its test result objects have already been created and set to pending or other suitable status.
func (runner *TestRunner) executeBatch (batchResultId string, batchParams BatchExecParams, testCasePaths []string, stopRequest <-chan struct{}, executionLogAppend chan<- string) {

	type BatchExecutionStatus int
	const (
		BATCH_EXEC_STATUS_RUNNING BatchExecutionStatus = iota
		BATCH_EXEC_STATUS_DONE
		BATCH_EXEC_STATUS_LINK_ERROR
		BATCH_EXEC_STATUS_GENERIC_ERROR
	)

	// Start running batch result.

	{
		opSet := rtdb.NewOpSet()
		opSet.Call(typeBatchResult, batchResultId, "SetStatus", BATCH_STATUS_CODE_RUNNING)
		err := runner.rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	var appendExecutionLog = func(content string) {
		executionLogAppend <- content
	}

	var appendTestInfoLog = func(content string) {
		wrappedContent := "**** Test binary info log chunk begins ****\n"
		wrappedContent += content
		wrappedContent += "**** Test binary info log chunk ends ****\n"
		appendExecutionLog(wrappedContent)
	}

	var appendCherryLogLine = func(content string) {
		appendExecutionLog(content + "\n")
	}

	var appendRunnerLogLine = func(content string) {
		log.Printf("[runner] %s\n", content)
		appendCherryLogLine(content)
	}

	appendRunnerLogLine(fmt.Sprintf("Starting test batch execution at %v", time.Now().Format(defaultHumanReadableTimeFormat)))

	var deviceConfig DeviceConfig
	adbOk			:= true
	runCanceled		:= false

	{
		err := runner.rtdbServer.GetObject(batchParams.DeviceId, &deviceConfig)
		if err != nil { panic(err) }
	}

	if deviceConfig.IsADBDevice {
		err := LaunchAndroidExecServer(deviceConfig.ADBSerialNumber, batchParams.TargetPort)
		if err != nil {
			appendRunnerLogLine(fmt.Sprintf("Failed to launch ExecServer on Android via ADB: %v", err))
			adbOk = false
		}
	}

	if adbOk {
		// Processed cases (to avoid re-executing them).
		processedCasePaths := make(map[string]bool)

		// Spawn execution as long as more cases to handle.
		appendRunnerLogLine(fmt.Sprintf("Execute %d tests...", len(testCasePaths)))
		for len(testCasePaths) > 0 {
			// Choose next batch to execute & encode case list trie.
			packageName, launchCaseList := getNextTestCaseBatch(testCasePaths)
			encodedCaseList := prefixEncode(launchCaseList)
			appendRunnerLogLine(fmt.Sprintf("Launch %d cases from package '%s'...", len(launchCaseList), packageName))
			testPackage := runner.testPackages[packageName]

			didProgress := false
			var executionStatus BatchExecutionStatus = BATCH_EXEC_STATUS_RUNNING

			// Try a few times (in case of connection errors).
			for tryNdx := 0; tryNdx < 3; tryNdx++ {
				if tryNdx > 0 {
					appendRunnerLogLine(fmt.Sprintf("Try again: %d", tryNdx))
					time.Sleep((time.Duration)(tryNdx) * 500 * time.Millisecond)
				}

				// If previous error was link error, relaunch execserver just to be sure
				if executionStatus == BATCH_EXEC_STATUS_LINK_ERROR && deviceConfig.IsADBDevice {
					appendRunnerLogLine("Relaunching execserver")
					err := RelaunchAndroidExecServer(deviceConfig.ADBSerialNumber, batchParams.TargetPort)
					if err != nil {
						appendRunnerLogLine(fmt.Sprintf("Failed to relaunch ExecServer on Android via ADB: %v", err))
						continue // Just try again, if tries left
					}
				}

				// Create link to target.
				linkParams := CommLinkParams {
					SpawnProcessPath:	batchParams.SpawnLocalProcess,
					TargetAddress:		batchParams.TargetAddress,
					TargetPort:			batchParams.TargetPort,
				}
				link := NewCommLinkTcpIp(linkParams, appendCherryLogLine)
				err := link.Start()
				if err != nil {
					appendRunnerLogLine(fmt.Sprintf("WARNING: failed to start link: %s", err))
					continue // Just try again, if tries left
				}

				// Execute test case on target device.
				execEventChan := make(chan TestExecutorEvent, 4)
				linkStopRequest := make(chan struct{}, 1)
				execParams := CommLinkExecParams {
					binaryName:		strings.Replace(batchParams.TestBinaryName, "${TestPackageName}", testPackage.binaryName, -1),
					commandLine:	batchParams.TestBinaryCommandLine,
					workingDir:		strings.Replace(batchParams.TestBinaryWorkingDir, "${TestPackageDir}", testPackage.binaryDir, -1),
					testCasePaths:	encodedCaseList,
				}
				err = link.Execute(execParams, execEventChan, linkStopRequest)
				if err != nil {
					appendRunnerLogLine(fmt.Sprintf("WARNING: connecting to target device failed: %s", err))
					link.Stop()
					continue
				}

				currentlyRunningCases := make(map[string]bool) // Paths of the test cases currently running.

				// Handle all events from comm link, as well as stop requests.
				executionStatus = BATCH_EXEC_STATUS_RUNNING
				for executionStatus == BATCH_EXEC_STATUS_RUNNING {
					select {
						case <-stopRequest:
							runCanceled = true
							appendRunnerLogLine("Got stop request")
							select {
								case linkStopRequest <- struct{}{}:
									appendRunnerLogLine("Sent stop request to comm link")
								default:
									appendRunnerLogLine("Stop request already sent to comm link")
							}

						case event := <-execEventChan:
							switch event.(type) {
								case EventSessionInfoRead:
									appendRunnerLogLine("Session info received")
									opSet := rtdb.NewOpSet()
									opSet.Call(typeBatchResult, batchResultId, "SetSessionInfo", event.(EventSessionInfoRead).sessionInfo)
									err := runner.rtdbServer.ExecuteOpSet(opSet)
									if err != nil { panic(err) }

								case EventInfoLogRead:
									logContent := event.(EventInfoLogRead).infoLog
									appendTestInfoLog(logContent)

								case EventTestCaseStarted:
									testCasePath := event.(EventTestCaseStarted).testCasePath

									if _, isAlreadyProcessed := processedCasePaths[testCasePath]; isAlreadyProcessed {
										appendRunnerLogLine(fmt.Sprintf("WARNING: got EventTestCaseStarted for already-processed test case '%s'; ignoring", testCasePath))
									} else {
										runner.setTestCaseStatus(batchResultId, testCasePath, TEST_STATUS_CODE_RUNNING)
										currentlyRunningCases[testCasePath] = true
									}

								case EventTestCaseFinished:
									testCaseInfo	:= event.(EventTestCaseFinished)
									path			:= testCaseInfo.path

									if _, isCurrentlyRunning := currentlyRunningCases[path]; !isCurrentlyRunning {
										if _, isAlreadyProcessed := processedCasePaths[path]; !isAlreadyProcessed {
											appendRunnerLogLine(fmt.Sprintf("WARNING: got EventTestCaseFinished for test case '%s' that isn't running; ignoring", path))
										}
									} else {
										delete(currentlyRunningCases, path)
										processedCasePaths[path] = true
										runner.finishTestCase(batchResultId, testCaseInfo) // upload to rtdb
									}

								case EventProcessStarted:
									appendRunnerLogLine("Test process started")

								case EventProcessLaunchFailed:
									launchFailed := event.(EventProcessLaunchFailed)
									appendRunnerLogLine(fmt.Sprintf("Process launch failed: %s", launchFailed.reason))
									executionStatus = BATCH_EXEC_STATUS_GENERIC_ERROR

								case EventExecutionFinished:
									appendRunnerLogLine(fmt.Sprintf("Test execution finished with status %#v", event.(EventExecutionFinished).status))
									switch (event.(EventExecutionFinished).status) {
										case EXEC_STATUS_DONE:
											executionStatus = BATCH_EXEC_STATUS_DONE
										case EXEC_STATUS_LINK_ERROR:
											executionStatus = BATCH_EXEC_STATUS_LINK_ERROR
										case EXEC_STATUS_TIMEOUT:
											executionStatus = BATCH_EXEC_STATUS_GENERIC_ERROR
										default:
											appendRunnerLogLine(fmt.Sprintf("WARNING: unknown end status received: %#v", event.(EventExecutionFinished).status))
											executionStatus = BATCH_EXEC_STATUS_GENERIC_ERROR
									}

								default:
									appendRunnerLogLine(fmt.Sprintf("WARNING: unknown execute event received: %#v", event))
							}
					}
				}

				// Disconnect from target.
				// \todo [petri] keep link active for longer?
				link.Stop()

				// Reset unfinished (running) cases to pending, so they can be re-run in the future.
				for testCasePath, _ := range currentlyRunningCases {
					runner.setTestCaseStatus(batchResultId, testCasePath, TEST_STATUS_CODE_PENDING)
				}

				// Remove processed cases from the list
				dstNdx := 0
				for srcNdx := 0; srcNdx < len(testCasePaths); srcNdx++ {
					casePath := testCasePaths[srcNdx]
					if _, ok := processedCasePaths[casePath]; !ok {
						testCasePaths[dstNdx] = testCasePaths[srcNdx]
						dstNdx++
					}
				}
				numProcessed := len(testCasePaths) - dstNdx
				if numProcessed > 0 {
					appendRunnerLogLine(fmt.Sprintf("%d test case(s) processed", numProcessed))
					testCasePaths = testCasePaths[0:dstNdx]
					didProgress = true
				}

				if runCanceled {
					appendRunnerLogLine("Run canceled")
				}

				if runCanceled || didProgress {
					break
				}

				appendRunnerLogLine("WARNING: no test cases processed")
			}

			// Exit loop if run was stopped or no progress was made.
			if runCanceled || !didProgress {
				break
			}
		}
	}

	// Mark the batch inactive and set its status.
	var batchStatus BatchStatusCode
	if runCanceled {
		batchStatus = BATCH_STATUS_CODE_CANCELED
	} else if len(testCasePaths) > 0 {
		batchStatus = BATCH_STATUS_CODE_INTERRUPTED
	} else {
		batchStatus = BATCH_STATUS_CODE_FINISHED
	}

	// Write status of batch result (in batchResult itself and in list of active batchResults).
	{
		opSet := rtdb.NewOpSet()
		opSet.Call(typeBatchResult, batchResultId, "SetStatus", batchStatus)
		opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Remove", batchResultId)
		err := runner.rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	if deviceConfig.IsADBDevice {
		err := RemoveADBPortForward(deviceConfig.ADBSerialNumber, batchParams.TargetPort)
		if err != nil {
			appendRunnerLogLine(fmt.Sprintf("WARNING: Failed to remove ADB port forward: %v", err))
		}
	}

	appendRunnerLogLine(fmt.Sprintf("Ending test batch execution at %v", time.Now().Format(defaultHumanReadableTimeFormat)))
}

// Create and initialize the test header, result, and tree node objects for the given batch.
func (runner *TestRunner) initializeBatchResult (batchResultId string) {
	log.Printf("[runner] initialize test headers and results for batch: batchResultId=%q\n", batchResultId)

	{
		totalOps := batchResultHierarchyInitOps(runner.rtdbServer, batchResultId)

		// Do transactions in chunks, because there can a big amount of operations,
		// and we don't want the DB to be blocked for too long at once.
		// Also keep updating the batch's InitProgress to inform the user.
		startTime := time.Now()
		{
			numOpsDone	:= 0
			chunkOps	:= rtdb.NewOpSet()
			for target, opList := range totalOps.ObjectOps {
				chunkOps.ObjectOps[target] = opList
				numOpsDone++
				if len(chunkOps.ObjectOps) == 500 {
					chunkOps.Call(typeBatchResult, batchResultId, "SetInitProgress", float32(numOpsDone) / float32(len(totalOps.ObjectOps)))
					err := runner.rtdbServer.ExecuteOpSet(chunkOps)
					if err != nil { panic(err) }
					chunkOps = rtdb.NewOpSet()
				}
			}
			chunkOps.Call(typeBatchResult, batchResultId, "SetInitProgress", float32(1.0))
			err := runner.rtdbServer.ExecuteOpSet(chunkOps)
			if err != nil { panic(err) }
		}
		elapsed := time.Now().Sub(startTime)
		log.Printf("[runner] initializeBatchResult hierarchy init op exec duration: %v\n", elapsed)
	}

	// \note Setting the batch result status to "pending" (from "initializing") should be the last
	//		 operation here, so in case Cherry e.g. crashes it won't think the batch was initialized
	//		 when it really wasn't.
	opSet := rtdb.NewOpSet()
	opSet.Call(typeBatchResult, batchResultId, "SetStatus", BATCH_STATUS_CODE_PENDING)
	err := runner.rtdbServer.ExecuteOpSet(opSet)
	if err != nil { panic(err) }
}

func (runner *TestRunner) filterPendingCasePaths (batchResultId string, testCasePaths []string) []string {
	rtdbServer := runner.rtdbServer

	// Get paths of unfinished test cases, and only execute those.
	pendingTestCasePaths := make([]string, 0)
	for _, testCasePath := range testCasePaths {
		caseObjId := batchResultId + "/" + testCasePath
		var testCaseHeader TestCaseHeader
		err := rtdbServer.GetObject(caseObjId, &testCaseHeader)
		if err != nil { panic(err) }
		if testCaseHeader.Status == TEST_STATUS_CODE_PENDING {
			pendingTestCasePaths = append(pendingTestCasePaths, testCasePath)
		}
	}

	return pendingTestCasePaths
}

func importTestPackage (packageName string, binaryName string, binaryDir string, testCaseFileName string) *TestPackageInfo {
	// Import test case tree.
	log.Printf("[config] importTestPackage('%s')\n", packageName)

	// Open file.
	xmlFile, err := os.Open(testCaseFileName)
	if err != nil {
		log.Printf("Failed to open test case file (%s : %s)\n", testCaseFileName, err.Error())
		return nil
	}
	defer xmlFile.Close()

	testCaseTree, err := importTestCaseTree(xmlFile, packageName)
	if err != nil {
		log.Printf("Failed to parse test case file (%s : %s)\n", testCaseFileName, err.Error())
		return nil
	}

	// Create test package.
	testPackage := TestPackageInfo {
		name:			packageName,
		binaryName:		binaryName,
		binaryDir:		binaryDir,
		testCaseTree:	testCaseTree,
		testCaseList:	testCaseTree.GetLinearizedList(),
	}

	return &testPackage
}

// Return the list imported packages. Failure to import leaves the failing package silently out of the list.
func importTestPackages (descriptors []TestPackageDescriptor) []*TestPackageInfo {
	packageList := []*TestPackageInfo{}
	for _, descriptor := range(descriptors) {
		testPackage := importTestPackage(descriptor.packageName, descriptor.binaryName, descriptor.binaryDir, descriptor.testCaseFileName)
		if (testPackage != nil) {
			packageList = append(packageList, testPackage)
		} else {
			log.Printf("Failed to import package '%s'\n", descriptor.packageName)
		}
	}
	return packageList
}

func NewTestRunner (rtdbServer *rtdb.Server) *TestRunner {
	var dataDir = "data/"

	testPackageDescriptors := []TestPackageDescriptor {
		// name			 binary					path									test case listing file
		{"dE-IT",		 "de-internal-tests",	"internal",								dataDir + "dE-IT-cases.xml"},
		{"dEQP-EGL",	 "deqp-egl",			"egl",									dataDir + "dEQP-EGL-cases.xml"},
		{"dEQP-GLES2",	 "deqp-gles2",			"gles2",								dataDir + "dEQP-GLES2-cases.xml"},
		{"dEQP-GLES3",	 "deqp-gles3",			"gles3",								dataDir + "dEQP-GLES3-cases.xml"},
		{"dEQP-GLES31",	 "deqp-gles31",			"gles31",								dataDir + "dEQP-GLES31-cases.xml"},
		{"dEQP-VK",		 "deqp-vk",				"../external/vulkancts/modules/vulkan",	dataDir + "dEQP-VK-cases.xml"},
	}

	packageList := importTestPackages(testPackageDescriptors)

	// Concatenate all test case names to one big list used, e.g., in test launch view
	fullTestCaseList := make([]string, 0)
	for _, testPackage := range packageList {
		fullTestCaseList = append(fullTestCaseList, testPackage.testCaseList...)
	}
	log.Printf("[config] total cases imported: %d\n", len(fullTestCaseList))

	// List of packages used in the server side test launch
	testPackages := make(map[string]TestPackageInfo, 0)
	for _, testPackage := range packageList {
		testPackages[testPackage.name] = *testPackage
	}

	queueControl := make(chan batchExecQueueControl)
	importControl := make(chan batchImportControl)

	runner := &TestRunner {
		rtdbServer:			rtdbServer,
		testPackages:		testPackages,
		fullTestCaseList:	fullTestCaseList,
		queueControl:		queueControl,
		importControl:		importControl,
	}

	go runner.handleQueue(queueControl)
	go runner.handleImports(importControl)

	return runner
}

func AddressQueueId (address string, port int) string {
	return address + ":" + strconv.Itoa(port)
}

func batchQueueId (params BatchExecParams) string {
	return AddressQueueId(params.TargetAddress, params.TargetPort)
}

// Create a new batch and start executing asynchronously.
func (runner *TestRunner) ExecuteTestBatch (batchName string, batchParams BatchExecParams, timestamp time.Time) (string, error) {
	// Resolve test case list to execute.
	// \todo [petri] fetch testCaseList dynamically from target?
	log.Printf("[runner] test name filters: %q\n", batchParams.TestNameFilters)
	testCasePaths := filterTestCaseNames(runner.fullTestCaseList, batchParams.TestNameFilters)
	log.Printf("[runner] filtered from %d cases to %d\n", len(runner.fullTestCaseList), len(testCasePaths))

	return runner.ExecuteTestBatchWithCaseList(batchName, batchParams, timestamp, testCasePaths)
}

func (runner *TestRunner) ExecuteTestBatchWithTestSet (batchName string, batchParams BatchExecParams, timestamp time.Time, testSetId string) (string, error) {
	var testSet TestSet
	err := runner.rtdbServer.GetObject(testSetId, &testSet)
	log.Printf("Start test set '%s' with %d filters.\n", testSetId, len(testSet.Filters))
	if err != nil {
		panic(err)
	}
	for ndx, filter := range(testSet.Filters) {
		if ndx > 5 {
			log.Printf("...")
			break
		}
		log.Printf("   Filter: '%s'", filter)
	}
	return runner.ExecuteTestBatchWithCaseList(batchName, batchParams, timestamp, testSet.Filters)
}

// Create a new batch, with a specific case list and no regard to batchParams.TestNameFilters, and start executing asynchronously.
func (runner *TestRunner) ExecuteTestBatchWithCaseList (batchName string, batchParams BatchExecParams, timestamp time.Time, testCasePaths []string) (string, error) {
	batchResultId := runner.rtdbServer.MakeUniqueID()
	opSet := rtdb.NewOpSet()

	// Empty batch result.
	batchResult := BatchResult {
		Name:			batchName,
		ExecParams:		batchParams,
		Status:			BATCH_STATUS_CODE_INITIALIZING,
		Timestamp:		timestamp,
	}

	// Header to batch result list.
	batchResultHeader := BatchResultHeader {
		Id:		batchResultId,
		Name:	batchName,
	}

	// Store in rtdb. \note Also initialize root group node already, so that the batch result list may show something sensible.
	opSet.Call(typeBatchResultList, "batchResultList", "Append", batchResultHeader)
	opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Append", batchResultId)
	opSet.Call(typeBatchResult, batchResultId, "Init", batchResult)
	opSet.Call(typeTestCaseList, batchResultId, "Init", TestCaseList { Paths: testCasePaths })
	opSet.Call(typeTestCaseTreeGroup, batchResultId + "/", "Init", TestCaseTreeGroup { NumTotalCases: len(testCasePaths) })
	opSet.Call(typeBatchResultExecutionLog, batchResultId, "Init")

	err := runner.rtdbServer.ExecuteOpSet(opSet)
	if err != nil { panic(err) }

	// Initialize and enqueue in background.
	go func () {
		runner.initializeBatchResult(batchResultId);

		runner.queueControl <- batchExecQueueControlEnqueue {
			batchResultId:	batchResultId,
			queueId:		batchQueueId(batchParams),
		}
	}()

	return batchResultId, nil
}

// Send a stop request to the given batch execution or import.
func (runner *TestRunner) StopBatchExecution (batchResultId string) error {
	var batchResult BatchResult
	err := runner.rtdbServer.GetObject(batchResultId, &batchResult)
	if err != nil { return err }

	if batchResult.Status == BATCH_STATUS_CODE_IMPORTING {
		runner.importControl <- batchImportControlStop {
			batchResultId: batchResultId,
		}
	} else {
		runner.queueControl <- batchExecQueueControlStopBatch {
			batchResultId:	batchResultId,
			queueId:		batchQueueId(batchResult.ExecParams),
		}
	}

	return nil
}

// Resume the execution of a previously stopped batch, asynchronously.
func (runner *TestRunner) ContinueBatchExecution (batchResultId string) error {
	batchStatusPending := BATCH_STATUS_CODE_PENDING

	var batchResult BatchResult
	err := runner.rtdbServer.GetObject(batchResultId, &batchResult)
	if err != nil { return err }

	if batchResult.Status != BATCH_STATUS_CODE_CANCELED && batchResult.Status != BATCH_STATUS_CODE_INTERRUPTED {
		return fmt.Errorf("[runner] WARNING: trying to continue batch '%s' with status '%s'", batchResultId, batchResult.Status)
	}

	opSet := rtdb.NewOpSet()
	opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Append", batchResultId)
	opSet.Call(typeBatchResult, batchResultId, "SetStatus", batchStatusPending)
	err = runner.rtdbServer.ExecuteOpSet(opSet)
	if err != nil { panic(err) }

	runner.queueControl <- batchExecQueueControlEnqueue {
		batchResultId:	batchResultId,
		queueId:		batchQueueId(batchResult.ExecParams),
	}

	return nil
}

func (runner *TestRunner) MoveBatchInQueue (batchResultId string, offset int) error {
	var batchResult BatchResult
	err := runner.rtdbServer.GetObject(batchResultId, &batchResult)
	if err != nil { return err }

	runner.queueControl <- batchExecQueueControlMove {
		batchResultId:	batchResultId,
		queueId:		batchQueueId(batchResult.ExecParams),
		offset:			offset,
	}

	return nil
}

func (runner *TestRunner) QueryBatchExecutionLog (batchResultId string) (string, error) {
	var batchResult BatchResult
	err := runner.rtdbServer.GetObject(batchResultId, &batchResult)
	if err != nil { return "", fmt.Errorf("when trying to get batch result object: %v", err) }

	executionLogChan := make(chan string, 1)
	runner.queueControl <- batchExecQueueControlExecutionLogQuery {
		batchResultId:	batchResultId,
		queueId:		batchQueueId(batchResult.ExecParams),
		dst:			executionLogChan,
	}
	return <-executionLogChan, nil
}

func (runner *TestRunner) ImportBatch (batchResultDefaultName string, qpaReader *multipart.Part, totalContentLength int64) error {
	batchResultId := runner.rtdbServer.MakeUniqueID()

	var stopRequest <-chan struct{}
	{
		stopRequestBidir := make(chan struct{})
		stopRequest = stopRequestBidir
		runner.importControl <- batchImportControlStarted { batchResultId, stopRequestBidir }
	}

	qpaParserQueue		:= make(chan TestExecutorEvent, 4)
	qpaParser			:= CreateLogContainerParser(qpaParserQueue)
	countingQpaReader	:= NewCountingReader(qpaReader)
	scanner				:= bufio.NewScanner(countingQpaReader)

	// Initialize batch result and root group. Add to batch result list.
	{
		opSet := rtdb.NewOpSet()

		batchResult := BatchResult {
			Name:			batchResultDefaultName,
			Status:			BATCH_STATUS_CODE_IMPORTING,
			InitProgress:	0.0,
		}

		batchResultHeader := BatchResultHeader {
			Id:		batchResultId,
			Name:	batchResultDefaultName,
		}

		opSet.Call(typeBatchResultList, "batchResultList", "Append", batchResultHeader)
		opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Append", batchResultId)
		opSet.Call(typeBatchResult, batchResultId, "Init", batchResult)
		opSet.Call(typeTestCaseList, batchResultId, "Init", TestCaseList { Paths: []string{} })
		opSet.Call(typeTestCaseTreeGroup, batchResultId + "/", "Init", TestCaseTreeGroup{})
		opSet.Call(typeBatchResultExecutionLog, batchResultId, "Init")

		err := runner.rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	isBatchFinished := true // Whether the batch contains only finished cases, and contains an #endSession.

	// Start reading input and writing to db.
	{
		opSet					:= rtdb.NewOpSet()
		keepReading				:= true
		eofReached				:= false
		lastDbExecReadCount		:= int64(0) // The value of countingQpaReader.Count() when the latest write to DB was done.
		existingTreeNodePaths	:= make(map[string]struct{})
		existingTreeNodePaths[""] = struct{}{} // \note Root node was already added above.

		for keepReading {
			select {
				case <-stopRequest:
					keepReading = false

				case event := <-qpaParserQueue:
					switch event.(type) {
						case EventSessionInfoRead:
							sessionInfo := event.(EventSessionInfoRead).sessionInfo
							if sessionInfo.DeviceId == "" {
								sessionInfo.DeviceId = "Unknown"
							}
							if sessionInfo.ResultName != "" {
								opSet.Call(typeBatchResultList, "batchResultList", "SetBatchResultName", batchResultId, sessionInfo.ResultName)
								opSet.Call(typeBatchResult, batchResultId, "SetName", sessionInfo.ResultName)
							}
							opSet.Call(typeBatchResult, batchResultId, "SetSessionInfo", sessionInfo)

							{
								err := runner.rtdbServer.GetObject(sessionInfo.DeviceId, &DeviceConfig{})
								if err != nil {
									var newConfig DeviceConfig
									if sessionInfo.ADBSerialNumber != "" {
										newConfig.IsADBDevice		= true
										newConfig.ADBSerialNumber	= sessionInfo.ADBSerialNumber
										newConfig.TargetAddress		= "127.0.0.1"
										newConfig.TargetPort		= 50016
									} else {
										if sessionInfo.DeviceId == "Unknown" {
											newConfig.Name = "Unknown"
										} else {
											newConfig.Name = "Unnamed"
										}
										opSet.Call(typeDeviceConfigList, "deviceConfigList", "Append", DeviceConfigHeader { sessionInfo.DeviceId })
									}

									opSet.Call(typeDeviceConfig, sessionInfo.DeviceId, "Init", newConfig)
								}
							}

						case EventTestCaseFinished:
							testCaseHeader, testCaseResult := augmentTestCaseInfo(event.(EventTestCaseFinished))

							caseObjId := batchResultId + "/" + testCaseResult.Path
							opSet.Call(typeTestCaseHeader, caseObjId, "Init", testCaseHeader)
							opSet.Call(typeTestCaseResult, caseObjId, "Init", testCaseResult)

							opSet.Call(typeTestCaseList, batchResultId, "Append", testCaseResult.Path)

							if testCaseHeader.Status == TEST_STATUS_CODE_PENDING {
								isBatchFinished = false
							}

							{
								statsDelta := testStatusCodeStatsDelta(testCaseHeader.Status)
								pathParts := strings.Split(testCaseResult.Path, ".")

								for ndx := 0; ndx < len(pathParts); ndx++ {
									nodePath := strings.Join(pathParts[:ndx], ".")
									nodeObjId := batchResultId + "/" + nodePath

									if _, ok := existingTreeNodePaths[nodePath]; !ok {
										existingTreeNodePaths[nodePath] = struct{}{}
										opSet.Call(typeTestCaseTreeGroup, nodeObjId, "Init", TestCaseTreeGroup{})
									}
									opSet.Call(typeTestCaseTreeGroup, nodeObjId, "AddCase")

									if testCaseHeader.Status != TEST_STATUS_CODE_PENDING {
										opSet.Call(typeTestCaseTreeGroup, nodeObjId, "UpdateStats", statsDelta)
									}
								}
							}
					}

				default:
					if (eofReached) {
						keepReading = false
					} else if scanner.Scan() {
						qpaParser.ParseLine(scanner.Text())
					} else {
						// EOF reached
						qpaParser.Terminate()
						eofReached = true
					}
			}

			// \note Write to DB in chunks.
			readCount := countingQpaReader.Count()
			if readCount - lastDbExecReadCount >= 4*1024*1024 {
				if totalContentLength != -1 { // Content-Length = -1 mean unknown
					approximateProgress := float32(float64(readCount) / float64(totalContentLength))
					opSet.Call(typeBatchResult, batchResultId, "SetInitProgress", approximateProgress)
				}
				err := runner.rtdbServer.ExecuteOpSet(opSet)
				if err != nil { panic(err) }
				opSet = rtdb.NewOpSet()
				lastDbExecReadCount = readCount
			}
		}

		opSet.Call(typeBatchResult, batchResultId, "SetInitProgress", float32(1.0))
		err := runner.rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	if qpaParser.IsInsideSession() {
		isBatchFinished = false
	}

	{
		opSet := rtdb.NewOpSet()

		var status BatchStatusCode
		if isBatchFinished {
			status = BATCH_STATUS_CODE_FINISHED
		} else {
			status = BATCH_STATUS_CODE_INTERRUPTED
		}
		opSet.Call(typeBatchResult, batchResultId, "SetStatus", status)
		opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Remove", batchResultId)

		err := runner.rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	runner.importControl <- batchImportControlFinished { batchResultId }
	return nil
}

// Batch execution queue controlling utilities.

type batchExecQueueControl interface {
}

// Enqueue a new batch execution.
type batchExecQueueControlEnqueue struct {
	batchResultId	string
	queueId			string
}

// Request stopping a batch run.
type batchExecQueueControlStopBatch struct {
	batchResultId	string
	queueId			string
}

// Move a batch to a different position in the queue.
type batchExecQueueControlMove struct {
	batchResultId	string
	queueId			string
	offset			int
}

// Query the execution log of a batch. The log will be sent to dst.
// \note This exists because the last part of the execution log of
//		 a running batch is kept in memory, not in DB.
type batchExecQueueControlExecutionLogQuery struct {
	batchResultId	string
	queueId			string
	dst				chan<- string
}

func (runner *TestRunner) isPartiallyExecutedBatch (batchResultId string) bool {
	var rootGroup TestCaseTreeGroup
	err := runner.rtdbServer.GetObject(batchResultId + "/", &rootGroup)
	if err != nil { panic(err) }

	return rootGroup.NumResults() != 0
}

// Get the DB version of the execution log of a batch result, i.e. the entire
// execution log if the batch isn't running, or, if the batch is running, the
// version containing all but the contents resulting from the current execution.
func (runner *TestRunner) getBatchResultPastExecutionLog (batchResultId string) string {
	var pastExecutionLog BatchResultExecutionLog
	err := runner.rtdbServer.GetObject(batchResultId, &pastExecutionLog)
	if err != nil { panic(err) }
	return pastExecutionLog.Content
}

// Handle the (e.g. per-device) batch execution queues. New batch enqueues and other queue operations
// are read from the channel. Removes finished/stopped batches from the queue.
// \todo [nuutti] There's currently no proper way of reporting errors (such as trying to stop a
//				  batch in a non-existing queue). Do we need a response channel of some kind?
func (runner *TestRunner) handleQueue (queueControl <-chan batchExecQueueControl) {
	execEndSignal := make(chan string)

	execute := func (enq batchExecQueueControlEnqueue, stopRequest <-chan struct{}, executionLogQuery <-chan chan<- string) {
		// Handle the execution log in a separate goroutine rather than in
		// the main loop of runner.executeBatch, so that any stalls in
		// executeBatch don't delay execution log queries.
		// The handler is controlled via the following channels.
		executionLogAppend	:= make(chan string)	// Append a string to the log; don't commit to DB yet.
		executionLogCommit	:= make(chan struct{})	// Commit uncommitted changes to DB.
		executionLogStop	:= make(chan struct{})	// Stop the goroutine.
		go func() {
			executionLog := bytes.Buffer{}
			for {
				select {
					case dst := <-executionLogQuery:
						dst <- runner.getBatchResultPastExecutionLog(enq.batchResultId) + executionLog.String()
					case str := <-executionLogAppend:
						executionLog.WriteString(str)
					case <-executionLogCommit:
						opSet := rtdb.NewOpSet()
						opSet.Call(typeBatchResultExecutionLog, enq.batchResultId, "Append", executionLog.String())
						err := runner.rtdbServer.ExecuteOpSet(opSet)
						if err != nil { panic(err) }
						executionLog.Reset()
					case <-executionLogStop:
						if executionLog.Len() > 0 { panic("Execution log handler stopped, but non-committed data remains") }
						return
				}
			}
		}()

		executionLogAppend <- fmt.Sprintf("Batch reached front of its queue at %v\n", time.Now().Format(defaultHumanReadableTimeFormat))

		var batchResult BatchResult
		err := runner.rtdbServer.GetObject(enq.batchResultId, &batchResult)
		if err != nil { panic(err) }

		var testCaseList TestCaseList
		err = runner.rtdbServer.GetObject(enq.batchResultId, &testCaseList)
		if err != nil { panic(err) }

		casePaths := testCaseList.Paths
		if runner.isPartiallyExecutedBatch(enq.batchResultId) {
			executionLogAppend <- fmt.Sprintf("Batch is partially executed, filtering pending cases\n")
			casePaths = runner.filterPendingCasePaths(enq.batchResultId, casePaths)
		}

		runner.executeBatch(enq.batchResultId, batchResult.ExecParams, casePaths, stopRequest, executionLogAppend)

		executionLogCommit <- struct{}{}
		execEndSignal <- enq.queueId
		executionLogStop <- struct{}{}
	}

	queueStopRequest		:= make(map[string]chan<- struct{})
	queueExecutionLogQuery	:= make(map[string]chan<- chan<- string)

	launch := func (enq batchExecQueueControlEnqueue) {
		stopRequest			:= make(chan struct{}, 1)
		executionLogQuery	:= make(chan chan<- string, 1)
		queueStopRequest[enq.queueId]			= stopRequest
		queueExecutionLogQuery[enq.queueId]		= executionLogQuery
		go execute(enq, stopRequest, executionLogQuery)
	}

	for {
		select {
			case command := <-queueControl:
				switch cmd := command.(type) {
					case batchExecQueueControlEnqueue:
						var queue DeviceBatchQueue
						err := runner.rtdbServer.GetObject(cmd.queueId, &queue)
						if err != nil {
							// Queue does not exist; create it.

							opSet := rtdb.NewOpSet()
							opSet.Call(typeDeviceBatchQueueList, "deviceBatchQueueList", "Append", cmd.queueId)
							opSet.Call(typeDeviceBatchQueue, cmd.queueId, "Init")
							err = runner.rtdbServer.ExecuteOpSet(opSet)
							if err != nil { panic(err) }

							log.Printf("[runner] created queue '%s'", cmd.queueId)
						}

						opSet := rtdb.NewOpSet()
						opSet.Call(typeDeviceBatchQueue, cmd.queueId, "Append", cmd.batchResultId)
						err = runner.rtdbServer.ExecuteOpSet(opSet)
						if err != nil { panic(err) }

						if len(queue.BatchResultIds) == 0 { // \note queue is the queue before appending.
							launch(cmd);
						}

					case batchExecQueueControlStopBatch:
						var queue DeviceBatchQueue
						err := runner.rtdbServer.GetObject(cmd.queueId, &queue)
						if err != nil {
							log.Printf("[runner] WARNING: stop request for non-existent queue '%s'", cmd.queueId)
							continue
						}

						found := false
						for ndx, enqueuedId := range queue.BatchResultIds {
							if enqueuedId == cmd.batchResultId {
								if ndx == 0 {
									select {
										case queueStopRequest[cmd.queueId] <- struct{}{}:
											log.Printf("[runner] stop request sent for batch '%s'\n", cmd.batchResultId)
										default:
											log.Printf("[runner] stop request already sent for batch '%s'\n", cmd.batchResultId)
									}
								} else {
									log.Printf("[runner] cancelled pending batch '%s'\n", cmd.batchResultId)

									// Set batch status, and remove it from the queue and active batch list.
									opSet := rtdb.NewOpSet()
									opSet.Call(typeBatchResult, cmd.batchResultId, "SetStatus", BATCH_STATUS_CODE_CANCELED)
									opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Remove", cmd.batchResultId)
									opSet.Call(typeDeviceBatchQueue, cmd.queueId, "Remove", cmd.batchResultId)
									err = runner.rtdbServer.ExecuteOpSet(opSet)
									if err != nil { panic(err) }
								}

								found = true
								break
							}
						}
						if !found {
							log.Printf("[runner] WARNING: stop request for batch '%s', does not exist in queue '%s'\n", cmd.batchResultId, cmd.queueId)
						}

					case batchExecQueueControlMove:
						var queue DeviceBatchQueue
						err := runner.rtdbServer.GetObject(cmd.queueId, &queue)
						if err != nil {
							log.Printf("[runner] WARNING: move command for non-existent queue '%s'", cmd.queueId)
							continue
						}

						found := false
						for srcNdx, enqueuedId := range queue.BatchResultIds {
							if enqueuedId == cmd.batchResultId {
								dstNdx := srcNdx + cmd.offset
								if srcNdx == 0 || dstNdx == 0 {
									// \todo [nuutti] Support moving running batch? We'd have to automatically
									//				  stop it first, which can be slow, so it could get confusing?
									log.Printf("[runner] WARNING: trying to move currently to/from running batch in queue\n")
								} else {
									if dstNdx < 0 || dstNdx >= len(queue.BatchResultIds) {
										log.Printf("[runner] WARNING: trying to move batch to position %d\n", dstNdx)
									} else {
										opSet := rtdb.NewOpSet()
										opSet.Call(typeDeviceBatchQueue, cmd.queueId, "Move", srcNdx, dstNdx)
										err := runner.rtdbServer.ExecuteOpSet(opSet)
										if err != nil { panic(err) }
									}
								}

								found = true
								break
							}
						}
						if !found {
							log.Printf("[runner] WARNING: move command for batch '%s', does not exist in queue '%s'\n", cmd.batchResultId, cmd.queueId)
						}

					case batchExecQueueControlExecutionLogQuery:
						var queue DeviceBatchQueue
						err := runner.rtdbServer.GetObject(cmd.queueId, &queue)
						if err != nil { cmd.dst <- runner.getBatchResultPastExecutionLog(cmd.batchResultId); continue }

						querySent := false
						for ndx, enqueueId := range queue.BatchResultIds {
							if enqueueId == cmd.batchResultId {
								if ndx == 0 {
									queueExecutionLogQuery[cmd.queueId] <- cmd.dst
									querySent = true
								}
								break
							}
						}
						if !querySent {
							cmd.dst <- runner.getBatchResultPastExecutionLog(cmd.batchResultId)
						}
				}

			case queueId := <-execEndSignal:
				var queue DeviceBatchQueue
				err := runner.rtdbServer.GetObject(queueId, &queue)
				if err != nil { panic(err) } // \note This shouldn't happen (a batch run ends while it's not even in the queue).

				opSet := rtdb.NewOpSet()
				opSet.Call(typeDeviceBatchQueue, queueId, "Remove", queue.BatchResultIds[0])
				err = runner.rtdbServer.ExecuteOpSet(opSet)
				if err != nil { panic(err) }

				if len(queue.BatchResultIds) > 1 { // \note queue is the queue before removal.
					launch(batchExecQueueControlEnqueue{
						batchResultId:	queue.BatchResultIds[1],
						queueId:		queueId,
					})
				}
		}
	}
}

// Batch import controlling utilities.

type batchImportControl interface {
}

type batchImportControlStarted struct {
	batchResultId	string
	stopChannel		chan<- struct{}
}

type batchImportControlFinished struct {
	batchResultId string
}

type batchImportControlStop struct {
	batchResultId string
}

func (runner *TestRunner) handleImports (importControl <-chan batchImportControl) {
	stopChannels := make(map[string]chan<- struct{})

	for {
		command := <-importControl
		switch cmd := command.(type) {
			case batchImportControlStarted:
				if _, alreadyExists := stopChannels[cmd.batchResultId]; alreadyExists {
					panic("[runner] Duplicate import for batch " + cmd.batchResultId)
				}
				stopChannels[cmd.batchResultId] = cmd.stopChannel

			case batchImportControlFinished:
				if _, exists := stopChannels[cmd.batchResultId]; !exists {
					panic("[runner] Non-existent import reported as finished for batch " + cmd.batchResultId)
				}
				delete(stopChannels, cmd.batchResultId)

			case batchImportControlStop:
				if stop, ok := stopChannels[cmd.batchResultId]; ok {
					stop <- struct{}{}
				} else {
					log.Printf("[runner] WARNING: tried to stop import for non-importing batch %s\n", cmd.batchResultId)
				}
		}
	}
}
