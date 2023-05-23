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

// Global utility functions.

var debugStr = function(val)
{
	var str = JSON.stringify(val);
	if (str === undefined)
		return 'undefined';
	if (str.length > 100)
		return str.slice(0, 97) + "...";
	return str;
};

// Declare app level module which depends on filters, and services
angular.module('cherry', [
	'ui.router',
	'ui.bootstrap',
	'angularSpinner',
	'treeControl',
	'cherry.filters',
	'cherry.services',
	'cherry.directives',
	'cherry.controllers',
	'cherry.testLaunch',
	'cherry.results',
	'cherry.batchResult',
	'cherry.testCaseResult',
	'cherry.batchResultComparison',
])

.config(['$stateProvider', '$urlRouterProvider', function($stateProvider, $urlRouterProvider)
{
	// In batch result view, initially show root group.
	$urlRouterProvider.when('/results/batch/{batchResultId}', '/results/batch/{batchResultId}/testGroup/');

	// Configure states.
	$stateProvider
	.state('main', {
		url:			'/main',
		templateUrl:	'partials/main.html'
	})
	.state('testLaunch', {
		url:			'/testLaunch',
		templateUrl:	'partials/testLaunch.html'
	})
	.state('results', {
		url:			'/results',
		templateUrl:	'partials/results.html'
	})
	.state('batchResult', {
		url:			'/results/batch/:batchResultId',
		templateUrl:	'partials/batchResult.html'
	})
	.state('batchResult.case', {
		url:			'/testCase/:testCasePath',
		templateUrl:	'partials/batchResult.case.html'
	})
	.state('batchResult.group', {
		url:			'/testGroup/:testGroupPath',
		templateUrl:	'partials/batchResult.group.html'
	})
	.state('batchResultComparison', {
		url:			'/batchResultComparison/:batchResultIds',
		templateUrl:	'partials/batchResultComparison.html'
	})
	.state('batchResultComparison.case', {
		url:			'/batch/:batchResultId/testCase/:testCasePath',
		templateUrl:	'partials/batchResult.case.html'
	})
	.state('batchResultComparison.group', {
		url:			'/batch/:batchResultId/testGroup/:testGroupPath',
		templateUrl:	'partials/batchResult.group.html'
	})
	.state('testCase', {
		url:			'/results/testCase/:batchResultId/:testCasePath',
		templateUrl:	'partials/batchResult.case.html'
	})
	.state('about', {
		url:			'/about',
		templateUrl:	'partials/about.html'
	})
	;

	// Configure routes.
	$urlRouterProvider.otherwise("/main");
}])

.run(['$rootScope', '$state', '$stateParams', function($rootScope, $state, $stateParams)
{
	$rootScope.$state = $state;

	// Helper to set a $watch on a scope, updating the title to the value of the watched expression.
	$rootScope.titleExpr = function(expr)
	{
		this.$watch(expr, function(t)
		{
			$rootScope.titleSuffix = ' - ' + t;
		});
		this.$on('$destroy', function()
		{
			$rootScope.titleSuffix = '';
		});
		// Prevent child scopes from overriding a parent's title.
		// \note Also prevents current scope from re-specifying the title expression (probably ok).
		this.titleExpr = function() {};
	};

	$rootScope.titleSuffix = '';
}])

;
