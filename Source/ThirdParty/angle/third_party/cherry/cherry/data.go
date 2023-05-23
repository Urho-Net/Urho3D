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
	"log"
	"reflect"
	"time"
	"../rtdb"
)

// CherryObjectSchemaVersion

type CherryObjectSchemaVersion struct {
	Value int `json:"value"`
}

func (version *CherryObjectSchemaVersion) PostLoad () {
}

func (version *CherryObjectSchemaVersion) Init () error {
	version.Value = 0
	return nil
}

func (version *CherryObjectSchemaVersion) Upgrade (newVersion int) error {
	if newVersion <= version.Value { panic("[data] trying to upgrade object schema to lower or equal version") }
	version.Value = newVersion
	return nil
}

// TestStatusCode

type TestStatusCode string

const (
	TEST_STATUS_CODE_PASS					= TestStatusCode("TSCPass")
	TEST_STATUS_CODE_FAIL					= TestStatusCode("TSCFail")
	TEST_STATUS_CODE_QUALITY_WARNING		= TestStatusCode("TSCQualityWarning")
	TEST_STATUS_CODE_COMPATIBILITY_WARNING	= TestStatusCode("TSCCompatibilityWarning")
	TEST_STATUS_CODE_PENDING				= TestStatusCode("TSCPending")
	TEST_STATUS_CODE_RUNNING				= TestStatusCode("TSCRunning")
	TEST_STATUS_CODE_NOT_SUPPORTED			= TestStatusCode("TSCNotSupported")
	TEST_STATUS_CODE_RESOURCE_ERROR			= TestStatusCode("TSCResourceError")
	TEST_STATUS_CODE_INTERNAL_ERROR			= TestStatusCode("TSCInternalError")
	TEST_STATUS_CODE_CANCELED				= TestStatusCode("TSCCanceled")
	TEST_STATUS_CODE_TIMEOUT				= TestStatusCode("TSCTimeout")
	TEST_STATUS_CODE_CRASH					= TestStatusCode("TSCCrash")
	TEST_STATUS_CODE_DISABLED				= TestStatusCode("TSCDisabled")
)

// TestCaseType

type TestCaseType string

const (
	TEST_CASE_TYPE_SELF_VALIDATE	= TestCaseType("SelfValidate")
	TEST_CASE_TYPE_PERFORMANCE		= TestCaseType("Performance")
	TEST_CASE_TYPE_ACCURACY			= TestCaseType("Accuracy")
	TEST_CASE_TYPE_CAPABILITY		= TestCaseType("Capability")
)

// DeviceConfig

type DeviceConfig struct {
	IsADBDevice			bool		`json:"isADBDevice"`
	ADBSerialNumber		string		`json:"adbSerialNumber"`

	Name				string		`json:"name"`
	TargetAddress		string		`json:"targetAddress"`
	TargetPort			int			`json:"targetPort"`
	CommandLine			string		`json:"commandLine"`

	LocalProcessPath	string		`json:"localProcessPath"`
	BinaryPath			string		`json:"binaryPath"`
	WorkingDir			string		`json:"workingDir"`
}

func (device *DeviceConfig) PostLoad () {
}

func (device *DeviceConfig) Init (src DeviceConfig) error {
	log.Printf("DeviceConfig.Init(%#v)", src)
	*device = src
	return nil
}

func (device *DeviceConfig) Delete () error {
	log.Printf("\\todo [petri] implement rtdb delete operation!\n")
	return nil
}

func (device *DeviceConfig) SetName (name string) error {
	device.Name = name
	return nil
}

// DeviceConfigHeader

type DeviceConfigHeader struct {
	Id string `json:"id"`
}

// DeviceConfigList
// \note Doesn't contain ADB devices. A list of currently connected ADB devices is maintained separately.

type DeviceConfigList struct {
	Devices		[]DeviceConfigHeader	`json:"devices"`
}

func (list *DeviceConfigList) PostLoad () {
	if list.Devices == nil {
		list.Devices = make([]DeviceConfigHeader, 0)
	}
}

func (list *DeviceConfigList) Init (devices []DeviceConfigHeader) error {
	if len(list.Devices) == 0 {
		list.Devices = devices
	}
	return nil
}

func (list *DeviceConfigList) Append (device DeviceConfigHeader) error {
	for ndx, dev := range list.Devices {
		if dev.Id == device.Id {
			list.Devices[ndx] = device
			return nil
		}
	}

	list.Devices = append(list.Devices, device)
	return nil
}

func (list *DeviceConfigList) Remove (deviceId string) error {
	for ndx, device := range list.Devices {
		if device.Id == deviceId {
			list.Devices = append(list.Devices[:ndx], list.Devices[ndx+1:]...)
			return nil
		}
	}

	return nil
}

// TestCaseResult

type TestCaseResult struct {
	Path			string			`json:"path"`
	Log				string			`json:"log"`
}

func (result *TestCaseResult) PostLoad () {
}

func (result *TestCaseResult) Init (src TestCaseResult) error {
	*result = src
	return nil
}

