#pragma once

#include "controllers/CameraController.hpp"

// Christopher D. Canfield
// February 2014
// Camera.hpp


namespace cdc
{
	///<summary>A camera that looks into the world.</summary>
	class Camera
	{
	public:
		typedef std::unique_ptr<Camera> UniquePtr;

		virtual ~Camera() {}

		///<summary>Adds a controller to the camera.</summary>
		///<param name="c">The controller to add.</param>
		virtual void addController(CameraController::UniquePtr c) = 0;

		///<summary>Updates all attached controllers. Must be called once per game tick.</summary>
		virtual void update() = 0;

		///<summary>Moves the camera forward in the Z direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveForwardZ(bool fastMovement) = 0;

		///<summary>Moves the camera backward in the Z direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveBackwardZ(bool fastMovement) = 0;

		///<summary>Moves the camera left in the X direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveLeftX(bool fastMovement) = 0;

		///<summary>Moves the camera right in the X direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveRightX(bool fastMovement) = 0;

		///<summary>Moves the camera up in the Y direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveUpY(bool fastMovement) = 0;

		///<summary>Moves the camera down in the Y direction.</summary>
		///<param name="fastMovement">true if the camera should be moved quickly.</param>
		virtual void moveDownY(bool fastMovement) = 0;

		///<summary>Gets the position of the camera.</summary>
		///<returns>Returns the position of the camera.</returns>
		virtual sf::Vector2f getCenter() const = 0;
	};
}
