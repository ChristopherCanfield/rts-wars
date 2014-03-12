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

		///<summary>Searches within an area, an returns a list of integers representing
		/// the indexes of the entities that are within that area.</summary>
		///<param name="searchArea">The search area.</param>
		///<returns>A vector of integers. The integer are indexes into the entity list.</returns>
		std::vector<int> findEntities(sf::IntRect searchArea);

		///<summary>Searches for an entity at a single point.</summary>
		///<param name="point">The point to search at.</param>
		///<returns></returns>
		int findEntity(sf::Vector2i point);

	private:
		bsp::TreeNode::SharedPtr root;

		// The leaf nodes. Each entity should be in a leaf node.
		std::vector<std::vector<int>> leafNodes;

		// Unassigned entity indexes. These will be assigned to the correct
		// leaf node when update() is called.
		std::vector<int> unassigned;
	};
}
