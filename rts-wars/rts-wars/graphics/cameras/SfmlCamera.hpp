#pragma once

#include "graphics/Camera.hpp"

// Christopher D. Canfield
// February 2014
// SfmlCamera.hpp

namespace cdc
{

	class SfmlCamera :
		public Camera
	{
	public:
		SfmlCamera(sf::RenderWindow& window);
		virtual ~SfmlCamera();

		virtual void moveForwardZ() override;

		virtual void moveBackwardZ() override;

		virtual void moveLeftX() override;

		virtual void moveRightX() override;

		virtual void moveUpY() override;

		virtual void moveDownY() override;

	private:
		SfmlCamera& operator=(SfmlCamera& rhs);

		sf::RenderWindow& window;
	};
}