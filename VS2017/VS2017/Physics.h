#pragma once
#include "GameObject.h"
#include <map>

class Physics
{
public:
	static void CalculatePositions(std::map<std::string, GameObject*>);
	static void CalculateCollisions();
	static void ResolveCollisions();
};