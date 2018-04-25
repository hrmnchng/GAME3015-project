#ifndef PHYSICS_H
#define PHYSICS_H
#include "GameObject.h"
#include "Scene.h"
#include <map>

class Physics
{
public:
	static void CalculatePositions(std::vector<GameObject*>);
	static void CalculateCollisions(std::vector<GameObject*>, Scene* currentScene);
	static void ResolveCollisions();
};

#endif