#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum FigureType
{
	rhombus,
	square,
	circle,
	triangle
};

class Object
{
	FigureType type;
	sf::Vector2f coor;

public:
	Object();
};

