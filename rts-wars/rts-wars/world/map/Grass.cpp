#include "stdafx.h"
#include "Grass.hpp"

// Christopher D. Canfield
// March 2014
// Grass.cpp

using namespace cdc;


Grass::Grass(float x, float y) :
	AbstractTile(x, y, 32, 32, true, 1.f)
{
}


Grass::~Grass()
{
}
