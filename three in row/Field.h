#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"

class Field
{
	Object** field;
	sf::VideoMode vm;

public:
	int x = 0;
	int y = 0;
	int objSize = 0;
	int size = 0;

	Field(int size);
	Field();
	void Draw(sf::RenderWindow& window, sf::VideoMode vm);
	void setFigure(FigureType type, int x, int y);
	int getX(int x);
	int getY(int y);
};

