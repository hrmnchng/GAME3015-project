#pragma once
#include "CombustionEngine.h"

class SplashScreen {
public:
	void Show(sf::RenderWindow& window);

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

};