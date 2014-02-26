#include "stdafx.h"
#include "AbstractSprite.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.cpp

using namespace cdc;


AbstractSprite::AbstractSprite(Entity& entity) :
	entity(&entity)
{
}


AbstractSprite::~AbstractSprite()
{
}
