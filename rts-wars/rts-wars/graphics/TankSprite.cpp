#include "stdafx.h"
#include "TankSprite.hpp"

// Christopher D. Canfield
// February 2014
// TankSprite.cpp

using namespace cdc;

const std::string TankSpriteTextureName("tank.png");


TankSprite::TankSprite(Entity& entity) :
	AbstractSprite(entity, true)
{
	sprite.setTexture(Graphics::Instance().getTexture(Graphics::TexturePath + TankSpriteTextureName));
	setSprite(sprite);
}

TankSprite::~TankSprite()
{
}
