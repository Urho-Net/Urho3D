// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

'use strict';

// Controllers

angular.module('cherry.testLaunch', [])

// \todo [petri] rename to DeviceConfigSelectorCtrl?
.controller('TestLaunchCtrl', ['$scope', '$location', 'rtdb', 'rpc', function($scope, $location, rtdb, rpc)
{
	$scope.loadFullTestCaseTree();

	rtdb.bind('DeviceConfigList', 'deviceConfigList', $scope, { valueName: 'normalDevices' });
	rtdb.bind('ADBDeviceConnectionList', 'adbDeviceConnectionList', $scope, { valueName: 'adbDeviceConnections' });

	var testTreeAccess;

	angular.extend($scope,
	{
		selectedDeviceId:	undefined,
		deviceSettings:		{},		// child scopes will fill this with { deviceId:$scope.value }
		deviceError:		{},		//									{ deviceId:error } if the specific device has an error prohibiting test execution
		deviceIsADB:		{},
		activeSelectorTab:	'tree',
		selectedTestSetId:	undefined,

		selectDevice: function(deviceId)
		{
			$scope.selectedDeviceId = deviceId;
		},

		setSelectorTab: function(tab)
		{
			$scope.activeSelectorTab = tab
		},

		canExecuteTestBatch: function()
		{
			var setsValid = $scope.activeSelectorTab === 'sets' && !!$scope.selectedTestSetId;
			return !!$scope.selectedDeviceId && ($scope.activeSelectorTab === 'tree' || setsValid);
		},

		getDeviceConfig: function(deviceId)
		{
			// Use settings specified in the child element (device config).
			var deviceConfig = $scope.deviceSettings[deviceId];
			console.log('[exec] config "' + deviceId + '":');
			_.map(deviceConfig, function(value, key) { console.log('  ' + key + ': ' + JSON.stringify(value)); });

			var targetPort = parseInt(deviceConfig.targetPort) || 0;

			// \todo [petri] better error checking/handling
			// \todo [2017-03-15 kraita] Also, split sanity checks into another function.
			if ($scope.deviceError.hasOwnProperty(deviceId))
				alert($scope.deviceError[deviceId]);
			else if (!deviceConfig.targetAddress)
				alert('Invalid target address: "' + (deviceConfig.targetAddress || '') + '"');
			else if (targetPort <= 0)
				alert('Invalid target port: "' + targetPort + '"');

			var config = {
				targetAddress:			deviceConfig.targetAddress,
				targetPort:				targetPort,
				spawnLocalProcess:		deviceConfig.localProcessPath,
				deviceId:				deviceId,
			}

			return config;
		},

		getTestPackageConfig: function(deviceId)
		{
			var deviceConfig = $scope.deviceSettings[deviceId];
			var config = {
				testBinaryName:			deviceConfig.binaryPath,
				testBinaryCommandLine:	deviceConfig.commandLine || '',
				testBinaryWorkingDir:	deviceConfig.workingDir,
			};
			return config;
		},

		executeTestBatch: function()
		{
			var params = {
				deviceConfig:	   $scope.getDeviceConfig($scope.selectedDeviceId),
				testPackageConfig: $scope.getTestPackageConfig($scope.selectedDeviceId),
			};

			var executeMethod = undefined;

			if ($scope.activeSelectorTab === 'sets')
			{
				params.testSetId = $scope.selectedTestSetId;
				if (!params.testSetId) {
					alert('No test set selected');
					return;
				}
				executeMethod = 'rtdb.ExecuteTestSet';
				console.log("[exec] Execute test set: " + params.testSetId);
			}
			else
			{
				// Combine final test filters string from test case tree selections and manually specified field.
				var testFilters = [];
				if (testTreeAccess.nodeSelected)
				{
					var str = genTestCaseTreeSubsetFilter($scope.fullTestCaseTree, testTreeAccess.nodeSelected);
					if (str !== '')
						testFilters.push(str);
				}
				if ($scope.testNameFilters)
					testFilters = testFilters.concat(_.filter($scope.testNameFilters.split(";"), function(f) { return f.length !== 0; }));
				testFilters = testFilters.join(";");

				if (!testFilters) {
					alert('No tests selected');
					return;
				}

				params.testNameFilters = testFilters;
				executeMethod		   = 'rtdb.ExecuteTestBatch'
			}

			// Check if the queue that this execution would go to contains different devices, and not this one.
			// It's unlikely that one would like to queue (i.e. use same port for) different devices.
			rpc.call('rtdb.WouldQueueWithOnlyDifferentDevices', {
				targetAddress:	params.deviceConfig.targetAddress,
				targetPort:		params.deviceConfig.targetPort,
				deviceId:		params.deviceId,
			})
			.then(function(wouldQueueWithOnlyDifferentDevices)
			{
				if (!wouldQueueWithOnlyDifferentDevices || confirm("Different device is using the same address and port - really queue?"))
				{
					rpc.call(executeMethod, params)
					.then(function(batchResultId)
					{
						console.log('Executing ' + batchResultId);
						$location.url('/results/batch/' + batchResultId);
					});
				}
			});
		},

		setTestTreeAccess: function(access)
		{
			testTreeAccess = access;
		},

		getTestTreeAccess: function()
		{
			return testTreeAccess;
		},

		testTreeSelectionType: function(event)
		{
			if (event.shiftKey)
				return 'area';
			return 'multiple';
		},
	});

	$scope.$watch('value.devices', function(devices)
	{
		// Auto-select first device.
		if ($scope.selectedDeviceId === undefined && devices && devices.length)
			$scope.selectedDeviceId = devices[0].id;
	});

	$scope.testCasePathFilter = '';

	var refilter = function()
	{
		if ($scope.fullTestCaseTree)
		{
			var pathFilterLower = $scope.testCasePathFilter.toLowerCase();
			filterTestCaseTree($scope.fullTestCaseTree, function(node) { return node.type !== 'testCase' || node.path.toLowerCase().indexOf(pathFilterLower) !== -1; });
		}
	};

	$scope.$watch('testCasePathFilter', refilter);

	$scope.titleExpr('"launch tests"');
}])

