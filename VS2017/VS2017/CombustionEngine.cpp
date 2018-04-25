#include "CombustionEngine.h"
#include <iostream>

#if defined(_DEBUG)
	#define GCC_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

const char* CombustionEngine::engineName = "COMBUSTION";
CombustionEngine::GameState CombustionEngine::_gameState = CombustionEngine::Uninitialized;
SceneGraph CombustionEngine::sceneGraph;
sf::Clock CombustionEngine::clock;

void CombustionEngine::Start(void)
{
	_gameState = CombustionEngine::Playing;

	clock.restart();
	GameLoop();
}

void CombustionEngine::GameLoop()
{
	sceneGraph.LoadScene("splash");
	sceneGraph.Start();

	sf::RenderWindow& mainWindow = WindowManager::rm().getWindow();

	bool handleInput = true;

	while (mainWindow.isOpen())
	{
		sceneGraph.ClearObsolete();

		sf::Event event;
		float elapsed = clock.restart().asSeconds() / 1000.0f;
		while (mainWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::GainedFocus:
				handleInput = true;
				break;

			case sf::Event::LostFocus:
				handleInput = false;
				break;

			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
			case sf::Event::MouseMoved:
			{
				if (handleInput)
				{
					sceneGraph.HandleInput(event);
				}
			}
			break;

			case sf::Event::Closed:
				mainWindow.close();
				break;

			default:
				break;
			}
		}
		mainWindow.clear();
		sceneGraph.CalculatePhysics(elapsed);
		sceneGraph.Update(elapsed);
		sceneGraph.Draw(elapsed, mainWindow);
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
	// Initialize fonts
	sf::Font fontPricedown;
	if (fontPricedown.loadFromFile("../../Assets/pricedown.ttf"))
	{
		CombustionEngine::CENGINE().m_engineFonts.insert(std::pair<const char*, sf::Font>("pricedown", fontPricedown));
	}
	

	sceneGraph.AddScene("splash", new SplashScreen());
	sceneGraph.AddScene("demo", new DemoScene());
	return true;
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

CombustionEngine& CombustionEngine::CENGINE()
{
	static CombustionEngine CENGINE;
	return CENGINE;
}