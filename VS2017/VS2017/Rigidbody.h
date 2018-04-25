#pragma once
#include "Component.h"
#include "SFML\Graphics.hpp"
#include <string>
#include <math.h>

class Rigidbody : public Component
{
public:
	
	Rigidbody();
	~Rigidbody();

	void Update(float);
	
	float GetMass() { return this->mass; }
	void SetMass(float value) { this->mass = value; }
	sf::Vector2f GetVelocity() { return this->velocity; }
	void SetVelocity(float x, float y) { this->velocity.x = x; this->velocity.y = y; }
	void SetVelocity(sf::Vector2f velocity) { this->velocity = velocity; }
	void NormalizeVelocity() { this->velocity = velocity / sqrtf(pow(velocity.x, 2) + pow(velocity.y, 2)); }
	sf::Vector2f GetAccel() { return this->accel; }
	void SetAccel(float x, float y) { this->accel.x = x; this->accel.y = y; }

	bool useGravity;

private:
	float mass;
	sf::Vector2f velocity;
	sf::Vector2f accel;
};