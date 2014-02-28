#pragma once

// Christopher D. Canfield
// February 2014
// TankSprite.hpp

#include <vector>

#include <SFML/Graphics.hpp>

namespace cdc
{
	class AbstractSprite;

	class TankSprite :
		public AbstractSprite
	{
	public:
		TankSprite(Entity& entity);
		virtual ~TankSprite();

	private:
		sf::Sprite sprite;
		std::vector<sf::IntRect> textureRegions;
	};
}
