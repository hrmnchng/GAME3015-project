#include <SFML\Graphics.hpp>
#define WINDOW_WIDTH 1400
#define WINDOW_HEIGHT 1024

class WindowManager
{
public:
	WindowManager();
	static WindowManager & rm();
	sf::RenderWindow & getWindow();

private:
	sf::RenderWindow window;
};