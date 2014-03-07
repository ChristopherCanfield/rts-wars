#pragma once

#include "FileLoadException.hpp"

// Christopher D. Canfield
// March 2014
// FileFormatException.hpp


namespace cdc
{
	///<summary>Thrown when a file is formatted incorrectly.</summary>
	class FileFormatException :
		public FileLoadException
	{
	public:
		FileFormatException(std::string message);
		virtual ~FileFormatException();
	};
}
