#pragma once

// Christopher D. Canfield
// February 2014
// Sprite.hpp

#include <SFML/Graphics.hpp>

namespace cdc
{
	class Sprite :
		public sf::Drawable
	{
	public:
		typedef std::shared_ptr<Sprite> SharedPtr;

		virtual ~Sprite() {}

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;

		///<summary>Specifies whether the sprite should be removed</summary>
		///<returns>true if the sprite should be removed, or false otherwise.</returns>
		virtual bool isDestroyed() const = 0;
	};
}