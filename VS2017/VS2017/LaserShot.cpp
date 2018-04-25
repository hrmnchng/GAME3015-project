#include "LaserShot.h"

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
		sprite.getGlobalBounds().top)
	);
}
