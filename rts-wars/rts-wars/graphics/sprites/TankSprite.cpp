#include "stdafx.h"
#include "TankSprite.hpp"

// Christopher D. Canfield
// February 2014
// TankSprite.cpp

using namespace cdc;

const std::string TankSpriteTextureName("tanks.png");


TankSprite::TankSprite(Entity& entity) :
	AbstractSprite(entity, true)
{
	using sf::IntRect;

	textureRegions.push_back(IntRect(4, 1, 24, 29));
	textureRegions.push_back(IntRect(37, 1, 24, 29));
	textureRegions.push_back(IntRect(70, 1, 24, 29));

	const sf::Texture& texture = Graphics::Instance().getTexture(Graphics::TexturePath + TankSpriteTextureName);
	sprite.setTexture(texture);
	sprite.setTextureRect(textureRegions[0]);
	addFrame(AnimationFrame(sprite, sf::Time::Zero));

	setSelectionBorder(sf::Sprite(texture, sf::IntRect(12, 68, 41, 52)), 6, 2);
}

TankSprite::~TankSprite()
{
}
