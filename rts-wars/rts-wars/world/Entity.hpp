#pragma once

// Christopher D. Canfield
// February 2014
// Entity.hpp

#include "../util/Typedefs.hpp"

#include "Poco/UUID.h"


namespace cdc
{
	class World;
	
	/// <summary>
	/// Interface for game entities. All game world objects are entities.
	/// </summary>
	class Entity
	{
	public:
		virtual ~Entity() {}

		virtual const Poco::UUID& getId() const = 0;

		virtual float getX() const = 0;

		virtual void setX(float x) = 0;

		virtual float getY() const = 0;

		virtual void setY(float y) = 0;

		virtual float getRotation() const = 0;

		virtual void setRotation(float radians) = 0;

		virtual uint getHeight() const = 0;

		virtual void setHeight(uint height) = 0;

		virtual uint getWidth() const = 0;

		virtual void setWidth(uint width) = 0;

		virtual void update(World& world) = 0;
	};
}