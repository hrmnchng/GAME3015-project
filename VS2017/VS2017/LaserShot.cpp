#include "LaserShot.h"
#include "Asteroid.h"
#include "CombustionEngine.h"
#include <iostream>

LaserShot::LaserShot(sf::Vector2f initialPosition, sf::Vector2f initialVelocity, float angle)
{
	SetSprite("../../Assets/lasershot.png");
	setPosition(initialPosition);

	AddComponent("Rigidbody", new Rigidbody());
	GetRigidbody()->useGravity = false;
	setRotation(angle);

	GetRigidbody()->SetVelocity(initialVelocity.x, initialVelocity.y);

	AddComponent("Collider", new BoxCollider(
		getPosition(),
		getRotation(),
		sprite.getGlobalBounds().left,
		sprite.getGlobalBounds().top));
}

LaserShot::~LaserShot()
{
}

void LaserShot::Update(float deltaTime)
{
	if (getPosition().y < 0 || getPosition().y > WINDOW_HEIGHT || getPosition().x < 0 || getPosition().x > WINDOW_WIDTH || IsObsolete())
	{
		parent->RemoveChild(this);
		delete this;
	}
}

void LaserShot::OnCollision(GameObject& other)
{
	if (typeid(other) == typeid(Asteroid))
	{
		DemoScene* parentScene = static_cast<DemoScene*>(CombustionEngine::sceneGraph.GetScene("demo"));
		parentScene->SetScore(parentScene->GetScore() + 1);

		std::cout << "Collided with " << typeid(other).name() << std::endl;
		SetObsolete();
		//other.SetObsolete();
	}
}
