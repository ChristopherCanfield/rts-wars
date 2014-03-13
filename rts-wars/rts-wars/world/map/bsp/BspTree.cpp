#include "stdafx.h"
#include "BspTree.hpp"

// Christopher D. Canfield
// March 2014
// BspTree.cpp

using namespace cdc;
using namespace cdc::bsp;
using namespace std;

///<summary>Builds the bsp tree.</summary>
///<param name="parent">The parent node.</param>
///<param name="width">The width of the region to place within the tree.</param>
///<param name="height">The height of the region to place within the tree.</param>
///<param name="axis">The axis to build along.</param>
///<param name="depth">The maximum depth of the tree. The root is at depth 0.</param>
///<param name="currentDepth">The current depth of the tree, starting at 0.</param>
void buildTree(TreeNode::SharedPtr& root, int width, int height, Axis axis, const int depth, int currentDepth = 0);

BspTree::BspTree(int mapWidth, int mapHeight)
{
	// Root:
	root = make_shared<TreeNode>(mapHeight, Axis::Z);

	int leafDepth = 3;
	// Build the tree.
	buildTree(root, mapWidth, mapHeight, Axis::X, leafDepth);

	// Create the leaf node vectors.
	auto leafNodeCount = static_cast<int>(pow(2, leafDepth));
	for (int i = 0; i < leafNodeCount; ++i)
	{
		leafNodes.push_back(vector<int>());
	}
}


BspTree::~BspTree()
{
}

///<summary>Builds the bsp tree.</summary>
///<param name="parent">The parent node.</param>
///<param name="width">The width of the region to place within the tree.</param>
///<param name="height">The height of the region to place within the tree.</param>
///<param name="axis">The axis to build along.</param>
///<param name="depth">The maximum depth of the tree. The root is at depth 0.</param>
///<param name="currentDepth">The current depth of the tree, starting at 0.</param>
void buildTree(TreeNode::SharedPtr& parent, int width, int height, Axis axis, const int depth, int currentDepth)
{
	if (currentDepth == depth)
	{
		// Return if the maximum depth of the tree has been reached.
		return;
	}

	const int point = (axis == Axis::X) ? width / 2 : height / 2;

	auto child1 = parent->setChild1(make_shared<TreeNode>(point, axis));
	auto child2 = parent->setChild2(make_shared<TreeNode>(point, axis));

	const Axis nextAxis = (axis == Axis::X) ? Axis::Z : Axis::X;
	const int nextWidth = (axis == Axis::X) ? width / 2 : width;
	const int nextHeight = (axis == Axis::Z) ? height / 2 : height;
	const int nextDepth = currentDepth + 1;

	// Recurse through the children.
	buildTree(child1, nextWidth, nextHeight, nextAxis, depth, nextDepth);
	buildTree(child2, nextWidth, nextHeight, nextAxis, depth, nextDepth);
}


std::vector<int> BspTree::findEntities(sf::IntRect searchArea)
{
	throw NotImplementedException("BspTree", "findEntities", "Not implemented");
}


int BspTree::findEntity(sf::Vector2i point)
{
	auto node = root.get();
	while (!node->isLeaf())
	{
		auto nodePoint = node->getChild1()->getPoint();
		if (node->getChild1()->getAxis() == Axis::X)
		{
			node = (point.x < nodePoint) ? node->getChild1() : node->getChild2();
		}
		else if (node->getChild1()->getAxis() == Axis::Z)
		{
			node = (point.y < nodePoint) ? node->getChild1() : node->getChild2();
		}
		else
		{
			throw GameLogicException("BspTree", "findEntity", "Invalid value returned by getAxis().");
		}
	}

	// TODO: complete this: need a way to get the vector index.
	throw NotImplementedException("BspTree", "findEntity", "Not yet implemented.");
}