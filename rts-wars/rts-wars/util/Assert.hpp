#pragma once

#include <string>

// Christopher D. Canfield
// March 2014
// Assert.hpp

namespace cdc
{

	template<class E>
	inline void Assert(bool assertion)
	{
		if (!assertion) throw E();
	}

	template<class E>
	inline void Assert(bool assertion, std::string message)
	{
		if (!assertion) throw E(message);
	}

	template<class E>
	inline void Assert(bool assertion, std::string className, std::string methodName, std::string message)
	{
		if (!assertion) throw E(className, methodName, message);
	}

	template<class E, bool DebugLevel>
	inline void Assert(bool assertion)
	{
		if (DebugLevel && !assertion) throw E();
	}

	template<class E, bool DebugLevel>
	inline void Assert(bool assertion, std::string message)
	{
		if (DebugLevel && !assertion) throw E(message);
	}

	template<class E, bool DebugLevel>
	inline void Assert(bool assertion, std::string className, std::string methodName, std::string message)
	{
		if (DebugLevel && !assertion) throw E(className, methodName, message);
	}
}