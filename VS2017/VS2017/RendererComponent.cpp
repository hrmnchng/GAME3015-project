#include "RendererComponent.h"

void RendererComponent::LoadFromFile(std::string path)
{
	image.loadFromFile(path);
	texture.loadFromImage(image);
	texture.setSmooth(true);
	sprite.setTexture(texture, true);
}

void RendererComponent::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}