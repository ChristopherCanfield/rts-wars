#pragma once

#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// Dirt.hpp


namespace cdc
{

	class Dirt :
		public AbstractTile
	{
	public:
		Dirt(float x, float y);
		virtual ~Dirt();
	};
}
