#pragma once
#include "Object.h"
#include "Field.h"
class Move
{
private:
	Field field;
	bool tryToMove(int a1, int b1, int a2, int b2);
public:
	Move(Field& f);
	void move(int a1, int b1, int a2, int b2);
};

