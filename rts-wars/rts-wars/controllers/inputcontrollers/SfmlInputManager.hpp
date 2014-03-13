#pragma once

#include "controllers/InputManager.hpp"

// Christopher D. Canfield
// March 2014
// SfmlInputManager.hpp


namespace cdc
{

	class SfmlInputManager :
		public InputManager
	{
	public:
		SfmlInputManager();
		virtual ~SfmlInputManager();

		virtual void update(World& world) = 0;
	};
}
