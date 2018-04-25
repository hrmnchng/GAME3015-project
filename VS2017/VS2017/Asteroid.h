#pragma once
#include "GameObject.h"

class Asteroid : public GameObject
{
public:
	Asteroid();
	~Asteroid();

	void Update(float deltaTime);
	void OnCollision(GameObject& other);
};