#pragma once

#include "AbstractTile.hpp"

// Christopher D. Canfield
// March 2014
// Bridge.hpp


namespace cdc
{
	///<summary>A bridge tile.</summary>
	class Bridge :
		public AbstractTile
	{
	public:
		Bridge(float x, float y);
		virtual ~Bridge();
	};
}
