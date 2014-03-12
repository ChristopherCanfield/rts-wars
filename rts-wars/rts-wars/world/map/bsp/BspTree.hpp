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

	private:

		std::vector<std::vector<int>> leafNodes;
	};
}
