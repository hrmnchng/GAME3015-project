#include "TransformComponent.h"

sf::Transform TransformComponent::GetWorldTransform()
{
	return sf::Transform();
}

void TransformComponent::SetWorldTransform(sf::Transform transform)
{
	this->worldTransform = transform;
}