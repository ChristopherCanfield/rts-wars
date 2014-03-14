#include "stdafx.h"
#include "AbstractSprite.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.cpp

using namespace cdc;


AbstractSprite::AbstractSprite(Entity& entity, bool isMovable) :
	entity(entity),
	movable(isMovable),
	currentFrame(0),
	borderDrawAdjustmentX(0),
	borderDrawAdjustmentZ(0)
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

void AbstractSprite::setSelectionBorder(sf::Sprite border, int drawAdjustmentX, int drawAdjustmentZ)
{
	selectionBorder = border;
	borderDrawAdjustmentX = drawAdjustmentX;
	borderDrawAdjustmentZ = drawAdjustmentZ;
}

void AbstractSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	Assert<GameLogicException, HIGH_ASSERT>(frames.size() != 0, "AbstractSprite", "draw", "No frames added to Sprite.");
	
	if (entity.isSelected())
	{
		target.draw(selectionBorder, states);
	}

	target.draw(frames[currentFrame].sprite, states);
}

void AbstractSprite::update(const sf::Time& deltaTime)
{
	// Update the sprite to match the underlying entity's position.
	if (movable)
	{
		frames[currentFrame].sprite.setPosition(entity.getX(), entity.getZ());

		const auto adjustedBorderWidth = (selectionBorder.getLocalBounds().width - entity.getWidth() + borderDrawAdjustmentX) / 2.f;
		const auto adjustedBorderHeight = (selectionBorder.getLocalBounds().height - entity.getHeight() + borderDrawAdjustmentZ) / 2.f;

		const auto borderX = entity.getX() - adjustedBorderWidth;
		const auto borderZ = entity.getZ() - adjustedBorderHeight;
		selectionBorder.setPosition(borderX, borderZ);
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