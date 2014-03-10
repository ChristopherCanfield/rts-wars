#pragma once

#include <string>

// Christopher D. Canfield
// March 2014
// Assert.hpp

namespace cdc
{

	template<class E, class A>
	inline void Assert(A assertion)
	{
		if (!assertion) throw E();
	}

	template<class E, class A>
	inline void Assert(A assertion, std::string message)
	{
		if (!assertion) throw E(message);
	}
}