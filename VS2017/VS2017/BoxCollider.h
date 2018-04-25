#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"
class BoxCollider : public Component
{
public:
	sf::RectangleShape boundingBox;
	bool m_showDebug;

	BoxCollider(sf::Vector2f, float, float, float);
	BoxCollider(sf::Vector2f, sf::Vector2f, sf::FloatRect);
	~BoxCollider();

	void Draw(sf::RenderTarget&) const;
	void Update(float);
	void UpdateBoundingBox(sf::Vector2f position, float width, float height, float angle);
	void Draw(sf::RenderTarget & target);
};