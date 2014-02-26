#pragma once

#include "SFML/Graphics.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.hpp

namespace cdc
{
	class Entity;

	class AbstractSprite
	{
	public:
		AbstractSprite(Entity& entity);
		virtual ~AbstractSprite();

	private:
		Entity* entity;

		sf::Sprite* currentSprite;
	};
}