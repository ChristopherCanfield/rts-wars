#pragma once

// Christopher D. Canfield
// February 2014
// GameLogicException.hpp

#include <string>
#include <stdexcept>

namespace cdc
{
	///<summary>Thrown when a logic error occurs.</summary>
	class GameLogicException :
		public std::logic_error
	{
	public:
		GameLogicException(std::string message);
		~GameLogicException();
	};
}