func (result *TestCaseResult) SetLog (log string) error {
	result.Log = log
	return nil
}

// TestCaseHeader

type TestCaseHeader struct {
	CaseType	TestCaseType	`json:"caseType"`
	Status		TestStatusCode	`json:"status"`
	Result		string			`json:"result"`
}

func (header *TestCaseHeader) PostLoad () {
}

func (header *TestCaseHeader) Init (src TestCaseHeader) error {
	*header = src
	return nil
}

func (header *TestCaseHeader) SetStatus (status TestStatusCode) error {
	header.Status = status
	return nil
}

func (header *TestCaseHeader) SetResult (caseType TestCaseType, status TestStatusCode, result string) error {
	header.CaseType		= caseType
	header.Status		= status
	header.Result		= result
	return nil
}

// TestCaseTreeGroup

type TestCaseTreeGroup struct {
	NumSuccess				int			`json:"numSuccess"`
	NumFailure				int			`json:"numFailure"`
	NumCrash				int			`json:"numCrash"`
	NumTimeout				int			`json:"numTimeout"`
	NumQualityWarning		int			`json:"numQualityWarning"`
	NumCompatibilityWarning	int			`json:"numCompatibilityWarning"`
	NumNotSupported			int			`json:"numNotSupported"`
	NumResourceError		int			`json:"numResourceError"`
	NumInternalError		int			`json:"numInternalError"`
	NumTotalCases			int			`json:"numTotalCases"`
}

func (group *TestCaseTreeGroup) PostLoad () {
}

func (group *TestCaseTreeGroup) Init (src TestCaseTreeGroup) error {
	*group = src
	return nil
}

func (group *TestCaseTreeGroup) AddCase () error {
	group.NumTotalCases++
	return nil
}

func (group *TestCaseTreeGroup) UpdateStats (delta TestCaseTreeGroupStatusDelta) error {
	group.NumSuccess				+= delta.DeltaSuccess;
	group.NumFailure				+= delta.DeltaFailure;
	group.NumCrash				    += delta.DeltaCrash;
	group.NumTimeout				+= delta.DeltaTimeout;
	group.NumQualityWarning		    += delta.DeltaQualityWarning;
	group.NumCompatibilityWarning	+= delta.DeltaCompatibilityWarning;
	group.NumNotSupported			+= delta.DeltaNotSupported;
	group.NumResourceError		    += delta.DeltaResourceError;
	group.NumInternalError		    += delta.DeltaInternalError;
	return nil
}

func (group *TestCaseTreeGroup) NumResults () int {
	return  group.NumSuccess				+
			group.NumFailure				+
			group.NumCrash					+
			group.NumTimeout				+
			group.NumQualityWarning			+
			group.NumCompatibilityWarning	+
			group.NumNotSupported			+
			group.NumResourceError			+
			group.NumInternalError
}

// TestCaseTreeGroupStatusDelta

type TestCaseTreeGroupStatusDelta struct {
	DeltaSuccess				int			`json:"deltaSuccess"`
	DeltaFailure				int			`json:"deltaFailure"`
	DeltaCrash					int			`json:"deltaCrash"`
	DeltaTimeout				int			`json:"deltaTimeout"`
	DeltaQualityWarning			int			`json:"deltaQualityWarning"`
	DeltaCompatibilityWarning	int			`json:"deltaCompatibilityWarning"`
	DeltaNotSupported			int			`json:"deltaNotSupported"`
	DeltaResourceError			int			`json:"deltaResourceError"`
	DeltaInternalError			int			`json:"deltaInternalError"`
}

// BatchExecParams

type BatchExecParams struct {
	TargetAddress			string		`json:"targetAddress"`		// Target network address.
	TargetPort				int			`json:"targetPort"`			// Target network port.
	SpawnLocalProcess		string		`json:"spawnLocalProcess"`
	DeviceId				string		`json:"deviceId"`

	TestBinaryName			string		`json:"testBinaryName"`
	TestBinaryCommandLine	string		`json:"testBinaryCommandLine"`
	TestBinaryWorkingDir	string		`json:"testBinaryWorkingDir"`

	// \todo [2017-05-18 kraita]: This field is relevant for 1/3 batch
	// launch types. I didn't find any code actually reading the field
	// from the DB for anything useful. Should nuke the field altogether.
	TestNameFilters			[]string	`json:"testNameFilters"`	// Filters for test case names (only execute matching).
}

// BatchStatusCode

type BatchStatusCode string

const (
	BATCH_STATUS_CODE_INITIALIZING	= BatchStatusCode("BSCInitializing")
	BATCH_STATUS_CODE_IMPORTING		= BatchStatusCode("BSCImporting")
	BATCH_STATUS_CODE_PENDING		= BatchStatusCode("BSCPending")
	BATCH_STATUS_CODE_RUNNING		= BatchStatusCode("BSCRunning")
	BATCH_STATUS_CODE_FINISHED		= BatchStatusCode("BSCFinished")
	BATCH_STATUS_CODE_CANCELED		= BatchStatusCode("BSCCanceled")
	BATCH_STATUS_CODE_INTERRUPTED	= BatchStatusCode("BSCInterrupted")
)

