#pragma once

// Christopher D. Canfield
// February 2014
// MoveController.hpp

#include "controllers/Controller.hpp"

#include <Poco/UUID.h>

namespace cdc
{
	///<summary>Controls entity movement.</summary>
	class MoveController :
		public Controller
	{
	public:
		///<summary>Constructs a MoveController</summary>
		///<param name="entityId">The ID of the entity that wil be controlled by
		///		this controller.</param>
		MoveController(Poco::UUID& entityId);
		virtual ~MoveController();

		virtual void update(World& world) override;

	private:
		Poco::UUID entityId;

		Poco::UUID targetId;

		bool hasTarget;
	};
}