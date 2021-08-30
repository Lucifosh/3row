#pragma once
#include "Field.h"
#include <cstdlib>
#include <ctime>
#include "Move.h"
class Gravity
{
	int count = 0;
	Field field;
public:
	Gravity(Field& field) { this->field = field; };
	bool drop(Move &m);
	int lastDrop(int x, int y);
	void add();
};

