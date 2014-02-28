#include "stdafx.h"
#include "MoveController.hpp"

// Christopher D. Canfield
// February 2014
// MoveController.hpp

using namespace cdc;

MoveController::MoveController(Poco::UUID& id) :
	entityId(id),
	hasTarget(false)
{
}


MoveController::~MoveController()
{
}

void MoveController::update(World& world)
{
	Entity& entity = *world.getEntity(entityId);

	// TODO (cdc - 2014-02-27): move the entity.
}