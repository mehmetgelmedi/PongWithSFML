#include <SFML\Graphics.hpp>

const int WIDTH = 640, HEIGHT = 480;
const char* TITLE = "Pong";
int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), TITLE);

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

	return 0;
}