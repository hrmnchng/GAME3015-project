#ifndef INFINITE_BACKGROUND_H
#define INFINITE_BACKGROUND_H

#include "GameObject.h"

class InfiniteBackground : public GameObject {

public:

	sf::Texture bgTexture;
	sf::Sprite bgSprite;
	sf::IntRect bgTextureRect;

	InfiniteBackground();
	~InfiniteBackground();

	void Draw(sf::RenderTarget& target) const;
	void Update(float deltaTime);
};
#endif