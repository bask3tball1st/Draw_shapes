#include <iostream>
#include "glut.h"
#include "Figure.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Circle.h"
#include "Ellipse.h"

GLint Width = 512, Height = 512;
const int CubeSize = 200;
int action;

enum Figures {
	TRIANGLE = 1,
	RECTANGLE,
	RHOMBUS,
	CIRCLE,
	ELLIPSE
};

enum Answer {
	YES = 1,
	NO
};

void Reshape(GLint w, GLint h) {
	w = Width;
	h = Height;
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50., 50., -50., 50.);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void printQuest() {
	std::cout << "Do you want to enter width";
	std::cout << " and height of the shape ? " << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
}


void Display(void) {
	
	switch (action) {
	case TRIANGLE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		printQuest();
		Triangle t;
		int answer;
		std::cin >> answer;
		if (answer == YES) {
			std::cout << "Enter width and height separated by spaces: ";
			int h, w;
			std::cin >> w >> h;
			t = Triangle(w, h);
		}
		t.draw();
		glFinish();
		break;
	}
	case RECTANGLE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		printQuest();
		Rectangle q;
		int answer;
		std::cin >> answer;
		if (answer == YES) {
			std::cout << "Enter width and height separated by spaces: ";
			int h, w;
			std::cin >> w >> h;
			q = Rectangle(w, h);
		}
		q.draw();
		glFinish();
		break;
	}
	case RHOMBUS:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		printQuest();
		Rhombus r;
		int answer;
		std::cin >> answer;
		if (answer == YES) {
			std::cout << "Enter width and height separated by spaces: ";
			int h, w;
			std::cin >> w >> h;
			r = Rhombus(w, h);
		}
		r.draw();
		glFinish();
		break;
	}
	case CIRCLE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		std::cout << "Do you want to enter the radius of the circle?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;
		Circle c;
		int answer;
		std::cin >> answer;
		if (answer == YES) {
			std::cout << "Enter the radius of the circle:" << std::endl;
			int radius;
			std::cin >> radius;
			c = Circle(radius);
		}
		c.draw();
		glFinish();
		break;
	}
	case ELLIPSE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		printQuest();
		Ellipse e;
		int answer;
		std::cin >> answer;
		if (answer == YES) {
			std::cout << "Enter width and height separated by spaces: ";
			int h, w;
			std::cin >> w >> h;
			e = Ellipse(w, h);
		}
		e.draw();
		glFinish();
		break;
	}
	default:
		exit(0);
	}
}

int main(int argc, char* argv[]) {
	std::cout << "Enter what shape you want to draw: " << std::endl;
	std::cout << "1. Triangle" << std::endl;
	std::cout << "2. Rectangle" << std::endl;
	std::cout << "3. Rhombus" << std::endl;
	std::cout << "4 Circle" << std::endl;
	std::cout << "5 Ellipse" << std::endl;
	std::cin >> action;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(1000, 100);
	glutCreateWindow("Figure");
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutMainLoop();
}