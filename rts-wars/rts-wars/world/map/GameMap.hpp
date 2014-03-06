#pragma once

#include "util/Typedefs.hpp"
#include "Terrain.hpp"

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

		GameMap(uint height, uint width, uint tileHeight, uint tileWidth);

		~GameMap() {}

		///<summary>Returns the height of the map.</summary>
		///<returns>the height of the map.</returns>
		uint getHeight() const;

		///<summary>Returns the width of the map.</summary>
		///<returns>the width of the map.</returns>
		uint getWidth() const;

		///<summary>Returns the specified terrain.</summary>
		///<param name="x">the x location of the terrain, in world coordinates.</param>
		///<param name="y">the y location of the terrain, in world coordinates.</param>
		///<returns>The terrain.</returns>
		Terrain& getTerrain(uint x, uint y) const;

		///<summary>Returns the specified node.</summary>
		///<param name="x">the x location of the node, in world coordinates.</param>
		///<param name="y">the y location of the node, in world coordinates.</param>
		///<returns>The node.</returns>
		Node& getNode(uint x, uint y) const;

	private:
		uint height;
		uint width;

		uint tileHeight;
		uint tileWidth;

		std::vector<std::vector<Terrain::UniquePtr>> tiles;

		void addTerrain(Terrain::UniquePtr);
	};
}