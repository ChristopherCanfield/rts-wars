#pragma once

#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// Dirt.hpp


namespace cdc
{
	///<summary>A dirt terrain.</summary>
	class Dirt :
		public AbstractTerrain
	{
	public:
		Dirt(float x, float y);
		virtual ~Dirt();
	};
}
