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

angular.module('cherry.batchResult', [])

.controller('ActiveBatchResultListCtrl', ['$scope', '$location', 'rtdb', 'rpc', function($scope, $location, rtdb, rpc)
{
	rtdb.bind('ActiveBatchResultList', 'activeBatchResultList', $scope);
}])

// Batch result view.

.controller('BatchResultCtrl', ['$scope', '$location', '$stateParams', 'rtdb', 'rpc', function($scope, $location, $stateParams, rtdb, rpc)
{
	var batchResultId = $stateParams.batchResultId || $scope.batchResultId;

	var getSubBatchTestFilters = function() { throw new Error('getSubBatchTestFilters callback not set'); };

	angular.extend($scope,
	{
		batchResultId: batchResultId,

		stopExecution: function()
		{
			rpc.call('rtdb.StopBatchExecution', { batchResultId:batchResultId });
		},

		continueExecution: function()
		{
			rpc.call('rtdb.ContinueBatchExecution', { batchResultId:batchResultId });
		},

		setSubBatchTestFiltersCallback:		function(callback) { getSubBatchTestFilters = callback; },
		anyNodesForSubBatch:				false,
		setAnyNodesForSubBatch:				function(v) { $scope.anyNodesForSubBatch = v; },

		executeSubBatch: function()
		{
			rpc.call('rtdb.ExecuteSubTestBatch', { originalBatchResultId:batchResultId, testNameFilters:getSubBatchTestFilters() })
			.then(function(batchResultId)
			{
				console.log('  executeSubBatch(): created batch result ' + batchResultId);
				$location.url('/results/batch/' + batchResultId);
			},
			function(reason)
			{
				console.log('executeSubBatch() failed: ' + reason);
			});
		},
	});

	$scope.$watch('batchResult.status', function(status)
	{
		$scope.isStoppable		= status === BATCH_STATUS_CODE.RUNNING || status === BATCH_STATUS_CODE.PENDING || status === BATCH_STATUS_CODE.IMPORTING;
		$scope.isContinuable	= status === BATCH_STATUS_CODE.INTERRUPTED || status === BATCH_STATUS_CODE.CANCELED;
		$scope.isInitialized	= status && status !== BATCH_STATUS_CODE.IMPORTING && status !== BATCH_STATUS_CODE.INITIALIZING; // \note When status is still undefined, we assume it's initializing.
	});

	$scope.$watch('batchResult.execParams.deviceId', function(deviceId)
	{
		if (deviceId)
			rtdb.bind('DeviceConfig', deviceId, $scope, { valueName:'deviceConfig' });
	});

	$scope.$watch('deviceConfig.name', function(deviceConfigName)
	{
		if ($scope.deviceConfig)
			$scope.deviceConfigName = deviceConfigNameHumanReadable($scope.deviceConfig);
	});

	$scope.batchResultNameInputWidth = function()
	{
		var inputPadding = $('#batchResultNameInput').outerWidth(true) - $('#batchResultNameInput').width();
		return $('#batchResultNameWidthHelper').width() + 2 + inputPadding; // +2 seems good enough to keep the blinking bar thingy visible even at the right edge.
	};

	$scope.initProgress = function()
	{
		if ($scope.batchResult)
			return $scope.batchResult.initProgress;
		return 0.0;
	};

	// Watch changes on the batch result's name input, and send a name update
	// request after the input has been unchanged for some time.
	var nameUpdateDelayMilliseconds = 200;
	var nameInputLastModified;
	var nameUpdateSendTimeoutHandle;
	var lastAssignedName;
	$scope.$watch('batchResultNameInput', function(name)
	{
		if (lastAssignedName !== undefined && name !== lastAssignedName)
		{
			nameInputLastModified = new Date();
			if (nameUpdateSendTimeoutHandle !== undefined)
				clearTimeout(nameUpdateSendTimeoutHandle);
			nameUpdateSendTimeoutHandle = setTimeout(function()
			{
				nameUpdateSendTimeoutHandle = undefined;
				rpc.call('rtdb.SetBatchResultName', { batchResultId:batchResultId, name:name });
			}, nameUpdateDelayMilliseconds);
			lastAssignedName = name;
		}
	});

	// Watch updates to the batch result's name from the server, and update the
	// input's value after it's hasn't been modified by the user in some time.
	var nameInputUpdateTimeoutHandle = undefined;
	$scope.$watch('batchResult.name', function(name)
	{
		if (name !== undefined)
		{
			var insideTimeout = false;
			var updateInputValue = function()
			{
				if (nameInputUpdateTimeoutHandle !== undefined)
					clearTimeout(nameInputUpdateTimeoutHandle);

				if (nameInputLastModified === undefined || (new Date()).getTime() - nameInputLastModified.getTime() > nameUpdateDelayMilliseconds)
				{
					nameInputUpdateTimeoutHandle = undefined;
					$scope.batchResultNameInput = name;
					lastAssignedName = name;
					if (insideTimeout)
						$scope.$digest();
				}
				else
				{
					insideTimeout = true;
					nameInputUpdateTimeoutHandle = setTimeout(updateInputValue, nameUpdateDelayMilliseconds);
				}
			};
			updateInputValue();
		}
	});

	rtdb.bind('BatchResult', batchResultId, $scope, { valueName:'batchResult' });

	$scope.titleExpr('batchResult.name + " - " + deviceConfigName');
}])

