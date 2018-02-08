#include "GameObject.h"

sf::Transform GameObject::GetWorldTransform()
{
	return sf::Transform();
}

void GameObject::SetWorldTransform(sf::Transform transform)
{
	this->worldTransform = transform;
}


void GameObject::SetParent(GameObject & p)
{
	this->parent = &p;
}

void GameObject::RemoveParent()
{
	this->parent = NULL;
}

void GameObject::AddChild(GameObject * c)
{
	children.push_back(c);
	c->parent = this;
}

void GameObject::RemoveChild(GameObject * c)
{
	//Check the entire array of chilren for the child you want to remove
	/*for (int i = 0; i < children.max_size; i++) {
		if (c == children[i]) {
			delete children[i];
		}
	}*/
}

void GameObject::SetSprite(std::string filepath)
{
	this->image.loadFromFile(filepath);
	sf::Texture texture;
	texture.loadFromImage(image);
	this->sprite.setTexture(texture);
}

void GameObject::Update(float ms)
{
	if (parent) {
		worldTransform = parent->worldTransform * transform;
	}
	else {
		worldTransform = transform;
	}

}
