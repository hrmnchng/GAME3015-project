#include "CombustionEngine.h"
#include "SplashScreen.h"
#include <iostream>

#if defined(_DEBUG)
	#define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

const char* CombustionEngine::engineName = "COMBUSTION";
CombustionEngine::GameState CombustionEngine::_gameState = CombustionEngine::Uninitialized;
SceneGraph CombustionEngine::sceneGraph;

void CombustionEngine::Start(void)
{
	_gameState = CombustionEngine::Playing;

	sf::RenderWindow mainWindow({ 1024, 769 }, "JAILBREAK BOB GOES TO SPACE");
	mainWindow.setFramerateLimit(60);

	GameLoop(mainWindow);
}

void CombustionEngine::GameLoop(sf::RenderWindow& mainWindow)
{
	sceneGraph.LoadScene("splash");
	sceneGraph.Start();

	float deltaTime = 0.0f; // Calculate time between frames

	while (mainWindow.isOpen())
	{
		sf::Event event;
		while (mainWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mainWindow.close();
		}
		mainWindow.clear();
		sceneGraph.Update(deltaTime);
		sceneGraph.Draw(deltaTime, mainWindow);
		mainWindow.display();
	}
}

bool CombustionEngine::CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters =
		diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	std::cout << "Clusters needed:"  << neededClusters;
	if (diskfree.avail_clusters < neededClusters)
	{
		// if you get here you donft have enough disk space!
		printf("CheckStorage Failure : Not enough physical storage.");
		return false;
	}
	return true;
}

bool CombustionEngine::IsOnlyInstance(const char* gameTitle)
{
	LPCSTR _gameTitle = const_cast<LPSTR>(gameTitle);
	HANDLE handle = CreateMutex(NULL, TRUE, _gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(_gameTitle, NULL);
		if (hWnd) {
			// An instance of your game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}

bool CombustionEngine::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded)
{
	MEMORYSTATUSEX status;
	GlobalMemoryStatusEx(&status);
	if (status.ullTotalPhys < physicalRAMNeeded) {
		printf("CheckMemory Failure : Not enough physical memory."); return false;
	}
	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		printf("CheckMemory Failure : Not enough virtual	memory.");
		return false;
	}
	char *buff = GCC_NEW char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else {
		// even though there is enough memory, it isnft
		printf("CheckMemory Failure : Not enough contiguous memory.");
		return false;
	}
	return true;
}

DWORD CombustionEngine::ReadCPUSpeed()
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}
	
	return dwMHz;
}

bool CombustionEngine::InitializeGraphics()
{
	Scene *splashScreenScene = new Scene();
	GameObject *splashScreenObj = new GameObject(true);

	splashScreenObj->SetSprite("../../Assets/SplashScreen.png");
	splashScreenScene->AddGameObject("splash", splashScreenObj);
	
	sceneGraph.AddScene("splash", splashScreenScene);
	return false;
}

bool CombustionEngine::InitializeAudio()
{
	return false;
}

void CombustionEngine::Initialize(void){

	try
	{
		const DWORDLONG diskSpaceNeeded = 0x5F5E100;
		if (!CheckStorage(diskSpaceNeeded)) {
			throw std::runtime_error("Not enough disk space available");
		};

		if (!IsOnlyInstance(engineName)) {
			throw std::runtime_error("Another instance of the engine is already running");
		}

		const DWORDLONG physicalRAM = 0x5F5E100;
		const DWORDLONG virtualRAM = 0x5F5E100;
		if (!CheckMemory(physicalRAM, virtualRAM)) {
			throw std::runtime_error("Not enough memory");
		}
	}
	catch (std::runtime_error err) {
		const char* exception = err.what();
		std::cout << "Exception thrown:" << exception;
		exit(1);
	}

	ReadCPUSpeed();
	InitializeGraphics();
	InitializeAudio();
	
	_gameState = CombustionEngine::Initialized;
}