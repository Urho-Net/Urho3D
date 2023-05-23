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
	"log"
	"../rtdb"
	"strings"
	"time"
	"fmt"
)

type Void struct {}

// RPCHandler

type RPCHandler struct {
	rtdbServer	*rtdb.Server
	testRunner	*TestRunner
}

func NewRPCHandler (rtdbServer *rtdb.Server, testRunner *TestRunner) *RPCHandler {
	return &RPCHandler {
		rtdbServer: rtdbServer,
		testRunner:	testRunner,
	}
}

// RPCClient

type RPCClient struct {
	listener	*rtdb.Listener
}

func NewRPCClient (listener *rtdb.Listener) *RPCClient {
	return &RPCClient {
		listener:	listener,
	}
}

// Subscribe

type SubscribeArgs struct {
	Objects		[]rtdb.TypedObject	`json:"objects"`
}

func (handler *RPCHandler) Subscribe (client *RPCClient, args SubscribeArgs) (bool, error) {
	log.Printf("[rpc] subscribe %d objects\n", len(args.Objects))

	// Subscribe to object.
	err := client.listener.Subscribe(args.Objects)
	if err != nil { return false, err }

	return true, nil
}

// Unsubsribe

type UnsubscribeArgs struct {
	Objects		[]rtdb.TypedObject	`json:"objects"`
}

func (handler *RPCHandler) Unsubscribe (client *RPCClient, args UnsubscribeArgs) (bool, error) {
	log.Printf("[rpc] unsubscribe %d objects\n", len(args.Objects))
	err := client.listener.Unsubscribe(args.Objects)
	return err == nil, err
}

// ExecuteTestBatch

type DeviceConfigArgs struct {
	TargetAddress			string					`json:"targetAddress"`
	TargetPort				int						`json:"targetPort"`
	SpawnLocalProcess		string					`json:"spawnLocalProcess"`
	DeviceId				string					`json:"deviceId"`
}

type TestPackageConfigArgs struct {
	TestBinaryName			string					`json:"testBinaryName"`
	TestBinaryCommandLine	string					`json:"testBinaryCommandLine"`
	TestBinaryWorkingDir	string					`json:"testBinaryWorkingDir"`
}

// \todo [2017-03-15 kraita] Embedded structs could be replaced by object references?
type ExecuteTestBatchArgs struct {
	DeviceConfig			DeviceConfigArgs		`json:"deviceConfig"`
	TestPackageConfig 		TestPackageConfigArgs	`json:"testPackageConfig"`
	TestNameFilters			string					`json:"testNameFilters"`
}

func getDefaultBatchName () string {
	return time.Now().Format(defaultHumanReadableTimeFormat)
}

func (handler *RPCHandler) ExecuteTestBatch (client *RPCClient, args ExecuteTestBatchArgs) (string, error) {
	log.Println("[rpc] ExecuteTestBatch requested")

	// Check that the specified device exists.
	err := handler.rtdbServer.GetObject(args.DeviceConfig.DeviceId, &DeviceConfig{})
	if err != nil { return "", err }

	// Generate time-based id for batch result.
	startTime := time.Now()

	// Execute tests in background.
	execParams := BatchExecParams {
		TargetAddress:			args.DeviceConfig.TargetAddress,
		TargetPort:				args.DeviceConfig.TargetPort,
		SpawnLocalProcess:		args.DeviceConfig.SpawnLocalProcess,
		DeviceId:				args.DeviceConfig.DeviceId,

		TestBinaryName:			args.TestPackageConfig.TestBinaryName,
		TestBinaryCommandLine:	args.TestPackageConfig.TestBinaryCommandLine,
		TestBinaryWorkingDir:	args.TestPackageConfig.TestBinaryWorkingDir,

		TestNameFilters:		strings.Split(args.TestNameFilters, ";"),
	}
	batchResultId, err := handler.testRunner.ExecuteTestBatch(getDefaultBatchName(), execParams, startTime)
	if err != nil { return "", err }

	return batchResultId, nil
}

// ExecuteSubTestBatch
// Execute a test batch with parameters identical to another batch, except that the case list is filtered further.

type ExecuteSubTestBatchArgs struct {
	OriginalBatchResultId	string `json:"originalBatchResultId"`
	TestNameFilters			string `json:"testNameFilters"`
}

