#include "stdafx.h"

#include "GameApp.hpp"

using namespace cdc;
using namespace sf;

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
	window.create(sf::VideoMode(800, 600), Constants::AppName);
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
	}
	else if (timer.getElapsedTime().asMilliseconds() - Constants::MillisPerTick > 5)
	{
		Time sleepTime(sf::microseconds(timer.restart().asMilliseconds() - Constants::MillisPerTick));
		sf::sleep(sleepTime);
	}

	return true;
}

void GameApp::teardown()
{

}