.controller('DeviceConfigCtrl', ['$scope', 'rtdb', 'rpc', function($scope, rtdb, rpc)
{
	var deviceId = '';
	var oldValue = {};

	var onObjectUpdate = function(objType, objId, value)
	{
		// Store value received from server for modification detection purposes.
		oldValue = angular.copy(value);

		// Expose our current parameters to parent, so it can launch tests with modified parameters.
		// \todo [petri] Is there a cleaner way to communicate this stuff to parent?
		$scope.$parent.deviceSettings[deviceId] = $scope.value;
	};

	angular.extend($scope,
	{
		isNewObject:	false,
		isSaving:		false,
		value:			{},

		initExisting: function(id)
		{
			deviceId = id;
			$scope.deviceIsADB[id] = false;
			rtdb.bind('DeviceConfig', deviceId, $scope, { onUpdate:onObjectUpdate });
		},

		initNew: function()
		{
			deviceId = '';
			$scope.isNewObject = true;
			$scope.deviceIsADB[deviceId] = false;
			$scope.$parent.deviceSettings[deviceId] = $scope.value;
		},

		initADB: function(connection)
		{
			$scope.initExisting(connection.deviceId);
			$scope.deviceIsADB[connection.deviceId] = true;
			$scope.adbConnection = connection;
		},

		isModified: function()
		{
			return !angular.equals(oldValue, $scope.value)
		},

		deleteConfig: function()
		{
			if ($scope.isNewObject)
				throw new Error('cannot delete new object');

			if (confirm('Really delete config "' + $scope.value.name + '"?'))
			{
				rpc.call('rtdb.DeleteDeviceConfig', deviceId)
				.then(function()
				{
					console.log('deleted device ' + deviceId);
					if ($scope.$parent.selectedDeviceId === deviceId)
						$scope.$parent.selectDevice(undefined);
				});
			}
		},

		saveConfig: function()
		{
			$scope.isSaving = true;

			var deviceConfig = angular.copy($scope.value);
			deviceConfig.targetPort = parseInt($scope.value.targetPort) || 0;

			rpc.call('rtdb.SaveDeviceConfig', { id:deviceId, config:deviceConfig })
			.then(function()
			{
				// If new empty, empty all values.
				if ($scope.isNewObject)
					$scope.value = {};

				$scope.isSaving = false;
				console.log('SAVED!');
			});
		}
	});

	$scope.$watch('adbConnection.state', function(connectionState)
	{
		if (connectionState)
		{
			if (connectionState != 'device')
				$scope.deviceError[deviceId] = 'Device unavailable (' + connectionState + ')';
			else
				delete $scope.deviceError[deviceId];
		}
	});
}])

