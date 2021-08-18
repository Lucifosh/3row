#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow w(sf::VideoMode(500, 500), "t");
	while (w.isOpen())
	{
		w.clear(sf::Color::White);

		sf::Event e;
		while (w.pollEvent(e))
		{

		}

		w.display();
	}
}