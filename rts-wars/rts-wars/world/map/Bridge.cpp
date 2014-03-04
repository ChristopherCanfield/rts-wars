#include "stdafx.h"
#include "Bridge.hpp"

// Christopher D. Canfield
// March 2014
// Bridge.cpp

using namespace cdc;


Bridge::Bridge(float x, float y) :
	AbstractTerrain(x, y, 32, 32, true, 1.f)
{
}


Bridge::~Bridge()
{
}