.controller('TestSetSelectCtrl', ['$scope', 'rtdb', 'rpc', function($scope, rtdb, rpc)
{
	rtdb.bind('TestSetList', 'testSetList', $scope, { valueName: 'testSets' });

	angular.extend($scope,
	{
		selectedSetHeader: 		undefined,
		editableTestSetName: 	undefined,
		uploadFilterFile: 		[],

		selectTestSet: function(testSet)
		{
			if (!testSet || (!!$scope.selectedSetHeader && testSet.id === $scope.selectedSetHeader.id))
			{
				$scope.selectedSetHeader		 = undefined;
				$scope.$parent.selectedTestSetId = undefined;
				$scope.editableTestSetName		 = undefined;
			}
			else
			{
				$scope.selectedSetHeader		 = testSet;
				$scope.$parent.selectedTestSetId = testSet.id;
				$scope.editableTestSetName		 = $scope.selectedSetHeader.name;
			}
		},

		clearTestSetUploadFields: function()
		{
			$scope.editableTestSetName	= undefined;
			$scope.uploadFilterFile		= [];
		},

		makeUploadFailureNotification: function(setName)
		{
			var name = setName;
			return function() {
				alert("Uploading test set '" + name + "' failed");
				$scope.uploadFinished();
			};
		},

		uploadTestSet: function()
		{
			if (!$scope.editableTestSetName || $scope.uploadFilterFile[0] == null)
				return;

			console.log("Uploading test set: " + $scope.editableTestSetName);

			var formData	= new FormData();
			var setName		= $scope.editableTestSetName;
			var filterFile	= $scope.uploadFilterFile[0];

			formData.append("set-name", setName);
			formData.append("set-filters", filterFile);

			$.ajax({
				type:			'POST',
				url:			'/importTestSet/',
				beforeSend:		$scope.uploadStarted,
				success:		$scope.uploadFinished,
				error:			$scope.makeUploadFailureNotification(setName),
				data:			formData,
				cache:			false,
				contentType:	false,
				processData:	false,
			});

			$scope.clearTestSetUploadFields();
		},

		deleteTestSet: function(testSet)
		{
			if (confirm('Really delete test set "' + $scope.selectedSetHeader.name + '"?'))
			{
				var setId = $scope.selectedSetHeader.id
				rpc.call('rtdb.DeleteTestSet', setId)
				.then(function()
				{
					console.log('deleted test set: ' + setId);
				},
				function()
				{
					alert("Test set deletion failed!");
				});

				// Immediately de-select test set to discourage interacting with it before delete is complete.
				$scope.selectTestSet(undefined);
			}
		},

		initTestSetCtrl: function()
		{
		},
		// Test set todos:
		// - Button text 'Add' vs. 'Update' when existing selected, i.e., change text based on action
		// - Rename choose files
		// - Visualization of filters
		// - Wildcards (expand against local tree or executable tree?)
		// - Enable uploading new set of filters?
		// - Interactive editing of filters?
		// - What to do with the 'Additional tests' field? Move under the tree select tab? Concatenate with the test set filter list?
	});
}])

;
