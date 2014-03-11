#include "stdafx.h"
#include "AbstractSprite.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.cpp

using namespace cdc;


AbstractSprite::AbstractSprite(Entity& entity, bool isMovable) :
	entity(entity),
	movable(isMovable),
	currentFrame(0)
{
}

AbstractSprite::~AbstractSprite()
{
}

bool AbstractSprite::isDestroyed() const
{
	return entity.isDestroyed();
}

void AbstractSprite::addFrame(AnimationFrame frame)
{
	frames.push_back(frame);
}

void AbstractSprite::setCurrentFrame(int index)
{
	currentFrame = index;
}

void AbstractSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Assert<GameLogicException>(frames.size() != 0, "AbstractSprite: No frames added to Sprite.");
	target.draw(frames[currentFrame].sprite, states);
}

void AbstractSprite::update(const sf::Time& deltaTime)
{
	// Update the sprite to match the underlying entity's position.
	if (movable)
	{
		frames[currentFrame].sprite.setPosition(entity.getX(), entity.getZ());
	}

	// Rotate through the animation frames, if there are more than one.
	if (frames.size() > 1)
	{
		auto& frame = frames[currentFrame];
		frame.timeRemaining -= deltaTime;
		if (frame.timeRemaining.asMilliseconds() <= 0)
		{
			currentFrame = (currentFrame == static_cast<int>(frames.size() - 1u)) ? 0 : currentFrame + 1;
			frames[currentFrame].timeRemaining = frames[currentFrame].timePerFrame;
		}
	}
}