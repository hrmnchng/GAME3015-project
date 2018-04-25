#pragma once
#include "Component.h"
#include <string>

class RendererComponent: public Component
{
public:
	void LoadFromFile(std::string path);
	void Draw(sf::RenderWindow& window, sf::Transform transform);
	sf::Sprite GetSprite();

private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
};