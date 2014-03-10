#include "stdafx.h"
#include "TiledMapParser.hpp"
#include "world/map/maps/tiled/TiledMapFileInfo.hpp"


// Christopher D. Canfield
// March 2014
// TiledMapParser.cpp

using namespace cdc;
using namespace cdc::tiled;
using namespace std;

typedef std::vector<Node>& Nodes;

typedef void (*terrainFactory)(Nodes, uint row, uint column, uint index, int x, int z);

void loadMapImages(TiledMapFileInfo& fileInfo);
map<uint, terrainFactory> setFactories(Poco::XML::Node* node);
void setFactory(map<uint, terrainFactory>& terrainFactories, uint id, const std::string& name);

// Smart pointer for Poco::XML::NamedNodeMap
class SmartNamedNodeMap
{
public:
	SmartNamedNodeMap(Poco::XML::NamedNodeMap* attributes) :
		att(attributes) {}

	~SmartNamedNodeMap() {
		att->release();
	}

	Poco::XML::NamedNodeMap* operator->() { 
		return att; 
	}

private:
	Poco::XML::NamedNodeMap* att;
};

// Properties from the tmx file.
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

MapProperties processMapProperties(Poco::XML::Node* node);

void processTerrain(Nodes& navGraph, const map<int, terrainFactory>& terrainFactories, Poco::XML::Node* node, 
					const MapProperties& properties);


TiledMapParser::TiledMapParser(tiled::TiledMapFileInfo& mapFileInfo) :
	fileInfo(mapFileInfo)
{
}

TiledMapParser::~TiledMapParser()
{
}


GameMap::UniquePtr TiledMapParser::parse()
{
	using namespace Poco;

	loadMapImages(fileInfo);
	
	ifstream in(Constants::MapPath + fileInfo.getTmxFileName());
	if (!in.good)
	{
		throw FileLoadException("Unable to load the Tiled tmx file: " + Constants::MapPath + fileInfo.getTmxFileName());
	}

	XML::InputSource src(in);
	
	XML::DOMParser parser;
	AutoPtr<XML::Document> doc = parser.parse(&src);

	MapProperties properties;
	std::map<uint, terrainFactory> terrainFactories;

	GameMap::NavGraphList navGraph;

	XML::NodeIterator iterator(doc, XML::NodeFilter::SHOW_ELEMENT);
	XML::Node* node = iterator.nextNode();
	while (node)
	{
		if (node->nodeName() == "map")
		{
			if (!node->hasAttributes()) throw FileFormatException("The Tiled map file is formatted incorrectly: there are no map attributes.");

			// Load the properties.
			properties = processMapProperties(node);
		
			XML::NodeIterator childIterator(node, XML::NodeFilter::SHOW_ELEMENT);
			XML::Node* childNode = childIterator.nextNode();
			while (childNode)
			{
				if (node->nodeName() == "tileset")
				{
					terrainFactories = setFactories(childNode);
				}
				else if (node->nodeName() == "layer")
				{
					processTerrain(navGraph, terrainFactories, node, properties);
				}
			}
		}

		node = iterator.nextNode();
	}

	GameMap::UniquePtr gameMap = make_unique<GameMap>(properties.rows, properties.columns, 
			properties.tileHeight, properties.tileWidth, move(navGraph));
	return move(gameMap);
}

// Imports the map properties, which should be in the following form:
// <map version="1.0" orientation="orthogonal" width="50" height="50" tilewidth="32" tileheight="32">
MapProperties processMapProperties(Poco::XML::Node* node)
{
	try
	{
		MapProperties properties;

		SmartNamedNodeMap attributes(node->attributes());

		stringstream widthStream(attributes->getNamedItem("width")->nodeValue());
		widthStream >> properties.columns;

		stringstream heightStream(attributes->getNamedItem("height")->nodeValue());
		heightStream >> properties.rows;

		stringstream tileWidthStream(attributes->getNamedItem("tileWidth")->nodeValue());
		tileWidthStream >> properties.tileWidth;

		stringstream tileHeightStream(attributes->getNamedItem("tileHeight")->nodeValue());
		tileHeightStream >> properties.tileHeight;

		return move(properties);
	} 
	catch (exception e)
	{
		cerr << e.what() << endl;
		throw FileFormatException("The Tiled map file is formatted incorrectly: one or more map attributes are missing.");
	}
}

