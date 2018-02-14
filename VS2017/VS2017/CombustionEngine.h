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

	static bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	static bool IsOnlyInstance(LPCTSTR gameTitle);
	static bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	static DWORD ReadCPUSpeed();

	static bool InitializeGraphics();
	static bool InitializeAudio();

private:
	enum GameState {
		Uninitialized, Initialized, ShowingSplash, Paused,
		ShowingMenu, Playing, Exiting
	};
	static GameState _gameState;
	static bool IsExiting();
	static void GameLoop();
	
};