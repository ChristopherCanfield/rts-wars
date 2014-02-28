#include "stdafx.h"
#include "SfmlCamera.hpp"

// Christopher D. Canfield
// February 2014
// SfmlCamera.cpp

using namespace cdc;

const float movementPerTick = 0.1f;

SfmlCamera::SfmlCamera(sf::RenderWindow& window, sf::Vector2u worldDimensions) :
	window(window),
	worldDimensions(worldDimensions),
	view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y))
{
}


SfmlCamera::~SfmlCamera()
{
}

void SfmlCamera::addController(CameraController::UniquePtr c)
{
	controllers.push_back(move(c));
}

void SfmlCamera::update()
{
	for (auto& c : controllers)
	{
		c->update();
	}
}


void SfmlCamera::moveForwardZ()
{
	// TODO: restrict this from moving off the world.
	view.move(0.f, -movementPerTick);
	window.setView(view);
}

void SfmlCamera::moveBackwardZ()
{
	// TODO: restrict this from moving off the world.
	view.move(0.f, movementPerTick);
	window.setView(view);
}

void SfmlCamera::moveLeftX()
{
	// TODO: restrict this from moving off the world.
	view.move(-movementPerTick, 0.f);
	window.setView(view);
}

void SfmlCamera::moveRightX()
{
	// TODO: restrict this from moving off the world.
	view.move(movementPerTick, 0.f);
	window.setView(view);
}

void SfmlCamera::moveUpY()
{
	// Do nothing, because SFML is a 2D library.
}

void SfmlCamera::moveDownY()
{
	// Do nothing, because SFML is a 2D library.
}