#pragma once

// Christopher D. Canfield
// February 2014
// Constants.hpp

#include <string>

#include <SFML/System.hpp>

namespace cdc
{
	namespace Constants
	{
		// The name of the application.
		const std::string AppName = "RTS Wars";

		// The number of ticks per second.
		const int TicksPerSecond = 30;

		// The number of milliseconds per tick.
		const sf::Int32 MillisPerTick = 1000 / TicksPerSecond;
	}
}