#pragma once

#include "controllers/CameraController.hpp"

// Christopher D. Canfield
// February 2014
// SfmlCameraController.hpp

namespace cdc
{
	///<summary>Controller for an SFML Camera</summary>
	class SfmlCameraController :
		public CameraController
	{
	public:
		SfmlCameraController(Camera& camera);
		virtual ~SfmlCameraController();

		virtual void update() override;

	private:
		SfmlCameraController& operator=(SfmlCameraController& rhs);

		Camera& camera;
	};
}

