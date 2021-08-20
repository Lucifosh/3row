#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Field.h"
#include "Controller.h"
#include <cmath>
#include "Move.h"

enum class EControllerState
{
	pressed,
	none
};

int main()
{
	sf::VideoMode vm = sf::VideoMode::getFullscreenModes()[0];
	/*if (vm.height > vm.height)
	{
		int temp = vm.height;
		vm.height = vm.width;
		vm.width = temp;
	}*/

	sf::RenderWindow w(vm, "t", sf::Style::Fullscreen);

	Field field(10);
	field.Draw(w, vm);

	Controller controller(field);

	Move move(field);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j % 2 == 0)
				field.setFigure(FigureType::square, i, j);
			else if (j == 3)
				field.setFigure(FigureType::triangle, i, j);
			else if(j == 5)
				field.setFigure(FigureType::rhombus, i, j);
			else
				field.setFigure(FigureType::circle, i, j);
		}
	}

	sf::Vector2i posFigure;
	sf::Vector2i pos;
	EControllerState state = EControllerState::none;
	
	while (w.isOpen())
	{
		w.clear(sf::Color::Black);

		sf::Event e;
		while (w.pollEvent(e))
		{
			if (e.type == sf::Event::EventType::MouseButtonPressed)
			{
				posFigure = controller.transtlate(sf::Mouse::getPosition());
				pos = sf::Mouse::getPosition();
				state = EControllerState::pressed;
			}

			if (e.type == sf::Event::EventType::MouseButtonReleased)
				state = EControllerState::none;

			if (e.type == sf::Event::EventType::MouseMoved && state == EControllerState::pressed)
			{
				if (sf::Mouse::getPosition().x - pos.x >= field.objSize)
				{
					//move right
					move.move(posFigure.x, posFigure.y, posFigure.x + 1, posFigure.y);
				}
				else if (sf::Mouse::getPosition().x - pos.x >= field.objSize * -1)
				{
					//move left
				}

				if (sf::Mouse::getPosition().y - pos.y >= field.objSize)
				{
					//move down
				}
				else if (sf::Mouse::getPosition().y - pos.y >= field.objSize * -1)
				{
					//move up
				}
			}
		}

		field.Draw(w, vm);
		

		w.display();
	}
}