#pragma once

#include "util/Typedefs.hpp"
#include "world/map/terrain/Terrain.hpp"

#include <vector>
#include <memory>

// Christopher D. Canfield
// March 2014
// GameMap.hpp


namespace cdc
{
	class Node;

	///<summary>The game map, which contains tile information.</summary>
	class GameMap
	{
	public:
		typedef std::unique_ptr<GameMap> UniquePtr;

		///<summary>Constructs a new GameMap object.</summary>
		///<param name="height">The height of the map, in world coordinates.</summary>
		///<param name="width">The width of the map, in world coordinates.</summary>
		///<param name="tileHeight">The height of each tile, in world coordinates.</summary>
		///<param name="tileWidth">The width of each tile, in world coordinates.</summary>
		///<param name="tiles">A list of all terrain objects in the game.</summary>
		GameMap(uint height, uint width, uint tileHeight, uint tileWidth, std::vector<std::vector<Terrain::UniquePtr>> terrain);

		~GameMap() {}

		///<summary>Returns the height of the map, in world coordinates.</summary>
		///<returns>the height of the map.</returns>
		uint getHeight() const;

		///<summary>Returns the width of the map, in world coordinates.</summary>
		///<returns>the width of the map.</returns>
		uint getWidth() const;

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

		// TODO: add ability to change terrain objects?

	private:
		uint height;
		uint width;

		uint tileHeight;
		uint tileWidth;

		std::vector<std::vector<Terrain::UniquePtr>> terrain;

		void addTerrain(Terrain::UniquePtr);
	};
}