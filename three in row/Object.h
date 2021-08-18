#pragma once
#include <string>
#include <SFML/Graphics.hpp>

enum class FigureType
{
	rhombus,
	square,
	circle,
	triangle,
	none
};

class Object
{
private:
	FigureType type = FigureType::none;
	sf::Vector2f coor;

public:
	Object(FigureType type, sf::Vector2f coor);
	FigureType getType();
	sf::Vector2f getCoor();
};

