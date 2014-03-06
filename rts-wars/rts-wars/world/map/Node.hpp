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

		explicit Node(Terrain&& terrain);
		~Node();

		std::vector<Node::WeakPtr>& getConnections() const;

		void addConnection(Node& node);

		void removeConnection(Node& node);

		Terrain& getTerrain() const;

	private:
		Terrain::UniquePtr terrain;

		std::vector<Node::WeakPtr> connections;
	};
}