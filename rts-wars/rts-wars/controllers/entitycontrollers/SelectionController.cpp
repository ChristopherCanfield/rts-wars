#include "stdafx.h"
#include "SelectionController.hpp"

// Christopher D. Canfield
// March 2014
// SelectionController.cpp

using namespace cdc;

SelectionController::SelectionController(const Poco::UUID& id) :
	entityId(id)
{
}


SelectionController::~SelectionController()
{
}

void SelectionController::update(World& world)
{
	using namespace sf;

	// Get the entity.
	const Entity& entity = *world.getEntity(entityId);

	if (Mouse::isButtonPressed(Mouse::Button::Left))
	{
		// Determine if the mouse click falls within the entity's bounds.
		const auto mousePosition = Mouse::getPosition(world.getCamera().getWindow());
		const auto adjustedMousePosition = world.getCamera().cameraToWorldCoordinates(mousePosition);
		const auto adjustedMousePositionInt = Vector2i(mousePosition.x, mousePosition.y);
		const bool withinBounds =  entity.getBoundingBox().contains(adjustedMousePositionInt);

		const bool multiSelectKeyDown = Keyboard::isKeyPressed(Keyboard::Key::LShift) || Keyboard::isKeyPressed(Keyboard::Key::LShift) || 
				Keyboard::isKeyPressed(Keyboard::Key::LControl) || Keyboard::isKeyPressed(Keyboard::Key::RControl);

		// The unit has clicked outside of this unit's bounding box, and this unit is currently selected.
		if (entity.isSelected() && !withinBounds && !multiSelectKeyDown)
		{
			// TODO: this should probably move the unit, instead of deselecting it.
			world.getSelected().remove(entityId);
		}
		// The unit is attempting to select the unit.
		else if (!entity.isSelected() && withinBounds)
		{
			world.getSelected().add(entityId);
		}
		// The user is attempting to deselect the unit.
		// TODO: add a click timer, and then uncomment this line.
		/*else if (entity.isSelected() && withinBounds && multiSelectKeyDown)
		{
			world.getSelected().remove(entityId);
		}*/
	}
	else if (Mouse::isButtonPressed(Mouse::Button::Right) && entity.isSelected())
	{
		// Right click deselects all selected units.
		world.getSelected().removeAll();
	}
}