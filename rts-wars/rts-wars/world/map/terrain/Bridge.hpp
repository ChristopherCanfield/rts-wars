#pragma once

#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// Bridge.hpp


namespace cdc
{
	///<summary>A bridge terrain.</summary>
	class Bridge :
		public AbstractTerrain
	{
	public:
		Bridge(float x, float z);
		virtual ~Bridge();
	};
}
