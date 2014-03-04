#pragma once

#include "Tile.hpp"

// Christopher D. Canfield
// March 2014
// Grass.hpp


namespace cdc
{

	class Grass :
		public AbstractTile
	{
	public:
		Grass(float x, float y);
		virtual ~Grass();
	};
}