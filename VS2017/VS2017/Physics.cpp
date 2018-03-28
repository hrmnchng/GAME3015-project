#include "Physics.h"

Physics::Physics()
{

}

Physics::~Physics()
{

}

void Physics::CalculatePositions(std::map<std::string, GameObject*> sceneObjects)
{
	for (const auto& mpair : sceneObjects)
	{
		if (mpair.second != nullptr)
		{
			Rigidbody* rb = mpair.second->GetRigidbody();
			if (rb != nullptr)
			{
				mpair.second->transform->Translate(
					rb->GetVelocity().x,
					rb->GetVelocity().y
				);
			}
		}
	}
}