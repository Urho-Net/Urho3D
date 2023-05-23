'use strict';

function genTestCaseTree(testCasePaths, rootLabel)
{
	var genTree = function(testCasePaths, depth, skipLength)
	{
		// Find common prefixes for all test cases.
		var groups = {};
		var labels = [];
		for (var ndx = 0; ndx < testCasePaths.length; ndx++)
		{
			var path	= testCasePaths[ndx];
			var dotNdx	= path.indexOf('.', skipLength);
			var isLeaf	= dotNdx === -1;
			var label	= isLeaf ? path.substring(skipLength) : path.substring(skipLength, dotNdx);

			if (!groups.hasOwnProperty(label))
			{
				groups[label] =
				{
					isLeaf:		isLeaf,
					path:		isLeaf ? path : path.substring(0, dotNdx),
					children:	[]
				};
				labels.push(label);
			}
			groups[label].children.push(path);
		}

		var result = [];

		for (var labelNdx = 0; labelNdx < labels.length; labelNdx++)
		{
			var label = labels[labelNdx];
			var group = groups[label];

			if (group.isLeaf)
			{
				var testCasePath = group.children[0];
				result.push({
					id:					'!'+testCasePath,
					type:				'testCase',
					label:				label,
					path:				testCasePath,
					depth:				depth,
					headerIdSuffix:		'/' + testCasePath
				});
			}
			else
			{
				result.push({
					id:					'!'+group.path,
					type:				'testGroup',
					label:				label,
					path:				group.path,
					depth:				depth,
					children:			genTree(group.children, depth + 1, skipLength + label.length + 1),
					headerIdSuffix:		'/' + group.path
				});
			}
		}

		return result;
	};

	// Built-in root node for whole tree.
	return [{
		id:					'!',
		type:				'testGroup',
		label:				rootLabel,
		path:				'',
		depth:				0,
		children:			genTree(testCasePaths, 1, 0),
		headerIdSuffix:		'/'
	}];
}

// Returns a filter string (possibly containing multiple filters separated
// with semicolons) representing a subset of the rootNodes tree.
// A node is covered by the filters if either includeNodeInSubTree(node.id)
// is true or the node's parent is covered by the filters.
var genTestCaseTreeSubsetFilter = function(rootNodes, includeNodeInSubTree)
{
	var allSelected = function(nodes)
	{
		return _.all(nodes, function(node) { return includeNodeInSubTree(node.id) || (node.children && allSelected(node.children)); });
	};

	var filtersStr = function(nodes)
	{
		var filters = [];
		for (var ndx = 0; ndx < nodes.length; ndx++)
		{
			var node = nodes[ndx];
			if (node.children)
			{
				if (includeNodeInSubTree(node.id) || allSelected(node.children))
					filters.push(node.path === '' ? '*' : node.path + '.*');
				else
				{
					var f = filtersStr(node.children);
					if (f)
						filters.push(f);
				}
			}
			else if (includeNodeInSubTree(node.id))
				filters.push(node.path);
		}
		return filters.join(';');
	};

	return filtersStr(rootNodes);
};

// Calls visit on all nodes with depth < maxDepth.
function traverseTestCaseTreeToDepth(nodes, maxDepth, visit)
{
	for (var nodeNdx = 0; nodeNdx < nodes.length; nodeNdx++)
	{
		var node = nodes[nodeNdx];
		if (node.depth < maxDepth)
		{
			visit(node);
			if (node.depth+1 < maxDepth)
				traverseTestCaseTreeToDepth(node.children, maxDepth, visit);
		}
	}
}

function setTestCaseTreeInitialDepthExpansion(nodes, depth)
{
	traverseTestCaseTreeToDepth(nodes, depth, function(node) { node.initiallyExpanded = true; });
}

// Calls visit on all nodes on the path to targetNodePath, in order of ascending depth.
function traverseTestCaseTreeToNode(nodes, targetNodePath, visit)
{
	for (var nodeNdx = 0; nodeNdx < nodes.length; nodeNdx++)
	{
		var node = nodes[nodeNdx];
		if (targetNodePath.lastIndexOf(node.path, 0) === 0 && (node.path === '' || node.path.length === targetNodePath.length || targetNodePath[node.path.length] === '.'))
		{
			visit(node);
			if (targetNodePath !== node.path)
				traverseTestCaseTreeToNode(node.children, targetNodePath, visit);
		}
	}
}

function setTestCaseTreeInitialPathExpansion(nodes, targetNodePath)
{
	traverseTestCaseTreeToNode(nodes, targetNodePath, function(node)
	{
		if (node.path !== targetNodePath)
			node.initiallyExpanded = true;
	});
}

function getTestCaseTreeNodeIdFromPath(nodes, nodePath)
{
	var result;
	traverseTestCaseTreeToNode(nodes, nodePath, function(node) { result = node.id; });
	return result;
}

// Mutates the given tree, setting a 'hidden' attribute
// for each node N to !preserveNode(N). Also hides groups
// that only have hidden children.
function filterTestCaseTree(tree, preserveNode)
{
	var filter = function(tree)
	{
		var allHidden = true;
		for (var nodeNdx = 0; nodeNdx < tree.length; nodeNdx++)
		{
			var node = tree[nodeNdx];
			node.hidden = !preserveNode(node);
			if (node.type === 'testGroup')
			{
				var allChildrenHidden = filter(node.children);
				node.hidden = node.hidden || allChildrenHidden;
			}
			allHidden = allHidden && node.hidden;
		}
		return allHidden;
	};
	filter(tree);
}
