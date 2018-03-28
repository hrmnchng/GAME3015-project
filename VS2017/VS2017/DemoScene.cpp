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
	GameObject *spaceBackground = new GameObject(true);
	spaceBackground->SetSprite("../../Assets/SpaceBackground.png");
	spaceBackground->transform->Scale(2.5f, 2.5f);

	// Create player
	Player *player = new Player(true);
	player->SetSprite("../../Assets/Spaceship.png");
	sf::FloatRect playerBounds = player->GetRenderer()->GetSprite().getGlobalBounds();
	
	// Scale and translate the player to the center of the screen
	player->transform->Translate(mainWindow.getSize().x / 2.0f, mainWindow.getSize().y / 2.0f);
	player->transform->Scale(0.35f, 0.35f);
	player->transform->Translate(-playerBounds.width / 2.0f, -playerBounds.height / 2.0f);

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

}