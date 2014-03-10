#include "stdafx.h"
#include "CppUnitTest.h"

#include "util/CheckedUnsignedInt.hpp"

#include <iostream>

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
			++t;
			Assert::AreEqual(1u, t.toValue());
		}

		TEST_METHOD(opMinusMinus1)
		{
			CheckedUnsignedInt t(10);
			t--;
			Assert::AreEqual(9u, t.toValue());
		}

		TEST_METHOD(opMinusMinus2)
		{
			CheckedUnsignedInt t(10);
			--t;
			Assert::AreEqual(9u, t.toValue());
		}

		TEST_METHOD(opMinusMinus3)
		{
			CheckedUnsignedInt t;
			try {
				t--;
				Assert::Fail();
			} catch(...) {}
		}

		TEST_METHOD(opPlus1)
		{
			CheckedUnsignedInt a(2);
			CheckedUnsignedInt b(5);
			CheckedUnsignedInt c = a + b;
			Assert::AreEqual(7u, c.toValue());
		}

		TEST_METHOD(opPlus2)
		{
			CheckedUnsignedInt a(2);
			unsigned int b(5);
			CheckedUnsignedInt c = a + b;
			Assert::AreEqual(7u, c.toValue());
		}

		TEST_METHOD(opPlus3)
		{
			CheckedUnsignedInt a(2);
			int b(5);
			CheckedUnsignedInt c = a + b;
			Assert::AreEqual(7u, c.toValue());
		}

		TEST_METHOD(opMinus1)
		{
			CheckedUnsignedInt a(5);
			CheckedUnsignedInt b(2);
			CheckedUnsignedInt c = a - b;
			Assert::AreEqual(3u, c.toValue());
		}

		TEST_METHOD(opMinus2)
		{
			CheckedUnsignedInt a(5);
			unsigned int b(2);
			CheckedUnsignedInt c = a - b;
			std::cout << a.toValue();
			Assert::AreEqual(3u, c.toValue());
		}

		TEST_METHOD(opMinus3)
		{
			CheckedUnsignedInt a(5);
			int b(2);
			CheckedUnsignedInt c = a - b;
			Assert::AreEqual(3u, c.toValue());
		}

		TEST_METHOD(opMinusExcept)
		{
			CheckedUnsignedInt a(2);
			CheckedUnsignedInt b(5);
			try {
				auto i = (a - b);
				Assert::Fail();
			} catch (...) {}
		}

		TEST_METHOD(toValueInt)
		{
			CheckedUnsignedInt a(3);
			Assert::AreEqual(3, a.toValue<int>());
		}

		TEST_METHOD(toValueFloat)
		{
			CheckedUnsignedInt a(3);
			Assert::AreEqual(3.f, a.toValue<float>());
		}
	};
}