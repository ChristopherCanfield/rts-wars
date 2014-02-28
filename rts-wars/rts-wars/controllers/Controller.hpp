#pragma once

#include <memory>

// Christopher D. Canfield
// February 2014
// Controller.hpp

namespace cdc
{
	class World;

	///<summary>Interface for entity controllers</summary>
	class Controller
	{
	public:
		typedef std::unique_ptr<Controller> UniquePtr;

		virtual ~Controller() {}

		///<summary>Updates the controller. Must be called once per game tick.</summary>
		///<param name="world">Reference to the game world.</param>
		virtual void update(World& world) = 0;
	};
}