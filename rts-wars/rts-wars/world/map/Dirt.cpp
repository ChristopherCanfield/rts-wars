#include "stdafx.h"
#include "Dirt.hpp"

// Christopher D. Canfield
// March 2014
// Grass.cpp

using namespace cdc;


Dirt::Dirt(float x, float y) :
	AbstractTile(x, y, 32, 32, true, 1.f)
{
}


Dirt::~Dirt()
{
}
