#pragma once

// Christopher D. Canfield
// February 2014
// Sprite.hpp

#include <SFML/Graphics.hpp>

namespace cdc
{
	class Sprite
	{
	public:
		virtual ~Sprite() {}

		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
	};
}