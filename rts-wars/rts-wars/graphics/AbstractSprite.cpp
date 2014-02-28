#include "stdafx.h"
#include "AbstractSprite.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.cpp

using namespace cdc;


AbstractSprite::AbstractSprite(Entity& entity) :
	entity(entity)
{
}


AbstractSprite::~AbstractSprite()
{
}

bool AbstractSprite::isDestroyed() const
{
	return entity.isDestroyed();
}

void AbstractSprite::setSprite(sf::Sprite& sprite)
{
	currentSprite = &sprite;
}

sf::Sprite& AbstractSprite::getSprite() const
{
	return *currentSprite;
}