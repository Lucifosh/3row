#include "Object.h"

Object::Object()
{
	this->type = FigureType::empty;
}

Object::Object(FigureType type, sf::Vector2f coor)
{
	this->type = type;
	this->coor = coor;
}

FigureType Object::getType()
{
	return this->type;
}

sf::Vector2f Object::getCoor()
{
	return this->coor;
}
