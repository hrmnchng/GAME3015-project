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
	void DeleteScene(const char*);
	void LoadScene(const char*);

	void Start();
	void HandleInput(sf::Event);
	void Update(float deltaTime);
	void Draw(float deltaTime, sf::RenderWindow&);

	std::map<std::string, Scene*> scenes;

	Scene* currentScene;
	std::string currentSceneKey;
};

#endif
