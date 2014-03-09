#include "stdafx.h"
#include "Map1.hpp"

// Christopher D. Canfield
// March 2014
// Map1.hpp

using namespace cdc;
using namespace cdc::tiled;

using namespace std;

Map1::Map1()
{
	setFileName(string("map1.tmx"));

	vector<MapImageProperties> properties;
	
	MapImageProperties image0;
	image0.fileName = "map1.png";
	image0.imageLeft = 0;
	image0.imageTop = 0;
	properties.push_back(image0);

	setProperties(properties);
}


Map1::~Map1()
{
}
