#include "DemoScene.h"
#include "SFML\Graphics\Image.hpp"

DemoScene::DemoScene()
{
	elapsed = 0.0f;
}

DemoScene::~DemoScene()
{

}

void DemoScene::Start()
{
	this->Scene::Start();
	sf::RenderWindow& mainWindow = WindowManager::rm().getWindow();

	// Create background
	GameObject *spaceBackground = new GameObject();
	spaceBackground->SetSprite("../../Assets/SpaceBackground.png");
	spaceBackground->setPosition(0.0f, 0.0f);
	spaceBackground->sprite.setScale(2.0f, 2.0f);

	// Create player
	player = new Player();
	player->GetRigidbody()->useGravity = false;
	player->SetSprite("../../Assets/Spaceship.png");
	player->sprite.setScale(0.3f, 0.3f);

	// Center player
	float xpos = mainWindow.getSize().x * 0.5f - player->sprite.getGlobalBounds().width * player->sprite.getScale().x * 0.5f;
	float ypos = mainWindow.getSize().y * 0.5f - player->sprite.getGlobalBounds().height * player->sprite.getScale().y * 0.5f;
	
	player->setOrigin(
		player->sprite.getGlobalBounds().width * 0.5f,
		player->sprite.getGlobalBounds().height * 0.5f
	);
	
	player->setPosition(xpos, ypos);
	

	// Add objects to the scene
	AddGameObject("background", spaceBackground);
	AddGameObject("player", player);
}

void DemoScene::Update(float deltaTime)
{
	this->Scene::Update(deltaTime);
	elapsed += deltaTime * 1000;
}

void DemoScene::Draw(float deltaTime, sf::RenderWindow& mainWindow)
{
	this->Scene::Draw(deltaTime, mainWindow);
}

void DemoScene::HandleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::MouseMoved:
	{
		sf::Vector2f mousePosition(event.mouseMove.x, event.mouseMove.y);
		sf::Vector2f dir = mousePosition - player->getPosition();
		dir = dir / sqrtf(pow(dir.x, 2) + pow(dir.y, 2));
		player->GetRigidbody()->SetVelocity(dir.x, dir.y);
	}
	break;

	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::A)
		{
			player->rotate(-5.0f);
		}
		else if (event.key.code == sf::Keyboard::D)
		{
			player->rotate(5.0f);
		}
		else if (event.key.code == sf::Keyboard::Space)
		{
			player->rotate(5.0f);
		}

	}
	}
}