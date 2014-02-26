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
	x = y = rotation = 0;
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

float AbstractEntity::getY() const
{
	return y;
}

void AbstractEntity::setY(float y)
{
	this->y = y;
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

bool AbstractEntity::isDestroyed() const
{
	return destroyed;
}

void AbstractEntity::setDestroyed(bool value)
{
	destroyed = value;
}

// Default implementation: do nothing.
void AbstractEntity::update(World& world)
{
}