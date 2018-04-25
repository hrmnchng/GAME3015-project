#include "Asteroid.h"
#include "WindowManager.h"
#include <iostream>

Asteroid::Asteroid()
{
	GameObject::GameObject();
	AddComponent("Rigidbody", new Rigidbody());
	GetRigidbody()->useGravity = false;
	BoxCollider* asteroidCollider = new BoxCollider(getPosition(), getScale(), sprite.getGlobalBounds());
	AddComponent("Collider", asteroidCollider);

	this->AddComponent("AudioEmitter", new AudioEmitterComponent("../../Assets/explosion.wav", false, true, false));
}

Asteroid::~Asteroid()
{
}

void Asteroid::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	if (getPosition().y > WINDOW_HEIGHT + 100) setPosition(getPosition().x, -100.0f - rand() % WINDOW_HEIGHT);
	if (getPosition().x > WINDOW_WIDTH + 100) setPosition(rand() % WINDOW_WIDTH, getPosition().y);
}

void Asteroid::OnCollision(GameObject & other)
{
	if (typeid(other) == typeid(Asteroid)) return;

	AudioEmitterComponent* audioEmitter = static_cast<AudioEmitterComponent*>(GetComponent("AudioEmitter"));
	audioEmitter->sound.play();

	setPosition(getPosition().x, -100.0f - rand() % WINDOW_HEIGHT);
	GetRigidbody()->SetVelocity(((rand() % 2) - 1) + 1, (rand() % 7) + 3);

	if (GetRigidbody()->GetVelocity().y == 0.0f)
		GetRigidbody()->SetVelocity(GetRigidbody()->GetVelocity().x, 4.5f);

	if (GetRigidbody()->GetVelocity().x == 0)
		GetRigidbody()->SetVelocity(1.0f, GetRigidbody()->GetVelocity().y);
}
