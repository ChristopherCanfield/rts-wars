#include "stdafx.h"
#include "CheckedUnsignedInt.hpp"

#include <stdexcept>
#include <climits>

// Christopher D. Canfield
// March 2014
// CheckedUnsignedInt.hpp

using namespace cdc;
using namespace std;

CheckedUnsignedInt::CheckedUnsignedInt() :
	value(0)
{
}

CheckedUnsignedInt::CheckedUnsignedInt(unsigned int val) :
	value(val)
{
	Assert<range_error>(val <= INT_MAX, "CheckedUnsignedInt exceeded max int value.");
}

CheckedUnsignedInt::CheckedUnsignedInt(int value)
{
	Assert<range_error>(value >= 0, "CheckedUnsignedInt was negative.");
	this->value = value;
}

CheckedUnsignedInt& CheckedUnsignedInt::operator++()
{
	Assert<range_error>(value <= INT_MAX, "CheckedUnsignedInt exceeded max int value.");
	++value;
	return *this;
}

CheckedUnsignedInt CheckedUnsignedInt::operator++(int val)
{
	Assert<range_error>(value <= INT_MAX, "CheckedUnsignedInt exceeded max int value.");
	return CheckedUnsignedInt(++value);
}

CheckedUnsignedInt& CheckedUnsignedInt::operator--()
{
	--value;
	Assert<range_error>(value >= 0, "CheckedUnsignedInt was negative.");
	return *this;
}

CheckedUnsignedInt CheckedUnsignedInt::operator--(int)
{
	Assert<range_error>(value - 1 >= 0, "CheckedUnsignedInt was negative.");
	return CheckedUnsignedInt(--value);
}

CheckedUnsignedInt CheckedUnsignedInt::operator+(CheckedUnsignedInt val)
{
	Assert<range_error>(val.toValue() + value <= INT_MAX, "CheckedUnsignedInt exceeded max int value.");
	return CheckedUnsignedInt(value + val.value);
}

CheckedUnsignedInt CheckedUnsignedInt::operator+(unsigned int val)
{
	Assert<range_error>(val + value <= INT_MAX, "CheckedUnsignedInt exceeded max int value.");
	return CheckedUnsignedInt(value + val);
}

CheckedUnsignedInt CheckedUnsignedInt::operator+(int val)
{
	Assert<range_error>(value + val >= 0, "CheckedUnsignedInt was negative.");
	return CheckedUnsignedInt(value + val);
}

CheckedUnsignedInt CheckedUnsignedInt::operator-(CheckedUnsignedInt val)
{
	Assert<range_error>(value - val.value >= 0, "CheckedUnsignedInt was negative.");
	return CheckedUnsignedInt(value - val.value);
}

CheckedUnsignedInt CheckedUnsignedInt::operator-(unsigned int val)
{
	Assert<range_error>(value - val >= 0, "CheckedUnsignedInt was negative.");
	return CheckedUnsignedInt(value - val);
}
		
CheckedUnsignedInt CheckedUnsignedInt::operator-(int val)
{
	Assert<range_error>(value - val >= 0, "CheckedUnsignedInt was negative.");
	return CheckedUnsignedInt(value - val);
}