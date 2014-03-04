#include "stdafx.h"
#include "Water.hpp"

// Christopher D. Canfield
// March 2014
// Water.cpp

using namespace cdc;

Water::Water(float x, float y) :
	AbstractTile(x, y, 32, 32, true, 1.f)
{
}


Water::~Water()
{
}
