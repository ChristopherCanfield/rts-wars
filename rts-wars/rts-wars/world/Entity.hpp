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

		///<summary>Gets the entity's x coordinate, in world coordinates.</summary>
		///<returns>The entity's x coordinate.</returns>
		virtual float getX() const = 0;

		///<summary>Sets the entity's x coordinate.</summary>
		///<param name="x">The entity's x coordinate.</param>
		virtual void setX(float x) = 0;

		///<summary>Gets the entity's z coordinate, in world coordinates.</summary>
		///<returns>The entity's z coordinate.</returns>
		virtual float getZ() const = 0;

		///<summary>Sets the entity's z coordinate.</summary>
		///<param name="z">The entity's z coordinate.</param>
		virtual void setZ(float z) = 0;

		///<summary>Gets the entity's rotation.</summary>
		///<returns>The entity's rotation.</returns>
		virtual float getRotation() const = 0;

		///<summary>Sets the entity's rotation.</summary>
		///<param name="radians">The entity's rotation.</param>
		virtual void setRotation(float radians) = 0;

		///<summary>Gets the entity's height.</summary>
		///<returns>The entity's height.</returns>
		virtual uint getHeight() const = 0;

		///<summary>Sets the entity's height.</summary>
		///<param name="height">The entity's height.</param>
		virtual void setHeight(uint height) = 0;

		///<summary>Gets the entity's width.</summary>
		///<returns>The entity's width.</returns>
		virtual uint getWidth() const = 0;

		///<summary>Sets the entity's width.</summary>
		///<param name="width">The entity's width.</param>
		virtual void setWidth(uint width) = 0;

		virtual sf::IntRect getBoundingBox() const;

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