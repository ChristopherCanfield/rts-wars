#pragma once

#include <memory>

// Christopher D. Canfield
// February 2014
// CameraController.hpp

namespace cdc
{
	class World;

	///<summary>Interface for camera controllers</summary>
	class CameraController
	{
	public:
		typedef std::unique_ptr<CameraController> UniquePtr;

		virtual ~CameraController() {}

		///<summary>Updates the controller. Must be called once per game tick.</summary>
		virtual void update() = 0;
	};
}