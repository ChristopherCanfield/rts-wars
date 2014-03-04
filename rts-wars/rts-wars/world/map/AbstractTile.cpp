#include "stdafx.h"
#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// AbstractTile.cpp

using namespace cdc;


AbstractTile::AbstractTile(float x, float y, uint height, uint width, bool passable, float speedPercentage) :
	x(x),
	y(y),
	height(height),
	width(width),
	passable(passable),
	speedPercentage(speedPercentage)
{
}


AbstractTile::~AbstractTile()
{
}


float AbstractTile::getX() const
{
	return x;
}

float AbstractTile::getY() const
{
	return y;
}

uint AbstractTile::getHeight() const
{
	return height;
}

uint AbstractTile::getWidth() const
{
	return width;
}

bool AbstractTile::isPassable() const
{
	return passable;
}

float AbstractTile::getSpeedPercentage() const
{
	return speedPercentage;
}