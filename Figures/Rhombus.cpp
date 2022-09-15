#include "Rhombus.h"
#include "glut.h"

Rhombus::Rhombus() {
	this->height = 25;
	this->width = 25;
	this->setRhombPoints();
}

Rhombus::Rhombus(int w, int h) {
	this->setWidth(w);
	this->setHeight(h);
	this->setRhombPoints();
}

void Rhombus::setRhombPoints() {
	this->A.x = static_cast<__int64>(x) - height / 2;
	this->A.y = y;
	this->B.x = x;
	this->B.y = static_cast<__int64>(y) + width / 2;
	this->C.x = static_cast<__int64>(x) + height / 2;
	this->C.y = y;
	this->D.x = x;
	this->D.y = static_cast<__int64>(y) - width / 2;
}

void Rhombus::draw() {
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glVertex2f(D.x, D.y);
	glEnd();
}