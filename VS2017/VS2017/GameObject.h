#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <map>
#include <vector>
#include "RendererComponent.h"
#include "AudioEmitterComponent.h"
#include "Rigidbody.h"
#include "BoxCollider.h"

class GameObject: public sf::Transformable {

public:
	GameObject* parent;

	sf::Sprite sprite;

	std::vector<GameObject*> children;
	std::map<std::string, Component*> objectComponents;

	void SetParent(GameObject& p);
	void RemoveParent();

	void AddChild(GameObject* c);
	void RemoveChild(GameObject* c);

	void SetSprite(std::string filepath);

	void AddComponent(const char*, Component*);
	Component* GetComponent(const char*);
	void RemoveComponent(const char*);

	// Helpers
	Rigidbody* GetRigidbody();
	BoxCollider* GetCollider();

	virtual void Start();
	virtual void Update(float);
	virtual void Draw(sf::RenderTarget&) const;
	virtual void HandleInput(sf::Event event);
	virtual void OnCollision(GameObject& other);

	GameObject();
	~GameObject();

private:
	sf::Image image;
	sf::Texture texture;
};
#endif