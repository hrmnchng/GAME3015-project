#pragma once
#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include <windows.h> 
#include <direct.h>
#include <tchar.h>

class CombustionEngine
{
public:
	static void Start();
	static void Initialize();

	enum GameState {
		Uninitialized, Initialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};
	 static GameState _gameState;

	 bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	 bool IsOnlyInstance(LPCTSTR gameTitle);
	 bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	 DWORD ReadCPUSpeed();

	 bool InitializeGraphics();

	 bool initother();
private:
	static bool IsExiting();
	static void GameLoop();
	

	

	
};