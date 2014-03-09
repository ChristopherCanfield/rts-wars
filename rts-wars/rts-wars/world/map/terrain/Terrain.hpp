#pragma once

#include "util/Typedefs.hpp"

#include <memory>

// Christopher D. Canfield
// March 2014
// Terrain.hpp

namespace cdc
{
	///<summary>Interface for terrain objects.</summary>
	class Terrain
	{
	public:
		typedef std::shared_ptr<Terrain> SharedPtr;
		typedef std::unique_ptr<Terrain> UniquePtr;

		virtual ~Terrain() {}

		///<summary>Returns the x coordinate of the tile, in world coordinates.</summary>
		///<returns>the x coordinate of the tile, in world coordinates.</returns>
		virtual float getX() const = 0;

		///<summary>Returns the z coordinate of the tile, in world coordinates.</summary>
		///<returns>the z coordinate of the tile, in world coordinates.</returns>
		virtual float getZ() const = 0;

		///<summary>Returns the terrain's height.</summary>
		///<returns>the terrain's height.</returns>
		virtual uint getHeight() const = 0;

		///<summary>Returns the terrain's width.</summary>
		///<returns>the terrain's width.</returns>
		virtual uint getWidth() const = 0;

		///<summary>Specifies whether the terrain is passable or not.</summary>
		///<returns>true if the terrain is passable.</returns>
		virtual bool isPassable() const = 0;

		///<summary>Specifies the percentage of the entity's max speed that can be reached
		///	when traveling across the terrain.</summary>
		virtual float getSpeedPercentage() const = 0;

		///<summary>Returns the cost of traveling across the square.</summary>
		virtual float getCost() const = 0;
	};
}
