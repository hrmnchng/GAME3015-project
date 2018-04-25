#ifndef DEMO_SCENE_H
#define DEMO_SCENE_H
#include "CombustionEngine.h"
#include "Player.h"
#include "InfiniteBackground.h"
#include "UILabel.h"

class DemoScene : public Scene {
public:
	float elapsed;

	DemoScene();
	~DemoScene();

	void Start() override;
	void Update(float) override;
	void Draw(float, sf::RenderWindow&) override;
	void HandleInput(sf::Event) override;

private:
	Player* player;
};

#endif