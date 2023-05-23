'use strict';

// Tree control component meant for viewing a tree (or, rather, a forest) and
// selecting nodes in it.
// This is a modified version of angular-tree-control.
// The template appearing in the tree control element will be replicated for
// each (visible) node, each having its own scope whose parent is the entire
// tree control's parent scope, and that contains two additional variables:
// 'node', which is the node object in the tree, and 'groupShared', which is
// an (initially empty) object that is the same object for sibling nodes (and
// different for non-siblings).
//
// Attributes:
//   tree-model (required)
//     Angular expression evaluating to an array containing the root nodes of
//     the forest. Each node shall have a property named 'id', a string unique
//     to the node within the forest. Also, if node.initiallyExpanded is truthy,
//     node will be expanded when the tree is formed. A node may have a property
//     'children', an array containing the children. Furthermore, if node.hidden
//     is truthy for node, that node (and its descendants, if any) is hidden
//     (its DOM and angular stuff etc. are generated but hidden).
//
//  tree-selectable (optional)
//    If exists, the nodes in the tree are selectable. Can contain the following
//    properties:
//      selectionType
//        A function taking a click event as a parameter; returns a value
//        telling what kind of selection the click corresponds to. The returned
//        value must be one of the following:
//          any falsey value: no changes to the selection
//          'area': select sequentially from the last-clicked to the currently
//            clicked node (something like shift+click selection)
//          'multiple': toggle the selectedness state of the clicked node
//            (ctrl+click selection)
//          'single': unselect all other nodes; select this node
//
//      setAccess
//        A function that will be called in the tree's initialization with an
//        object having the following properties that provide access to the tree
//        control from outside (none of the properties shall be modified from
//        outside):
//          selectNode: a function that takes a node's id and selects the node.
//            Sometimes it's useful to select nodes from the outside, like if
//            you want to set a node as initially selected.
//          unselectAll: a function that unselects all nodes in the tree
//          anySelected: a boolean that will be updated according to whether any
//            nodes are selected at a given moment
//          nodeSelected: a function taking a node's id and returning a boolean
//            telling whether the node is selected

