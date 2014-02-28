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
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}
}