#include "SplashScreen.h"
#include "SFML\Graphics\Image.hpp"

SplashScreen::SplashScreen()
{
	elapsed = 0.0f;

	// Add splash screen object
	GameObject *splashScreenObj = new GameObject();
	splashScreenObj->SetSprite("../../Assets/SplashScreen.png");
	splashScreenObj->setPosition(0.0f, 0.0f);
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