#pragma once

#include "MapParser.hpp"

// Christopher D. Canfield
// March 2014
// TiledMapParser.hpp


namespace cdc
{
	class TiledMapParser :
		public MapParser
	{
	public:
		TiledMapParser();
		virtual ~TiledMapParser();

		virtual void parse(std::string path) override;
	};
}

