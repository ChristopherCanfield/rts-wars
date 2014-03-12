#pragma once

#include "GameLogicException.hpp"

// Christopher D. Canfield
// March 2014
// NotImplementedException.hpp


namespace cdc
{

	class NotImplementedException :
		public GameLogicException
	{
	public:
		NotImplementedException(std::string className, std::string methodName, std::string message);
		virtual ~NotImplementedException();
	};
}
