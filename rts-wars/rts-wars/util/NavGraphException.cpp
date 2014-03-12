#include "stdafx.h"
#include "NavGraphException.hpp"

// Christopher D. Canfield
// March 2014
// NavGraphException.hpp

using namespace cdc;


NavGraphException::NavGraphException(std::string className, std::string methodName, std::string message) :
	GameLogicException(className, methodName, message)
{
}


NavGraphException::~NavGraphException()
{
}
