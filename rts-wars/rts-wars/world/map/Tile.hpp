#pragma once

#include "util/Typedefs.hpp"

#include <memory>

// Christopher D. Canfield
// March 2014
// Tile.hpp

namespace cdc
{

	class Tile
	{
	public:
		typedef std::shared_ptr<Tile> SharedPtr;
		typedef std::unique_ptr<Tile> UniquePtr;

		virtual ~Tile() {}

		virtual float getX() const = 0;

		virtual float getY() const = 0;

		virtual uint getHeight() const = 0;

		virtual uint getWidth() const = 0;

		virtual bool isPassable() const = 0;

		virtual float getSpeedPercentage() const = 0;
	};
}
