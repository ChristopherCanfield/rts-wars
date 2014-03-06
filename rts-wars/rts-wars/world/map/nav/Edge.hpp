#pragma once

// Christopher D. Canfield
// October 2013
// Edge.hpp

#include "util/Typedefs.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>


namespace cdc 
{
	class Node;
	class PathNode;

	// An edge between nodes in the graph.
	class Edge :
			public sf::Drawable
	{
	public:
		typedef std::weak_ptr<Edge> WeakPtr;
		typedef std::shared_ptr<Edge> SharedPtr;

		explicit Edge(Node& startNode);
		Edge(Node& startNode, Node& endNode, float cost);
		Edge(Node& startNode, Node& endNode, int cost);

		// Returns the the first node that the edge is connected to.
		Node* getNode1() const;

		// Returns the second node that the edge is connected to, or nullptr if there
		// is no connected node.
		Node* getNode2() const;

		// Returns the node opposite the specified node, or nullptr if 
		// none exists.
		Node* getOppositeNode(const Node& node) const;
		Node* getOppositeNode(PathNode node) const;

		// Returns the cost of moving along the edge.
		float getCost() const;

		bool operator==(const Edge& other) const;
		bool operator!=(const Edge& other) const;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
		void draw(sf::RenderTarget &target, sf::RenderStates states, sf::Color color) const;

	private:
		void Edge::setVertices(Node& startNode, Node& endNode);

		// The start node.
		Node* startNode;
		// The end node, or nullptr if no node is connected to the other edge
		Node* endNode;

		// The cost of moving along the edge.
		float cost;

		// The graphical representation of the edge.
		sf::VertexArray vertices;
	};
}