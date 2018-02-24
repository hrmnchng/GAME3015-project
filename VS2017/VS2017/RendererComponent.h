#pragma once
#include "Component.h"
#include "SFML\Graphics.hpp"
#include <string>

class RendererComponent: public Component
{
public:
	void LoadFromFile(std::string path);
	void Draw(sf::RenderWindow& window);

private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
};