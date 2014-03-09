#include "stdafx.h"
#include "World.hpp"
#include "Entity.hpp"

// Christopher D. Canfield
// February 2014
// World.cpp

using namespace cdc;
using namespace std;

std::unique_ptr<World> World::instance;

World& World::Instance()
{
	if (World::instance.get() == nullptr)
	{
		World::instance = unique_ptr<World>(new World());
	}
	return *World::instance;
}


World::World()
{
}


World::~World()
{
}


void World::addEntity(Entity::SharedPtr e)
{
	entities.push_back(e);
	entityMap[Poco::UUID(e->getId())] = e.get();
}

vector<Entity::SharedPtr>& World::getEntities()
{
	return entities;
}


Entity* World::getEntity(Poco::UUID id)
{
	if (entityMap.count(id))
	{
		return entityMap[id];
	}
	return nullptr;
}

void World::removeEntity(Poco::UUID id)
{
	// Remove from entity map.
	entityMap.erase(id);

	// Find the entity.
	auto entityToRemove = find_if(entities.begin(), entities.end(), [&id](Entity::SharedPtr& entity) {
		return (entity->getId() == id);
	});

	if (entityToRemove != entities.end())
	{
		// Remove from entity list.
		entities.erase(entityToRemove);
	}
}

void World::setGameMap(GameMap::UniquePtr map)
{
	gameMap = move(map);
}

GameMap& World::getGameMap() const
{
	return *gameMap.get();
}

void World::update()
{
	for (auto& entity : entities)
	{
		entity->update(*this);
	}
}