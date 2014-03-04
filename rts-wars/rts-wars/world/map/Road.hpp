#pragma once

#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// Road.hpp


namespace cdc
{
	///<summary>A road terrain.</summary>
	class Road :
		public AbstractTerrain
	{
	public:
		Road(float x, float y);
		virtual ~Road();
	};
}
