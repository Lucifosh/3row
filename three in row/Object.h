#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum class FigureType
{
	rhombus,
	square,
	circle,
	triangle,
	none,
	empty
};

class Object
{
private:
	FigureType type = FigureType::none;
	sf::Vector2f coor;
	int x = 0;
	int y = 0;

public:
	Object();
	Object(FigureType type, int x, int y);
	FigureType getType();
};

