#include "stdafx.h"
#include "GameMap.hpp"

// Christopher D. Canfield
// March 2014
// GameMap.cpp

using namespace cdc;
using namespace std;

GameMap::GameMap(uint height, uint width, uint tileHeight, uint tileWidth, std::vector<std::vector<Terrain::UniquePtr>> terrain) :
	height(height),
	width(width),
	tileHeight(tileHeight),
	tileWidth(tileWidth),
	terrain(move(terrain))
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

Terrain& GameMap::getTerrain(uint x, uint z) const
{
	uint gridX(x / tileWidth);
	uint gridZ(z / tileHeight);

	#ifdef _DEBUG
		if (gridX > terrain.size() - 1)
		{
			throw new GameLogicException("GameMap::getTerrain: x parameter is out of range: " + gridX);
		}
		else if (gridZ > terrain[0].size() - 1)
		{
			throw new GameLogicException("GameMap::getTerrain: z parameter is out of range: " + gridZ);
		}
	#endif

	return *terrain[gridX][gridZ].get();
}

void GameMap::addTerrain(Terrain::UniquePtr tile)
{
	uint gridX(tile->getX() / tileWidth);
	uint gridY(tile->getZ() / tileHeight);
}