#pragma once

// Christopher D. Canfield
// February 2014
// TankSprite.hpp

#include "graphics/Sprite.hpp"

namespace cdc
{

	class TankSprite :
		public Sprite
	{
	public:
		TankSprite(Entity& entity);
		virtual ~TankSprite();
	};
}
