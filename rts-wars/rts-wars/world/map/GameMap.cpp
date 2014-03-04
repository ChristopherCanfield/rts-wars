#include "stdafx.h"
#include "GameMap.hpp"

// Christopher D. Canfield
// March 2014
// GameMap.cpp

using namespace cdc;


GameMap::GameMap(uint height, uint width, uint tileHeight, uint tileWidth) :
	height(height),
	width(width),
	tileHeight(tileHeight),
	tileWidth(tileWidth)
{
}


uint GameMap::getHeight() const
{
	return height;
}

uint GameMap::getWidth() const
{
	return width;
}

Tile& GameMap::getTile(uint x, uint y) const
{
	// TODO: implement this.

	uint gridX(x / tileWidth);
	uint gridY(y / tileHeight);
	return *tiles[gridX][gridY].get();
}

void GameMap::addTile(Tile::UniquePtr tile)
{
	// TODO: implement this.
}