// TestCaseList
// \note A test case list is logically a part of a batch result; the
//		 test case list of a batch result has the same id as the batch
//		 result. Test case lists are not stored with batch results because
//		 batch results may get frequent status updates, and test case
//		 lists can be rather big.

type TestCaseList struct {
	Paths []string `json:"paths"`
}

func (list *TestCaseList) PostLoad () {
	if list.Paths == nil {
		list.Paths = make([]string, 0)
	}
}

func (list *TestCaseList) Init (src TestCaseList) error {
	*list = src
	return nil
}

func (list *TestCaseList) Append (path string) error {
	list.Paths = append(list.Paths, path)
	return nil
}

// BatchResult

type BatchResult struct {
	Name				string				`json:"name"`
	ExecParams			BatchExecParams		`json:"execParams"`
	Status				BatchStatusCode		`json:"status"`
	Timestamp			time.Time			`json:"timestamp"`

	// Only relevant if the batch is being initialized or imported.
	// Between 0.0 and 1.0.
	InitProgress		float32				`json:"initProgress"`

	// \note ReleaseName, ReleaseId and BuildTargetName are session
	// info written by the test executable.
	ReleaseName			string				`json:"releaseName"`
	ReleaseId			string				`json:"releaseId"`
	BuildTargetName		string				`json:"buildTargetName"`

	// \note The following values are only relevant for Candy.
	//		 In Cherry, they're stored because we don't want to
	//		 lose them if we import and then export a log
	//		 originating from Candy. For batches results created
	//		 by Cherry these will be empty.
	CandyTargetName		string				`json:"candyTargetName"`
	CandyConfigName		string				`json:"candyConfigName"`
}

func (result *BatchResult) PostLoad () {
	if result.ExecParams.TestNameFilters == nil {
		result.ExecParams.TestNameFilters = make([]string, 0)
	}
}

func (result *BatchResult) Init (src BatchResult) error {
	*result = src
	return nil
}

func (result *BatchResult) SetName (name string) error {
	result.Name = name
	return nil
}

func (result *BatchResult) SetStatus (status BatchStatusCode) error {
	result.Status = status
	return nil
}

func (result *BatchResult) SetSessionInfo (info BatchSessionInfo) error {
	if result.Name == ""					{ result.Name				= info.ResultName }
	if result.Timestamp == (time.Time{})	{ result.Timestamp			= info.Timestamp }
	if result.ReleaseName == ""				{ result.ReleaseName		= info.ReleaseName }
	if result.ReleaseId == ""				{ result.ReleaseId			= info.ReleaseId }
	if result.BuildTargetName == ""			{ result.BuildTargetName	= info.BuildTargetName }
	if result.CandyTargetName == ""			{ result.CandyTargetName	= info.CandyTargetName }
	if result.CandyConfigName == ""			{ result.CandyConfigName	= info.CandyConfigName }

	if result.ExecParams.TargetAddress == ""			{ result.ExecParams.TargetAddress = info.TargetAddress }
	if result.ExecParams.TargetPort == 0				{ result.ExecParams.TargetPort = info.TargetPort }
	if result.ExecParams.SpawnLocalProcess == ""		{ result.ExecParams.SpawnLocalProcess = info.SpawnLocalProcess }
	if result.ExecParams.DeviceId == ""					{ result.ExecParams.DeviceId = info.DeviceId }

	if result.ExecParams.TestBinaryName == ""			{ result.ExecParams.TestBinaryName = info.TestBinaryName }
	if result.ExecParams.TestBinaryCommandLine == ""	{ result.ExecParams.TestBinaryCommandLine = info.TestBinaryCommandLine }
	if result.ExecParams.TestBinaryWorkingDir == ""		{ result.ExecParams.TestBinaryWorkingDir = info.TestBinaryWorkingDir }

	return nil
}

func (result *BatchResult) SetInitProgress (progress float32) error {
	result.InitProgress = progress
	return nil
}

// BatchResultHeader

type BatchResultHeader struct {
	Id			string			`json:"id"`
	Name		string			`json:"name"`
}

func (header *BatchResultHeader) PostLoad () {
}

// BatchResultExecutionLog
// Per batch result; ID is the same as the batch result's.
// \note Because these can become rather big and can get frequent updates,
//		 the test runner only appends the last part (i.e. the part starting
//		 at the start of the current execution of the batch, due to e.g.
//		 starting a new batch or continuing a partially-executed batch) to
//		 the DB object when the batch execution ends (due to e.g. the test
//		 run being finished or stopped). Until that, the last part is only
//		 kept and updated in memory. This also means that if Cherry crashes
//		 while a batch is being executed, its execution log will lose the
//		 last part.

type BatchResultExecutionLog struct {
	Content string `json:"content"`
}

func (log *BatchResultExecutionLog) PostLoad () {
}

