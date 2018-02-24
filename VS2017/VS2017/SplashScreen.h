#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
#include "CombustionEngine.h"

class SplashScreen {
public:
	void Show(sf::RenderWindow& window);

	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

};

#endif