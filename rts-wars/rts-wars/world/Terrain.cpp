#include "stdafx.h"
#include "Terrain.hpp"

using namespace cdc;


Terrain::Terrain(bool passable) :
	passable(passable)
{
}

Terrain::~Terrain()
{
}

bool Terrain::isPassable() const
{
	return passable;
}