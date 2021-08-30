#pragma once
#include "Object.h"
#include "Field.h"
class Move
{
private:
	Field field;
	void Delete(int x, int y, bool isRight);
public:
	Move(Field&);
	int moving = 0;
	bool tryToMove(int x, int y);
	void move(AnimState state, int a1, int b1, int a2, int b2, bool stop = false);
	int checkAndDelete(int x, int y, bool needDelete = false);
	void checkAnim();
	void click(int x, int y);
	//void goMove(AnimState state, int a1, int b1, int a2, int b2, bool stop = false);
};

