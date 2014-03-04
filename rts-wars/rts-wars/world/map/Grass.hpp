#pragma once

#include "Tile.hpp"

// Christopher D. Canfield
// March 2014
// Grass.hpp


namespace cdc
{
	///<summary>A grass tile.</summary>
	class Grass :
		public AbstractTile
	{
	public:
		Grass(float x, float y);
		virtual ~Grass();
	};
}