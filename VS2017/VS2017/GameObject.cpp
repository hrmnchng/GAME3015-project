#include "GameObject.h"
#include "RendererComponent.h"
#include <iostream>

void GameObject::SetParent(GameObject & p)
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
	c->parent = this;
}

void GameObject::RemoveChild(GameObject* c)
{
	for (std::vector<GameObject*>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (*it == c)
		{
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
	// Only renderable components are drawn
	RendererComponent* r = static_cast<RendererComponent*>(objectComponents.at("Renderer"));
	if (r != nullptr)
	{
		r->LoadFromFile(filepath);
	}
}

RendererComponent* GameObject::GetRenderer()
{
	RendererComponent* renderer = static_cast<RendererComponent*>(objectComponents.at("Renderer"));
	return renderer;
}

Rigidbody* GameObject::GetRigidbody()
{
	Rigidbody* rb = static_cast<Rigidbody*>(objectComponents.at("Rigidbody"));
	return rb;
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
	if (parent != nullptr) 
	{
		transform->SetWorldTransform(parent->transform->GetWorldTransform() * transform->GetTransform());
	}
	else 
	{
		transform->SetWorldTransform(transform->GetTransform());
	}

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

void GameObject::Draw(float deltaTime, sf::RenderWindow& window) {

	for (int i = 0; i < children.size(); i++)
	{
		if (i == children.size()) break;
		children[i]->Draw(deltaTime, window);
	}

	// Only renderable components are drawn
	RendererComponent* r = static_cast<RendererComponent*>(objectComponents.at("Renderer"));
	if (r != nullptr)
	{
		r->Draw(window, transform->GetTransform());
	}
}


GameObject::GameObject(bool bShouldRender) {
	parent = nullptr;
	transform = new TransformComponent(0.0f, 0.0f);
	if (bShouldRender)
	{
		RendererComponent* renderer = new RendererComponent();
		AddComponent("Renderer", renderer);
	}
}
