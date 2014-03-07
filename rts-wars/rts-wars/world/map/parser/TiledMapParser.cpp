#include "stdafx.h"
#include "TiledMapParser.hpp"


// Christopher D. Canfield
// March 2014
// TiledMapParser.cpp

using namespace cdc;
using namespace std;

typedef std::vector<Node> Nodes;

typedef void (*terrainFactory)(Nodes, uint row, uint column, uint index, float x, float z);

struct MapProperties
{
	MapProperties() :
		rows(0),
		columns(0),
		tileHeight(0),
		tileWidth(0) {}

	uint rows;
	uint columns;
	uint tileHeight;
	uint tileWidth;
};

TiledMapParser::TiledMapParser(GameMap& gameMap) :
	map(gameMap)
{
}


TiledMapParser::~TiledMapParser()
{
}


void TiledMapParser::parse(std::string path)
{
	// TODO: implement this.
	// 

	//MapProperties properties = processMapProperties(node);

	//Nodes nodes;
	//nodes.resize(properties.rows);

	//GameMap::UniquePtr gameMap = make_unique<GameMap>(properties.rows, properties.columns, 
	//		properties.tileHeight, properties.tileWidth, nodes);
	
}


MapProperties processMapProperties(Poco::XML::Node* node)
{

}

void processTerrain(Nodes& nodes, map<int, terrainFactory> terrainFactories, Poco::XML::Node* node)
{

}

void bridgeFactory(Nodes& nodes, uint row, uint column, uint index, float x, float z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Bridge>(x, z)));
}

void dirtFactory(Nodes& nodes, uint row, uint column, uint index, float x, float z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Dirt>(x, z)));
}

void grassFactory(Nodes& nodes, uint row, uint column, uint index, float x, float z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Grass>(x, z)));
}

void roadFactory(Nodes& nodes, uint row, uint column, uint index, float x, float z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Road>(x, z)));
}

void waterFactory(Nodes& nodes, uint row, uint column, uint index, float x, float z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Water>(x, z)));
}