#include "Field.h"
#include <iostream>
int Field::getX(int x)
{
	return vm.width / 2 - vm.height / 15 / 2 + (x - (size / 2)) * (vm.height / 15) + vm.height / 30 * (x - (size / 2));
}
int Field::getY(int y)
{
	return vm.height / 35 + vm.height / 15 * y + vm.height / 30 * y;
}
Field::Field(int size)
{
	this->size = size;
	field = new Object*[size];
	for (int i = 0; i < size; i++)
	{
		field[i] = new Object[size];
	}
}

Field::Field()
{
}

void Field::Draw(sf::RenderWindow& window, sf::VideoMode vm)
{
	this->vm = vm;
	int objSize = vm.height / 15;// потом исправить на ширину
	this->objSize = objSize;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (field[i][j].getType() == FigureType::square)
			{
				sf::RectangleShape r;
				r.setFillColor(sf::Color(11, 218, 81));
				r.setPosition(sf::Vector2f(getX(i), getY(j)));
				r.setSize(sf::Vector2f(objSize, objSize));
				window.draw(r);
			}
			else if (field[i][j].getType() == FigureType::circle)
			{
				sf::CircleShape r;
				r.setFillColor(sf::Color::Red);
				r.setPosition(sf::Vector2f(getX(i), getY(j)));
				r.setRadius(objSize/2);
				window.draw(r);
			}
			else if (field[i][j].getType() == FigureType::triangle)
			{
				sf::CircleShape r;
				r.setPointCount(3);
				r.setRadius(objSize / 1.8);
				r.setPosition(sf::Vector2f(getX(i), getY(j)));
				r.setFillColor(sf::Color::Blue);
				window.draw(r);
			}
			else if (field[i][j].getType() == FigureType::rhombus)
			{
				sf::CircleShape r;
				r.setPointCount(4);
				r.setRadius(objSize / 1.8);
				r.setPosition(sf::Vector2f(getX(i), getY(j)));
				r.setFillColor(sf::Color::Magenta);
				window.draw(r);
			}
		}
	}
}

void Field::setFigure(FigureType type, int x, int y)
{
	field[x][y] = Object(type, x, y);
}
