#include "Test.h"
#include "glut.h"
#include <cmath>
#include <math.h>

void Figure::setHeight(const int h) {
	this->height = h;
}

void Figure::setWidth(const int w) {
	this->width = w;
}

void Triangle::setTriangPoints() {
	this->A.x = static_cast<__int64>(x) - width / 2;
	this->A.y = static_cast<__int64>(y) - height / 2;
	this->B.x = static_cast<__int64>(x) + width / 2;
	this->B.y = static_cast<__int64>(y) - height / 2;
	this->C.x = static_cast<__int64>(x) + height / 2;
	this->C.y = static_cast<__int64>(y) + height / 2;
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

void Circle::setRadius(const int rad) {
	this->r = rad;
}

void Triangle::draw() {
	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glEnd();
}

void Rhombus::draw() {
	setRhombPoints();
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glVertex2f(D.x, D.y);
	glEnd();
}

void Rectangle::draw() {
	setRectPoints();
	glColor3ub(255, 0, 0);
	glBegin(GL_QUADS);
	glVertex2f(A.x, A.y);
	glVertex2f(B.x, B.y);
	glVertex2f(C.x, C.y);
	glVertex2f(D.x, D.y);
	glEnd();
}

void Circle::draw() {
	const float step = 2 * 3.14 / 100;
	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle <= 2 * 3.14 + step; angle += step)
	{
		float dx = r * cosf(angle);
		float dy = r * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}

void Ellipse::draw() {
	const float step = 2 * 3.14 / 100;
	float xr = width / 2, yr = height / 2;
	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (float angle = 0; angle <= 2 * 3.14 + step; angle += step)
	{
		float dx = xr * cosf(angle);
		float dy = yr * sinf(angle);
		glVertex2f(x + dx, y + dy);
	}
	glEnd();
}

Triangle::Triangle() {
	this->setHeight(25);
	this->setWidth(25);
	this->setTriangPoints();
}

Triangle::Triangle(int w, int h) {
	this->setHeight(h);
	this->setWidth(w);
	this->setTriangPoints();
}

Rectangle::Rectangle() {

}

Rectangle::Rectangle(int w, int h) {

}