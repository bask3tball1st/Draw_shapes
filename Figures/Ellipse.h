#pragma once
#include "Figure.h"

class Ellipse :public Figure {
public:
	Ellipse();
	Ellipse(int, int);
	void virtual draw();
};
