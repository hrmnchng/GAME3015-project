#include "DemoScene.h"
#include "SFML\Graphics\Image.hpp"
#include <math.h>

DemoScene::DemoScene()
{
	elapsed = 0.0f;
}

DemoScene::~DemoScene()
{
	std::cout << "Destroying DemoScene" << std::endl;
}

void DemoScene::Start()
{
	this->Scene::Start();
	sf::RenderWindow& mainWindow = WindowManager::rm().getWindow();

	// Create background
	InfiniteBackground *spaceBackground = new InfiniteBackground();

	// Create player
	player = new Player("../../Assets/Spaceship.png");

	// Center player
	player->setPosition(mainWindow.getSize().x * 0.5f, mainWindow.getSize().y * 0.5f);

	// Create asteroid
	GameObject* asteroid = new GameObject();
	asteroid->SetSprite("../../Assets/Asteroid.png");
	asteroid->setPosition(100.0f, 100.0f);
	asteroid->setScale(1.4f, 1.4f);

	BoxCollider* asteroidCollider = new BoxCollider(asteroid->getPosition(), asteroid->getScale(), asteroid->sprite.getGlobalBounds());
	asteroid->AddComponent("Collider", asteroidCollider);

	// Create BGM emitter
	GameObject* bgmEmitter = new GameObject();
	bgmEmitter->AddComponent("AudioEmitter", new AudioEmitterComponent("../../Assets/bgm-01.wav", true, false, true));

	// Create UI Label
	UILabel* scoreLabel = new UILabel("Score: 123002G");

	// Add objects to the scene
	AddGameObject("background", spaceBackground);
	AddGameObject("player", player);
	AddGameObject("spaceball", asteroid);
	AddGameObject("bgmEmitter", bgmEmitter);
	AddGameObject("scoreLabel", scoreLabel);

	std::cout << CombustionEngine::CENGINE().m_engineFonts.size() << std::endl;
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
	this->Scene::HandleInput(event);
}