// Test case list.

.controller('TestCaseListCtrl', ['$scope', '$stateParams', 'rtdb', 'rpc', function($scope, $stateParams, rtdb, rpc)
{
	var batchResultId				= $stateParams.batchResultId || $scope.batchResultId;
	var initiallySelectedNodePath	= $stateParams.testGroupPath || $stateParams.testCasePath || '';
	var latestClickedNodePath		= undefined;

	var selectInitialNode = function()
	{
		$scope.treeAccess.selectNode(getTestCaseTreeNodeIdFromPath($scope.testCaseTree, initiallySelectedNodePath));
	};

	$scope.setTreeAccess = function(access)
	{
		$scope.treeAccess = access;
		$scope.setSubBatchTestFiltersCallback(function()
		{
			return genTestCaseTreeSubsetFilter($scope.testCaseTree, $scope.treeAccess.nodeSelected);
		});

		if ($scope.testCaseTree)
			selectInitialNode();
	};

	$scope.treeSelectionType = function(event)
	{
		if (event.button === 0)
		{
			if (event.shiftKey)
				return 'area';
			if (event.ctrlKey)
				return 'multiple';
			return 'single';
		}
	}

	$scope.maybeUnselectNodes = function(event)
	{
		if ($scope.treeAccess && !event.ctrlKey && !event.shiftKey)
			$scope.treeAccess.unselectAll();
	};

	$scope.$watch('treeAccess.anySelected', $scope.setAnyNodesForSubBatch);

	$scope.testCasePathFilter = '';

	var refilter = function()
	{
		if ($scope.testCaseTree)
		{
			var pathFilterLower = $scope.testCasePathFilter.toLowerCase();
			filterTestCaseTree($scope.testCaseTree, function(node) { return node.type !== 'testCase' || node.path.toLowerCase().indexOf(pathFilterLower) !== -1; });
		}
	};

	$scope.$watch('testCaseList.paths', function(caseList)
	{
		if (caseList)
		{
			console.log('test case list updated with ' + caseList.length + ' items');
			$scope.testCaseTree = genTestCaseTree(caseList, 'All Results');
			setTestCaseTreeInitialDepthExpansion($scope.testCaseTree, 2);
			setTestCaseTreeInitialPathExpansion($scope.testCaseTree, initiallySelectedNodePath);
			if ($scope.treeAccess)
				selectInitialNode();
			refilter();
		}
	});

	$scope.$watch('testCasePathFilter', refilter);

	rtdb.bind('TestCaseList', batchResultId, $scope, { valueName:'testCaseList' });
}])

// Stats for selected group node in tree.
// \todo [petri] same as TreeGroupCtrl?

