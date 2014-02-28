#include "stdafx.h"
#include "SfmlCameraController.hpp"

// Christopher D. Canfield
// February 2014
// SfmlCameraController.cpp

using namespace cdc;

SfmlCameraController::SfmlCameraController(Camera& camera) :
	camera(camera)
{
}


SfmlCameraController::~SfmlCameraController()
{
}


void SfmlCameraController::update()
{
	// TODO: allow these keys to be set at run-time.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		camera.moveLeftX();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		camera.moveRightX();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		camera.moveForwardZ();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		camera.moveBackwardZ();
	}
}