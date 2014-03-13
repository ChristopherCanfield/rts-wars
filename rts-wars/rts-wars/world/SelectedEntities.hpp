#pragma once

#include "Entity.hpp"

#include <vector>

// Christopher D. Canfield
// March 2014
// SelectedEntities.hpp

namespace cdc
{
	///<summary>Contains the indexes of all selected entities.</summary>
	class SelectedEntities
	{
	public:
		SelectedEntities();
		~SelectedEntities();

		///<summary>Returns the list of selected entities.</summary>
		///<returns>The list of selected entities (the indexes to those entities).</returns>
		const std::vector<Poco::UUID>& get() const;

		///<summary>Adds the entity's index to the selected entities list.</summary>
		///<param name="entityId">The unique id of the entity that will be added to the list.</param>
		void add(const Poco::UUID& entityId);

		///<summary>Removes the entity's index from the selected entities list.</summary>
		///<param name="entityId">The unique id of the entity that will be removed from the list.</param>
		void remove(const Poco::UUID& entityId);

		///<summary>Removes all indexes from the selected entities list.</summary>
		void removeAll();

	private:
		std::vector<Poco::UUID> selected;
	};
}
