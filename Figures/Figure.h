#pragma once
class Figure {
public:
	//x, y: ������ ���������(����� ������); 
	//height, width: ������ � ������ ������
	int x = 0, y = 0, height, width;
	int color;
	void setColor();
	void setWidth(const int w);
	void setHeight(const int h);
	void virtual draw() {};
};

struct Point {
	double x, y;
};


