#include "CombustionEngine.h"
#include "SplashScreen.h"

#if defined(_DEBUG)
#define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


void CombustionEngine::Start(void)
{
	//if (_gameState != Uninitialized)
		//return;
		//_gameState = CombustionEngine::Playing;

	sf::RenderWindow mainWindow({ 1024, 769 }, "GAME NAME");
	mainWindow.setFramerateLimit(60);

	SplashScreen splashScreen;
	splashScreen.Show(mainWindow);
		while (mainWindow.isOpen())
		{
			sf::Event event;
			while (mainWindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					mainWindow.close();
			}
			mainWindow.clear();
			splashScreen.Show(mainWindow);
			mainWindow.display();
		}


	//while (!IsExiting())
	//{
	//	GameLoop();
	//}
	//_mainWindow.Close();
}


bool CombustionEngine::CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters =
		diskSpaceNeeded /
		(diskfree.sectors_per_cluster * diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters)
	{
		// if you get here you donft have enough disk space!
		printf("CheckStorage Failure : Not enough physical storage.");
		return false;
	}
	return true;
}

bool CombustionEngine::IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
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
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	for (std::size_t i = 0; i < modes.size(); ++i)
	{
		sf::VideoMode mode = modes[i];
	}
	// Create a window with the same pixel depth as the desktop
	//sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	//sf::RenderWindow window.create(sf::VideoMode(1024, 768, desktop.bitsPerPixel), "SFML window");
	return true;
}

bool CombustionEngine::InitializeAudio()
{
	return false;
}

void CombustionEngine::Initialize(void){

	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	ReadCPUSpeed();
	InitializeGraphics();
	InitializeAudio();
	//_gameState = CombustionEngine::Initialized;
}