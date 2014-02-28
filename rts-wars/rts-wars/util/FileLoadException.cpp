#include "stdafx.h"
#include "FileLoadException.hpp"

// Christopher D. Canfield
// February 2014
// FileLoadException.hpp

using namespace cdc;

FileLoadException::FileLoadException(std::string message) :
	std::runtime_error(message)
{
}


FileLoadException::~FileLoadException()
{
}
