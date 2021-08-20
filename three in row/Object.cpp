#include "Object.h"

Object::Object()
{
	this->type = FigureType::empty;
}

Object::Object(FigureType type, int x, int y)
{
	this->type = type;
	this->x = x; this->y = y;
}

FigureType Object::getType()
{
	return this->type;
}
