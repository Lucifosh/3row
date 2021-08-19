#pragma once
#include "Object.h"
#include "Field.h"
class Move
{
private:
	Field field;
	bool tryToMove(int a, int b);
public:
	Move(Field& f);
	void move(int a, int b);
};

