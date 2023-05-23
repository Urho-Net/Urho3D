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

angular.module('cherry.batchResultComparison', [])

// Batch result view.

.controller('BatchResultComparisonCtrl', ['$scope', '$location', '$stateParams', 'rtdb', 'rpc', function($scope, $location, $stateParams, rtdb, rpc)
{
	var numBatchResultsLoaded		= 0;
	var numTestCaseListsLoaded		= 0;
	var numTestCaseHeadersLoaded	= 0;
	var totalNumTestCases			= 0;
	var initiallySelectedNodePath	= $stateParams.testGroupPath || $stateParams.testCasePath || '';

	var testCaseResultsDifferent = function(node)
	{
		for (var ndx = 1; ndx < $scope.batchResultIds.length; ndx++)
		{
			if (node.existsInTree[ndx] !== node.existsInTree[0])
				return true;
		}

		var result0 = testCaseListResult($scope.testCaseHeaders[$scope.batchResultIds[0] + node.headerIdSuffix]);
		for (var ndx = 1; ndx < $scope.batchResultIds.length; ndx++)
		{
			var result = testCaseListResult($scope.testCaseHeaders[$scope.batchResultIds[ndx] + node.headerIdSuffix]);
			if (result !== result0)
				return true;
		}
		return false;
	};

	var batchResultUpdateFunc = function(batchResultNdx)
	{
		return function(objType, objId, value)
		{
			if ($scope.batchResults[batchResultNdx] === undefined)
				numBatchResultsLoaded++;

			$scope.batchResults[batchResultNdx] = value;

			if (numBatchResultsLoaded === $scope.batchResultIds.length)
			{
				var batchResultsStr = '';
				for (var ndx = 0; ndx < $scope.batchResults.length; ndx++)
				{
					if (ndx > 0)
						batchResultsStr += ndx < $scope.batchResults.length-1 ? ', ' : ' and ';
					batchResultsStr += $scope.batchResults[ndx].name;
				}
				$scope.batchResultNamesStr = batchResultsStr;
			}
		};
	};

	var testCaseHeaderUpdate = function(objType, objId, header)
	{
		if (!$scope.testCaseHeaders.hasOwnProperty(objId))
			numTestCaseHeadersLoaded++;

		$scope.testCaseHeaders[objId] = header;

		if (numTestCaseListsLoaded === $scope.batchResultIds.length && numTestCaseHeadersLoaded === totalNumTestCases)
			$scope.isInitialized = true;
	};

	var testCaseListUpdateFunc = function(batchResultNdx)
	{
		return function(objType, objId, list)
		{
			if ($scope.testCaseTrees[batchResultNdx] === undefined)
			{
				numTestCaseListsLoaded++;
				totalNumTestCases += list.paths.length;
			}

			$scope.testCaseTrees[batchResultNdx] = genTestCaseTree(list.paths, 'All Results')

			if (numTestCaseListsLoaded === $scope.batchResultIds.length)
			{
				$scope.unionTestCaseTree = genUnionTestCaseTree($scope.testCaseTrees);
				setTestCaseTreeInitialDepthExpansion($scope.unionTestCaseTree, 2);
				setTestCaseTreeInitialPathExpansion($scope.unionTestCaseTree, initiallySelectedNodePath);
				filterTestCaseTree($scope.unionTestCaseTree, function(node) { return true; });
			}

			for (var ndx = 0; ndx < list.paths.length; ndx++)
				rtdb.bind('TestCaseHeader', $scope.batchResultIds[batchResultNdx] + '/' + list.paths[ndx], $scope, { onUpdate: testCaseHeaderUpdate });
		};
	}

	// Indexed by batch result index
	$scope.batchResultIds			= JSON.parse($stateParams.batchResultIds);
	$scope.batchResults				= [];
	$scope.testCaseTrees			= [];

	for (var ndx = 0; ndx < $scope.batchResultIds.length; ndx++)
	{
		var resultId = $scope.batchResultIds[ndx];
		rtdb.bind('BatchResult',	resultId, $scope, { onUpdate: batchResultUpdateFunc(ndx) });
		rtdb.bind('TestCaseList',	resultId, $scope, { onUpdate: testCaseListUpdateFunc(ndx) });
	}

	// Indexed by test case header ID
	$scope.testCaseHeaders			= {};

	// Will be set to true when all relevant objects have been received from server.
	$scope.isInitialized			= false;

	$scope.initProgress = function()
	{
		if (numTestCaseListsLoaded === $scope.batchResultIds.length)
			return numTestCaseHeadersLoaded / totalNumTestCases;
		else
			return 0.0;
	};

	$scope.booleanFilters =
	[
		{
			description: 'Different',
			preserveNode: function(node) { return node.type === 'testGroup' || testCaseResultsDifferent(node); }
		},
		{
			description: 'Finished',
			preserveNode: function(node)
			{
				for (var ndx = 0; ndx < $scope.batchResultIds.length; ndx++)
				{
					if (!node.existsInTree[ndx])
						return false;
					if (node.type === 'testCase')
					{
						var header = $scope.testCaseHeaders[$scope.batchResultIds[ndx] + node.headerIdSuffix];
						if (header.result === '' && !isTestStatusCodeFinished(header.status))
							return false;
					}
				}
				return true;
			}
		},
		{
			description: 'Non-passed',
			preserveNode: function(node)
			{
				if (node.type === 'testGroup')
					return true;
				for (var ndx = 0; ndx < $scope.batchResultIds.length; ndx++)
				{
					if (!node.existsInTree[ndx])
						return true;

					var header = $scope.testCaseHeaders[$scope.batchResultIds[ndx] + node.headerIdSuffix];
					if (header.status !== TEST_STATUS_CODE.PASS)
						return true;
				}
				return false;
			}
		},
	];

	$scope.testCasePathFilter = '';

	$scope.booleanFilterEnabled = [];

	for (var ndx = 0; ndx < $scope.booleanFilters.length; ndx++)
		$scope.booleanFilterEnabled.push(false);

	var refilter = function()
	{
		if ($scope.unionTestCaseTree)
		{
			var and					= function(p0, p1) { return function(node) { return p0(node) && p1(node); }; };
			var totalFilterFunc		= function(node) { return true; };

			for (var ndx = 0; ndx < $scope.booleanFilters.length; ndx++)
			{
				if ($scope.booleanFilterEnabled[ndx])
					totalFilterFunc = and(totalFilterFunc, $scope.booleanFilters[ndx].preserveNode);
			}

			var pathFilterLower = $scope.testCasePathFilter.toLowerCase();
			totalFilterFunc = and(totalFilterFunc, function(node) { return node.type !== 'testCase' || node.path.toLowerCase().indexOf(pathFilterLower) !== -1; });

			filterTestCaseTree($scope.unionTestCaseTree, totalFilterFunc);
		}
	}

	$scope.$watchCollection('booleanFilterEnabled', refilter);
	$scope.$watch('testCasePathFilter', refilter);

	// A bit of a hack(?) to access $stateParams in the template.
	$scope.stateParams = $stateParams;

	$scope.titleExpr('"comparison of " + batchResultNamesStr')
}])

