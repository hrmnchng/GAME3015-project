#include "Physics.h"
#include <iostream>

void Physics::CalculatePositions(std::vector<GameObject*> sceneObjects)
{
	for (std::size_t i = 0; i < sceneObjects.size(); ++i)
	{
		Rigidbody* rb = sceneObjects[i]->GetRigidbody();
		if (rb != nullptr)
		{
			sceneObjects[i]->move(rb->GetVelocity());
		}

		BoxCollider* collider = sceneObjects[i]->GetCollider();
		if (collider != nullptr)
		{
			collider->UpdateBoundingBox(
				sceneObjects[i]->getPosition(),
				sceneObjects[i]->sprite.getGlobalBounds().width * sceneObjects[i]->getScale().x,
				sceneObjects[i]->sprite.getGlobalBounds().height * sceneObjects[i]->getScale().y,
				sceneObjects[i]->getRotation()
			);
		}

		CalculatePositions(sceneObjects[i]->children);
	}
}

void Physics::CalculateCollisions(std::map<std::string, GameObject*> sceneObjects)
{
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
	
				if (collider->boundingBox.getGlobalBounds().intersects(_collider->boundingBox.getGlobalBounds()))
				{
					mpair.second->OnCollision(*_mpair.second);
				}
			}
		}
	}
}