#pragma once
#include "Object.h"
#include "SFML/Graphics.hpp"
#include <thread>
#include <chrono>

class Field
{
public:
	Object** field;
	sf::VideoMode vm;

public:
	int objSize = 0;
	int size = 0;

	Field(int size);
	Field();
	void Draw(sf::RenderWindow& window, sf::VideoMode vm);
	void setFigure(FigureType type, int x, int y);
	void setFigure(Object o, int x, int y);
	void swap(int x1, int y1, int x2, int y2);
	Object getFigure(int x, int y);
	int getX(int x);
	int getY(int y);
};


