#pragma once

#include "MapParser.hpp"

// Christopher D. Canfield
// March 2014
// TiledMapParser.hpp


namespace cdc
{
	namespace tiled
	{
		class TiledMapFileInfo;
	}

	class GameMap;

	///<summary>Parser for maps that were created using the Tiled map editor.</summary>
	class TiledMapParser :
		public MapParser
	{
	public:
		TiledMapParser(GameMap& map, tiled::TiledMapFileInfo& mapFileInfo);
		virtual ~TiledMapParser();

		virtual void parse() override;

	private:
		TiledMapParser& operator=(const TiledMapParser& rhs);

		GameMap& map;

		tiled::TiledMapFileInfo& fileInfo;
	};
}

