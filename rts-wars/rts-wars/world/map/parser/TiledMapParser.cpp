#include "stdafx.h"
#include "TiledMapParser.hpp"


// Christopher D. Canfield
// March 2014
// TiledMapParser.cpp

using namespace cdc;
using namespace std;

typedef std::vector<std::vector<Node::SharedPtr>> Nodes;

typedef void (*terrainFactory)(Nodes, float x, float z, uint row, uint column);

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

	MapProperties properties = processMapProperties(node);

	Nodes nodes;
	nodes.resize(properties.rows);

	GameMap::UniquePtr gameMap = make_unique<GameMap>(properties.rows, properties.columns, 
			properties.tileHeight, properties.tileWidth, nodes);
	
}


MapProperties processMapProperties(Poco::XML::Node* node)
{

}

void processTerrain(Nodes& nodes, map<int, terrainFactory> terrainFactories, Poco::XML::Node* node)
{

}

void bridgeFactory(Nodes& nodes, float x, float z, uint row, uint column)
{
	Bridge terrain(x, z);
	Node::SharedPtr node = make_shared<Node>(GridLocation(row, column), x, z, terrain);
	
	nodes[row].push_back(node);
}

void dirtFactory(Nodes& nodes, float x, float z, uint row, uint column)
{

}

void grassFactory(Nodes& nodes, float x, float z, uint row, uint column)
{

}

void roadFactory(Nodes& nodes, float x, float z, uint row, uint column)
{

}

void waterFactory(Nodes& nodes, float x, float z, uint row, uint column)
{

}