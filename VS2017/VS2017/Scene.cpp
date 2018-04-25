#include "Scene.h"
#include <iostream>
#include <vector>

Scene::Scene()
{

}

Scene::~Scene()
{

}

void Scene::AddGameObject(const char* key, GameObject* g)
{
	gameObjects.insert(std::pair<const char*, GameObject*>(key, g));
}

void Scene::DeleteGameObject(const char* key)
{
	gameObjects.erase(key);
}

GameObject* Scene::GetGameObject(const char* key)
{
	return gameObjects.at(key);
}

void Scene::Start()
{
	for (const auto& mpair : gameObjects)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Start();
		}
	}
}

void Scene::Update(float deltaTime)
{
	for (const auto& mpair : gameObjects)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Update(deltaTime);
		}
	}
}

void Scene::Draw(float deltaTime, sf::RenderWindow& window)
{
	for (const auto& mpair : gameObjects)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Draw(window);
		}
	}
}

void Scene::HandleInput(sf::Event event)
{
	for (const auto& mpair : gameObjects)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->HandleInput(event);
		}
	}

	switch (event.type)
	{
	case sf::Event::MouseMoved:
		break;

	case sf::Event::KeyPressed:
		break;

	case sf::Event::KeyReleased:
		break;

	default:
		break;
	}
}

void Scene::ApplyPhysics(float deltaTime)
{
	std::vector<GameObject*> sceneObjectsVector;
	for (const auto& mpair : gameObjects)
	{
		if (mpair.second != nullptr)
		{
			sceneObjectsVector.push_back(mpair.second);
		}
	}

	Physics::CalculatePositions(sceneObjectsVector);
	Physics::CalculateCollisions(gameObjects);
}
