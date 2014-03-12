#include "stdafx.h"
#include "GameLogicException.hpp"

// Christopher D. Canfield
// February 2014
// GameLogicException.cpp

using namespace cdc;


GameLogicException::GameLogicException(std::string className, std::string methodName, std::string message) :
	std::logic_error(className + "::" + methodName + ": " + message),
	className(className),
	methodName(methodName)
{
}


GameLogicException::~GameLogicException()
{
}

const std::string& GameLogicException::getClassName() const
{
	return className;
}

const std::string& GameLogicException::getMethodName() const
{
	return methodName;
}