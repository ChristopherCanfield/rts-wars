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
		AbstractTerrain(float x, float z, uint height, uint width, bool passable, float speedPercentage);
		virtual ~AbstractTerrain();

		///<summary>Returns the x coordinate of the terrain, in world coordinates.</summary>
		///<returns>the x coordinate of the terrain, in world coordinates.</returns>
		virtual float getX() const override;

		///<summary>Returns the z coordinate of the terrain, in world coordinates.</summary>
		///<returns>the z coordinate of the terrain, in world coordinates.</returns>
		virtual float getZ() const override;

		///<summary>Returns the terrain's height.</summary>
		///<returns>the terrain's height.</returns>
		virtual uint getHeight() const override;

		///<summary>Returns the terrain's width.</summary>
		///<returns>the terrain's width.</returns>
		virtual uint getWidth() const override;

		///<summary>Specifies whether the terrain is passable or not.</summary>
		///<returns>true if the terrain is passable.</returns>
		virtual bool isPassable() const override;

		///<summary>Specifies the percentage of the entity's max speed that can be reached
		///	when traveling across the terrain.</summary>
		///<returns>The max speed percent.</returns>
		virtual float getSpeedPercentage() const override;

	private:
		float x;
		float z;

		uint height;
		uint width;

		bool passable;

		float speedPercentage;
	};
}