;

// Given an array of trees (as generated by genTestCaseTree), returns a tree
// that contains all the cases combined. The tree is of the same format as
// returned by genTestCaseTree, except that each node contains an additional
// 'existsInTree' member such that n.existsInTree[ndx] is true/false according
// to whether testCaseTrees[ndx] contains that node.
function genUnionTestCaseTree(testCaseTrees)
{
	var result					= [];
	var resultTopLevelLabels	= {};
	var treeNodesByLabel		= [];

	for (var treeNdx = 0; treeNdx < testCaseTrees.length; treeNdx++)
	{
		var tree = testCaseTrees[treeNdx];
		treeNodesByLabel[treeNdx] = {};
		for (var nodeNdx = 0; nodeNdx < tree.length; nodeNdx++)
		{
			var node = tree[nodeNdx];
			treeNodesByLabel[treeNdx][node.label] = node;
		}
	}

	for (var treeNdx = 0; treeNdx < testCaseTrees.length; treeNdx++)
	{
		var tree = testCaseTrees[treeNdx];
		for (var nodeNdx = 0; nodeNdx < tree.length; nodeNdx++)
		{
			var node = tree[nodeNdx];
			if (!resultTopLevelLabels.hasOwnProperty(node.label))
			{
				resultTopLevelLabels[node.label] = true;

				var nodePerTree			= [];
				var nodeExistsInTree	= [];
				for (var ndx = 0; ndx < testCaseTrees.length; ndx++)
				{
					nodeExistsInTree[ndx]	= treeNodesByLabel[ndx].hasOwnProperty(node.label);
					nodePerTree[ndx]		= nodeExistsInTree[ndx] && treeNodesByLabel[ndx][node.label];
				}

				if (node.type === 'testCase')
					result.push(angular.extend({}, node, { existsInTree: nodeExistsInTree }));
				else if (node.type === 'testGroup')
				{
					var subTrees = [];
					for (var ndx = 0; ndx < testCaseTrees.length; ndx++)
					{
						var n = nodePerTree[ndx];
						subTrees.push(n ? n.children : []);
					}

					result.push(angular.extend({}, node, { existsInTree: nodeExistsInTree, children: genUnionTestCaseTree(subTrees) }));
				}
				else
					throw new Error('genUnionTestCaseTree: bad node type: ' + node.type);
			}
		}
	}

	return result;
}
