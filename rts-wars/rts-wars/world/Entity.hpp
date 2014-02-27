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
		typedef std::shared_ptr<Entity> SharedPtr;
		typedef std::unique_ptr<Entity> UniquePtr;
		typedef std::weak_ptr<Entity> WeakPtr;

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

		/// <summary>Determines whether this entity is destroyed.</summary>
		/// <returns>true if this entity is destroyed.</returns>
		virtual bool isDestroyed() const = 0;

		/// <summary>Updates this entity. Must be called once per game tick.</summary>
		/// <param name="world">Reference to the world.</param>
		virtual void update(World& world) = 0;

	private:
		Entity& operator=(const Entity& rhs);
	};
}