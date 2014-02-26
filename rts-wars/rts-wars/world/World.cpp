#include "stdafx.h"
#include "World.hpp"
#include "Entity.hpp"

// Christopher D. Canfield
// February 2014
// World.cpp

using namespace cdc;
using namespace std;

World::World()
{
}


World::~World()
{
}


void World::addEntity(unique_ptr<Entity>&& e)
{
	entities.push_back(move(e));
}