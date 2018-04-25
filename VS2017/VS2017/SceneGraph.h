#ifndef SCENE_GRAPH_H
#define SCENE_GRAPH_H

#include "Scene.h"
#include <iostream>

class SceneGraph 
{

public:
	SceneGraph();
	~SceneGraph(void);

	void AddScene(const char*, Scene*);
	Scene* GetScene(const char*);
	void DeleteScene(const char*);
	void LoadScene(const char*);

	void Start();
	void CalculatePhysics(float deltaTime);
	void HandleInput(sf::Event);
	void ClearObsolete();
	void Update(float deltaTime);
	void Draw(float deltaTime, sf::RenderWindow&);

	std::map<std::string, Scene*> scenes;

	Scene* currentScene;
	std::string currentSceneKey;
};

#endif
