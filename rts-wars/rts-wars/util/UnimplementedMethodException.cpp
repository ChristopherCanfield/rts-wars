#include "stdafx.h"
#include "UnimplementedMethodException.hpp"

// Christopher D. Canfield
// March 2014
// UnimplementedMethodException.hpp

using namespace cdc;

UnimplementedMethodException::UnimplementedMethodException(std::string className, std::string methodName, std::string message) :
	GameLogicException(className, methodName, message)
{
}


UnimplementedMethodException::~UnimplementedMethodException()
{
}
