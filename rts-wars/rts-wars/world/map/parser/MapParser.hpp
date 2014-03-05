#pragma once

#include <string>

// Christopher D. Canfield
// March 2014
// MapParser.hpp


namespace cdc
{
	///<summary>Parser for the game map file.</summary
	class MapParser
	{
	public:
		virtual ~MapParser() {}

		///<summary>Parses the game map file.</summary>
		///<param name="string">The path to the map file, including the file name.</param>
		virtual void parse(std::string path) = 0;
	};
}