#pragma once

// Christopher D. Canfield
// February 2014
// UUIDHash.hpp

#include <functional>

#include <Poco/UUID.h>

namespace std
{
	template<>
	class hash<Poco::UUID>
	{
	public:
		// Adapted from Bjarne Stroustrup, "A Tour of C++"
		std::size_t operator()(const Poco::UUID& key) const
		{
			return hash<std::string>()(key.toString());
		}
	};
}