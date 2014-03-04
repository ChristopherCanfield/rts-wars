#pragma once

#include "Tile.hpp"

// Christopher D. Canfield
// March 2014
// AbstractTile.hpp

namespace cdc
{

	class AbstractTile :
		public Tile
	{
	public:
		AbstractTile(float x, float y, uint height, uint width, bool passable, float speedPercentage);
		virtual ~AbstractTile();

		virtual float getX() const override;

		virtual float getY() const override;

		virtual uint getHeight() const override;

		virtual uint getWidth() const override;

		virtual bool isPassable() const override;

		virtual float getSpeedPercentage() const override;

	private:
		float x;
		float y;

		uint height;
		uint width;

		bool passable;

		float speedPercentage;
	};
}
