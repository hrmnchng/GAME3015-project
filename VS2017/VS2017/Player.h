#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

class Player : public GameObject {

public:
	Player(bool);
	~Player();

	void Update(float);

	float getHealth() { return this->health; }
	void setHealth(float value) { this->health = value; }

private:
	float health;

};
#endif