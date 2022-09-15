#include "Ellipse.h"
#include "glut.h"
#include <math.h>

Ellipse::Ellipse() {
	this->height = 30;
	this->width = 50;
}

Ellipse::Ellipse(int w, int h) {
	setHeight(h);
	setWidth(w);
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