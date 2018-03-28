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

void Physics::CalculateCollisions(std::map<std::string, GameObject*> sceneObjects)
{
	for (const auto& mpair : sceneObjects)
	{
		if (mpair.second != nullptr)
		{
			BoxCollider* collider = mpair.second->GetCollider();
			if (collider != nullptr)
			{
				collider->UpdateBoundingBox(
					mpair.second->getPosition(),
					mpair.second->sprite.getGlobalBounds().width,
					mpair.second->sprite.getGlobalBounds().height
				);
			}
		}
	}

	for (const auto& mpair : sceneObjects)
	{
		if (mpair.second != nullptr)
		{
			BoxCollider* collider = mpair.second->GetCollider();
			if (collider == nullptr) continue;

			for (const auto& _mpair : sceneObjects)
			{
				if (_mpair.first == mpair.first) continue;
				
				BoxCollider* _collider = _mpair.second->GetCollider();
				if (_collider == nullptr) continue;
	
				if (collider->boundingBox.intersects(_collider->boundingBox))
				{
					// Colliding!
					mpair.second->setScale(0.0f, 0.0f);
				}
			}
		}
	}
}