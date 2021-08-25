#pragma once
#include "Object.h"
#include "Field.h"
class Move
{
private:
	Field field;
	bool tryToMove(int x, int y);
	void Delete(int x, int y, bool isRight);
public:
	Move(Field& f);
	void move(int a1, int b1, int a2, int b2);
	void checkAndDelete();
};

