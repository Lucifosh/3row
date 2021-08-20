#include "Controller.h"

sf::Vector2i Controller::transtlate(sf::Vector2i coor)
{
	int x = -1;
	int y = -1;
	for (int i = 0; i < field.size; i++)
	{
		if (coor.x >= field.getX(i) && coor.x <= field.getX(i) + field.objSize)
		{
			x = i;
		}
		if (coor.y >= field.getY(i) && coor.y <= field.getY(i) + field.objSize)
		{
			y = i;
		}
		if (x > -1 && y > -1)
		{
			//field.setFigure(FigureType::circle, x, y);
			break;
		}
	}
	return sf::Vector2i(x, y);
}

Controller::Controller(Field& f)
{
	this->field = f;
}


