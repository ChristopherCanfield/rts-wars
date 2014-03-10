#pragma once

#include "AbstractTerrain.hpp"

// Christopher D. Canfield
// March 2014
// Grass.hpp


namespace cdc
{
	///<summary>A grass terrain.</summary>
	class Grass :
		public AbstractTerrain
	{
	public:
		Grass(float x, float z);
		virtual ~Grass();
	};
}