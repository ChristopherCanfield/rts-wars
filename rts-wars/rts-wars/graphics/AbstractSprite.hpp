#pragma once

#include "SFML/Graphics.hpp"

// Christopher D. Canfield
// February 2014
// AbstractSprite.hpp

#include "graphics/Sprite.hpp"

namespace cdc
{
	class Entity;

	class AbstractSprite :
		public Sprite
	{
	public:
		AbstractSprite(Entity& entity);
		virtual ~AbstractSprite();

		virtual bool isDestroyed() const override;

	private:
		Entity& entity;

		sf::Sprite* currentSprite;
	};
}