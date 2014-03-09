#pragma once

#include "world/map/maps/tiled/TiledMapFileInfo.hpp"

// Christopher D. Canfield
// March 2014
// TiledMapFileInfo.hpp


namespace cdc
{
	namespace tiled
	{
		class Map1 :
			public TiledMapFileInfo
		{
		public:
			Map1();
			virtual ~Map1();
		};
	}
}

