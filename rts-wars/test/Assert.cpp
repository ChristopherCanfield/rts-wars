#include "stdafx.h"
#include "CppUnitTest.h"

#include "util/Assert.hpp"
#include "util/GameLogicException.hpp"

#include <stdexcept>
#include <exception>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{		
	TEST_CLASS(AssertTest)
	{
	public:
		
		TEST_METHOD(Assert_noMessage)
		{
			cdc::Assert<std::exception>(true);
		}

		TEST_METHOD(Assert_failNoMessage)
		{
			try {
				cdc::Assert<std::exception>(false);
				Assert::Fail();
			} catch (...) {}
		}

		TEST_METHOD(Assert_message)
		{
			cdc::Assert<cdc::GameLogicException>(true, "class", "method", "assertion message");
		}

		TEST_METHOD(Assert_failMessage)
		{
			try {
				cdc::Assert<cdc::GameLogicException>(false, "class", "method", "assertion message");
				Assert::Fail();
			} catch (...) {}
		}
	};
}