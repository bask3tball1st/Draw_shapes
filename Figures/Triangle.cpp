#include "Triangle.h"
#include "glut.h"

Triangle::Triangle() {
	this->height = 25;
	this->width = 25;
	this->setTriangPoints();
}

Triangle::Triangle(int w, int h) {
	this->setHeight(h);
	this->setWidth(w);
	this->setTriangPoints();
}

void Triangle::setTriangPoints() {
	this->A.x = static_cast<__int64>(x) - width / 2;
	this->A.y = static_cast<__int64>(y) - height / 2;
	this->B.x = static_cast<__int64>(x) + width / 2;
	this->B.y = static_cast<__int64>(y) - height / 2;
	this->C.x = static_cast<__int64>(x) + height / 2;
	this->C.y = static_cast<__int64>(y) + height / 2;
}

void Triangle::draw() {
	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glEnd();
}

