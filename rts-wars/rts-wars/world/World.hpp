#pragma once

// Christopher D. Canfield
// February 2014
// World.hpp

#include <memory>
#include <vector>

namespace cdc
{	
	class Entity;

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
		void addEntity(std::unique_ptr<Entity>&& e);

	private:
		World& operator=(World& rhs);
		World(const World& rhs);
		World(const World&& rhs);

		std::vector<std::unique_ptr<Entity>> entities;
	};
}
