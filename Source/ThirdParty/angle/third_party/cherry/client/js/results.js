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

angular.module('cherry.results', [])

.controller('BatchResultListCtrl', ['$scope', '$location', 'rtdb', 'rpc', function($scope, $location, rtdb, rpc)
{
	var toggleBatchResultSelection = function(batchResultId)
	{
		if ($scope.batchResultSelected[batchResultId])
		{
			var index = $scope.selectedBatchResults.indexOf(batchResultId);
			$scope.selectedBatchResults.splice(index, 1);
			$scope.batchResultSelected[batchResultId] = false;
		}
		else
		{
			$scope.selectedBatchResults.push(batchResultId);
			$scope.batchResultSelected[batchResultId] = true;
		}
	};

	var getBatchResultIndex = function(batchResultId)
	{
		for (var index = 0; index < $scope.value.batchResults.length; index++)
		{
			if ($scope.value.batchResults[index].id === batchResultId)
				return index;
		}
		return -1;
	};

	var latestClickedBatchResultId = undefined;

	$scope.selectedBatchResults		= [];
	$scope.batchResultSelected		= {};

	$scope.comparisonBatchIdsStr = function()
	{
		return JSON.stringify($scope.selectedBatchResults);
	};

	$scope.unselectAllBatchResults = function()
	{
		$scope.selectedBatchResults = [];
		for (var key in $scope.batchResultSelected)
			$scope.batchResultSelected[key] = false;
	};

	$scope.batchResultClicked = function(batchResultId, event)
	{
		if (event.ctrlKey || event.shiftKey)
		{
			if (event.shiftKey)
			{
				if (latestClickedBatchResultId !== undefined)
				{
					var fromNdx		= getBatchResultIndex(latestClickedBatchResultId)
					var toNdx		= getBatchResultIndex(batchResultId);
					if (fromNdx !== undefined && toNdx !== undefined && fromNdx !== toNdx)
					{
						var step = fromNdx < toNdx ? 1 : -1;
						for (var ndx = fromNdx+step; ndx != toNdx+step; ndx += step)
						{
							var id = $scope.value.batchResults[ndx].id;
							if (!$scope.batchResultSelected[id])
								toggleBatchResultSelection(id);
						}
					}
				}
			}
			else
				toggleBatchResultSelection(batchResultId);

			latestClickedBatchResultId = batchResultId;

			event.preventDefault();
			event.stopPropagation();
		}
	};

	$scope.$watchCollection('value.batchResults', function(batchResults)
	{
		if (batchResults)
		{
			for (var ndx = 0; ndx < batchResults.length; ndx++)
			{
				var id = batchResults[ndx].id;
				if (!$scope.batchResultSelected.hasOwnProperty(id))
					$scope.batchResultSelected[id] = false;
			}
		}
	});

	rtdb.bind('BatchResultList', 'batchResultList', $scope);

	$scope.titleExpr('"results"');
}])

// Batch result importing (upload).

// \note Currently BatchImportCtrl assumes that the controller is used on the form element.
.controller('BatchImportCtrl', ['$scope', '$element', function($scope, $element)
{
	var upload = function()
	{
		var formData = new FormData($($element)[0]);

		$.ajax({
			type:			'POST',
			url:			'/import/',
			beforeSend:		$scope.uploadStarted,
			success:		$scope.uploadFinished,
			error:			$scope.uploadFinished,
			data:			formData,
			cache:			false,
			contentType:	false,
			processData:	false,
		});
	};

	$scope.$watch('filename', function(name)
	{
		if (name)
			upload();
	});
}])

;
