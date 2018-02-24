#include "SplashScreen.h"
#include "SFML\Graphics\Image.hpp"

void SplashScreen::Show(sf::RenderWindow & renderWindow) {

	image.loadFromFile("../../Assets/SplashScreen.png");
	texture.loadFromImage(image);
	texture.setSmooth(true);
	sprite.setTexture(texture, true);

	renderWindow.draw(sprite);
	renderWindow.display();
	sf::Event event;
}