(function (angular)
{
	'use strict';

	angular.module('treeControl', [])

	.directive('treecontrol', ['$compile', '$detail', function($compile, $detail)
	{
		return {
			restrict:	'EA',
			require:	"treecontrol",
			transclude:	true,
			scope: {
				treeModel:			"=",
				treeSelectable:		"=",
			},

			controller: ['$scope', function($scope)
			{
				$scope.nodeExpanded = {};

				$scope.parentScopeOfTree = $scope.$parent;

				$scope.headClass = function(node)
				{
					if (!node.hasOwnProperty('children'))
						return "tree-leaf";
					else if ($scope.nodeExpanded[node.id])
						return "tree-expanded";
					else
						return "tree-collapsed";
				};

				$scope.nodeExpanded = function(node)
				{
					return !!$scope.nodeExpanded[node.id];
				};

				$scope.nodeHeadClicked = function(node, event)
				{
					$scope.nodeExpanded[node.id] = !$scope.nodeExpanded[node.id];

					// if expanding and only one visible child, expand that too
					if ($scope.nodeExpanded(node))
					{
						$detail.expandOnlyChild($scope, node);
					}

					event.stopPropagation();
				};

				$scope.nodeSelected = {};

				var treeAccess;
				var numSelectedNodes = 0;

				var setNodeSelectionStatus = function(nodeId, selected)
				{
					numSelectedNodes += (selected ? 1 : 0) - ($scope.nodeSelected[nodeId] ? 1 : 0);
					$scope.nodeSelected[nodeId] = selected;
					treeAccess.anySelected = numSelectedNodes !== 0;
				};

				var toggleNodeSelectionStatus = function(nodeId)
				{
					setNodeSelectionStatus(nodeId, !$scope.nodeSelected[nodeId]);
				};

				var unselectAll = function()
				{
					numSelectedNodes = 0;
					$scope.nodeSelected = {};
					treeAccess.anySelected = false;
				};

				var latestClickedNodeId = undefined;
				$scope.nodeClicked = function(nodeId, event)
				{
					if ($scope.treeSelectable)
					{
						var selectionType = $scope.treeSelectable.selectionType(event);

						if (selectionType)
						{
							if (selectionType === 'area')
							{
								if (latestClickedNodeId !== undefined)
								{
									var id0		= latestClickedNodeId;
									var id1		= nodeId;
									var endId	= undefined;

									var traverse = function(nodes, isVisible)
									{
										for (var ndx = 0; ndx < nodes.length; ndx++)
										{
											var node = nodes[ndx];

											if (endId === undefined && (node.id === id0 || node.id === id1))
												endId = node.id === id0 ? id1 : id0;

											if (endId !== undefined)
											{
												if (isVisible && !node.hidden)
													setNodeSelectionStatus(node.id, true);
												if (node.id === endId)
													return false;
											}

											if (node.children && !traverse(node.children, isVisible && !node.hidden && $scope.nodeExpanded(node)))
												return false;
										}

										return true;
									};

									traverse($scope.treeModel, true);
								}
							}
							else if (selectionType === 'multiple')
								toggleNodeSelectionStatus(nodeId);
							else if (selectionType === 'single')
							{
								unselectAll();
								setNodeSelectionStatus(nodeId, true);
							}
							else
								throw new Error('Invalid selectionType() in tree control');

							event.preventDefault();
						}

						event.stopPropagation();
						latestClickedNodeId = nodeId;
					}
				};

				if ($scope.treeSelectable)
				{
					treeAccess = {
						selectNode:		function(nodeId) { setNodeSelectionStatus(nodeId, true); },
						unselectAll:	unselectAll,
						anySelected:	false,
						nodeSelected:	function(nodeId) { return !!$scope.nodeSelected[nodeId]; },
					};

					if ($scope.treeSelectable.setAccess)
						$scope.treeSelectable.setAccess(treeAccess);
				}

				var template =
					'<ul>' +
					'<li ng-repeat="node in node.children" ng-class="headClass(node)" ng-show="!node.hidden" ng-init="groupShared=childrenGroupShared;childrenGroupShared={};">' +
					'<i class="tree-branch-head" ng-click="nodeHeadClicked(node, $event)"></i>' +
					'<i class="tree-leaf-head"></i>' +										// \todo [petri] this is not really necessary (only used for layouting now)
					'<div class="tree-label" tree-transclude ng-click="nodeClicked(node.id, $event)" ng-class="{\'tree-selected\':nodeSelected[node.id]}"></div>' +
					'<treeitem ng-if="nodeExpanded(node)"></treeitem>' +
					'</li>' +
					'</ul>';

				return {
					template: $compile(template)
				}
			}],

			link: function (scope, element, attrs, treemodelCntr, childTranscludeFn)
			{
				scope.$watch("treeModel", function updateNodeOnRootScope(newValue)
				{
					if (angular.isArray(newValue))
					{
						if (angular.isDefined(scope.node) && angular.equals(scope.node.children, newValue))
							return;
						scope.node = {};
						scope.node.children = newValue;
					}
					else
					{
						if (angular.equals(scope.node, newValue))
							return;
						scope.node = newValue;
					}

					scope.groupShared = {};
					scope.childrenGroupShared = {};
				});

				// Rendering template for a root node
				treemodelCntr.template(scope, function(clone)
				{
					element.html('').append(clone);
				});

				scope.$treeTransclude = childTranscludeFn;
			}
		};
	}])

	.directive("treeitem", function()
	{
		return {
			restrict: 'E',
			require: "^treecontrol",
			link: function(scope, element, attrs, treemodelCntr)
			{
				// Rendering template for the current node
				treemodelCntr.template(scope, function(clone)
				{
					element.html('').append(clone);
				});
			}
		}
	})

	.directive("treeTransclude", [ "$detail", function($detail)
	{
		return {
			link: function(scope, element, attrs)
			{
				if (scope.node.initiallyExpanded && !scope.nodeExpanded.hasOwnProperty(scope.node.id))
				{
					scope.nodeExpanded[scope.node.id] = true;
					$detail.expandOnlyChild(scope, scope.node);
				}

				// create a scope for the transclusion, whos parent is the parent of the tree control
				scope.transcludeScope = scope.parentScopeOfTree.$new();
				scope.transcludeScope.node = scope.node;
				scope.transcludeScope.groupShared = scope.groupShared;
				scope.$on('$destroy', function()
				{
					scope.transcludeScope.$destroy();
				});

				scope.$treeTransclude(scope.transcludeScope, function(clone)
				{
					element.empty();
					element.append(clone);
				});
			}
		}
	}])

	.factory("$detail", function ()
	{
		return {
			expandOnlyChild: function (scope, node)
			{
				var _expandOnlyChild = function(node)
				{
					var onlyChild = undefined;

					if (!node.hasOwnProperty("children"))
						return;

					for (var ndx = 0; ndx < node.children.length; ndx++)
					{
						var childNode = node.children[ndx];

						if (!childNode.hidden && onlyChild === undefined)
							onlyChild = childNode;
						else if (!childNode.hidden)
						{
							onlyChild = undefined;
							break;
						}
					}

					if (onlyChild !== undefined)
					{
						scope.nodeExpanded[onlyChild.id] = true;
						_expandOnlyChild(onlyChild);
					}
				};

				_expandOnlyChild(node);
			}
		};
	});

})(angular);
