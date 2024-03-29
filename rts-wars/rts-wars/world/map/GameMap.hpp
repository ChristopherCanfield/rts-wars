#pragma once

#include "util/Typedefs.hpp"
#include "world/map/terrain/Terrain.hpp"
#include "world/map/nav/Node.hpp"
#include "world/map/nav/GridLocation.hpp"

#include <vector>
#include <memory>

// Christopher D. Canfield
// March 2014
// GameMap.hpp


namespace cdc
{
	///<summary>The game map, which contains tile information.</summary>
	class GameMap
	{
	public:
		typedef std::unique_ptr<GameMap> UniquePtr;
		typedef std::vector<Node> NavGraphList;

		///<summary>Constructs a new GameMap object.</summary>
		///<param name="rows">The number of rows of terrain objects.</summary>
		///<param name="columns">The number of rows of terrain objects.</summary>
		///<param name="tileHeight">The height of each tile, in world coordinates.</summary>
		///<param name="tileWidth">The width of each tile, in world coordinates.</summary>
		///<param name="nodes">A list of all node objects in the game.</summary>
		GameMap(uint rows, uint columns, uint tileHeight, uint tileWidth, std::vector<Node> nodes);

		~GameMap() {}

		///<summary>Returns the number of rows of terrain objects.</summary>
		///<returns>the number of rows of terrain objects.</returns>
		uint getRows() const;

		///<summary>Returns the number of columns of terrain objects.</summary>
		///<returns>the number of columns of terrain objects.</returns>
		uint getColumns() const;

		///<summary>Returns the width of the map.</summary>
		///<returns>the width of the map.</returns>
		int getWidth() const;

		///<summary>Returns the height of the map.</summary>
		///<returns>the height of the map.</returns>
		int getHeight() const;

		///<summary>Returns the specified terrain.</summary>
		///<param name="x">the x location of the terrain, in world coordinates.</param>
		///<param name="z">the z location of the terrain, in world coordinates.</param>
		///<returns>The terrain.</returns>
		Terrain& getTerrain(uint x, uint z) const;

		///<summary>Returns the specified node.</summary>
		///<param name="x">the x location of the node, in world coordinates.</param>
		///<param name="z">the z location of the node, in world coordinates.</param>
		///<returns>The node.</returns>
		Node& getNode(uint x, uint z) const;

		///<summary>Returns a reference to the navigation graph.</summary>
		///<returns>The nav graph, as a list.</returns>
		const std::vector<Node>& getNavGraph() const;

		// TODO: add ability to change terrain objects?

	private:
		// The number of rows of terrain objects.
		uint rows;
		// The number of columns of terrain objects.
		uint columns;

		uint tileHeight;
		uint tileWidth;

		std::vector<Node> navGraph;

		std::unordered_map<GridLocation, uint> nodeIndices;
	};
}