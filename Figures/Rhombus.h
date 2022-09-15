#pragma once
#include "Figure.h"

class Rhombus :public Figure {
private:
	Point A, B, C, D;
public:
	Rhombus();
	Rhombus(int, int);
	void setRhombPoints();
	void virtual draw();
};
