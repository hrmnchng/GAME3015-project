#include "TransformComponent.h"

sf::Transform TransformComponent::GetWorldTransform()
{
	return worldTransform;
}

void TransformComponent::SetWorldTransform(sf::Transform transform)
{
	this->worldTransform = transform;
}

sf::Transform TransformComponent::GetTransform()
{
	return transform;
}

void TransformComponent::SetTransform(sf::Transform transform)
{
	this->transform = transform;
}

TransformComponent::TransformComponent(float x, float y)
{
	transform.translate(x, y);
}

void TransformComponent::Start()
{
	Component::Start();
}

void TransformComponent::Update(float deltaTime)
{
	Component::Update(deltaTime);
}

void TransformComponent::Translate(float x, float y)
{
	transform.translate(x, y);
}