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
		// Get the entity.
		const Entity& entity = *world.getEntity(entityId);
		
		// Determine if the mouse click falls within the entity's bounds.
		const auto mousePosition = Mouse::getPosition(world.getCamera().getWindow());
		const auto adjustedMousePosition = world.getCamera().cameraToWorldCoordinates(mousePosition);
		const auto adjustedMousePositionInt = Vector2i(mousePosition.x, mousePosition.y);
		const bool withinBounds =  entity.getBoundingBox().contains(adjustedMousePositionInt);

		if (entity.isSelected() && !withinBounds)
		{
			world.getSelected().remove(entityId);
		}
		else if (!entity.isSelected() && withinBounds)
		{
			world.getSelected().add(entityId);
		}
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && isSelected)
	{
		// Right click deselects all selected units.
		world.getSelected().removeAll();
	}
}