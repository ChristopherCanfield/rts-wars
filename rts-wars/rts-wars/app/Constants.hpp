#pragma once

// Christopher D. Canfield
// February 2014
// Constants.hpp

#include <string>

namespace cdc
{
	namespace Constants
	{
		// The name of the application.
		const std::string AppName = "RTS Wars";

		// The number of ticks per second.
		const int TicksPerSecond = 30;

		// The number of milliseconds per tick.
		const float MillisPerTick = TicksPerSecond / 1000;
	}
}