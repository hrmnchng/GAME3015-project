#include "Physics.h"
#include <iostream>

void Physics::CalculatePositions(std::map<std::string, GameObject*> sceneObjects)
{
	for (const auto& mpair : sceneObjects)
	{
		if (mpair.second != nullptr)
		{
			Rigidbody* rb = mpair.second->GetRigidbody();
			if (rb != nullptr)
			{
				mpair.second->move(rb->GetVelocity());
			}
		}
	}
}