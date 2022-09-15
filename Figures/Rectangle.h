#pragma once
#include "Figure.h"

class Rectangle :public Figure {
private:
	Point A, B, C, D;
public:
	Rectangle();
	Rectangle(int, int);
	void setRectPoints();
	void virtual draw();
};
