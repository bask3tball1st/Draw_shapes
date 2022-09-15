#include "Rectangle.h"
#include "glut.h"

Rectangle::Rectangle() {
	this->height = 25;
	this->width = 25;
	this->setRectPoints();
}

Rectangle::Rectangle(int w, int h) {
	this->setHeight(h);
	this->setWidth(w);
	this->setRectPoints();
}

void Rectangle::setRectPoints() {
	this->A.x = static_cast<__int64>(x) - height / 2;
	this->A.y = static_cast<__int64>(y) - width / 2;
	this->B.x = static_cast<__int64>(x) - height / 2;
	this->B.y = static_cast<__int64>(y) + width / 2;
	this->C.x = static_cast<__int64>(x) + height / 2;
	this->C.y = static_cast<__int64>(y) + width / 2;
	this->D.x = static_cast<__int64>(x) + height / 2;
	this->D.y = static_cast<__int64>(y) - width / 2;
}

void Rectangle::draw() {
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glVertex2f(D.x, D.y);
	glEnd();
}
