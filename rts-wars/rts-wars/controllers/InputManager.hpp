#pragma once

#include <memory>

// Christopher D. Canfield
// March 2014
// InputManager.hpp

namespace cdc
{
	class World;

	///<summary>Interface for the input manager.</summary>
	class InputManager
	{
	public:
		typedef std::unique_ptr<InputManager> UniquePtr;

		virtual ~InputManager() {}

		///<summary>Updates the input manager. Must be called once per game tick.</summary>
		///<param name="world">Reference to the game world.</param>
		virtual void update(World& world) = 0;
	};
}