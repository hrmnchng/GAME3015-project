#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "Component.h"
#include "SFML\Graphics.hpp"
#include <string.h>

class TransformComponent : public Component
{

public:
	sf::Transform GetWorldTransform();
	sf::Transform GetTransform();
	void SetTransform(sf::Transform);
	void SetWorldTransform(sf::Transform);

	TransformComponent(float, float);

	void Start() override;
	void Update(float deltaTime) override;

	void Translate(float x, float y);
	void Rotate(float angle);
	void Scale(float x, float y);

private:
	sf::Transform transform;
	sf::Transform worldTransform;

};

#endif
