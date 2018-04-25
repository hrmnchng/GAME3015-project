#ifndef GAME_OVER_SCREEN_H
#define GAME_OVER_SCREEN_H
#include "CombustionEngine.h"

class GameOverScene : public Scene {
public:
	float elapsed;

	GameOverScene();
	~GameOverScene();

	void Start();
	void HandleInput(sf::Event) override;
};

#endif