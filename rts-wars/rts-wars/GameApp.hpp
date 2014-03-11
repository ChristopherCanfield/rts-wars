#pragma once

// Christopher D. Canfield
// November 2013
// GameApp.hpp

#include "app/App.hpp"
#include "world/World.hpp"
#include "graphics/Camera.hpp"

#include <SFML/Graphics.hpp>


/// <summary>
/// The game application.
/// </summary>

namespace cdc
{
	class GameApp :
		public cdc::App
	{
	public:
		GameApp();
		virtual ~GameApp();

		virtual void setup() override;

		virtual bool run() override;

		virtual void teardown() override;

	private:
		sf::RenderWindow window;
		Camera::UniquePtr camera;

		sf::Clock timer;
		sf::Clock deltaTime;
	};
}