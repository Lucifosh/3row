#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

int main()
{
	sf::VideoMode vm = sf::VideoMode::getFullscreenModes()[0];
	/*if (vm.height > vm.height)
	{
		int temp = vm.height;
		vm.height = vm.width;
		vm.width = temp;
	}*/
	std::cout << vm.height << ' ' << vm.width;
	sf::RenderWindow w(vm, "t", sf::Style::Fullscreen);

	int objSize = vm.height / 12;
	Object o(FigureType::square, sf::Vector2f(vm.width/12, vm.height/12));

	while (w.isOpen())
	{
		w.clear(sf::Color::Black);

		sf::Event e;
		while (w.pollEvent(e))
		{

		}

		if (o.getType() == FigureType::square)
		{
			sf::RectangleShape r;
			r.setFillColor(sf::Color::Green);
			r.setPosition(o.getCoor());
			r.setSize(sf::Vector2f(objSize, objSize));
			w.draw(r);
		}
		else if (o.getType() == FigureType::circle)
		{
			sf::CircleShape r;
			//r.setFillColor()
		}

		w.display();
	}
}