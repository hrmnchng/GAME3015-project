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

void fetchAllObjects(std::vector<GameObject*> toAdd, std::vector<GameObject*>& container)
{
	for (std::size_t i = 0; i < toAdd.size(); ++i)
	{
		container.push_back(toAdd[i]);
		fetchAllObjects(toAdd[i]->children, container);
	}
}

void Physics::CalculateCollisions(std::vector<GameObject*> sceneObjects, Scene* currentScene)
{
	std::vector<GameObject*> allObjects;
	fetchAllObjects(sceneObjects, allObjects);

	for (std::size_t i = 0; i < allObjects.size(); ++i)
	{
		BoxCollider* collider = allObjects[i]->GetCollider();
		if (collider != nullptr)
		{
			for (std::size_t j = 0; j < allObjects.size(); ++j)
			{
				if (allObjects[i] == allObjects[j]) continue;
				BoxCollider* _collider = allObjects[j]->GetCollider();
				if (_collider != nullptr)
				{
					if (collider->boundingBox.getGlobalBounds().intersects(_collider->boundingBox.getGlobalBounds()))
					{
						allObjects[i]->OnCollision(*allObjects[j]);
						currentScene->OnCollision(*allObjects[i], *allObjects[j]);
					}
				}
			}
		}
	}
}

void Physics::ResolveCollisions()
{
}
