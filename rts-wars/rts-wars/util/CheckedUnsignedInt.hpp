#pragma once

// Christopher D. Canfield
// March 2014
// CheckedUnsignedInt.hpp

namespace cdc
{
	/// <summary>A checked implementation of an unsigned int. Use this during testing to catch 
	/// underflow errors, and then switch to unsigned int for production.</summary>
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
			return value;
		}

		template <class T>
		T toValue() const
		{
			return static_cast<T>(value);
		}

	private:
		unsigned int value;
	};
}