#ifndef SCENE_H
#define SCENE_H

#include "GameObject.h"
#include "SFML/Graphics.hpp"

class Scene
{
public:
	Scene();
	~Scene(void);

	std::string getName();
	void setName(std::string);
	unsigned int getIndex();
	void setIndex(unsigned int index);

	void AddGameObject(const char * key, GameObject * g);
	void DeleteGameObject(const char*);
	GameObject* GetGameObject(const char*);

	void Start();
	void Update(float);
	void Draw(float, sf::RenderWindow&);

private:
	std::string name;
	unsigned int sceneIndex;
	std::map<std::string, GameObject*> gameObjects;
};

#endif