#pragma once

#include "world/map/GameMap.hpp"

#include <string>

// Christopher D. Canfield
// March 2014
// MapParser.hpp


namespace cdc
{
	///<summary>Parser for the game map file. The parser should be constructed with
	/// the information it needs to load the map file.</summary
	class MapParser
	{
	public:
		virtual ~MapParser() {}

		///<summary>Parses the game map file.</summary>
		virtual GameMap::UniquePtr parse() = 0;
	};
}