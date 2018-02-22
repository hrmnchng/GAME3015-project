#pragma once
#include "SceneGraph.h"
#include "GameObject.h"

class Scene
{
public:
	GameObject GameObjects [] ;
	//std::vector<GameObject*> GameOList;

private:
	void AddGameObject();
	void RemoveGameObject();


};

