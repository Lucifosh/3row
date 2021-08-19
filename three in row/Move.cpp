#include "Move.h"

bool Move::tryToMove(int a, int b)
{
	return false;
}

Move::Move(Field& f)
{
	field = f;
}

void Move::move(int a, int b)
{
	if (tryToMove(a, b))
	{
		
	}
}
