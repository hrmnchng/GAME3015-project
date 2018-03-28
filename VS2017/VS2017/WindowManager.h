#include <SFML\Graphics.hpp>

class WindowManager
{
public:
	WindowManager();
	static WindowManager & rm();
	sf::RenderWindow & getWindow();

private:
	sf::RenderWindow window;
};