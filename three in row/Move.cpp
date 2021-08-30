#include "Move.h"
#include "Object.h"
#include <iostream>
#include <thread>

bool Move::tryToMove(int x, int y)
{
	int count = 0;
	bool reset = true;
	for (int side = 0; side < 4; side++)
	{
		int k = 1;
		if (side == 2 && reset)
		{
			count = 0;
			reset = false;
		}
		while (true)
		{
			if (count >= 2)
				return true;
			if (side == 0) // check up
			{
				if ((x - k) < field.size && x - k >= 0)
				{
					switch (field.getFigure(x-k, y).getType())
					{
					case FigureType::circle:
						std::cout << "c ";
						break;
					case FigureType::rhombus:
						std::cout << "r ";
						break;
					case FigureType::square:
						std::cout << "s ";
						break;
					case FigureType::triangle:
						std::cout << "t ";
						break;
					default:
						break;
					}
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
				if ((x + k) >= 0 && x + k < field.size)
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
				if ((y - k) >= 0 && (y - k) < field.size)
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
				if ((y + k) < field.size && (y + k) >= 0)
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

int Move::checkAndDelete(int x, int y, bool needDelete)
{
	if (x < 0 || x >= field.size || y < 0 || y >= field.size)
		return 0;

	int count = 0;
	
	std::cout << "check and delete " << x << ' ' << y << '\n';
	FigureType type = field.getFigure(x, y).getType();
	field.setFigure(FigureType::none, x, y);

	for (int side = 0; side < 4; side++)
	{
		std::cout << side << ' ';
		if (side == 0 && x-1 >= 0) //up
		{
			std::cout << "up ";
			if (type == field.getFigure(x - 1, y).getType() && type != FigureType::none)
				count += 1 + checkAndDelete(x - 1, y, needDelete);
		}
		else if (side == 1 && x + 1 < field.size) //down
		{
			std::cout << "down ";
			if (type == field.getFigure(x + 1, y).getType() && type != FigureType::none)
				count += 1 + checkAndDelete(x + 1, y, needDelete);
		}
		else if (side == 2 && y - 1 >= 0)
		{
			std::cout << "left ";
			if(type == field.getFigure(x, y - 1).getType() && type != FigureType::none)
				count += 1 + checkAndDelete(x, y - 1, needDelete);
		}
		else if (side == 3 && y + 1 < field.size)
		{
			std::cout << "right ";
			if (type == field.getFigure(x, y + 1).getType() && type != FigureType::none)
				count += 1 + checkAndDelete(x, y + 1, needDelete);
		}
	}
	if (needDelete)
	{
		field.setFigure(FigureType::none, x, y);
	}
	else
		field.setFigure(type, x, y);

	return count;
}

void Move::checkAnim()
{
	for (int i = 0; i < field.size; i++)
	{
		for (int j = 0; j < field.size; j++)
		{
			Object o = field.getFigure(i, j);
			if (o.anim.getState() != AnimState::None)
			{
				if (o.getEndShiftX() == o.getShiftX() && o.getEndShiftY() == o.getShiftY())
				{
					if (o.anim.getState() == AnimState::Left)
					{
						o.reset();
						field.swap(i, j, i, j - 1);
					}
					else if (o.anim.getState() == AnimState::Right)
					{
						o.reset();
						field.swap(i, j, i, j + 1);
					}
					else if (o.anim.getState() == AnimState::Up)
					{
						o.reset();
						field.swap(i, j, i - 1, j);
					}
					else if (o.anim.getState() == AnimState::Down)
					{
						o.reset();
						field.swap(i, j, i + 1, j);
					}
				}
				else
				{
					if (o.getEndShiftX() < 0)
						o.addShiftX(-1);
					else if (o.getEndShiftX() > 0)
						o.addShiftX(1);
					if (o.getEndShiftY() < 0)
						o.addShiftY(-1);
					else if (o.getEndShiftY() > 0)
						o.addShiftY(1);
				}

				field.setFigure(o, i, j);
			}
		}
	}
}

void Move::click(int x, int y)
{
	int c = checkAndDelete(x, y);
	std::cout << '\n' << c << '\n';
	if (c >= 2)
		checkAndDelete(x, y, true);
	else
		std::cout << "no\n";
}

/*void Move::goMove(AnimState state, int a1, int b1, int a2, int b2, bool stop)
{
	field.swap(a1, b1, a2, b2);
	if (!stop)
	{
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
			AnimState temp = state;
			if (temp == AnimState::Down)
				temp = AnimState::Up;
			else if (temp == AnimState::Up)
				temp = AnimState::Down;
			else if (temp == AnimState::Left)
				temp = AnimState::Right;
			else if (temp == AnimState::Right)
				temp = AnimState::Left;
			move(temp, a1, b1, a2, b2, true);
			field.swap(a1, b1, a2, b2);
		}
	}
} */

Move::Move(Field& f)
{
	field = f;
}

void Move::move(AnimState state, int a1, int b1, int a2, int b2, bool stop)
{
	if (a1 < 0 || a1 >= field.size || a2 < 0 || a2 >= field.size || 
		b1 < 0 || b1 >= field.size || b2 < 0 || b2 >= field.size)
	{
		std::cout << "no\n";
		return;
	}
	if (!stop)
	{
		AnimState temp = state;
		if (temp == AnimState::Down)
			temp = AnimState::Up;
		else if (temp == AnimState::Up)
			temp = AnimState::Down;
		else if (temp == AnimState::Left)
			temp = AnimState::Right;
		else if (temp == AnimState::Right)
			temp = AnimState::Left;
		Object o = field.getFigure(a1, b1);
		o.anim.setState(state);
		o.setEndShiftX(field.getX(a2) - field.getX(a1));
		o.setEndShiftY(field.getY(b2) - field.getY(b1));
		field.setFigure(o, a1, b1);
		o = field.getFigure(a2, b2);
		o.anim.setState(temp);
		o.setEndShiftX(field.getX(a1) - field.getX(a2));
		o.setEndShiftY(field.getY(b1) - field.getY(b2));
		field.setFigure(o, a2, b2);
	}
}
