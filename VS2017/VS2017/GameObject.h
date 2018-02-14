#pragma once
#include "GameObject.h"
#include <string.h>

class GameObject {

public:
	GameObject* parent;
	std::vector<GameObject*> children;

	sf::Transform transform;
	sf::Transform worldTransform;

	sf::Image image;
	sf::Sprite sprite;

	sf::Transform GetWorldTransform();
	void SetWorldTransform(sf::Transform transform);

	void SetParent(GameObject& p);
	void RemoveParent();

	void AddChild(GameObject* c);
	void RemoveChild(GameObject* c);

	void SetSprite(std::string filepath);

	virtual void Update(float ms);

private:


};