#pragma once

// Christopher D. Canfield
// February 2014
// Camera.hpp


namespace cdc
{
	///<summary>A camera that looks into the world.</summary>
	class Camera
	{
	public:
		typedef std::unique_ptr<Camera> SharedPtr;

		virtual ~Camera() {}

		virtual void moveForwardZ() = 0;

		virtual void moveBackwardZ() = 0;

		virtual void moveLeftX() = 0;

		virtual void moveRightX() = 0;

		virtual void moveUpY() = 0;

		virtual void moveDownY() = 0;
	};
}
