#include <stdlib.h>
#include<iostream>

class Figure {
public:
	//x, y: Начало координат(центр фигуры); 
	//height, width: Ширина и высота фигуры
	int x = 0, y = 0, height = 25, width = 50;
	//int color;
	void setWidth(const int w);
	void setHeight(const int h);
	void virtual draw() {};
};

struct Point {
	double x, y;
};

class Rectangle :public Figure {
private:
	Point A, B, C, D;
public:
	Rectangle();
	Rectangle(int, int);
	void setRectPoints();
	void virtual draw();
};

class Rhombus :public Figure {
private:
	Point A, B, C, D;
public:
	void setRhombPoints();
	void virtual draw();
};

class Triangle :public Figure {
private:
	Point A, B, C;
public:
	Triangle();
	Triangle(int, int);
	void setTriangPoints();
	void virtual draw();
};

class Circle :public Figure {
private:
	int r;
public:
	void setRadius(const int rad);
	void virtual draw();
};

class Ellipse :public Figure {
public:
	void virtual draw();
};

