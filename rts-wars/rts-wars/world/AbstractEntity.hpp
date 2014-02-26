#pragma once

#include "Entity.hpp"

// Christopher D. Canfield
// February 2014
// AbstractEntity.hpp

namespace cdc
{
	class AbstractEntity : 
		public Entity
	{
	public:
		AbstractEntity();
		virtual ~AbstractEntity();


	};
}