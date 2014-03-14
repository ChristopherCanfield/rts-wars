#pragma once

#include "controllers/Controller.hpp"

#include <Poco/UUID.h>

// Christopher D. Canfield
// March 2014
// SelectionController.hpp

namespace cdc
{

	class SelectionController :
		public Controller
	{
	public:
		SelectionController(const Poco::UUID& id);
		virtual ~SelectionController();

		virtual void update(World& world) override;

	private:
		SelectionController& operator=(const SelectionController&);

		const Poco::UUID entityId;
	};
}
