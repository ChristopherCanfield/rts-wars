#include "stdafx.h"
#include "CppUnitTest.h"

#include "util/CheckedUnsignedInt.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace cdc;

namespace test
{
	TEST_CLASS(CheckedUnsignedIntTest)
	{
	public:
		
		TEST_METHOD(constructor1)
		{
			CheckedUnsignedInt t;
			Assert::AreEqual(0u, t.toValue());
		}

		TEST_METHOD(constructor2)
		{
			CheckedUnsignedInt t(0u);
			Assert::AreEqual(0u, t.toValue());
		}

		TEST_METHOD(constructor3)
		{
			CheckedUnsignedInt t(0);
			Assert::AreEqual(0u, t.toValue());
		}

		TEST_METHOD(opPlusPlus1)
		{
			CheckedUnsignedInt t;
			t++;
			Assert::AreEqual(1u, t.toValue());
		}

		TEST_METHOD(opPlusPlus2)
		{
			CheckedUnsignedInt t;
			Assert::AreEqual(0u, t.toValue());
		}

		CheckedUnsignedInt& operator++();
		CheckedUnsignedInt operator++(int);

		CheckedUnsignedInt& operator--();
		CheckedUnsignedInt operator--(int);

		CheckedUnsignedInt operator+(CheckedUnsignedInt);
		CheckedUnsignedInt operator+(unsigned int);
		CheckedUnsignedInt operator+(int);

		CheckedUnsignedInt operator-(CheckedUnsignedInt);
		CheckedUnsignedInt operator-(unsigned int);
		CheckedUnsignedInt operator-(int);
	};
}