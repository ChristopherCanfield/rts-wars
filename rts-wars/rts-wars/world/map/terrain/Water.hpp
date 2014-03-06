#pragma once

#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// Water.hpp


namespace cdc
{
	///<summary>A water terrain.</summary>
	class Water :
		public AbstractTerrain
	{
	public:
		Water(float x, float y);
		virtual ~Water();
	};
}
