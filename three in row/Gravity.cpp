#include "Gravity.h"
#include <thread>
#include <chrono>

Gravity::Gravity(Field field)
{
	this->field = field;
}

bool Gravity::drop()
{
	bool d = false;
	for (int i = field.size - 1; i > 0; i--)
	{
		for (int j = field.size - 1; j >= 0; j--)
		{
			if (field.getFigure(i, j).getType() == FigureType::none)
			{
				field.setFigure(field.getFigure(i-1, j).getType(), i, j);
				field.setFigure(FigureType::none, i - 1, j);
				d = true;
			}
		}
	}
	return d;
}

void Gravity::add()
{
	for (int i = 0; i < field.size; i++)
	{
		if (field.getFigure(0, i).getType() == FigureType::none)
		{
			srand(time(0));
			int temp = (rand() + count) % 4;
			count++;
			if (temp == 0)
			{
				field.setFigure(FigureType::square, 0, i);
			}
			else if (temp == 1)
			{
				field.setFigure(FigureType::circle, 0, i);
			}
			else if (temp == 2)
			{
				field.setFigure(FigureType::rhombus, 0, i);
			}
			else if (temp == 3)
			{
				field.setFigure(FigureType::triangle, 0, i);
			}
			//std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}
