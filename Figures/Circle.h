#pragma once
#include "Figure.h"

class Circle :public Figure {
private:
	int r;
public:
	Circle();
	Circle(int);
	void virtual draw();
};
