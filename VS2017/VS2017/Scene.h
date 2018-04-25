#ifndef SCENE_H
#define SCENE_H

#include "GameObject.h"
#include "Physics.h"
#include "SFML/Graphics.hpp"
#include <memory>

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

	virtual void Start();
	virtual void Update(float);
	virtual void Draw(float, sf::RenderWindow&);
	virtual void HandleInput(sf::Event);
	virtual void ApplyPhysics(float);

protected:
	std::string name;
	unsigned int sceneIndex;
	std::map<std::string, GameObject*> gameObjects;
};

#endif