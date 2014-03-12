#pragma once

#include "GameLogicException.hpp"

// Christopher D. Canfield
// March 2014
// UnimplementedMethodException.hpp


namespace cdc
{

	class UnimplementedMethodException :
		public GameLogicException
	{
	public:
		UnimplementedMethodException(std::string className, std::string methodName, std::string message);
		virtual ~UnimplementedMethodException();
	};
}
