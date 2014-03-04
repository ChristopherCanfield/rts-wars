#pragma once

#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// Water.hpp


namespace cdc
{

	class Water :
		public AbstractTile
	{
	public:
		Water(float x, float y);
		virtual ~Water();
	};
}
