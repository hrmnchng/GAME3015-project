#include "Scene.h"
#include <iostream>

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
			mpair.second->Draw(deltaTime, window);
		}
	}
}

void Scene::ApplyPhysics(float deltaTime)
{
	Physics::CalculatePositions(gameObjects);
}
