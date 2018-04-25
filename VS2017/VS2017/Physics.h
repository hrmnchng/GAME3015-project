#pragma once
#include "GameObject.h"
#include <map>

class Physics
{
public:
	static void CalculatePositions(std::vector<GameObject*>);
	static void CalculateCollisions(std::map<std::string, GameObject*> sceneObjects);
	static void ResolveCollisions();
};