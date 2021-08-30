#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Anim.h"

enum class FigureType
{
	rhombus,
	square,
	circle,
	triangle,
	none,
	empty
};

class Object
{
private:
	FigureType type = FigureType::none;
	int shiftX = 0;
	int shiftY = 0;
	int endShiftX = 0;
	int endShiftY = 0;

public:
	Anim anim;
	Object();
	Object(FigureType type, int x, int y);
	FigureType getType();
	int getShiftX() { return shiftX; };
	int getShiftY() { return shiftY; };
	void addShiftX(int x) { shiftX += x; };
	void addShiftY(int y) { shiftY += y; };
	int getEndShiftX() { return endShiftX; };
	int getEndShiftY() { return endShiftY; };
	void setEndShiftX(int x) { endShiftX = x; };
	void setEndShiftY(int y) { endShiftY = y; };
	void reset();
};
