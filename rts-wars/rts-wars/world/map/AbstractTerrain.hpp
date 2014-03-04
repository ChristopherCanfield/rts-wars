#pragma once

#include "Terrain.hpp"

// Christopher D. Canfield
// March 2014
// AbstractTerrain.hpp

namespace cdc
{

	class AbstractTerrain :
		public Terrain
	{
	public:
		AbstractTerrain(float x, float y, uint height, uint width, bool passable, float speedPercentage);
		virtual ~AbstractTerrain();

		///<summary>Returns the x coordinate of the tile, in world coordinates.</summary>
		///<returns>the x coordinate of the tile, in world coordinates.</returns>
		virtual float getX() const override;

		///<summary>Returns the y coordinate of the tile, in world coordinates.</summary>
		///<returns>the y coordinate of the tile, in world coordinates.</returns>
		virtual float getY() const override;

		///<summary>Returns the tile's height.</summary>
		///<returns>the tile's height.</returns>
		virtual uint getHeight() const override;

		///<summary>Returns the tile's width.</summary>
		///<returns>the tile's width.</returns>
		virtual uint getWidth() const override;

		///<summary>Specifies whether the tile is passable or not.</summary>
		///<returns>true if the tile is passable.</returns>
		virtual bool isPassable() const override;

		///<summary>Specifies the percentage of the entity's max speed that can be reached
		///	when traveling across the tile.</summary>
		///<returns>The max speed percent.</returns>
		virtual float getSpeedPercentage() const override;

	private:
		float x;
		float y;

		uint height;
		uint width;

		bool passable;

		float speedPercentage;
	};
}
