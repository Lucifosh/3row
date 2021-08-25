#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "Field.h"
#include "Controller.h"
#include <cmath>
#include "Move.h"
#include <cstdlib>
#include <ctime>
#include "Gravity.h"

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

	int size = 10;
	Field field(size);
	field.Draw(w, vm);

	Controller controller(field);

	Move move(field);

	Gravity gravity(field);

	srand(time(0));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int temp = rand() % 4;
			if (temp == 0)
				field.setFigure(FigureType::square, i, j);
			else if(temp == 1)
				field.setFigure(FigureType::circle, i, j);
			else if(temp == 2)
				field.setFigure(FigureType::rhombus, i, j);
			else if(temp == 3)
				field.setFigure(FigureType::triangle, i, j);

				std::cout << temp << ' ';
		}
		std::cout << '\n';
	}

	sf::Vector2i posFigure;
	sf::Vector2i pos;
	EControllerState state = EControllerState::none;
	
	while (w.isOpen())
	{
		bool droped = false;
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
					move.move(posFigure.x, posFigure.y, posFigure.x, posFigure.y + 1);
					state = EControllerState::none;
				}
				else if (sf::Mouse::getPosition().x - pos.x <= field.objSize * -1)
				{
					//move left
					/*move.move(posFigure.x, posFigure.y, posFigure.x-1, posFigure.y);
					state = EControllerState::none;*/
					move.move(posFigure.x, posFigure.y, posFigure.x, posFigure.y - 1);
					state = EControllerState::none;
				}

				if (sf::Mouse::getPosition().y - pos.y >= field.objSize)
				{
					//move down
					
					move.move(posFigure.x, posFigure.y, posFigure.x + 1, posFigure.y);
					state = EControllerState::none;
				}
				else if (sf::Mouse::getPosition().y - pos.y <= field.objSize * -1)
				{
					//move up
					/**/
					
					move.move(posFigure.x, posFigure.y, posFigure.x - 1, posFigure.y);
					state = EControllerState::none;
				}
			}
		}

		field.Draw(w, vm);

		gravity.add();
		
		gravity.drop();

		move.checkAndDelete();
		

		w.display();
	}
}