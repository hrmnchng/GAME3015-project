#ifndef DEMO_SCENE_H
#define DEMO_SCENE_H
#include "CombustionEngine.h"
#include "Player.h"
#include "InfiniteBackground.h"
#include "UILabel.h"
#include "Asteroid.h"

class DemoScene : public Scene {
public:
	float elapsed;

	DemoScene();
	~DemoScene();

	void Start() override;
	void Update(float) override;
	void Draw(float, sf::RenderWindow&) override;
	void HandleInput(sf::Event) override;
	void OnCollision(GameObject & first, GameObject & second);

	int GetScore();
	void SetScore(int value);
	void RespawnPlayer();

	sf::Texture asteroidTexture;

private:
	Player* player;
	int score;
	int collisions;
	int maxCollisions;
	float spawnInterval;
	int spawnQuantity;
};

#endif