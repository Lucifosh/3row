#include "Gravity.h"
#include "Anim.h"

bool Gravity::drop(Move &m)
{
	bool d = false;
	for (int i = 0; i < field.size-1; i++)
	{
		for (int j = 0; j < field.size; j++)
		{
			if (field.getFigure(i+1, j).getType() == FigureType::none)
			{
				m.move(AnimState::Down, i, j, lastDrop(i+1, j), j);
				//field.swap(i, j, i + 1, j);
				d = true;
			}
		}
	}
	return d;
}

int Gravity::lastDrop(int x, int y)
{
	int k = 1;
	while (true)
	{
		if (x - k >= 0)
		{
			if (field.getFigure(x + k, y).getType() == FigureType::none)
			{
				k++;
			}
			else
			{
				k--;
				return x - k;
			}
		}
	}
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
