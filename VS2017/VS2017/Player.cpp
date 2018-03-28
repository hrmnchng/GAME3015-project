#include "Player.h"
#include "Rigidbody.h"
#include <iostream>
using namespace::std;

Player::Player()
{
	this->health = 100.0f;
	AddComponent("Rigidbody", new Rigidbody());
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	this->GameObject::Update(deltaTime);
}