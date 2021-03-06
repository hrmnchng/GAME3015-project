#include "SceneGraph.h"

SceneGraph::SceneGraph()
{

}

SceneGraph::~SceneGraph()
{

}

void SceneGraph::AddScene(const char* key, Scene* scene)
{
	scenes.insert(std::pair<const char*, Scene*>(key, scene));
}

Scene* SceneGraph::GetScene(const char * key)
{
	return scenes.at(key);
}

void SceneGraph::DeleteScene(const char* key)
{
	scenes.erase(key);
}

void SceneGraph::LoadScene(const char* key)
{
	// To do: unload current scene's object from memory
	//currentScene = scenes.at(key);
	currentSceneKey = key;
	scenes[currentSceneKey]->Start();
}

void SceneGraph::Draw(float deltaTime, sf::RenderWindow& mainWindow)
{
	scenes[currentSceneKey]->Draw(deltaTime, mainWindow);
}

void SceneGraph::Start()
{
	scenes[currentSceneKey]->Start();
}

void SceneGraph::CalculatePhysics(float deltaTime)
{
	scenes[currentSceneKey]->ApplyPhysics(deltaTime);
}

void SceneGraph::Update(float deltaTime)
{
	scenes[currentSceneKey]->Update(deltaTime);
}

void SceneGraph::HandleInput(sf::Event event)
{
	scenes[currentSceneKey]->HandleInput(event);
}

void SceneGraph::ClearObsolete()
{
	scenes[currentSceneKey]->ClearObsolete();
}