#include "stdafx.h"
#include "GameMap.hpp"

// Christopher D. Canfield
// March 2014
// GameMap.cpp

using namespace cdc;
using namespace std;

GameMap::GameMap(uint rows, uint columns, uint tileHeight, uint tileWidth, std::vector<Node> nodes) :
	rows(rows),
	columns(columns),
	tileHeight(tileHeight),
	tileWidth(tileWidth),
	navGraph(move(nodes))
{
	for (const auto& node : navGraph)
	{
		auto gridLocation(GridLocation(node.getRow(), node.getColumn()));
		if (nodeIndices.count(gridLocation) == 0)
		{
			nodeIndices[GridLocation(node.getRow(), node.getColumn())] = node.getIndex();
		}
		else
		{
			stringstream s;
			s << "Duplicate GridLocation in navGraph: " << node.getRow() << ", " << node.getColumn();
			throw GameLogicException(s.str());
		}
	}
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
	GridLocation gridLocation(x / tileWidth, z / tileHeight);
	#ifdef _DEBUG
		if (nodeIndices.count(gridLocation) == 0)
		{
			stringstream s;
			s << "Invalid x and z provided to getTerrain. x: " << x << "; z: " << z << "; row: "
				<< gridLocation.getRow() << "; column: " << gridLocation.getColumn();
			throw NavGraphException(s.str());
		}
	#endif

	auto index = nodeIndices.at(gridLocation);
	return navGraph[index].getTerrain();
}