#include "Rigidbody.h"
#include <iostream>

#define GRAVITY_X 0.0
#define GRAVITY_Y 9.8

Rigidbody::Rigidbody()
{
	velocity.x = 0.0f;
	velocity.y = 0.0f;
	accel.x = 0.0f;
	accel.y = 0.0f;
	useGravity = true;
}

Rigidbody::~Rigidbody()
{

}

void Rigidbody::Update(float deltaTime)
{
	deltaTime *= 1000.0f;

	if (fabs(accel.x + accel.y) > 0.0f)
	{
		velocity += accel * deltaTime;
	}

	if (useGravity)
	{
		accel.x += GRAVITY_X * deltaTime;
		accel.y += GRAVITY_Y * deltaTime;
	}

	//std::cout << "deltaTime: " << deltaTime << std::endl;
}