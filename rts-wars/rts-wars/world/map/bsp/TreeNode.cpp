#include "stdafx.h"
#include "TreeNode.hpp"

// Christopher D. Canfield
// March 2014
// TreeNode.cpp

using namespace cdc;
using namespace bsp;

bsp::TreeNode::TreeNode(int point, Axis axis) :
	point(point),
	axis(axis),
	child1(nullptr),
	child2(nullptr)
{
}


bsp::TreeNode::~TreeNode()
{
}


bsp::TreeNode* bsp::TreeNode::getChild1() const
{
	if (child1)
	{
		return child1.get();
	}
	return nullptr;
}

///<summary>Sets the first child.</summary>
///<param name="child">Pointer to the child.</param>
TreeNode::SharedPtr bsp::TreeNode::setChild1(TreeNode::SharedPtr child)
{
	child1 = child;
	return child1;
}

///<summary>Gets the second child, or null if there isn't one.</summary>
///<returns>The second child, or null if there isn't one.</returns>
bsp::TreeNode* bsp::TreeNode::getChild2() const
{
	if (child2)
	{
		return child2.get();
	}
	return nullptr;
}

///<summary>Sets the second child.</summary>
///<param name="child">Pointer to the child.</param>
TreeNode::SharedPtr bsp::TreeNode::setChild2(TreeNode::SharedPtr child)
{
	child2 = child;
	return child2;
}

int bsp::TreeNode::getPoint() const
{
	return point;
}

Axis bsp::TreeNode::getAxis() const
{
	return axis;
}