#pragma once

#include "graphics/Camera.hpp"

#include "SFML/Graphics/View.hpp"
#include "SFML/System/Vector2.hpp"

#include <vector>

// Christopher D. Canfield
// February 2014
// SfmlCamera.hpp

namespace cdc
{
	///<summary>A camera used with the SFML library</summary>
	class SfmlCamera :
		public Camera
	{
	public:
		SfmlCamera(sf::RenderWindow& window, sf::Vector2u worldDimensions);
		virtual ~SfmlCamera();

		virtual void addController(CameraController::UniquePtr c) override;

		virtual void moveForwardZ() override;

		virtual void moveBackwardZ() override;

		virtual void moveLeftX() override;

		virtual void moveRightX() override;

		virtual void moveUpY() override;

		virtual void moveDownY() override;

	private:
		SfmlCamera& operator=(SfmlCamera& rhs);

		sf::RenderWindow& window;

		sf::View view;

		sf::Vector2u worldDimensions;

		std::vector<CameraController::UniquePtr> controllers;
	};
}