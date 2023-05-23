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

// Function to load a test set.
function loadTestSet(rpc, testSetToLoad)
{
	var testSet = testSetToLoad; // Note: Closure for the then call.
	rpc.call('rtdb.GetTestSetFilters', {testSetName:testSet.name})
	.then(function(paths)
	{
	  testSet.paths = paths;
	});
}

// Controllers

angular.module('cherry.controllers', [])

// Global application controller.

.controller('GlobalCtrl', ['$scope', 'rtdb', 'rpc', 'socket', function($scope, rtdb, rpc, socket)
{
	// Subscribe some common objects so they're always accessed instantly.
	rtdb.prefetch('DeviceConfigList', 'deviceConfigList', $scope);
	rtdb.prefetch('BatchResultList', 'batchResultList', $scope);
	rtdb.prefetch('ActiveBatchResultList', 'activeBatchResultList', $scope);
	rtdb.prefetch('TestSetList', 'testSetList', $scope);

	var numActiveUploads = 0;
	angular.extend($scope,
	{
		connectionStatus:	null,		// status of websocket connection

		reconnect: function()
		{
			window.location.reload();
		},

		// For access in HTMLs.
		TEST_STATUS_CODE: TEST_STATUS_CODE,
		BATCH_STATUS_CODE: BATCH_STATUS_CODE,
		TEST_CASE_TYPE: TEST_CASE_TYPE,

		numActiveUploads:		function() { return numActiveUploads; },
		uploadStarted:			function() { numActiveUploads++; },
		uploadFinished:			function() { numActiveUploads--; },

		// \note Full test case tree doesn't change and can be rather big, so
		//		 we allow child scopes to request loading it to the global scope,
		//		 and let it remain there.
		loadFullTestCaseTree:	function()
		{
			if ($scope.fullTestCaseTree === undefined)
			{
				rpc.call('rtdb.GetTestCaseList', {})
				.then(function(caseList)
				{
					$scope.fullTestCaseTree = genTestCaseTree(caseList, 'All Tests');
					setTestCaseTreeInitialDepthExpansion($scope.fullTestCaseTree, 1);
				});
			}
		},
	});

	socket.onStatus(function(status)
	{
		$scope.connectionStatus = status;
	});
}])

// Top navigation bar controller.

.controller('NavCtrl', ['$scope', 'rtdb', function($scope, rtdb)
{
	rtdb.bind('ActiveBatchResultList', 'activeBatchResultList', $scope);
}])

;
