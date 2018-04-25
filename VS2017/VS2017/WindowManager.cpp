#include "WindowManager.h"

WindowManager::WindowManager()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "JAILBREAK BOB GOES TO SPACE");
	window.setFramerateLimit(60);
}

WindowManager& WindowManager::rm()
{
	static WindowManager rm;
	return rm;
}

sf::RenderWindow& WindowManager::getWindow()
{
	return window;
}