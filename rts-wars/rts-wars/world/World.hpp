#pragma once

// Christopher D. Canfield
// February 2014
// World.hpp

#include "Entity.hpp"

#include <memory>
#include <vector>

namespace cdc
{	
	/// <summary>
	/// Represents the game world.
	/// </summary>
	class World
	{
	public:
		World();
		~World();

		/// <summary>Adds the entity to the world.</summary>
		/// <param name="e">The entity to add.</param>
		void addEntity(Entity::SharedPtr e);

		/// <summary>Returns the list of entities.</summary>
		/// <returns>The list of entities</returns>
		std::vector<Entity::SharedPtr>& getEntities();

		/// <summary>Returns the specified entity.</summary>
		/// <param name="id">The entity's unique id.</param>
		/// <returns>The entity with that has the specified unique id, or nullptr 
		///  if there are no matches</returns>
		Entity* getEntity(Poco::UUID id);

		/// <summary>Removes the specified entity.</summary>
		/// <param name="id">The entity's unique id.</param>
		void removeEntity(Poco::UUID id);

		/// <summary>Updates all entities</summary>
		void update();

	private:
		World& operator=(World& rhs);
		World(const World& rhs);
		World(const World&& rhs);

		std::vector<Entity::SharedPtr> entities;
		std::unordered_map<Poco::UUID, Entity*> entityMap;
	};
}
