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

	sf::Texture& texture = Graphics::Instance().getTexture(Graphics::TexturePath + TankSpriteTextureName);
	sprite.setTexture(texture);
	sprite.setTextureRect(textureRegions[0]);

	setSprite(sprite);
}

TankSprite::~TankSprite()
{
}
