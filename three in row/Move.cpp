#include "Move.h"

bool Move::tryToMove(int a1, int b1, int a2, int b2)
{
	if(a1 >= field.size || a2 >= field.size || b1 >= field.size || b2 >= field.size)
		return false;
	if (a1 < 0 || a2 < 0 || b1 < 0 || b2 < 0)
		return false;
	

}

Move::Move(Field& f)
{
	field = f;
}

void Move::move(int a1, int b1, int a2, int b2)
{
	if (tryToMove(a1, b1, a2, b2))
	{
		
	}
}
