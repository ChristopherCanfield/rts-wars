#include "stdafx.h"
#include "AbstractEntity.hpp"


// Christopher D. Canfield
// February 2014
// AbstractEntity.hpp


using namespace cdc;


AbstractEntity::AbstractEntity() :
	id(Poco::UUIDGenerator::defaultGenerator().createRandom())
{
	constructEntity();
}

AbstractEntity::AbstractEntity(Poco::UUID id) :
	id(id)
{
	constructEntity();
}

void AbstractEntity::constructEntity()
{
	x = z = rotation = 0;
	height = width = 0;
	destroyed = false;
}

AbstractEntity::~AbstractEntity()
{
}

const Poco::UUID& AbstractEntity::getId() const
{
	return id;
}

float AbstractEntity::getX() const
{
	return x;
}

void AbstractEntity::setX(float x)
{
	this->x = x;
}

float AbstractEntity::getZ() const
{
	return z;
}

void AbstractEntity::setZ(float z)
{
	this->z = z;
}

float AbstractEntity::getRotation() const
{
	return rotation;
}

void AbstractEntity::setRotation(float radians)
{
	this->rotation = radians;
}

uint AbstractEntity::getHeight() const
{
	return height;
}

void AbstractEntity::setHeight(uint height)
{
	this->height = height;
}

uint AbstractEntity::getWidth() const
{
	return width;
}

void AbstractEntity::setWidth(uint width)
{
	this->width = width;
}

sf::IntRect AbstractEntity::getBoundingBox() const
{
	return sf::IntRect(x, z, width, height);
}

bool AbstractEntity::isDestroyed() const
{
	return destroyed;
}

void AbstractEntity::destroy()
{
	destroyed = true;
}

void AbstractEntity::update(World& world)
{
	for (auto& controller : controllers)
	{
		controller.update(world);
	}
}