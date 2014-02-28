#include "stdafx.h"
#include "Graphics.hpp"

using namespace cdc;
using namespace std;

Graphics Graphics::instance;

const std::string Graphics::TexturePath("res/textures/");


Graphics::Graphics()
{
}


Graphics::~Graphics()
{
}

Graphics& Graphics::Instance()
{
	return Graphics::instance;
}

void Graphics::addSprite(Sprite::SharedPtr sprite)
{
	sprites.push_back(sprite);
}

sf::Texture& Graphics::getTexture(std::string path)
{
	if (textures.count(path) == 0)
	{
		auto t = make_unique<sf::Texture>();
		if (t->loadFromFile(path))
		{
			textures[path] = move(t);
		}
		else
		{
			throw FileLoadException("Unable to load texture file: " + path);
		}
	}
	return *textures[path];
}

void Graphics::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& sprite : sprites)
	{
		target.draw(*sprite, states);
	}

	
}

void Graphics::update()
{
	// Remove destroyed sprites.
	auto eraseIterator = remove_if(sprites.begin(), sprites.end(), [](Sprite::SharedPtr sprite) {
		return sprite->isDestroyed();
	});

	if (eraseIterator != sprites.end())
	{
		sprites.erase(eraseIterator);
	}
}