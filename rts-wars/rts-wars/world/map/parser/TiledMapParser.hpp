#pragma once

#include "MapParser.hpp"

// Christopher D. Canfield
// March 2014
// TiledMapParser.hpp


namespace cdc
{
	class GameMap;

	///<summary>Parser for maps that were created using the Tiled map editor.</summary>
	class TiledMapParser :
		public MapParser
	{
	public:
		TiledMapParser(GameMap& map);
		virtual ~TiledMapParser();

		virtual void parse(std::string path) override;

	private:
		GameMap& operator=(const GameMap& rhs);

		GameMap& map;
	};
}

