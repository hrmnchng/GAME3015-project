#pragma once
#include "Scene.h"
#include <string.h>
#include "TransformComponent.h"
#include "RigidBody.h"

class GameObject {

public:
	GameObject* parent;
	std::vector<GameObject*> children;

	
	sf::Image image;
	sf::Sprite sprite;

	

	void SetParent(GameObject& p);
	void RemoveParent();

	void AddChild(GameObject* c);
	void RemoveChild(GameObject* c);

	void SetSprite(std::string filepath);

	virtual void Update(float ms);

	TransformComponent m_transform;

private:


};
