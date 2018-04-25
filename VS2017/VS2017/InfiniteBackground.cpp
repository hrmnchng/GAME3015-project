#include "InfiniteBackground.h"
#include <iostream>

InfiniteBackground::InfiniteBackground()
{
	if (bgTexture.loadFromFile("../../Assets/SpaceBackground.png"))
	{
		bgTexture.setRepeated(true);
		bgSprite.setTexture(bgTexture);

		bgTextureRect = bgSprite.getTextureRect();
		bgTextureRect.width *= 2.0f;
		bgSprite.setTextureRect(bgTextureRect);

	}
}

InfiniteBackground::~InfiniteBackground()
{
}

void InfiniteBackground::Update(float deltaTime)
{
	bgTextureRect.top -= 5.75f;
	bgSprite.setTextureRect(bgTextureRect);
}

void InfiniteBackground::Draw(sf::RenderTarget & target) const
{
	target.draw(bgSprite);
}


