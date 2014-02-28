#pragma once

// Christopher D. Canfield
// February 2014
// FileLoadException.hpp

#include <stdexcept>

namespace cdc
{
	///<summary>Thrown when a file load fails.</summary>
	class FileLoadException :
		std::runtime_error
	{
	public:
		FileLoadException(const std::string& message);
		~FileLoadException();
	};
}
