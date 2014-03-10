#include "stdafx.h"
#include "AbstractSprite.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.cpp

using namespace cdc;


AbstractSprite::AbstractSprite(Entity& entity, bool isMovable) :
	entity(entity),
	movable(isMovable)
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

void AbstractSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	if (movable)
	{
		currentSprite->setPosition(entity.getX(), entity.getZ());
	}
	target.draw(*currentSprite, states);
}