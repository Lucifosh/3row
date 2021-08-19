#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"

class Field
{
	Object** field;
	int size = 0;
	sf::VideoMode vm;

public:
	Field(int size);
	Field();
	void Draw(sf::RenderWindow& window, sf::VideoMode vm);
	void setFigure(int x, int y, FigureType type);
};

