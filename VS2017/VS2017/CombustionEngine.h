#ifndef COMBUSTION_ENGINE_H
#define COMBUSTION_ENGINE_H

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "SceneGraph.h"
#include "SplashScreen.h"
#include "DemoScene.h"
#include "WindowManager.h"

#include <windows.h> 
#include <direct.h>
#include <tchar.h>
#include <iostream>
#include <memory>

class CombustionEngine
{
public:
	static void Start();	
	static void Initialize();

	static bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	static bool IsOnlyInstance(const char* gameTitle);
	static bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	static DWORD ReadCPUSpeed();

	static bool InitializeGraphics();
	static bool InitializeAudio();

//private:
	enum GameState {
		Uninitialized, Initialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};

	static GameState _gameState;
	static sf::Clock clock;
	static const char* engineName;
	static SceneGraph sceneGraph;

	static bool IsExiting();
	static void GameLoop();
	
};

#endif