func (log *BatchResultExecutionLog) Init () error {
	log.Content = ""
	return nil
}

func (log *BatchResultExecutionLog) Append (part string) error {
	log.Content += part
	return nil
}

// BatchResultList

type BatchResultList struct {
	BatchResults	[]BatchResultHeader		`json:"batchResults"`
}

func (list *BatchResultList) PostLoad () {
	if list.BatchResults == nil {
		list.BatchResults = make([]BatchResultHeader, 0)
	}
}

func (list *BatchResultList) Init () error {
	if list.BatchResults == nil {
		list.BatchResults = make([]BatchResultHeader, 0)
	}
	log.Printf("BatchResultList.Init(): %q\n", list.BatchResults)
	return nil
}

func (list *BatchResultList) Append (result BatchResultHeader) error {
	list.BatchResults = append(list.BatchResults, result)
	return nil
}

func (list *BatchResultList) SetBatchResultName (id string, name string) error {
	for ndx, result := range list.BatchResults {
		if result.Id == id {
			list.BatchResults[ndx].Name = name
			return nil
		}
	}

	return fmt.Errorf("[data] WARNING: trying to set name of unknown batchResultId '%s'", id)
}

// ActiveBatchResultList

type ActiveBatchResultList struct {
	BatchResultIds	[]string	`json:"batchResultIds"`
}

func (list *ActiveBatchResultList) PostLoad () {
	if list.BatchResultIds == nil {
		list.BatchResultIds = make([]string, 0)
	}
}

func (list *ActiveBatchResultList) Init () error {
	if list.BatchResultIds == nil {
		list.BatchResultIds = make([]string, 0)
	}
	log.Printf("ActiveBatchResultList.Init(): %q\n", list.BatchResultIds)
	return nil
}

func (list *ActiveBatchResultList) Append (resId string) error {
	for _, id := range list.BatchResultIds {
		if id == resId {
			return fmt.Errorf("[data] WARNING: trying to append duplicate batch result '%s' to active batch results", resId)
		}
	}

	list.BatchResultIds = append(list.BatchResultIds, resId)
	return nil
}

func (list *ActiveBatchResultList) Remove (resId string) error {
	for ndx, id := range list.BatchResultIds {
		if id == resId {
			list.BatchResultIds = append(list.BatchResultIds[:ndx], list.BatchResultIds[ndx+1:]...)
			return nil
		}
	}

	return fmt.Errorf("[data] WARNING: trying to remove unknown batch result '%s' from active batch results", resId)
}

func (list *ActiveBatchResultList) Clear () error {
	list.BatchResultIds = make([]string, 0)
	return nil
}

// TestSetHeader
type TestSetHeader struct {
	Id			string			`json:"id"`
	Name		string			`json:"name"`
}

func (header *TestSetHeader) PostLoad () {
}

func (testSet *TestSetHeader) Init (src TestSetHeader) error {
	*testSet = src
	return nil
}

// TestSet
type TestSet struct {
	Id			string			`json:"id"`
	Name		string			`json:"name"`
	Filters		[]string		`json:"filters"`
}

func (testSet *TestSet) PostLoad () {
	if testSet.Filters == nil {
		testSet.Filters = make([]string, 0)
	}
}

func (testSet *TestSet) Init (src TestSet) error {
	*testSet = src
	return nil
}

func (device *TestSet) Delete () error {
	log.Printf("\\todo [kraita] implement rtdb delete operation!\n")
	return nil
}

// TestSetList
type TestSetList struct {
	TestSetHeaders	[]TestSetHeader	`json:"testSetHeaders"`
}

func (list *TestSetList) PostLoad () {
	if list.TestSetHeaders == nil {
		list.TestSetHeaders = make([]TestSetHeader, 0)
	}
}

func (list *TestSetList) Init () error {
	if list.TestSetHeaders == nil {
		list.TestSetHeaders = make([]TestSetHeader, 0)
	}
	log.Printf("TestSetList.Init(): Loaded %d\n", len(list.TestSetHeaders))
	return nil
}

func (list *TestSetList) Append (setHeader TestSetHeader) error {
	list.TestSetHeaders = append(list.TestSetHeaders, setHeader)
	return nil
}

func (list *TestSetList) Remove (testSetId string) error {
	for ndx, header := range list.TestSetHeaders {
		if header.Id == testSetId {
			list.TestSetHeaders = append(list.TestSetHeaders[:ndx], list.TestSetHeaders[ndx+1:]...)
			return nil
		}
	}
	return fmt.Errorf("[data] WARNING: trying to remove unknown test set '%s' from the test set list", testSetId)
}

// DeviceBatchQueue

type DeviceBatchQueue struct {
	BatchResultIds []string `json:"batchResultIds"`
}

func (queue *DeviceBatchQueue) PostLoad () {
	if queue.BatchResultIds == nil {
		queue.BatchResultIds = make([]string, 0)
	}
}

func (queue *DeviceBatchQueue) Init () error {
	queue.BatchResultIds = make([]string, 0)
	return nil
}

