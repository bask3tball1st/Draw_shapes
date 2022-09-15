#pragma once
#include "Figure.h"

class Triangle :public Figure {
private:
	Point A, B, C;
public:
	Triangle();
	Triangle(int, int);
	void setTriangPoints();
	void virtual draw();
};
