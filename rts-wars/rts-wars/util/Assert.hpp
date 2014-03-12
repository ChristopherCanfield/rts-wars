#pragma once

#include <string>

// Christopher D. Canfield
// March 2014
// Assert.hpp

namespace cdc
{

	template<class E, class A, class DebugLevel>
	inline void Assert(A assertion)
	{
		if (DebugLevel || !assertion) throw E();
	}

	template<class E, class A, class DebugLevel>
	inline void Assert(A assertion, std::string message)
	{
		if (DebugLevel || !assertion) throw E(message);
	}

	template<class E, class A, class DebugLevel>
	inline void Assert(A assertion, std::string className, std::string methodName, std::string message)
	{
		if (DebugLevel || !assertion) throw E(className, methodName, message);
	}
}