func (handler *RPCHandler) ExecuteSubTestBatch (client *RPCClient, args ExecuteSubTestBatchArgs) (string, error) {
	log.Println("[rpc] ExecuteSubTestBatch requested")

	var original BatchResult
	err := handler.rtdbServer.GetObject(args.OriginalBatchResultId, &original)
	if err != nil { return "", err }

	var originalCaseList TestCaseList
	err = handler.rtdbServer.GetObject(args.OriginalBatchResultId, &originalCaseList)
	if err != nil { return "", err }

	startTime := time.Now()

	testCasePaths := filterTestCaseNames(originalCaseList.Paths, strings.Split(args.TestNameFilters, ";"))

	batchResultId, err := handler.testRunner.ExecuteTestBatchWithCaseList(getDefaultBatchName(), original.ExecParams, startTime, testCasePaths)
	if err != nil { return "", err }

	return batchResultId, nil
}

type ExecuteTestSetArgs struct {
	DeviceConfig		DeviceConfigArgs		`json:"deviceConfig"`
	TestPackageConfig 	TestPackageConfigArgs	`json:"testPackageConfig"`
	TestSetId			string					`json:"testSetId"`
}

func (handler *RPCHandler) ExecuteTestSet (client *RPCClient, args ExecuteTestSetArgs) (string, error) {
	log.Println("[rpc] ExecuteTestSet requested")

	// Check that the specified device exists.
	err := handler.rtdbServer.GetObject(args.DeviceConfig.DeviceId, &DeviceConfig{})
	if err != nil { return "", err }

	startTime := time.Now()

	// Execute tests in background.
	execParams := BatchExecParams {
		TargetAddress:			args.DeviceConfig.TargetAddress,
		TargetPort:				args.DeviceConfig.TargetPort,
		SpawnLocalProcess:		args.DeviceConfig.SpawnLocalProcess,
		DeviceId:				args.DeviceConfig.DeviceId,

		TestBinaryName:			args.TestPackageConfig.TestBinaryName,
		TestBinaryCommandLine:	args.TestPackageConfig.TestBinaryCommandLine,
		TestBinaryWorkingDir:	args.TestPackageConfig.TestBinaryWorkingDir,

		TestNameFilters:		make([]string, 0),
	}

	// Test sets can have some tens of MBs data. Should not load the
	// full test set in the server thread. Passing the test set ID to
	// the runner instead.
	log.Printf("Requesting execution of test set: %s", args.TestSetId)
	batchResultId, err := handler.testRunner.ExecuteTestBatchWithTestSet(getDefaultBatchName(), execParams, startTime, args.TestSetId)
	if err != nil { return "", err }

	return batchResultId, nil
}


// WouldQueueWithOnlyDifferentDevices

type WouldQueueWithOnlyDifferentDevicesArgs struct {
	TargetAddress	string	`json:"targetAddress"`
	TargetPort		int		`json:"targetPort"`
	DeviceId		string	`json:"deviceId"`
}

// Tells whether the queue that the execution with the given address and port would go to
// currently contains only devices other than args.DeviceId .
func (handler *RPCHandler) WouldQueueWithOnlyDifferentDevices (client *RPCClient, args WouldQueueWithOnlyDifferentDevicesArgs) (bool, error) {
	log.Printf("[rpc] WouldQueueWithDifferentDevice called: %v\n", args)

	queueId := AddressQueueId(args.TargetAddress, args.TargetPort)
	var queue DeviceBatchQueue
	err := handler.rtdbServer.GetObject(queueId, &queue)
	if err != nil { return false, nil }

	differentDeviceFound := false

	for _, batchResultId := range queue.BatchResultIds {
		var batchResult BatchResult
		err := handler.rtdbServer.GetObject(batchResultId, &batchResult)
		if err == nil {
			if batchResult.ExecParams.DeviceId == args.DeviceId {
				return false, nil
			} else {
				differentDeviceFound = true
			}
		}
	}

	return differentDeviceFound, nil
}

// DeleteDeviceConfig

func (handler *RPCHandler) DeleteDeviceConfig (client *RPCClient, deviceId string) (bool, error) {
	opSet := rtdb.NewOpSet()
	opSet.Delete(typeDeviceConfig, deviceId)
	opSet.Call(typeDeviceConfigList, "deviceConfigList", "Remove", deviceId)
	err := handler.rtdbServer.ExecuteOpSet(opSet)
	return err == nil, err
}

// SaveDeviceConfig

type SaveDeviceConfigArgs struct {
	Id			string			`json:"id"`
	Config		DeviceConfig	`json:"config"`
}

func (handler *RPCHandler) SaveDeviceConfig (client *RPCClient, args *SaveDeviceConfigArgs) (bool, error) {
	log.Printf("SaveDeviceConfig: %s, %#v\n", args.Id, args.Config)

	opSet := rtdb.NewOpSet()

	// If no id specified, create a new one.
	var deviceId string
	if args.Id == "" {
		deviceId = genRandomId(8)
	} else {
		deviceId = args.Id
	}

	if !args.Config.IsADBDevice {
		// Append to list or rename old one.
		header := DeviceConfigHeader{ deviceId }
		opSet.Call(typeDeviceConfigList, "deviceConfigList", "Append", header)
	}

	// Save device config.
	opSet.Call(typeDeviceConfig, deviceId, "Init", args.Config)

	// Store results.
	err := handler.rtdbServer.ExecuteOpSet(opSet)

	if err != nil {
		return false, err
	}

	return true, nil
}

