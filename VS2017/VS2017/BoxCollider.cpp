#include "BoxCollider.h"
#include "GameObject.h"
#include <iostream>

BoxCollider::BoxCollider(sf::Vector2f position, float angle, float width, float height)
{
	boundingBox.setPosition(position.x, position.y);
	boundingBox.setSize(sf::Vector2f(width, height));
	boundingBox.setFillColor(sf::Color(0, 255, 0, 100));
	boundingBox.setOrigin(width / 2.0f, height / 2.0f);
	boundingBox.setRotation(angle);
	m_showDebug = false;
}

BoxCollider::BoxCollider(sf::Vector2f position, sf::Vector2f scale, sf::FloatRect box)
{
	boundingBox.setPosition(position.x, position.y);
	boundingBox.setSize(sf::Vector2f(box.width, box.height));
	boundingBox.setFillColor(sf::Color(0, 255, 0, 100));
	boundingBox.setOrigin((box.width / 2.0f) * scale.x, (box.height / 2.0f) * scale.y);
	boundingBox.setRotation(0.0f);
	m_showDebug = false;
}

BoxCollider::~BoxCollider()
{

}

void BoxCollider::Update(float deltaTime)
{
	this->Component::Update(deltaTime);
}

void BoxCollider::UpdateBoundingBox(sf::Vector2f position, float width, float height, float angle)
{
	boundingBox.setPosition(position.x, position.y);
	boundingBox.setSize(sf::Vector2f(width, height));
	boundingBox.setFillColor(sf::Color(0, 255, 0, 100));
	boundingBox.setOrigin(width / 2.0f, height / 2.0f);
	boundingBox.setRotation(angle);
}

void BoxCollider::Draw(sf::RenderTarget& target)
{
	target.draw(boundingBox);
}
