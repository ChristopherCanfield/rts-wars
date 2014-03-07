#include "stdafx.h"
#include "NavGraphException.hpp"

// Christopher D. Canfield
// March 2014
// NavGraphException.hpp

using namespace cdc;


NavGraphException::NavGraphException(std::string message) :
	GameLogicException(message)
{
}


NavGraphException::~NavGraphException()
{
}
