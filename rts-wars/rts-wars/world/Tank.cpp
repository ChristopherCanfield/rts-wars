#include "stdafx.h"
#include "Tank.hpp"
#include "graphics/sprites/TankSprite.hpp"

// Christopher D. Canfield
// February 2014
// Tank.hpp

using namespace cdc;

using std::make_shared;
using std::move;

Tank::Tank()
{
	Controller::UniquePtr selectionController = make_unique<SelectionController>(getId());
	addController(move(selectionController));

	Sprite::SharedPtr sprite(make_shared<TankSprite>(*this));
	Graphics::Instance().addSprite(sprite);

	setHeight(32);
	setWidth(32);

	// Ensure that the entity's invariants hold.
	#if HIGH_ASSERT
		checkInvariants();
	#endif
}

Tank::Tank(Poco::UUID id) :
	AbstractEntity(id)
{
}

Tank::~Tank()
{
}


std::string Tank::toString() const
{
	return "Tank";
}