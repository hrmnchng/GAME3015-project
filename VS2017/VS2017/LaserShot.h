#ifndef LASER_SHOT_H
#define LASER_SHOT_H

#include "CombustionEngine.h"
#include "GameObject.h"

class LaserShot : public GameObject {

public:

	LaserShot(sf::Vector2f, sf::Vector2f, float);
	~LaserShot();
};
#endif