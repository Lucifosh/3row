#pragma once
#include "SFML/Graphics.hpp"
#include "Field.h"
class Controller
{
	Field field;

public:
	Controller(Field& f);
	sf::Vector2i transtlate(sf::Vector2i coor);
};

