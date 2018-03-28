#include "Player.h"
#include "Rigidbody.h"
#include <iostream>
using namespace::std;

Player::Player()
{
	this->health = 100.0f;
	this->speedMult = 1.0f;
	AddComponent("Rigidbody", new Rigidbody());
	AddComponent("Collider", new BoxCollider(this->sprite.getGlobalBounds()));
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	this->GameObject::Update(deltaTime);
	
}