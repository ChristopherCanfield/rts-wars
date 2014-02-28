#include "stdafx.h"
#include "GameLogicException.hpp"

// Christopher D. Canfield
// February 2014
// GameLogicException.cpp

using namespace cdc;

GameLogicException::GameLogicException(const std::string& message) :
	std::logic_error(message)
{
	
}


GameLogicException::~GameLogicException()
{
}
