#pragma once

#include "GameLogicException.hpp"

// Christopher D. Canfield
// March 2014
// NavGraphException.hpp

namespace cdc
{
	///<summary>Thrown when there are problems interacting with the navigation graph.</summary>
	class NavGraphException :
		public GameLogicException
	{
	public:
		NavGraphException(std::string message);
		virtual ~NavGraphException();
	};
}