// SetBatchResultName

type SetBatchResultNameArgs struct {
	BatchResultId		string	`json:"batchResultId"`
	Name				string	`json:"name"`
}

func (handler *RPCHandler) SetBatchResultName (client *RPCClient, args *SetBatchResultNameArgs) (bool, error) {
	log.Printf("[rpc] SetBatchResultName(%s, %s)\n", args.BatchResultId, args.Name)

	opSet := rtdb.NewOpSet()
	opSet.Call(typeBatchResultList, "batchResultList", "SetBatchResultName", args.BatchResultId, args.Name)
	opSet.Call(typeBatchResult, args.BatchResultId, "SetName", args.Name)
	err := handler.rtdbServer.ExecuteOpSet(opSet)
	return err == nil, err
}

// StopBatchExecution

type StopBatchExecutionArgs struct {
	BatchResultId string `json:"batchResultId"`
}

func (handler *RPCHandler) StopBatchExecution (client *RPCClient, args *StopBatchExecutionArgs) (bool, error) {
	log.Printf("[rpc] StopBatchExecution(%s)\n", args.BatchResultId)

	err := handler.testRunner.StopBatchExecution(args.BatchResultId)
	if err != nil { return false, err }

	return true, nil
}

// ContinueBatchExecution

type ContinueBatchExecutionArgs struct {
	BatchResultId string `json:"batchResultId"`
}

func (handler *RPCHandler) ContinueBatchExecution (client *RPCClient, args *ContinueBatchExecutionArgs) (bool, error) {
	log.Printf("[rpc] ContinueBatchExecution(%s)\n", args.BatchResultId)

	err := handler.testRunner.ContinueBatchExecution(args.BatchResultId)
	if err != nil { return false, err }

	return true, nil
}

// MoveBatchInQueue

type MoveBatchInQueueArgs struct {
	BatchResultId	string	`json:"batchResultId"`
	Offset			int		`json:"offset"`
}

func (handler *RPCHandler) MoveBatchInQueue (client *RPCClient, args *MoveBatchInQueueArgs) (bool, error) {
	log.Printf("[rpc] MoveBatchInQueue(%s, %d)\n", args.BatchResultId, args.Offset)

	err := handler.testRunner.MoveBatchInQueue(args.BatchResultId, args.Offset)
	if err != nil { return false, err }

	return true, nil
}

// NewVersionView

func (handler *RPCHandler) NewVersionView (client *RPCClient, args struct{}) (int, error) {
	viewId := client.listener.NewVersionView()
	return viewId, nil
}

// ReleaseVersionView

type ReleaseVersionViewArgs struct {
	ViewId int `json:"viewId"`
}

func (handler *RPCHandler) ReleaseVersionView (client *RPCClient, args ReleaseVersionViewArgs) (struct{}, error) {
	return struct{}{}, client.listener.ReleaseVersionView(args.ViewId)
}

// GetVersionViewedObjects

type GetVersionViewedObjectsArgs struct {
	ViewId		int					`json:"viewId"`
	Objects		[]rtdb.TypedObject	`json:"objects"`
}

func (handler *RPCHandler) GetVersionViewedObjects (client *RPCClient, args GetVersionViewedObjectsArgs) ([]rtdb.ObjectBase, error) {
	log.Printf("[rpc] GetVersionViewedObjects(%d, [%d objects])\n", args.ViewId, len(args.Objects))
	result := []rtdb.ObjectBase{}
	for _, objInfo := range args.Objects {
		object, err := client.listener.GetVersionViewedObject(objInfo, args.ViewId)
		if err != nil { return nil, fmt.Errorf("At %s object '%s': %v", objInfo.Type, objInfo.ObjId, err) }
		result = append(result, object)
	}
	return result, nil
}

// GetTestCaseList

func (handler *RPCHandler) GetTestCaseList (client *RPCClient, args struct{}) ([]string, error) {
    return handler.testRunner.fullTestCaseList, nil
}

// Delete TestSet

func (handler *RPCHandler) DeleteTestSet (client *RPCClient, testSetId string) (bool, error) {
	opSet := rtdb.NewOpSet()
	opSet.Delete(typeTestSet, testSetId)
	opSet.Call(typeTestSetList, "testSetList", "Remove", testSetId)
	err := handler.rtdbServer.ExecuteOpSet(opSet)
	return err == nil, err
}
