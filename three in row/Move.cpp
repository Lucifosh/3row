#include "Move.h"
#include "Object.h"
#include <iostream>

bool Move::tryToMove(int x, int y)
{
	int count = 0;
	std::cout << std::endl;
	bool reset = true;
	for (int side = 0; side < 4; side++)
	{
		int k = 1;
		while (true)
		{
			if (side == 2 && reset)
			{
				if (count >= 2)
					return true;
				count = 0;
				reset = false;
			}
			if (side == 0) // check up
			{
				if (x - k >= 0)
				{
					if (field.getFigure(x - k, y).getType() == field.getFigure(x, y).getType())
					{
						std::cout << "up + " << x - k << ' ' << y << " + ";
						count++;
						k++;
					}
					else
						break;
				}
				else
					break;
			}
			else if (side == 1) // check down
			{
				if (x + k < field.size)
				{
					if (field.getFigure(x + k, y).getType() == field.getFigure(x, y).getType())
					{
						std::cout << "down " << x + k << ' ' << y << " + ";
						count++;
						k++;
					}
					else
						break;
				}
				else
					break;
			}
			else if (side == 2) // check left
			{
				if (y - k >= 0)
				{
					if (field.getFigure(x, y - k).getType() == field.getFigure(x, y).getType())
					{
						std::cout << "left + " << x << ' ' << y-k << " + ";
						count++;
						k++;
					}
					else
						break;
				}
				else
					break;
			}
			else if (side == 3) // check right
			{
				if (y + k < field.size)
				{
					if (field.getFigure(x, y + k).getType() == field.getFigure(x, y).getType())
					{
						std::cout << "right + " << x << ' ' << y + k << " + ";
						count++;
						k++;
					}
					else
						break;
				}
				else
					break;
			}
		}
	}

	if (count >= 2)
		return true;

	return false;
}

void Move::Delete(int x, int y, bool isRight)
{
	int k = 1;
	FigureType temp = field.getFigure(x, y).getType();
	if (isRight)
	{
		while (true)
		{
			if (y + k < field.size)
			{
				if (field.getFigure(x, y + k).getType() == temp)
					field.setFigure(FigureType::none, x, y + k);
				else
					break;
				k++;
			}
			else
				break;
		}
	}
	else
	{
		while (true)
		{
			if (x + k < field.size)
			{
				if (field.getFigure(x + k, y).getType() == temp)
					field.setFigure(FigureType::none, x + k, y);
				else
					break;
				k++;
			}
			else
				break;
		}
	}
}

void Move::checkAndDelete()
{
	std::cout << "check adn delete\n";
	for (int i = 0; i < field.size; i++)
	{
		for (int j = 0; j < field.size; j++)
		{
			
			bool isDelete = false;
			FigureType temp = field.getFigure(i, j).getType();
			if (j < field.size - 2)
			{
				if (field.getFigure(i, j + 1).getType() == temp && field.getFigure(i, j + 2).getType() == temp
					&& temp != FigureType::none)
				{
					Delete(i, j, true);
					isDelete = true;
				}
			}
			if (i < field.size - 2)
			{
				if (field.getFigure(i + 1, j).getType() == temp && field.getFigure(i + 2, j).getType() == temp
					&& temp != FigureType::none)
				{
					Delete(i, j, false);
					isDelete = true;
				}
			}
			if (isDelete)
				field.setFigure(FigureType::none, i, j);
		}
	}
}

Move::Move(Field& f)
{
	field = f;
}

void Move::move(int a1, int b1, int a2, int b2)
{
	if (a1 < 0 || a1 >= field.size || a2 < 0 || a2 >= field.size || 
		b1 < 0 || b1 >= field.size || b2 < 0 || b2 > field.size)
	{
		std::cout << "no\n";
		return;
	}
	field.swap(a1, b1, a2, b2);
	if (tryToMove(a2, b2))
	{
		std::cout << "yes\n";
		checkAndDelete();
	}
	else if (tryToMove(a1, b1))
	{
		std::cout << "yes\n";
		checkAndDelete();
	}
	else
	{
		std::cout << "no\n";
		field.swap(a1, b1, a2, b2);
	}
}
