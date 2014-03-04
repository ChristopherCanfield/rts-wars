#pragma once

#include "util/Typedefs.hpp"
#include "Tile.hpp"

#include <vector>

// Christopher D. Canfield
// March 2014
// GameMap.hpp


namespace cdc
{
	///<summary>The game map, which contains tile information.</summary>
	class GameMap
	{
	public:
		GameMap(uint height, uint width, uint tileHeight, uint tileWidth);

		~GameMap() {}

		///<summary>Returns the height of the map.</summary>
		///<returns>the height of the map.</returns>
		uint getHeight() const;

		///<summary>Returns the width of the map.</summary>
		///<returns>the width of the map.</returns>
		uint getWidth() const;

		///<summary>Returns the height of the map.</summary>
		///<param name="x">the x location of the tile, in world coordinates.</param>
		///<param name="y">the y location of the tile, in world coordinates.</param>
		///<returns>the height of the map.</returns>
		Tile& getTile(uint x, uint y) const;

	private:
		uint height;
		uint width;

		uint tileHeight;
		uint tileWidth;

		std::vector<std::vector<Tile::UniquePtr>> tiles;

		void addTile(Tile::UniquePtr);
	};
}