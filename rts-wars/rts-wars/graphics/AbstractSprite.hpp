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

	protected:
		///<summary>Sets the current sprite.</summary>
		///<param name="sprite">The sprite that will be drawn.</param>
		void setSprite(sf::Sprite& sprite);

		///<summary>Gets the current sprite.</summary>
		sf::Sprite& getSprite() const;

	private:
		AbstractSprite& operator=(AbstractSprite& rhs);

		Entity& entity;

		sf::Sprite* currentSprite;
	};
}