#pragma once

#include "Entity.hpp"

// Christopher D. Canfield
// February 2014
// AbstractEntity.hpp

#include <vector>

namespace cdc
{
	class Controller;

	///<summary>The abstract base class for entities.</summary>
	class AbstractEntity : 
		public Entity
	{
	public:
		virtual ~AbstractEntity();

		virtual const Poco::UUID& getId() const override;

		///<summary>Gets the entity's x coordinate, in world coordinates.</summary>
		///<returns>The entity's x coordinate.</returns>
		virtual float getX() const override;

		///<summary>Sets the entity's x coordinate.</summary>
		///<param name="x">The entity's x coordinate.</param>
		virtual void setX(float x) override;

		///<summary>Gets the entity's z coordinate, in world coordinates.</summary>
		///<returns>The entity's z coordinate.</returns>
		virtual float getZ() const override;

		///<summary>Sets the entity's z coordinate.</summary>
		///<param name="z">The entity's z coordinate.</param>
		virtual void setZ(float z) override;

		///<summary>Gets the entity's rotation.</summary>
		///<returns>The entity's rotation.</returns>
		virtual float getRotation() const override;

		///<summary>Sets the entity's rotation.</summary>
		///<param name="radians">The entity's rotation.</param>
		virtual void setRotation(float radians) override;

		///<summary>Gets the entity's height.</summary>
		///<returns>The entity's height.</returns>
		virtual uint getHeight() const override;

		///<summary>Sets the entity's height.</summary>
		///<param name="height">The entity's height.</param>
		virtual void setHeight(uint height) override;

		///<summary>Gets the entity's width.</summary>
		///<returns>The entity's width.</returns>
		virtual uint getWidth() const override;

		///<summary>Sets the entity's width.</summary>
		///<param name="width">The entity's width.</param>
		virtual void setWidth(uint width) override;

		sf::IntRect getBoundingBox() const override;

		///<summary>Specifies whether the entity is destroyed.</summary>
		///<returns>true if the entity is destroyed.</returns>
		virtual bool isDestroyed() const override;

		///<summary>Updates the entity. Must be called once per game tick.</summary>
		///<param name="world">Reference to the world.</param>
		virtual void update(World& world) override;

	protected:
		/// <summary>
		/// Constructs a new instance of <see cref="AbstractEntity"/> with 
		/// a random UUID.
		/// </summary>
		AbstractEntity();

		/// <summary>
		/// Constructs a new instance of <see cref="AbstractEntity"/> with the 
		/// specified id.
		/// </summary>
		/// <param name="uuid">The entity's id.</param>
		AbstractEntity(Poco::UUID uuid);

		void destroy();

		void addController(Controller::UniquePtr controller);

	private:
		AbstractEntity operator=(AbstractEntity&) {}

		void constructEntity();

		const Poco::UUID id;

		float x;
		float z;

		float rotation;

		uint height;
		uint width;

		bool destroyed;

		std::vector<Controller::UniquePtr> controllers;
	};
}