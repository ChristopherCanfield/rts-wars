#include "stdafx.h"
#include "TiledMapParser.hpp"


// Christopher D. Canfield
// March 2014
// TiledMapParser.cpp

using namespace cdc;
using namespace std;

typedef std::vector<Node> Nodes;

typedef void (*terrainFactory)(Nodes, uint row, uint column, uint index, float x, float z);

void loadMapImages(Poco::XML::Node* node);
map<int, terrainFactory> setFactories(Poco::XML::Node* node);

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


TiledMapParser::TiledMapParser(GameMap& gameMap) :
	map(gameMap)
{
}

TiledMapParser::~TiledMapParser()
{
}


void TiledMapParser::parse(std::string path)
{
	using namespace Poco;

	// TODO: implement this.
	
	ifstream in(path);
	XML::InputSource src(in);

	XML::DOMParser parser;
	AutoPtr<XML::Document> doc = parser.parse(&src);

	MapProperties properties;
	std::map<int, terrainFactory> terrainFactories;

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
				if (node->nodeName() == "property")
				{
					// TODO: Implement.
					loadMapImages(childNode);
				}
				else if (node->nodeName() == "tileset")
				{
					// TODO: Implement.
					terrainFactories = setFactories(childNode);
				}
				else if (node->nodeName() == "layer")
				{

				}
			}
		}

		node = iterator.nextNode();
	}

	//MapProperties 

	//Nodes nodes;
	//nodes.resize(properties.rows);

	//GameMap::UniquePtr gameMap = make_unique<GameMap>(properties.rows, properties.columns, 
	//		properties.tileHeight, properties.tileWidth, nodes);
	
}

// Imports the map properties, which should be in the following form:
// <map version="1.0" orientation="orthogonal" width="50" height="50" tilewidth="32" tileheight="32">
MapProperties processMapProperties(Poco::XML::Node* node)
{
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
// Example:
//  <property name="image0" value="map1.png"/>
//  <property name="imageLeft0" value="0"/>
//  <property name="imageTop0" value="0"/>
void loadMapImages(Poco::XML::Node* node)
{
	using namespace Poco;

	int i = 0;
	bool nodeNotFound = false;
	while (!nodeNotFound)
	{
		// TODO: loop through the images, and load them into Graphics.
	}

	XML::NodeIterator childIterator(node, XML::NodeFilter::SHOW_ELEMENT);
	XML::Node* childNode = childIterator.nextNode();
	while (childNode)
	{
		if (childNode->fin
	}
}

map<int, terrainFactory> setFactories(Poco::XML::Node* node)
{
	map<int, terrainFactory> factories;

	
	return factories;
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