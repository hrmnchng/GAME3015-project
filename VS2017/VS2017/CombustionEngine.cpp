#include "CombustionEngine.h"

#if defined(_DEBUG)
#define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif


void CombustionEngine::Start(void)
{
		sf::RenderWindow window({ 1024, 769 }, "GAME NAME");
		window.setFramerateLimit(30);
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			window.display();
		}

	//if (_gameState != Uninitialized)
	//	return;
	//_mainWindow.Create(sf::VideoMode(1024, 768, 32), "GameName");
	//_gameState = CombustionEngine::Playing;

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




void CombustionEngine::Initialize(void){

	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool IsOnlyInstance(LPCTSTR gameTitle);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	DWORD ReadCPUSpeed();

}