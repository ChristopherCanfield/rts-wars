#include "stdafx.h"
#include "GameMap.hpp"

// Christopher D. Canfield
// March 2014
// GameMap.cpp

using namespace cdc;
using namespace std;

GameMap::GameMap(uint height, uint width, uint tileHeight, uint tileWidth, std::vector<std::vector<Terrain::UniquePtr>> nodes) :
	rows(rows),
	columns(columns),
	tileHeight(tileHeight),
	tileWidth(tileWidth),
	nodes(nodes)
{
}


uint GameMap::getRows() const
{
	return rows;
}

uint GameMap::getColumns() const
{
	return columns;
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