#pragma once

#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// Water.hpp


namespace cdc
{
	///<summary>A water tile.</summary>
	class Water :
		public AbstractTile
	{
	public:
		Water(float x, float y);
		virtual ~Water();
	};
}
