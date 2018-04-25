#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "LaserShot.h"

class Player : public GameObject {

public:
	Player(const char * spriteName);
	~Player();

	void Update(float);
	void HandleInput(sf::Event event);
	void OnCollision(GameObject & other);

	float getHealth() { return this->health; }
	void setHealth(float value) { this->health = value; }

	void Fire(float, float);

	float speedMult;
private:
	float health;
	

};
#endif