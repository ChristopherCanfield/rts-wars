#include "stdafx.h"
#include "NotImplementedException.hpp"

// Christopher D. Canfield
// March 2014
// NotImplementedException.hpp

using namespace cdc;

NotImplementedException::NotImplementedException(std::string className, std::string methodName, std::string message) :
	GameLogicException(className, methodName, message)
{
}


NotImplementedException::~NotImplementedException()
{
}
