#include "stdafx.h"

#include "GameApp.hpp"
#include "world/Tank.hpp"
#include "graphics/cameras/SfmlCamera.hpp"
#include "controllers/cameracontrollers/SfmlCameraController.hpp"
#include "world/map/parser/TiledMapParser.hpp"
#include "world/map/maps/tiled/Map1.hpp"
#include "world/map/maps/tiled/TiledMapFileInfo.hpp"

using namespace cdc;
using namespace sf;
using namespace std;

GameApp::GameApp()
{
}


GameApp::~GameApp()
{
}

void GameApp::setup()
{
	// TODO: allow the window resolution to be set by user?
	window.create(sf::VideoMode(800, 600), Constants::AppName, sf::Style::Default);

	// TODO: this is a test - remove it in the future.
	Entity::SharedPtr tank = make_shared<Tank>();
	tank->setX(50.f);
	tank->setZ(40.f);
	World::Instance().addEntity(tank);

	tiled::Map1 map1;
	TiledMapParser parser(map1);
	auto gameMap = parser.parse();

	camera = make_unique<SfmlCamera>(window, sf::Vector2u(gameMap->getWidth(), gameMap->getHeight()));
	camera->addController(make_unique<SfmlCameraController>(*camera));

	World::Instance().setGameMap(move(gameMap));
}

bool GameApp::run()
{
	// Game loop.
	if (timer.getElapsedTime().asMilliseconds() > Constants::MillisPerTick)
	{
		// Poll for window events.
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				return false;
			}
		}

		window.clear(sf::Color::Blue);
		window.draw(Graphics::Instance());
		World::Instance().update();
		camera->update();
		Graphics::Instance().update(deltaTime.getElapsedTime());
		deltaTime.restart();

		window.display();
	}
	// Sleep if more than a very small amount of time remains in the time slice.
	else if (timer.getElapsedTime().asMilliseconds() - Constants::MillisPerTick > 5)
	{
		Time sleepTime(sf::milliseconds(timer.restart().asMilliseconds() - Constants::MillisPerTick));
		sf::sleep(sleepTime);
	}

	return true;
}

void GameApp::teardown()
{
}