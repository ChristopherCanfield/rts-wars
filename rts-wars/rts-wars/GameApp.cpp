#include "stdafx.h"

#include "GameApp.hpp"

using namespace cdc;

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
	// TODO: update this.
	return true;
}

void GameApp::teardown()
{

}