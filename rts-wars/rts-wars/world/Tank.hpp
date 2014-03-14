#pragma once

// Christopher D. Canfield
// February 2014
// Tank.hpp

#include "AbstractEntity.hpp"

namespace cdc
{
	///<summary>A tank entity.</summary>
	class Tank :
		public AbstractEntity
	{
	public:
		Tank();
		Tank(Poco::UUID id);

		virtual ~Tank();

		std::string toString() const override;
	};
}
