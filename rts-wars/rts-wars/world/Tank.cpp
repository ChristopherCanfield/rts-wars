#include "stdafx.h"
#include "Tank.hpp"

// Christopher D. Canfield
// February 2014
// Tank.hpp

using namespace cdc;

Tank::Tank()
{

}

Tank::Tank(Poco::UUID id) :
	AbstractEntity(id)
{
}

Tank::~Tank()
{
}