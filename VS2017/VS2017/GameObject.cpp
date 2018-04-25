#include "GameObject.h"
#include "RendererComponent.h"
#include <iostream>


GameObject::GameObject()
{
	_m_should_delete = false;
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

void GameObject::RemoveChild(GameObject *c)
{
	children.erase(std::remove(children.begin(), children.end(), c), children.end());
	c->RemoveParent();
}

bool GameObject::IsObsolete()
{
	return _m_should_delete;
}

/*void GameObject::RemoveChild(GameObject* c)
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
}*/

void GameObject::AddComponent(const char* key, Component* c) {
	objectComponents.insert(std::pair <const char*, Component*>(key, c));
}

Component* GameObject::GetComponent(const char* key)
{
	if (objectComponents.find(key) == objectComponents.end())
	{
		return nullptr;
	}
	else
	{
		return objectComponents.at(key);
	}
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

	// Move origin point
	this->setOrigin(sprite.getGlobalBounds().width / 2.0f, sprite.getGlobalBounds().height / 2.0f);

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
	for (const auto& mpair : objectComponents)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Update(deltaTime);
		}
	}

	for (int i = 0; i < children.size(); i++)
	{
		if (i == children.size()) break;
		children[i]->Update(deltaTime);
	}

}

void GameObject::Draw(sf::RenderTarget& target) const {

	//sf::Transform combinedTransform = parentTransform * transform;
	target.draw(sprite, this->getTransform());

	for (const auto& mpair : objectComponents)
	{
		if (mpair.second != nullptr)
		{
			mpair.second->Draw(target);
		}
	}

	for (std::size_t i = 0; i < children.size(); ++i)
	{
		children[i]->Draw(target);
	}
}

void GameObject::HandleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
		break;

	case sf::Event::KeyPressed:
		break;

	case sf::Event::KeyReleased:
		break;

	default:
		break;
	}
}

void GameObject::OnCollision(GameObject& other)
{

}