#include "stdafx.h"

#include "GameApp.hpp"
#include "world/Tank.hpp"

using namespace cdc;
using namespace sf;
using namespace std;

GameApp::GameApp() :
	window()
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
	tank->setY(40.f);
	world.addEntity(tank);
}

bool GameApp::run()
{
	if (timer.getElapsedTime().asMilliseconds() > Constants::MillisPerTick)
	{
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
		world.update();
		Graphics::Instance().update();

		window.display();
	}
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