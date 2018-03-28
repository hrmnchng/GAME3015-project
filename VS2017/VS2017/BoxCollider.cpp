#include "BoxCollider.h"
#include <iostream>

BoxCollider::BoxCollider(sf::FloatRect box)
{
	boundingBox = box;
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::Update(float deltaTime)
{
	// Super
	this->Component::Update(deltaTime);
}

void BoxCollider::UpdateBoundingBox(sf::Vector2f position, float width, float height)
{
	boundingBox.left = position.x;
	boundingBox.top = position.y;
	boundingBox.width = width;
	boundingBox.height = height;
}
