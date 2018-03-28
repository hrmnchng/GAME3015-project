#include "WindowManager.h"

WindowManager::WindowManager()
{
	window.create(sf::VideoMode(1024, 769), "JAILBREAK BOB GOES TO SPACE");
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