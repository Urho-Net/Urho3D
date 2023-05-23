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

// Directives

angular.module('cherry.directives', [])

.directive('appVersion', ['version', function(version)
{
	return function(scope, elm, attrs) {
		elm.text(version);
	};
}])

// When window is resized, compute height of this element accordingly.
// \note [nuutti] This is pretty hacky, and assumes that there are no
//				  other elements below this one. (Specifically, assumes
//				  that all vertical space below this element's content
//				  is caused by the margins, borders and paddings of
//				  this element and and its parents.)
.directive('sizedByWindow', function($document, $window, $timeout)
{
	return function(scope, elem)
	{
		var setHeight = function()
		{
			var pads = function(e)
			{
				if (e.outerHeight)
					return e.outerHeight(true) - e.height();
			};

			var allPads = 0;
			// Compute the size of presumed margins, borders and paddings below
			// elem.offset().top . We assume that top margins etc. are equal to bottom.
			allPads += pads(elem); // Both top and bottom for this element (offset begins at margin?)
			elem.parents().each(function()
			{
				allPads += pads($(this))/2; // Only bottom for parent elements.
			});

			elem.height($(window).height() - elem.offset().top - allPads);
		};

		angular.element($window).bind('resize', setHeight);

		scope.elemTop = function(){return elem.offset().top;};
		scope.$watch('elemTop()', setHeight);
	}
})

// Horizontally draggable thing, for adjusting the widths of two elements next to each other.
.directive('sizeDragBar', function($document, $window)
{
	return function(scope, barElem, attrs)
	{
		var dragAttrs		= JSON.parse(attrs.sizeDragBar);
		var leftElem		= $('#'+dragAttrs.left);
		var rightElem		= $('#'+dragAttrs.right);
		var containerElem	= $('#'+dragAttrs.container);

		var barLeftOffset;			// Difference between the bar's left side (at the time of mousedown) and mouse's x (page) position.
		var currentBarLeftRatio;	// Current position (in percentages) of the bar's left edge.

		barElem.on('mousedown', function(event)
		{
			event.preventDefault();
			$document.on('mousemove', move);
			$document.on('mouseup', up);
			barLeftOffset = leftElem.outerWidth() - event.pageX;
		});

		function percentStr(ratio)
		{
			return ratio*100.0 + '%';
		}

		function pads(elem)
		{
			return elem.outerWidth(true) - elem.width();
		}

		function setSizes(barLeftRatio)
		{
			var barWidthRatio			= barElem.outerWidth(true) / containerElem.width();
			var leftElemWidthRatio		= barLeftRatio;
			var rightElemWidthRatio		= 1.0 - barWidthRatio - barLeftRatio;

			// on some configurations (precision issues?) we need to give some leeway for the implementation
			var errorTolerance			= 0.01;

			leftElem.width(percentStr(leftElemWidthRatio - pads(leftElem)/containerElem.width() - errorTolerance));
			rightElem.width(percentStr(rightElemWidthRatio - pads(rightElem)/containerElem.width() - errorTolerance));

			currentBarLeftRatio = barLeftRatio;
		}

		function recompute()
		{
			setSizes(currentBarLeftRatio);
		}

		function move(event)
		{
			var barWidthRatio	= barElem.outerWidth(true) / containerElem.width();
			var barLeftRatio	= (event.pageX + barLeftOffset) / containerElem.width();

			barLeftRatio = Math.max(barLeftRatio, dragAttrs.leftMinWidthRatio);
			barLeftRatio = Math.min(barLeftRatio, 1.0 - dragAttrs.rightMinWidthRatio - barWidthRatio);

			setSizes(barLeftRatio);
		}

		function up()
		{
			$document.unbind('mousemove', move);
			$document.unbind('mouseup', up);
		}

		angular.element($document).ready(function(){ setSizes(dragAttrs.initialLeftWidthRatio); });
		// \note Due to precision issues (?) in the precentage widths, we need
		//		 to recompute the widths when window is resized.
		angular.element($window).bind('resize', recompute);
	}
})

.directive('fileNameModel', function($compile)
{
	return {
		restrict:	'A',
		link:		function(scope, elem, attrs)
		{
			// \note this.value will be a string; JSON.stringify is used to escape possible single quotes in it.
			elem.attr('onchange', 'angular.element(this).scope().$apply("' + attrs.fileNameModel + ' = " + JSON.stringify(this.value))');
		}
	}
})

.directive('fileModel', function($compile)
{
	return {
		restrict:	'A',
		link:		function(scope, elem, attrs)
		{
			elem.attr('onchange', 'angular.element(this).scope().' + attrs.fileModel + ' = this.files;');
			scope.$watch(attrs.fileModel, function(file) {
				if (typeof file === "undefined" || file.length == 0)
				{
					// File input can only be cleared programmatically.
					elem.val("");
				}
			});
		}
	}
})

.directive('onOffButtonModel', function($compile)
{
	return {
		restrict:	'A',
		link:		function(scope, elem, attrs)
		{
			var modelNameStr = JSON.stringify(attrs.onOffButtonModel);
			elem.attr('onclick', 'angular.element(this).scope().$apply(' + modelNameStr + ' + " = !" + ' + modelNameStr + ');');
			scope.$watch(attrs.onOffButtonModel, function(active)
			{
				if (active)
					elem.addClass('active');
				else
					elem.removeClass('active');
			});
		}
	}
})

.directive('deDynamicHtml', ['$compile', function($compile)
{
	// \todo [petri] is this a better way of doing dynamic html?
	return {
		restrict:	'A',
		replace:	true,
		link:		function(scope, elem, attrs)
		{
			scope.$watch(attrs.deDynamicHtml, function(html)
			{
				if (html)
				{
					var compiled = $compile(html.trim())(scope);
					elem.html('').append(compiled);
				}
			});
		}
	};
}])

.directive('rtdbVersionView', ['$compile', 'rtdb', 'rpc', function($compile, rtdb, rpc)
{
	return {
		restrict:		'A',
		transclude:		true,
		template:		'<div ng-if="rtdbVersionView.id !== undefined" ng-transclude></div>',
		link:			function(scope)
		{
			scope.rtdbVersionView = { id: undefined };
			rpc.call('rtdb.NewVersionView', {})
			.then(function(viewId)
			{
				scope.rtdbVersionView.id = viewId;
				scope.$on('$destroy', function()
				{
					scope.rtdbVersionView.id = undefined;
					rpc.call('rtdb.ReleaseVersionView', { viewId: viewId });
				});
			});
		}
	};
}])

;
