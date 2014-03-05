#pragma once

// Christopher D. Canfield
// February 2014
// Graphics.hpp

#include "graphics/Sprite.hpp"

#include <SFML/Graphics/Drawable.hpp>

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace sf
{
	class RenderWindow;
	class Drawable;
}

namespace cdc
{
	/// <summary>
	/// The graphics system.
	/// </summary>
	class Graphics :
		public sf::Drawable
	{
	public:
		static const std::string TexturePath;

		~Graphics();
		static Graphics& Instance();
		
		///<summary>Adds a sprite.<summary>
		///<param name="sprite">The sprite to add.</param>
		void addSprite(Sprite::SharedPtr sprite);

		///<summary></summary>
		///<param name="mapSprite">The sprite to add.</param>
		void addMapSprite(sf::Sprite mapSprite);

		sf::Texture& getTexture(std::string path);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		void update();

	private:
		Graphics();
		static Graphics instance;

		std::vector<Sprite::SharedPtr> sprites;

		std::vector<sf::Sprite> mapSprites;

		std::unordered_map<std::string, std::unique_ptr<sf::Texture>> textures;
	};
}
