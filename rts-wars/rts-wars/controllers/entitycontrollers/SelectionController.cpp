#include "stdafx.h"
#include "SelectionController.hpp"

// Christopher D. Canfield
// March 2014
// SelectionController.cpp

using namespace cdc;

SelectionController::SelectionController(Poco::UUID& id) :
	entityId(id)
{
}


SelectionController::~SelectionController()
{
}

void SelectionController::update(World& world)
{
	using namespace sf;

	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		const Entity& entity = *world.getEntity(entityId);
		const bool withinBounds =  entity.getBoundingBox().contains(Mouse::getPosition());

		if (isSelected && !withinBounds)
		{

		}
		else if (!isSelected && withinBounds)
		{

		}
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && isSelected)
	{
		world.selected().removeAll();
	}
}