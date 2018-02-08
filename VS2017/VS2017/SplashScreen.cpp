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


	//while (CombustionEngine::_gameState != CombustionEngine::Initialized) {
	//	while (renderWindow.getEvent(event)) {
	//		if (event.type == sf::Event::EventType::KeyPressed
	//			|| event.type == sf::Event::EventType::MouseButtonPressed
	//			|| event.type == sf::Event::EventType::Closed) {
	//			return;
	//		}
	//	}
	//}
}
