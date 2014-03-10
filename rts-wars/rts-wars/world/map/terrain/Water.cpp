#include "stdafx.h"
#include "Water.hpp"

// Christopher D. Canfield
// March 2014
// Water.cpp

using namespace cdc;

Water::Water(float x, float z) :
	AbstractTerrain(x, z, 32, 32, true, 1.f)
{
}


Water::~Water()
{
}
