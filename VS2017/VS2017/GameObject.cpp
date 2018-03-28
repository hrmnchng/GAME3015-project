#include "GameObject.h"
#include "RendererComponent.h"
#include <iostream>


GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}
void GameObject::SetParent(GameObject& p)
{
	this->parent = &p;
}

void GameObject::RemoveParent()
{
	this->parent = NULL;
}

void GameObject::AddChild(GameObject* c)
{
	children.push_back(c);
	c->SetParent(*this);
}

void GameObject::RemoveChild(GameObject* c)
{
	for (std::vector<GameObject*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (*it == c)
		{
			c->RemoveParent();
			children.erase(it);
			break;
		}
	}
}

void GameObject::AddComponent(const char* key, Component* c) {
	objectComponents.insert(std::pair <const char*, Component*>(key, c));
}

Component* GameObject::GetComponent(const char* key)
{
	return objectComponents.at(key);
}

void GameObject::RemoveComponent(const char* key) {
	objectComponents.erase(key);
}

void GameObject::SetSprite(std::string filepath)
{
	image.loadFromFile(filepath);
	texture.loadFromImage(image);
	texture.setSmooth(true);
	sprite.setTexture(texture, true);

	std::cout << "Loaded sprite from file " << filepath << std::endl;
}

Rigidbody* GameObject::GetRigidbody()
{
	if (objectComponents.find("Rigidbody") == objectComponents.end()) {
		return nullptr;
	}
	else {
		Rigidbody* rb = static_cast<Rigidbody*>(objectComponents.at("Rigidbody"));
		return rb;
	}
}

BoxCollider* GameObject::GetCollider()
{
	if (objectComponents.find("Collider") == objectComponents.end()) {
		return nullptr;
	}
	else {
		BoxCollider* collider = static_cast<BoxCollider*>(objectComponents.at("Collider"));
		return collider;
	}
}

void GameObject::Start()
{
	for (const auto& mpair : objectComponents)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Start();
		}
	}
}

void GameObject::Update(float deltaTime)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (i == children.size()) break;
		children[i]->Update(deltaTime);
	}

	for (const auto& mpair : objectComponents)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Update(deltaTime);
		}
	}
}

void GameObject::Draw(sf::RenderTarget& target, const sf::Transform& parentTransform) const {

	sf::Transform combinedTransform = parentTransform * transform;
	target.draw(sprite, combinedTransform);

	for (std::size_t i = 0; i < children.size(); ++i)
	{
		children[i]->Draw(target, transform);
		//children[i]->Draw(target, combinedTransform);
		//std::cout << "Drawing children " << children[i]->getPosition().x
		//	<< " " << children[i]->getPosition().y << std::endl;
	}
}
