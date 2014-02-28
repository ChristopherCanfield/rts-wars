#include "stdafx.h"
#include "Tank.hpp"
#include "graphics/TankSprite.hpp"

// Christopher D. Canfield
// February 2014
// Tank.hpp

using namespace cdc;

Tank::Tank()
{
	Sprite::SharedPtr sprite(std::make_shared<TankSprite>(*this));
	Graphics::Instance().addSprite(sprite);
}

Tank::Tank(Poco::UUID id) :
	AbstractEntity(id)
{
}

Tank::~Tank()
{
}