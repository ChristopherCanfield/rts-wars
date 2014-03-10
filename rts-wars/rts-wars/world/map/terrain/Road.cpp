#include "stdafx.h"
#include "Road.hpp"

// Christopher D. Canfield
// March 2014
// Road.cpp
using namespace cdc;


Road::Road(float x, float z) :
	AbstractTerrain(x, z, 32, 32, true, 1.f)
{
}


Road::~Road()
{
}
