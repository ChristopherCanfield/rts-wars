#include "stdafx.h"
#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// AbstractTerrain.cpp

using namespace cdc;


AbstractTerrain::AbstractTerrain(float x, float z, uint height, uint width, bool passable, float speedPercentage) :
	x(x),
	z(z),
	height(height),
	width(width),
	passable(passable),
	speedPercentage(speedPercentage)
{
}


AbstractTerrain::~AbstractTerrain()
{
}


float AbstractTerrain::getX() const
{
	return x;
}

float AbstractTerrain::getZ() const
{
	return z;
}

uint AbstractTerrain::getHeight() const
{
	return height;
}

uint AbstractTerrain::getWidth() const
{
	return width;
}

bool AbstractTerrain::isPassable() const
{
	return passable;
}

float AbstractTerrain::getSpeedPercentage() const
{
	return speedPercentage;
}