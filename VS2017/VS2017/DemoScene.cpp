#include "DemoScene.h"
#include "SFML\Graphics\Image.hpp"
#include <math.h>
#include <string>
#include <random>
#include <time.h>

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
	// Random initialization
	srand(time(NULL));

	this->Scene::Start();
	score = 0;
	lives = 0;

	sf::RenderWindow& mainWindow = WindowManager::rm().getWindow();

	// Create background
	InfiniteBackground *spaceBackground = new InfiniteBackground();

	// Create player
	player = new Player("../../Assets/Spaceship.png");

	// Center player
	player->setPosition(mainWindow.getSize().x * 0.5f, mainWindow.getSize().y * 0.5f);

	// Create asteroid
	asteroidTexture.loadFromFile("../../Assets/Asteroid.png");
	asteroidTexture.setSmooth(true);

	for (int i = 0; i < 10; ++i)
	{
		Asteroid* asteroid = new Asteroid();
		asteroid->sprite.setTexture(asteroidTexture);
		asteroid->setOrigin(asteroid->sprite.getGlobalBounds().width / 2.0f, asteroid->sprite.getGlobalBounds().height / 2.0f);
		asteroid->setPosition(rand() % (WINDOW_WIDTH), -50.0f - rand()%(WINDOW_HEIGHT));
		asteroid->GetRigidbody()->SetVelocity(((rand() % 2) - 1) + 1, (rand() % 7) + 3);

		std::cout << "adding at: " << asteroid->getPosition().x << std::endl;

		std::string name = "zasteroid" + std::to_string(rand());
		std::cout << "adding " + name << std::endl;

		AddGameObject(name.c_str(), asteroid);
	}


	// Create BGM emitter
	GameObject* bgmEmitter = new GameObject();
	bgmEmitter->AddComponent("AudioEmitter", new AudioEmitterComponent("../../Assets/bgm-01.wav", true, false, true));

	// Create UI Label
	std::string scoreText = "Score: " + std::to_string(score);
	UILabel* scoreLabel = new UILabel(scoreText.c_str());
	std::string livesText = "Collisions: " + std::to_string(lives);
	UILabel* livesLabel = new UILabel(livesText.c_str());
	livesLabel->label.setPosition(45.0f, 45.0f);

	// Add objects to the scene
	AddGameObject("background", spaceBackground);
	AddGameObject("player", player);
	AddGameObject("bgmEmitter", bgmEmitter);
	AddGameObject("scoreLabel", scoreLabel);
	AddGameObject("livesLabel", livesLabel);

	SetScore(0);
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

	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			CombustionEngine::sceneGraph.LoadScene("gameOver");
			elapsed = 0.0f;
		}
	}
	}
}

void DemoScene::OnCollision(GameObject& first, GameObject& second)
{
}

int DemoScene::GetScore() { return score; }
void DemoScene::SetScore(int value) {
	score = value; 

	UILabel* scoreLabel = static_cast<UILabel*>(GetGameObject("scoreLabel"));
	std::string scoreText = "Score: " + std::to_string(score);
	scoreLabel->label.setPosition(45.0f, 15.0f);
	scoreLabel->label.setString(scoreText);
}

void DemoScene::RespawnPlayer()
{
	sf::RenderWindow& mainWindow = WindowManager::rm().getWindow();

	// Center player
	player->setPosition(mainWindow.getSize().x * 0.5f, mainWindow.getSize().y * 0.5f);
	AudioEmitterComponent* emitter = static_cast<AudioEmitterComponent*>(
		GetGameObject("bgmEmitter")->GetComponent("AudioEmitter"));
	emitter->music.stop();
	emitter->music.play();

	lives = lives + 1;

	UILabel* livesLabel = static_cast<UILabel*>(GetGameObject("livesLabel"));
	std::string livesText = "Collisions: " + std::to_string(lives);
	livesLabel->label.setPosition(45.0f, 45.0f);
	livesLabel->label.setString(livesText);
}
