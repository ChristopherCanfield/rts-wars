#pragma once

#include "TreeNode.hpp"

#include <vector>

// Christopher D. Canfield
// March 2014
// BspTree.hpp

namespace cdc
{
	///<summary>A Binary Space Partition tree.</summary>
	class BspTree
	{
	public:
		BspTree(int mapWidth, int mapHeight);
		~BspTree();

		///<summary>Assigns entities to leaf nodes.</summary>
		void update();

	private:
		bsp::TreeNode::SharedPtr root;

		// The leaf nodes. Each entity should be in a leaf node.
		std::vector<std::vector<int>> leafNodes;

		// Unassigned entity indexes. These will be assigned to the correct
		// leaf node when update() is called.
		std::vector<int> unassigned;
	};
}
