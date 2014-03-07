#include "stdafx.h"
#include "FileFormatException.hpp"

// Christopher D. Canfield
// March 2014
// FileFormatException.hpp


using namespace cdc;

FileFormatException::FileFormatException(std::string message) :
	FileLoadException(message)
{
}


FileFormatException::~FileFormatException()
{
}
