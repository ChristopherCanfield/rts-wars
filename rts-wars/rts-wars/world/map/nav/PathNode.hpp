#pragma once

#include <vector>
#include <memory>

// Christopher D. Canfield
// October 2013
// PathNode.hpp


namespace cdc
{
	class Node;

	// A wrapper around a Node that includes the cost of getting to the Node
	// (edge cost + heuristic cost).
	class PathNode
	{
	public:
		PathNode(const PathNode& pathNode);
		PathNode(const Node& node, float g, float h);
		PathNode(const Node& node, const std::shared_ptr<PathNode> parent, float g, float h);
		PathNode(const Node& node, const std::shared_ptr<PathNode> parent, int g, int h);

		PathNode& operator=(const PathNode& rhs);
	
		const std::vector<uint> PathNode::getAdjacent() const;

		// Returns the underlying navigation node.
		Node& getNode() const;
		
		// Returns the parent search node (i.e., the node that led to this node). 
		// May return nullptr if there is no parent.
		PathNode* getParent() const;

		float getG() const;
		float getH() const;

		// Returns the g + h cost.
		float getCost() const;

		bool operator==(const PathNode& other) const;
		bool operator==(const Node& other) const;

	private:
		// Reference to a node. This is a non-owning class.
		Node* node;
		// The search node's parent.
		std::shared_ptr<PathNode> parent;
		// The actual cost of the path from the start to this node.
		float gCost;
		// The heuristic cost of this node.
		float hCost;
	};
}