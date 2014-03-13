#include "stdafx.h"
#include "SfmlCamera.hpp"

// Christopher D. Canfield
// February 2014
// SfmlCamera.cpp

using namespace cdc;

const float movementPerTick = 0.1f;
const float fastMovementPerTick = movementPerTick * 3.f;

SfmlCamera::SfmlCamera(sf::RenderWindow& window, sf::Vector2u worldDimensions) :
	window(window),
	worldDimensions(worldDimensions),
	view(sf::FloatRect(0, 0, static_cast<float>(window.getSize().x), static_cast<float>(window.getSize().y)))
{
	Assert<GameLogicException>(worldDimensions.x != 0 && worldDimensions.y != 0, 
		"SfmlCamera", "SfmlCamera", "worldDimensions are zero.");
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


void SfmlCamera::moveForwardZ(bool fastMovement)
{
	if (view.getCenter().y > view.getSize().y / 2.f)
	{
		view.move(0.f, (fastMovement ? -fastMovementPerTick : -movementPerTick));
		window.setView(view);
	}
}

void SfmlCamera::moveBackwardZ(bool fastMovement)
{
	if (view.getCenter().y < (worldDimensions.y - view.getSize().y / 2.f))
	{
		view.move(0.f, (fastMovement ? fastMovementPerTick : movementPerTick));
		window.setView(view);
	}
}

void SfmlCamera::moveLeftX(bool fastMovement)
{
	if (view.getCenter().x > view.getSize().x / 2.f)
	{
		view.move((fastMovement ? -fastMovementPerTick : -movementPerTick), 0.f);
		window.setView(view);
	}
}

void SfmlCamera::moveRightX(bool fastMovement)
{
	if (view.getCenter().x < (worldDimensions.x - view.getSize().x / 2.f))
	{
		view.move((fastMovement ? fastMovementPerTick : movementPerTick), 0.f);
		window.setView(view);
	}
}

void SfmlCamera::moveUpY(bool fastMovement)
{
	// Do nothing, because SFML is a 2D library.
}

void SfmlCamera::moveDownY(bool fastMovement)
{
	// Do nothing, because SFML is a 2D library.
}

sf::Vector2f SfmlCamera::getCenter() const
{
	return view.getCenter();
}

sf::Vector2f SfmlCamera::cameraToWorldCoordinates(const sf::Vector2i& cameraCoordinates) const 
{
	return window.mapPixelToCoords(cameraCoordinates);
}

sf::Vector2i SfmlCamera::worldToCameraCoordinates(const sf::Vector2f& worldCoordinates) const 
{
	return window.mapCoordsToPixel(worldCoordinates);
}