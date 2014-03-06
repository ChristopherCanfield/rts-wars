#pragma once

#include "world/map/Terrain.hpp"

#include <memory>
#include <vector>

// Christopher D. Canfield
// March 2014
// Node.hpp


namespace cdc
{
	///<summary>A navigation node.</summary>
	class Node
	{
	public:
		typedef std::weak_ptr<Node> WeakPtr;
		typedef std::shared_ptr<Node> SharedPtr;

		explicit Node(Terrain&& terrain);
		~Node();

		std::vector<Node::WeakPtr>& getConnections();

		void addConnection(Node::SharedPtr node);

		void removeConnection(Node& node);

		Terrain& getTerrain() const;

	private:
		Terrain::UniquePtr terrain;

		std::vector<Node::WeakPtr> connections;
	};
}