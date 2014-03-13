#include "stdafx.h"
#include "SelectionController.hpp"

// Christopher D. Canfield
// March 2014
// SelectionController.cpp

using namespace cdc;

SelectionController::SelectionController(const Poco::UUID& id) :
	entityId(id),
	isSelected(false)
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
		const auto mousePosition = world.getCamera().cameraToWorldCoordinates(Mouse::getPosition());
		const auto mousePositionInt = Vector2i(mousePosition.x, mousePosition.y);
		const bool withinBounds =  entity.getBoundingBox().contains(mousePositionInt);

		if (isSelected && !withinBounds)
		{
			world.getSelected().remove(entityId);
			isSelected = false;
		}
		else if (!isSelected && withinBounds)
		{
			world.getSelected().add(entityId);
			isSelected = true;
		}
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && isSelected)
	{
		world.getSelected().removeAll();
		isSelected = false;
	}
}