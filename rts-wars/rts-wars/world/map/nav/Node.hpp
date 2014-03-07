#pragma once

// Christopher D. Canfield
// October 2013
// Node.hpp

#include "Edge.hpp"
#include "GridLocation.hpp"
#include "util/Typedefs.hpp"
#include "world/map/terrain/Terrain.hpp>

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>
#include <functional>


namespace cdc 
{
	// A node in a graph.
	class Node :
		public sf::Drawable
	{
	public:
		Node(GridLocation location, uint index, int pixelX, int pixelY, Terrain::UniquePtr terrain);
		~Node();

		Node(const Node&& other);
		Node& operator=(const Node&& other);

		// Returns a reference to the list of adjacent nodes.
		const std::vector<uint>& getAdjacent() const;

		uint getIndex() const;

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
		Terrain::UniquePtr terrain;

		std::vector<uint> adjacent;

		int pixelX;
		int pixelY;

		uint index;

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