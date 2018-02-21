#pragma once
#include "CombustionEngine.h"
#include <string.h>
#include "Component.h"

class TransformComponent : Component
{

public:
	sf::Transform transform;
	sf::Transform worldTransform;

	sf::Transform GetWorldTransform();
	void SetWorldTransform(sf::Transform transform);

private:

};

