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


const std::vector<int>& SelectedEntities::get() const
{
	return selected;
}


void SelectedEntities::add(int entityIndex)
{
	if (!std::binary_search(selected.begin(), selected.end(), entityIndex))
	{
		selected.push_back(entityIndex);
		std::sort(selected.begin(), selected.end());
	}
}


void SelectedEntities::remove(int entityIndex)
{
	if (!selected.empty())
	{
		selected.erase(std::remove(selected.begin(), selected.end(), entityIndex));
	}
}


void SelectedEntities::removeAll()
{
	selected.clear();
}