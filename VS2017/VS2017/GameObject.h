#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <map>
#include <vector>
#include "TransformComponent.h"
#include "RendererComponent.h"
#include "Rigidbody.h"

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
	Component* GetComponent(const char*);
	void RemoveComponent(const char*);

	RendererComponent* GetRenderer();

	Rigidbody * GetRigidbody();

	virtual void Start();
	virtual void Update(float );
	virtual void Draw(float, sf::RenderWindow&);

	GameObject(bool);

private:

};
#endif