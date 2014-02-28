#pragma once

// Christopher D. Canfield
// February 2014
// Graphics.hpp

#include "graphics/Sprite.hpp"

#include <vector>

namespace sf
{
	class RenderWindow;
}

namespace cdc
{
	/// <summary>
	/// The graphics system.
	/// </summary>
	class Graphics
	{
	public:
		~Graphics();
		static Graphics& Instance();
		
		///<summary>Adds a sprite.<summary>
		///<param name="sprite">The sprite to add</param>
		void addSprite(Sprite::SharedPtr sprite);

		void draw(sf::RenderWindow& window, sf::RenderStates states);

	private:
		Graphics();
		static Graphics instance;

		std::vector<Sprite::SharedPtr> sprites;
	};
}
