#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <map>
#include <vector>
#include "TransformComponent.h"

class GameObject {

public:
	GameObject* parent;
	std::vector<GameObject*> children;
	std::map<std::string, Component*> objectComponents;
	
	TransformComponent* transform;

	sf::Image image;
	sf::Sprite sprite;

	void SetParent(GameObject& p);
	void RemoveParent();

	void AddChild(GameObject* c);
	void RemoveChild(GameObject* c);

	void SetSprite(std::string filepath);

	void AddComponent(const char*, Component*);
	void RemoveComponent(const char*);

	virtual void Start();
	virtual void Update(float );
	virtual void Draw(float, sf::RenderWindow&);

	GameObject(bool);

private:

};
#endif