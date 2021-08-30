#include "Object.h"

Object::Object()
{
	this->type = FigureType::empty;
}

Object::Object(FigureType type, int x, int y)
{
	this->type = type;
}

FigureType Object::getType()
{
	return this->type;
}

void Object::reset()
{
	anim.setState(AnimState::None);
	shiftX = 0; shiftY = 0;
	endShiftX = 0; endShiftY = 0;
}
