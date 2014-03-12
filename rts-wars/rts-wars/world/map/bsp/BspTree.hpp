#pragma once

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
		BspTree();
		~BspTree();

		///<summary>Assigns entities to leaf nodes.</summary>
		void update();

	private:
		// The leaf nodes. Each entity should be in a leaf node.
		std::vector<std::vector<int>> leafNodes;

		// Unassigned entity indexes. These will be assigned to the correct
		// leaf node when update() is called.
		std::vector<int> unassigned;
	};
}
