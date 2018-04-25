#include "SplashScreen.h"
#include "SFML\Graphics\Image.hpp"

SplashScreen::SplashScreen()
{
	elapsed = 0.0f;

	// Add splash screen object
	GameObject *splashScreenObj = new GameObject();
	splashScreenObj->SetSprite("../../Assets/SplashScreen.png");
	splashScreenObj->setOrigin(0.0f, 0.0f);
	splashScreenObj->setPosition(0.0f, 0.0f);
	splashScreenObj->setScale(1.45f, 1.45f);

	UILabel *engineName = new UILabel("Combustion Engine");
	engineName->label.setCharacterSize(72);
	engineName->label.setOutlineColor(sf::Color::Yellow);
	engineName->label.setOutlineThickness(3.0f);
	engineName->label.setFillColor(sf::Color::Red);
	engineName->label.setPosition(WINDOW_WIDTH / 2.0f - (17.5f * engineName->label.getString().getSize()), WINDOW_HEIGHT / 2.0f);

	AddGameObject("zLabel", engineName);
	AddGameObject("splash", splashScreenObj);
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Start()
{
	this->Scene::Start();
}

void SplashScreen::Update (float deltaTime)
{
	// Call super
	this->Scene::Update(deltaTime);
	elapsed += deltaTime * 1000;

	if (elapsed >= 2.0f)
	{
		CombustionEngine::sceneGraph.LoadScene("demo");
		elapsed = 0.0f;
	}
}

void SplashScreen::Draw(float deltaTime, sf::RenderWindow& mainWindow)
{
	this->Scene::Draw(deltaTime, mainWindow);
}

void SplashScreen::HandleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::E)
		{
			CombustionEngine::sceneGraph.LoadScene("demo");
			elapsed = 0.0f;
		}
	}
	}
}