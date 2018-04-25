#ifndef COMPONENT_H
#define COMPONENT_H

#include "SFML\Graphics.hpp"

class Component
{
public:
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Draw(sf::RenderTarget&);
};

#endif

