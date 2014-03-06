#pragma once

// Christopher D. Canfield
// October 2013
// Node.hpp

#include "Edge.hpp"
#include "GridLocation.hpp"
#include "util/Typedefs.hpp"

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <functional>


namespace cdc 
{
	class Terrain;

	// A node in a graph.
	class Node :
		public sf::Drawable
	{
	public:
		typedef std::weak_ptr<Node> WeakPtr;
		typedef std::shared_ptr<Node> SharedPtr;

		Node(GridLocation location, int pixelX, int pixelY);
		~Node();

		Node(const Node&& other);
		Node& operator=(const Node&& other);
	
		// Adds an edge.
		// - edge: the Edge to add.
		// - addEdgeToOppositeNode: add the Edge to the opposite node as well.
		//		In other words, if this is adding edge A->B, also add B->A.
		Node& addEdge(Edge::SharedPtr edge, bool addEdgeToOppositeNode = true);

		// Removes an edge.
		void removeEdge(Edge& edge, bool removeEdgeFromOpposite = true);

		// Returns a reference to the edge list.
		const std::vector<Edge::WeakPtr>& getEdgeList() const;

		// Returns a reference to an edge.
		// - index: the edge's index in the Node's edge list.
		Edge& getEdge(uint index) const;

		// Returns true if the edge exists.
		bool edgeExists(Edge& edge) const;

		// Gets the x location of the Node, in pixels.
		template <class T>
		T getPixelX() const;

		// Gets the y location of the Node, in pixels.
		template <class T>
		T getPixelY() const;

		sf::Rect<float> getBoundingBox() const;

		// Returns the node's row in the navigation grid.
		uint getRow() const;

		// Returns the node's column in the navigation grid.
		uint getColumn() const;

		// Returns true if the node is connected to the navigation graph 
		// (i.e., it has at least one edge).
		bool isConnected() const;

		Terrain& getTerrain() const;

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

		std::string toString() const;

		bool operator==(const Node& other) const;
		bool operator!=(const Node& other) const;

	private:
		void removeEdge(Edge& edge);

		Terrain::UniquePtr terrain;

		std::vector<Edge::WeakPtr> edges;

		int pixelX;
		int pixelY;

		// The node's row-column location.
		GridLocation location;

		// The graphical representation of the node.
		sf::CircleShape circle;
	};

	template <class T>
	T Node::getPixelX() const
	{
		return static_cast<T>(pixelX);
	}

	template <class T>
	T Node::getPixelY() const
	{
		return static_cast<T>(pixelY);
	}
}

std::ostream& operator<<(std::ostream& stream, const cdc::Node& node);


namespace std
{
	template<>
	class hash<cdc::Node>
	{
	public:
		// Adapted from Bjarne Stroustrup, "A Tour of C++"
		std::size_t operator()(const cdc::Node& key) const
		{
			return hash<uint>()(key.getColumn()) ^
					hash<uint>()(key.getRow());
		}
	};
}