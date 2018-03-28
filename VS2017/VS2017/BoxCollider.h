#pragma once
#include <SFML\Graphics.hpp>
#include "Component.h"
class BoxCollider : public Component
{
public:
	sf::FloatRect boundingBox;

	BoxCollider(sf::FloatRect);
	~BoxCollider();

	void Update(float);
	void UpdateBoundingBox(sf::Vector2f position, float width, float height);
};