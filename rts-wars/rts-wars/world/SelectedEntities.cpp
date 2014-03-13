#include "stdafx.h"
#include "SelectedEntities.hpp"

// Christopher D. Canfield
// March 2014
// SelectedEntities.cpp


using namespace cdc;

SelectedEntities::SelectedEntities()
{
}


SelectedEntities::~SelectedEntities()
{
}


const std::vector<Poco::UUID>& SelectedEntities::get() const
{
	return selected;
}


void SelectedEntities::add(const Poco::UUID& entityId)
{
	if (!std::binary_search(selected.begin(), selected.end(), entityId))
	{
		selected.push_back(entityId);
		std::sort(selected.begin(), selected.end());
	}
}


void SelectedEntities::remove(const Poco::UUID& entityId)
{
	if (!selected.empty())
	{
		selected.erase(std::remove(selected.begin(), selected.end(), entityId));
	}
}


void SelectedEntities::removeAll()
{
	selected.clear();
}