// Loads the map images based on the properties specified in the Tiled xml file.
// fileInfo: The tiled map information.
void loadMapImages(TiledMapFileInfo& fileInfo)
{
	for (const MapImageProperties& properties : fileInfo.getProperties())
	{
		// The map files and textures are stored in the same location.
		auto& texture = Graphics::Instance().getTexture(Constants::MapPath + properties.fileName);

		sf::Sprite mapSprite(texture);
		mapSprite.setPosition(static_cast<float>(properties.imageLeft), static_cast<float>(properties.imageTop));

		Graphics::Instance().addMapSprite(mapSprite);
	}
}

map<uint, terrainFactory> setFactories(Poco::XML::Node* node)
{
	using namespace Poco;

	map<uint, terrainFactory> factories;
	
	XML::NodeIterator childIterator(node, XML::NodeFilter::SHOW_ELEMENT);
	XML::Node* tileNode = childIterator.nextNode();
	while (tileNode)
	{
		if (tileNode->nodeName() == "tile")
		{
			SmartNamedNodeMap tileAttributes(tileNode->attributes());

			stringstream id(tileAttributes->getNamedItem("id")->getNodeValue());
			uint tileId = 0;
			id >>tileId;

			auto propertyNode = node->firstChild()->firstChild();
			if (propertyNode->hasAttributes())
			{
				SmartNamedNodeMap attributes(propertyNode->attributes());
				setFactory(factories, tileId, attributes->getNamedItem("value")->nodeValue());
			}
			else
			{
				throw FileFormatException("TMX file malformed: tile>>properties should have a child, but does not.");
			}
		}
		
		tileNode = childIterator.nextNode();
	}
	
	return factories;
}


void processTerrain(Nodes& navGraph, const map<int, terrainFactory>& terrainFactories, Poco::XML::Node* node, const MapProperties& properties)
{
	using namespace Poco;

	uint row = 0;
	uint column = 0;
	uint index = 0;

	XML::NodeIterator childIterator(node, XML::NodeFilter::SHOW_ELEMENT);
	XML::Node* dataNode = childIterator.nextNode();
	while (dataNode)
	{
		SmartNamedNodeMap attributes(dataNode->attributes());
		stringstream id(attributes->getNamedItem("gid")->nodeValue());
		uint tileId;
		id >> tileId;

		dataNode = childIterator.nextNode();
		terrainFactories.at(tileId - 1)(navGraph, row, column, index, 
				static_cast<int>(properties.tileWidth * column), 
				static_cast<int>(properties.tileHeight * row));

		++column;
		if (column > properties.columns - 1)
		{
			column = 0;
			++row;
		}
		++index;
	}
}

void bridgeFactory(Nodes& nodes, uint row, uint column, uint index, int x, int z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Bridge>(static_cast<float>(x), static_cast<float>(z))));
}

void dirtFactory(Nodes& nodes, uint row, uint column, uint index, int x, int z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Dirt>(static_cast<float>(x), static_cast<float>(z))));
}

void grassFactory(Nodes& nodes, uint row, uint column, uint index, int x, int z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Grass>(static_cast<float>(x), static_cast<float>(z))));
}

void roadFactory(Nodes& nodes, uint row, uint column, uint index, int x, int z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Road>(static_cast<float>(x), static_cast<float>(z))));
}

void waterFactory(Nodes& nodes, uint row, uint column, uint index, int x, int z)
{
	nodes.emplace_back(Node(GridLocation(row, column), index, x, z, make_unique<Water>(static_cast<float>(x), static_cast<float>(z))));
}

// Loads one factory into the map.
void setFactory(map<uint, terrainFactory>& terrainFactories, uint id, const std::string& name)
{
	if (name == "concrete")
	{
		terrainFactories[id] = &roadFactory;
	}
	else if (name == "dirt")
	{
		terrainFactories[id] = &dirtFactory;
	}
	else if (name == "grass")
	{
		terrainFactories[id] = &grassFactory;
	}
	else if (name == "water")
	{
		terrainFactories[id] = &waterFactory;
	}
	else if (name == "bridge")
	{
		terrainFactories[id] = bridgeFactory;
	}
	else
	{
		throw FileFormatException("Invalid tile name found in TMX file: " + name);
	}
}