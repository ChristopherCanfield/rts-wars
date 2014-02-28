#include "stdafx.h"
#include "Graphics.hpp"

using namespace cdc;
using namespace std;

Graphics Graphics::instance;


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

void Graphics::draw(sf::RenderWindow& target, sf::RenderStates states)
{
	for (auto& sprite : sprites)
	{
		sprite->draw(target, states);
	}

	// Find the entity.
	sprites.erase(remove_if(sprites.begin(), sprites.end(), [](Sprite::SharedPtr& sprite) {
		return sprite->isDestroyed();
	}));
}