func (queue *DeviceBatchQueue) Append (resultId string) error {
	queue.BatchResultIds = append(queue.BatchResultIds, resultId)
	return nil
}

func (queue *DeviceBatchQueue) Remove (resultId string) error {
	for ndx, id := range queue.BatchResultIds {
		if id == resultId {
			queue.BatchResultIds = append(queue.BatchResultIds[:ndx], queue.BatchResultIds[ndx+1:]...)
			return nil
		}
	}

	return fmt.Errorf("[data] WARNING: trying to remove unknown batch result '%s' from a device batch queue", resultId)
}

func (queue *DeviceBatchQueue) Move (srcNdx int, dstNdx int) error {
	if srcNdx < 0 || srcNdx >= len(queue.BatchResultIds) {
		return fmt.Errorf("Trying to move batch result at index %d in queue of length %d", srcNdx, len(queue.BatchResultIds))
	} else if dstNdx < 0 || dstNdx >= len(queue.BatchResultIds) {
		return fmt.Errorf("Trying to move batch result to index %d in queue of length %d", dstNdx, len(queue.BatchResultIds))
	}

	elem := queue.BatchResultIds[srcNdx]
	if srcNdx < dstNdx {
		for ndx := srcNdx; ndx < dstNdx; ndx++ {
			queue.BatchResultIds[ndx] = queue.BatchResultIds[ndx+1]
		}
	} else {
		for ndx := srcNdx; ndx > dstNdx; ndx-- {
			queue.BatchResultIds[ndx] = queue.BatchResultIds[ndx-1]
		}
	}
	queue.BatchResultIds[dstNdx] = elem
	return nil
}

func (queue *DeviceBatchQueue) Clear () error {
	queue.BatchResultIds = make([]string, 0)
	return nil
}

// DeviceBatchQueueList

type DeviceBatchQueueList struct {
	QueueIds []string `json:"queueIds"`
}

func (list *DeviceBatchQueueList) PostLoad () {
	if list.QueueIds == nil {
		list.QueueIds = make([]string, 0)
	}
}

func (list *DeviceBatchQueueList) Init () error {
	if list.QueueIds == nil {
		list.QueueIds = make([]string, 0)
	}
	log.Printf("DeviceBatchQueueList.Init(): %q\n", list.QueueIds)
	return nil
}

func (list *DeviceBatchQueueList) Append (queueId string) error {
	list.QueueIds = append(list.QueueIds, queueId)
	return nil
}

// ADBDeviceConnection

type ADBDeviceConnection struct {
	// \note DeviceId is derived from, but not equal to, the serial number reported by
	//		 ADB. The serial number is in the DeviceConfig with id DeviceId.
	DeviceId		string `json:"deviceId"`
	State			string `json:"state"`
}

// ADBDeviceConnectionList

type ADBDeviceConnectionList struct {
	Connections		[]ADBDeviceConnection	`json:"connections"`
	// Error can inform about unavailability of ADB, for instance. Error is empty if all is OK.
	Error			string					`json:"error"`
}

func (list *ADBDeviceConnectionList) PostLoad () {
	if list.Connections == nil {
		list.Connections = make([]ADBDeviceConnection, 0)
	}
}

func (list *ADBDeviceConnectionList) Clear () error {
	list.Connections	= make([]ADBDeviceConnection, 0)
	list.Error			= ""
	return nil
}

func (list *ADBDeviceConnectionList) SetError (e string) error {
	list.Error = e
	return nil
}

func (list *ADBDeviceConnectionList) SetConnectionState (ndx int, state string) error {
	list.Connections[ndx].State = state
	return nil
}

func (list *ADBDeviceConnectionList) Remove (ndx int) error {
	list.Connections = append(list.Connections[:ndx], list.Connections[ndx+1:]...)
	return nil
}

func (list *ADBDeviceConnectionList) Append (connection ADBDeviceConnection) error {
	list.Connections = append(list.Connections, connection)
	return nil
}

// Object types.

var (
	typeDeviceConfig				= reflect.TypeOf((*DeviceConfig)(nil)).Elem()
	typeDeviceConfigHeader			= reflect.TypeOf((*DeviceConfigHeader)(nil)).Elem()
	typeDeviceConfigList			= reflect.TypeOf((*DeviceConfigList)(nil)).Elem()
	typeTestCaseResult				= reflect.TypeOf((*TestCaseResult)(nil)).Elem()
	typeTestCaseHeader				= reflect.TypeOf((*TestCaseHeader)(nil)).Elem()
	typeTestCaseTreeGroup			= reflect.TypeOf((*TestCaseTreeGroup)(nil)).Elem()
	typeTestCaseList				= reflect.TypeOf((*TestCaseList)(nil)).Elem()
	typeBatchResult					= reflect.TypeOf((*BatchResult)(nil)).Elem()
	typeBatchResultHeader			= reflect.TypeOf((*BatchResultHeader)(nil)).Elem()
	typeBatchResultExecutionLog		= reflect.TypeOf((*BatchResultExecutionLog)(nil)).Elem()
	typeBatchResultList				= reflect.TypeOf((*BatchResultList)(nil)).Elem()
	typeActiveBatchResultList		= reflect.TypeOf((*ActiveBatchResultList)(nil)).Elem()
	typeDeviceBatchQueue			= reflect.TypeOf((*DeviceBatchQueue)(nil)).Elem()
	typeDeviceBatchQueueList		= reflect.TypeOf((*DeviceBatchQueueList)(nil)).Elem()
	typeADBDeviceConnectionList		= reflect.TypeOf((*ADBDeviceConnectionList)(nil)).Elem()
	typeCherryObjectSchemaVersion	= reflect.TypeOf((*CherryObjectSchemaVersion)(nil)).Elem()
	typeTestSetHeader				= reflect.TypeOf((*TestSetHeader)(nil)).Elem()
	typeTestSet						= reflect.TypeOf((*TestSet)(nil)).Elem()
	typeTestSetList					= reflect.TypeOf((*TestSetList)(nil)).Elem()
)

