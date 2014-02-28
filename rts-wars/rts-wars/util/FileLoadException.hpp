#pragma once

// Christopher D. Canfield
// February 2014
// FileLoadException.hpp

#include <stdexcept>
#include <string>

namespace cdc
{
	///<summary>Thrown when a file load fails.</summary>
	class FileLoadException :
		public std::runtime_error
	{
	public:
		FileLoadException(std::string message);
		~FileLoadException();
	};
}
