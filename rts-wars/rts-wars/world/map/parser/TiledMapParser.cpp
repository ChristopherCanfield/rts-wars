#include "stdafx.h"
#include "TiledMapParser.hpp"


// Christopher D. Canfield
// March 2014
// TiledMapParser.cpp

using namespace cdc;
using namespace std;

typedef void (*terrainFactory)(World& world, float x, float z);


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
}


void processMapProperties(World& world, Poco::XML::Node* node)
{

}

void processTerrain(World& world, map<int, terrainFactory> terrainFactories, Poco::XML::Node* node)
{

}

void bridgeFactory(World& world, float x, float z)
{
	Terrain::SharedPtr terrain = make_shared<Bridge>(x, z);
	world.addEntity(entity);
}

void dirtFactory(World& world, float x, float z)
{

}

void grassFactory(World& world, float x, float z)
{

}

void roadFactory(World& world, float x, float z)
{

}

void waterFactory(World& world, float x, float z)
{

}