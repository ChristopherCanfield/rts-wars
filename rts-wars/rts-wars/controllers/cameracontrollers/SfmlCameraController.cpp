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
	using namespace sf;

	// TODO: allow these keys to be set at run-time.
	bool moveFast(Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift));

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		camera.moveLeftX(moveFast);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		camera.moveRightX(moveFast);
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		camera.moveForwardZ(moveFast);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		camera.moveBackwardZ(moveFast);
	}
}