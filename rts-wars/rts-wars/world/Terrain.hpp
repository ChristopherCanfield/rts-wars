#pragma once


namespace cdc
{
	class Terrain
	{
	public:
		Terrain(bool passable);
		~Terrain();

		bool isPassable() const;
		
	private:
		bool passable;
	};
}

