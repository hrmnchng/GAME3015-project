#pragma once
#include "SceneGraph.h"
#include "GameObject.h"

class Scene
{
public:
	std::vector<GameObject*> Gameobjects;

private:
	void AddGameObject();
	void RemoveGameObject();


};

