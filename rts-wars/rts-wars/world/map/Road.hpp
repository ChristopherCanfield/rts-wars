#pragma once

#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// Road.hpp


namespace cdc
{

	class Road :
		public AbstractTile
	{
	public:
		Road(float x, float y);
		virtual ~Road();
	};
}
