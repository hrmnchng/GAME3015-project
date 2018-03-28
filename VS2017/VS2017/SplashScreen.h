#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H
#include "CombustionEngine.h"

class SplashScreen : public Scene {
public:
	float elapsed;

	SplashScreen();
	~SplashScreen();

	void Start();
	void Update(float) override;
	void Draw(float, sf::RenderWindow&);
	void HandleInput(sf::Event) override;
};

#endif