// Return all RTDB object types used by Cherry.

func GetObjectTypes () []reflect.Type {
	return []reflect.Type {
		typeDeviceConfig,
		typeDeviceConfigList,
		typeTestCaseResult,
		typeTestCaseHeader,
		typeTestCaseTreeGroup,
		typeTestCaseList,
		typeBatchResult,
		typeBatchResultHeader,
		typeBatchResultExecutionLog,
		typeBatchResultList,
		typeActiveBatchResultList,
		typeDeviceBatchQueue,
		typeDeviceBatchQueueList,
		typeADBDeviceConnectionList,
		typeCherryObjectSchemaVersion,
		typeTestSetHeader,
		typeTestSet,
		typeTestSetList,
	}
}

// InitDB
func InitDB (rtdbServer *rtdb.Server) {
	upgradeObjectSchema(rtdbServer)

	// Empty the ADB device connection list.
	// \todo [nuutti] There's no point in saving temporary objects like this to the DB.
	//				  Implement support for runtime-only objects?
	{
		opSet := rtdb.NewOpSet()
		opSet.Call(typeADBDeviceConnectionList, "adbDeviceConnectionList", "Clear")
		err := rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	// Initialize empty active & full batch result lists, as well as device batch queue list.
	{
		opSet := rtdb.NewOpSet()
		opSet.Call(typeBatchResultList,			"batchResultList",			"Init")
		opSet.Call(typeActiveBatchResultList,	"activeBatchResultList",	"Init")
		opSet.Call(typeDeviceBatchQueueList,	"deviceBatchQueueList",		"Init")
		opSet.Call(typeTestSetList,				"testSetList",				"Init")
		err := rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}

	// Init device list.
	{
		devices := []DeviceConfig {
			DeviceConfig {
				Name:				"Localhost",
				TargetAddress:		"127.0.0.1",
				TargetPort:			50016,
				CommandLine:		"--deqp-watchdog=enable --deqp-crashhandler=enable --deqp-visibility=hidden --deqp-gl-config-name=rgba8888d24s8ms0",

				LocalProcessPath:	"../candy-build/deqp-wgl/execserver/Release/execserver.exe",
				BinaryPath:			"Debug/${TestPackageName}.exe",
				WorkingDir:			"../candy-build/deqp-wgl/modules/${TestPackageDir}",
			},
		}

		// Initialize device config list.
		// \todo [petri] implement me -- should never destroy anything?

		// Insert devices into db one-by-one.
		// \note uses name as id for built-in devices!
		for _, device := range devices {
			deviceId := device.Name

			opSet := rtdb.NewOpSet()
			opSet.Call(typeDeviceConfig, deviceId, "Init", device)
			opSet.Call(typeDeviceConfigList, "deviceConfigList", "Append", DeviceConfigHeader{ deviceId })
			err := rtdbServer.ExecuteOpSet(opSet)
			if err != nil { panic(err) }
		}
	}

	// Clear existing device batch queues.
	{
		var deviceBatchQueues DeviceBatchQueueList
		err := rtdbServer.GetObject("deviceBatchQueueList", &deviceBatchQueues)
		if err != nil { panic(err) }

		for _, queueId := range deviceBatchQueues.QueueIds {
			opSet := rtdb.NewOpSet()
			opSet.Call(typeDeviceBatchQueue, queueId, "Clear")
			err := rtdbServer.ExecuteOpSet(opSet)
			if err != nil { panic(err) }
		}
	}

	// Mark all batches in activeBatchResultList as interrupted and remove from the list.
	// Also mark any "running" test cases in those interrupted batch results as "pending".
	{
		var activeBatchResults ActiveBatchResultList
		err := rtdbServer.GetObject("activeBatchResultList", &activeBatchResults)
		if err != nil { panic(err) }

		opSet := rtdb.NewOpSet()

		for _, batchResultId := range activeBatchResults.BatchResultIds {
			var batchResult BatchResult
			err := rtdbServer.GetObject(batchResultId, &batchResult)
			if err != nil { panic(err) }

			if batchResult.Status == BATCH_STATUS_CODE_INITIALIZING {
				// Initialization of the batch didn't finish; finish it now.
				initOps := batchResultHierarchyInitOps(rtdbServer, batchResultId)
				// \todo [petri] use proper merge -- this overwrites opList in case of duplicates!
				for target, opList := range initOps.ObjectOps {
					opSet.ObjectOps[target] = opList
				}
			} else if batchResult.Status == BATCH_STATUS_CODE_RUNNING {
				// There may be "running" cases in this batch; mark them as pending.

				var testCaseList TestCaseList
				err := rtdbServer.GetObject(batchResultId, &testCaseList)
				if err != nil { panic(err) }

				for _, testCasePath := range testCaseList.Paths {
					caseObjId := batchResultId + "/" + testCasePath

					var header TestCaseHeader
					err := rtdbServer.GetObject(caseObjId, &header)
					if err != nil { panic(err) }

					if header.Status == TEST_STATUS_CODE_RUNNING {
						opSet.Call(typeTestCaseHeader, caseObjId, "SetStatus", TEST_STATUS_CODE_PENDING)
					}
				}

				opSet.Call(typeBatchResultExecutionLog, batchResultId, "Append", "WARNING: batch result was interrupted while it was running; execution log may be incomplete\n")
			} // else: batch must have been pending or importing when it was interrupted; we don't need to touch the test cases.

			opSet.Call(typeBatchResult, batchResultId, "SetStatus", BATCH_STATUS_CODE_INTERRUPTED)
		}

		opSet.Call(typeActiveBatchResultList, "activeBatchResultList", "Clear")
		err = rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }
	}
}

