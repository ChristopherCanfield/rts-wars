#pragma once

#include <string>

// Christopher D. Canfield
// March 2014
// MapParser.hpp


namespace cdc
{

	class MapParser
	{
	public:
		virtual ~MapParser() {}

		virtual void parse(std::string path) = 0;
	};
}