.controller('TestGroupStatsCtrl', ['$scope', '$stateParams', 'rtdb', 'rpc', function($scope, $stateParams, rtdb, rpc)
{
	var objId = $stateParams.batchResultId + '/' + $stateParams.testGroupPath;
	rtdb.bind('TestCaseTreeGroup', objId, $scope, { invalidateMode: 'scope' });

	$scope.testGroupPath = $stateParams.testGroupPath;

	// Batch name if displaying a comparison view
	$scope.batchResultName = "";
	if ($scope.batchResults && $scope.batchResultIds && $stateParams.batchResultId)
	{
		var batchResult = $scope.batchResults[$scope.batchResultIds.indexOf($stateParams.batchResultId)];
		if (batchResult)
			$scope.batchResultName = batchResult.name;
	}

	angular.extend($scope,
	{
		getNumResults: function(value)
		{
			if (value)
				return	value.numSuccess				+
						value.numFailure				+
						value.numCrash					+
						value.numTimeout				+
						value.numQualityWarning			+
						value.numCompatibilityWarning	+
						value.numNotSupported			+
						value.numResourceError			+
						value.numInternalError;
			else
				return '0';
		},

		getResultTypePercentage: function(value)
		{
			if (value)
			{
				var numHits = 0;
				for (var i = 1; i < arguments.length; ++i)
					numHits += value[arguments[i]]
				return percentageString(numHits, value.numTotalCases);
			}
			else
				return '0';
		},

		getResultTypeCount: function(value)
		{
			if (value)
			{
				var numHits = 0;
				for (var i = 1; i < arguments.length; ++i)
					numHits += value[arguments[i]]
				return numHits;
			}
			else
				return '0';
		},
	});
}])

// Treeview selected group node.

.controller('TreeGroupCtrl', ['$scope', 'rtdb', 'rpc', function($scope, rtdb, rpc)
{
	angular.extend($scope,
	{
		value: undefined,

		init: function(objId)
		{
			rtdb.bind('TestCaseTreeGroup', objId, $scope, { invalidateMode: 'scope' });
		},

		getNumResults: function()
		{
			if ($scope.value)
				return	$scope.value.numSuccess					+
						$scope.value.numFailure					+
						$scope.value.numCrash					+
						$scope.value.numTimeout					+
						$scope.value.numQualityWarning			+
						$scope.value.numCompatibilityWarning	+
						$scope.value.numNotSupported			+
						$scope.value.numResourceError			+
						$scope.value.numInternalError;
			else
				return "0";
		},

		getResultTypePercentage: function()
		{
			if ($scope.value)
			{
				var numHits = 0;
				for (var i = 0; i < arguments.length; ++i)
					numHits += $scope.value[arguments[i]]
				return percentageString(numHits, $scope.value.numTotalCases);
			}
			else
				return '0';
		},
	});
}])

// Treeview selected leaf node.

.controller('TreeLeafCtrl', ['$scope', 'rtdb', 'rpc', function($scope, rtdb, rpc)
{
	var resultFloat = undefined;

	var onUpdate = function()
	{
		var isNumeric = $scope.value.caseType === TEST_CASE_TYPE.PERFORMANCE ||
						$scope.value.caseType === TEST_CASE_TYPE.ACCURACY;

		if (isNumeric)
		{
			resultFloat = parseFloat($scope.value.result);
			if (isFinite(resultFloat))
			{
				if ($scope.groupShared.bestPerformanceResult === undefined ||
					$scope.groupShared.bestPerformanceResult < resultFloat)
					$scope.groupShared.bestPerformanceResult = resultFloat;
			}
			else
				isNumeric = false;
		}

		$scope.isNumericResult = isNumeric;
	};

	angular.extend($scope,
	{
		value: undefined,
		isNumericResult: false,
		getResultPercentage: function()
		{
			if (resultFloat !== undefined)
				return percentageString(Math.max(0, resultFloat), $scope.groupShared.bestPerformanceResult);
			else
				return '0';
		},
		init: function(obj)
		{
			// \note obj can be either a header object's id (a string) or the header object itself.
			if (_.isString(obj))
			{
				rtdb.bind('TestCaseHeader', obj, $scope, { onUpdate: onUpdate, invalidateMode: 'scope' });
			}
			else
			{
				$scope.value = obj;
				onUpdate();
			}
		},
	});
}])

;

function deviceConfigNameHumanReadable(config)
{
	return config.name || (config.isADBDevice ? 'Unknown Android device (' + config.adbSerialNumber + ')' : '');
}

function percentageString(num, den)
{
	// \note Slightly less than 100.0 is used so that we don't get
	//		 a total of greater than 100 due to precision issues
	//		 when summing percentages.
	return (num * 99.99 / den).toFixed(2);
}