// Return operations to initialize the test header, result, and tree node objects for the given batch.
func batchResultHierarchyInitOps (rtdbServer *rtdb.Server, batchResultId string) rtdb.ObjectOpSet {
	// Get batch result info.
	var testCaseList TestCaseList
	err := rtdbServer.GetObject(batchResultId, &testCaseList)
	if err != nil { panic(err) } // \todo [petri] better handling?

	// Create init ops for test case header and result objects.

	opSet := rtdb.NewOpSet()

	for _, testCasePath := range testCaseList.Paths {
		testCaseHeader := TestCaseHeader {
			CaseType:	"",
			Status:		TEST_STATUS_CODE_PENDING,
			Result:		"",
		}

		testCaseResult := TestCaseResult {
			Path:	testCasePath,
			Log:	"",
		}

		caseObjId := batchResultId + "/" + testCasePath
		opSet.Call(typeTestCaseHeader, caseObjId, "Init", testCaseHeader)
		opSet.Call(typeTestCaseResult, caseObjId, "Init", testCaseResult)
	}

	// Create init ops for tree node initialization.

	treeNodeInfos := computeTestCaseTreeNodes(testCaseList.Paths)

	for _, nodeInfo := range treeNodeInfos {
		group := TestCaseTreeGroup {
			NumTotalCases:	nodeInfo.numTotalCases,
		}
		objId := batchResultId + "/" + nodeInfo.path
		opSet.Call(typeTestCaseTreeGroup, objId, "Init", group)
	}

	return opSet
}

// Object schema version upgrades.
// \note Merely adding fields to an existing object type usually doesn't
//		 necessitate a schema upgrade, unless those fields need to have
//		 some specific initial value or something.

// Object types changed since version 0.

type Version0BatchResult struct {
	Id					string				`json:"id"`
	Name				string				`json:"name"`
	ExecParams			BatchExecParams		`json:"execParams"`
	Status				BatchStatusCode		`json:"status"`
	TestCasePaths		[]string			`json:"testCasePaths"`
}

func (result *Version0BatchResult) PostLoad () {
	if result.TestCasePaths == nil {
		result.TestCasePaths = make([]string, 0)
	}
}

var version0BatchResultTypeName = "BatchResult"

// Object types changed since version 1.

type Version1DeviceBatchQueueList struct {
	DeviceIds []string `json:"deviceIds"`
}

func (list *Version1DeviceBatchQueueList) PostLoad () {
	if list.DeviceIds == nil {
		list.DeviceIds = make([]string, 0)
	}
}

var version1DeviceBatchQueueListName = "DeviceBatchQueueList"

