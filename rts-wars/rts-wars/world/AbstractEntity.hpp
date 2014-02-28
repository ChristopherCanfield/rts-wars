#pragma once

#include "Entity.hpp"

// Christopher D. Canfield
// February 2014
// AbstractEntity.hpp

#include <vector>

namespace cdc
{
	class Controller;

	class AbstractEntity : 
		public Entity
	{
	public:
		virtual ~AbstractEntity();

		virtual const Poco::UUID& getId() const override;

		virtual float getX() const override;

		virtual void setX(float x) override;

		virtual float getY() const override;

		virtual void setY(float y) override;

		virtual float getRotation() const override;

		virtual void setRotation(float radians) override;

		virtual uint getHeight() const override;

		virtual void setHeight(uint height) override;

		virtual uint getWidth() const override;

		virtual void setWidth(uint width) override;

		virtual bool isDestroyed() const override;

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

		void setDestroyed(bool value);

	private:
		AbstractEntity operator=(AbstractEntity&) {}

		void constructEntity();

		const Poco::UUID id;

		float x;
		float y;

		float rotation;

		uint height;
		uint width;

		bool destroyed;

		std::vector<Controller> controllers;
	};
}