#pragma once
#include "Field.h"
#include <cstdlib>
#include <ctime>
class Gravity
{
	int count = 0;
	Field field;
public:
	Gravity(Field field);
	bool drop();
	void add();
};

