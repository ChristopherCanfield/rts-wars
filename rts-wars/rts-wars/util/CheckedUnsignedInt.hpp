#pragma once

#include "util/Assert.hpp"

// Christopher D. Canfield
// March 2014
// CheckedUnsignedInt.hpp

namespace cdc
{
	/// <summary>A checked implementation of an unsigned int. Use this during testing 
	/// to catch underflow errors, and then switch to unsigned int for production. 
	/// Note that overflow errors are not checked. Additionally, this class only 
	/// allows values up to unsigned int / 2.</summary>
	class CheckedUnsignedInt
	{
	public:
		CheckedUnsignedInt();
		CheckedUnsignedInt(unsigned int value);
		CheckedUnsignedInt(int value);

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

		unsigned int toValue() const 
		{
			return static_cast<unsigned int>(value);
		}

		template <class T>
		T toValue() const
		{
			return static_cast<T>(value);
		}

	private:
		int value;
	};
}

//cdc::CheckedUnsignedInt operator-(const cdc::CheckedUnsignedInt& val1, const cdc::CheckedUnsignedInt& val2)
//{
//	cdc::Assert<std::range_error>(val1.toValue() - val2.toValue() >= 0, "CheckedUnsignedInt is less than zero");
//	return cdc::CheckedUnsignedInt(val1.toValue() - val2.toValue());
//}
//
//cdc::CheckedUnsignedInt operator-(unsigned int val1, const cdc::CheckedUnsignedInt& val2)
//{
//	cdc::Assert<std::range_error>(val1 - val2.toValue() >= 0, "CheckedUnsignedInt is less than zero");
//	return cdc::CheckedUnsignedInt(val1 - val2.toValue());
//}
//
//cdc::CheckedUnsignedInt operator-(int val1, const cdc::CheckedUnsignedInt& val2)
//{
//	cdc::Assert<std::range_error>(val1 - val2.toValue() >= 0, "CheckedUnsignedInt is less than zero");
//	return cdc::CheckedUnsignedInt(val1 - val2.toValue());
//}