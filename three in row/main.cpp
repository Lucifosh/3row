#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Field.h"

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
	Field field(10);
	field.Draw(w, vm);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j % 2 == 0)
				field.setFigure(i, j, FigureType::square);
			else if (j == 3)
				field.setFigure(i, j, FigureType::triangle);
			else if(j == 5)
				field.setFigure(i, j, FigureType::rhombus);
			else
				field.setFigure(i, j, FigureType::circle);
		}
	}
	
	while (w.isOpen())
	{
		w.clear(sf::Color::Black);

		sf::Event e;
		while (w.pollEvent(e))
		{

		}

		field.Draw(w, vm);
		

		w.display();
	}
}