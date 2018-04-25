#include "Player.h"
#include "Rigidbody.h"
#include "LaserShot.h"
#include "Asteroid.h"
#include "CombustionEngine.h"
#include <iostream>
using namespace::std;

Player::Player(const char* spriteName)
{
	this->AddComponent("Rigidbody", new Rigidbody());
	this->AddComponent("AudioEmitter", new AudioEmitterComponent("../../Assets/lasershot.ogg", false, true, false));

	this->health = 100.0f;
	this->speedMult = 5.0f;

	this->GetRigidbody()->useGravity = false;
	this->GetRigidbody()->SetVelocity(0.0f, 0.0f);
	this->SetSprite(spriteName);
	
	this->setScale(0.3f, 0.3f);

	sf::FloatRect colliderDimensions;
	colliderDimensions.left = getPosition().x;
	colliderDimensions.top = getPosition().y;
	colliderDimensions.width = sprite.getGlobalBounds().width * getScale().x;
	colliderDimensions.height = sprite.getGlobalBounds().height * getScale().y;

	float width = sprite.getGlobalBounds().width * getScale().x;
	float height = sprite.getGlobalBounds().height * getScale().y;

	this->AddComponent("Collider", new BoxCollider(getPosition(), getRotation(), width, height));
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	float windowWidth = WINDOW_WIDTH;
	float windowHeight = WINDOW_HEIGHT;

	float playerWidth = this->sprite.getLocalBounds().width * getScale().x;
	float playerHeight = this->sprite.getLocalBounds().height * getScale().y;

	float right = windowWidth - playerWidth / 2.0f;
	float left = playerWidth / 2.0f;
	float top = playerHeight / 2.0f;
	float bottom = windowHeight - playerHeight / 2.0f;

	if (getPosition().x > right)
		setPosition(right, getPosition().y);

	if (getPosition().x < left)
		setPosition(left, getPosition().y);

	if (getPosition().y > bottom)
		setPosition(getPosition().x, bottom);

	if (getPosition().y < top)
		setPosition(getPosition().x, top);

	//std::cout << "Player x: " << getPosition().x << " , y: " << getPosition().y << " ,vel:" << getRotation() << std::endl;
	this->GameObject::Update(deltaTime);
	
}

void Player::OnCollision(GameObject& other)
{
	GameObject::OnCollision(other);
	if (typeid(other) == typeid(Asteroid))
	{
		DemoScene* parentScene = static_cast<DemoScene*>(CombustionEngine::sceneGraph.GetScene("demo"));
		parentScene->RespawnPlayer();
		//other.SetObsolete();
	}
}

void Player::HandleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
	{
		sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
		sf::Vector2f dir = mousePosition - getPosition();
		dir = dir / sqrtf(pow(dir.x, 2) + pow(dir.y, 2));
		dir *= speedMult;

		setRotation(((atan2(dir.y, dir.x)) * 180 / 3.1415f) + 90.0f);
		GetRigidbody()->SetVelocity(dir);
	}
	break;

	case sf::Event::MouseButtonPressed:
	{
		if (event.mouseButton.button == sf::Mouse::Left)
		{
			Fire(event.mouseButton.x, event.mouseButton.y);
		}
	}
		break;


	case sf::Event::KeyPressed:
	{
	}
	break;

	case sf::Event::KeyReleased:
	{
	}
	break;

	default:
		break;
	}
}

void Player::Fire(float mouseX, float mouseY)
{
	std::cout << "Pew pew\n";
	AudioEmitterComponent* audioEmitter = static_cast<AudioEmitterComponent*>(GetComponent("AudioEmitter"));
	audioEmitter->sound.play();

	sf::Vector2f mousePosition(mouseX, mouseY);
	sf::Vector2f dir = mousePosition - getPosition();
	dir = dir / sqrtf(pow(dir.x, 2) + pow(dir.y, 2));
	dir *= 10.0f;

	LaserShot* laserShot = new LaserShot(getPosition(), dir, getRotation());

	AddChild(laserShot);
}