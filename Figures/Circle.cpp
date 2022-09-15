#include "Circle.h"
#include "glut.h"
#include <math.h>

Circle::Circle() {
	this->r = 15;
	this->setHeight(2 * r);
	this->setWidth(2 * r);
}

Circle::Circle(int rad) {
	this->r = rad;
	this->setHeight(2 * r);
	this->setWidth(2 * r);
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