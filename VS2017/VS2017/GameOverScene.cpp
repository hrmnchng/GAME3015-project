#include "GameOverScene.h"

GameOverScene::GameOverScene()
{
	UILabel *engineName = new UILabel("Game Over");
	engineName->label.setCharacterSize(72);
	engineName->label.setOutlineColor(sf::Color::Yellow);
	engineName->label.setOutlineThickness(3.0f);
	engineName->label.setFillColor(sf::Color::Red);
	engineName->label.setPosition(WINDOW_WIDTH / 2.0f - (17.5f * engineName->label.getString().getSize()), WINDOW_HEIGHT / 2.0f);

	AddGameObject("zLabel", engineName);
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Start()
{
	Scene::Start();
}

void GameOverScene::HandleInput(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
	{
		if (event.key.code == sf::Keyboard::E)
		{
			CombustionEngine::sceneGraph.LoadScene("splash");
		}
	}
	}
}