// Successively upgrade the schema to the newest version, if needed.
func upgradeObjectSchema (rtdbServer *rtdb.Server) {
	var currentVersion int
	{
		var versionObj CherryObjectSchemaVersion
		err := rtdbServer.GetObject("cherryObjectSchemaVersion", &versionObj)
		if err != nil {
			// Schema version object didn't yet exist in version 0.
			currentVersion = 0
		} else {
			currentVersion = versionObj.Value
		}
	}

	// Upgrade functions in appropriate order.
	// \note These are not supposed to update cherryObjectSchemaVersion,
	//		 that's done by the loop below.
	objectSchemaUpgradeOps := []func () rtdb.ObjectOpSet {
		// Version 0 to 1.
		func () rtdb.ObjectOpSet {
			// Changes:
			// - create a TestCaseList for each BatchResult, corresponding
			//	 to the BatchResult's TestCasePaths
			// - drop the Id and TestCasePaths members from each BatchResult

			opSet := rtdb.NewOpSet()

			var batchResultList BatchResultList
			err := rtdbServer.GetObject("batchResultList", &batchResultList)
			if err != nil { return opSet /* No batch result list -> nothing to do. This is ok. */ }

			for _, header := range batchResultList.BatchResults {
				var batchResultV0 Version0BatchResult
				objKey := rtdb.TypedObject{ Type: version0BatchResultTypeName, ObjId: header.Id }
				err := rtdbServer.GetExplicitTypeObject(objKey, &batchResultV0)
				if err != nil { panic(err) }

				batchResultV1 := BatchResult {
					Name:			batchResultV0.Name,
					ExecParams:		batchResultV0.ExecParams,
					Status:			batchResultV0.Status,
				}

				testCaseList := TestCaseList {
					Paths: batchResultV0.TestCasePaths,
				}

				opSet.Call(typeBatchResult, header.Id, "Init", batchResultV1)
				opSet.Call(typeTestCaseList, header.Id, "Init", testCaseList)
			}

			return opSet
		},

		// Version 1 to 2.
		func () rtdb.ObjectOpSet {
			// Changes:
			// - rename DeviceBatchQueueList's deviceIds to queueIds

			opSet := rtdb.NewOpSet()

			var deviceBatchQueueListV1 Version1DeviceBatchQueueList
			objKey := rtdb.TypedObject{ Type: version1DeviceBatchQueueListName, ObjId: "deviceBatchQueueList" }
			err := rtdbServer.GetExplicitTypeObject(objKey, &deviceBatchQueueListV1)
			if err != nil { return opSet }

			opSet.Call(typeDeviceBatchQueueList, "deviceBatchQueueList", "Init")
			for _, queueId := range deviceBatchQueueListV1.DeviceIds {
				opSet.Call(typeDeviceBatchQueueList, "deviceBatchQueueList", "Append", queueId)
			}

			return opSet
		},

		// Version 2 to 3.
		func () rtdb.ObjectOpSet {
			// Changes:
			// - add DeviceId field to batch results.
			//	 For old results that don't have those, we create an "Unknown" device.

			opSet := rtdb.NewOpSet()

			var batchResultList BatchResultList
			err := rtdbServer.GetObject("batchResultList", &batchResultList)
			if err != nil { return opSet }

			unknownDeviceNeeded		:= false
			unknownDeviceId			:= "Unknown"
			unknownDeviceName		:= "Unknown"

			for _, header := range batchResultList.BatchResults {
				var batchResult BatchResult
				err := rtdbServer.GetObject(header.Id, &batchResult)
				if err != nil { panic(err) }

				if batchResult.ExecParams.DeviceId == "" {
					batchResult.ExecParams.DeviceId = unknownDeviceId
					opSet.Call(typeBatchResult, header.Id, "Init", batchResult)
					unknownDeviceNeeded = true
				}
			}

			if unknownDeviceNeeded {
				opSet.Call(typeDeviceConfig, "Unknown", "Init", DeviceConfig { Name: unknownDeviceName })
				opSet.Call(typeDeviceConfigList, "deviceConfigList", "Append", DeviceConfigHeader{ Id: unknownDeviceId })
			}

			return opSet
		},

		// Version 3 to 4.
		func () rtdb.ObjectOpSet {
			// Changes:
			// - add a (initially empty) BatchResultExecutionLog for each BatchResult

			opSet := rtdb.NewOpSet()

			var batchResultList BatchResultList
			err := rtdbServer.GetObject("batchResultList", &batchResultList)
			if err != nil { return opSet }

			for _, header := range batchResultList.BatchResults {
				opSet.Call(typeBatchResultExecutionLog, header.Id, "Init")
			}

			return opSet
		},

		// \note When you make a new version, if it changes the object types
		//		 used in some of the existing schema upgrades, make sure to
		//		 make upgrade-specific copies of those. For example,
		//		 upgradeObjectSchemaVersion0To1 uses BatchResult; if that is
		//		 modified, a Version1BatchResult will be needed.
	}

	requiredUpgradeOps := objectSchemaUpgradeOps[currentVersion:]
	// \todo If upgrades are going to be done, backup the DB in case something goes wrong.

	// Perform all required upgrades.
	for _, upgradeOps := range requiredUpgradeOps {
		log.Printf("[data] upgrading object schema from version %d to %d\n", currentVersion, currentVersion+1)

		opSet := upgradeOps()
		if currentVersion == 0 {
			opSet.Call(typeCherryObjectSchemaVersion, "cherryObjectSchemaVersion", "Init")
		}
		opSet.Call(typeCherryObjectSchemaVersion, "cherryObjectSchemaVersion", "Upgrade", currentVersion+1)
		err := rtdbServer.ExecuteOpSet(opSet)
		if err != nil { panic(err) }

		currentVersion += 1
	}
}
