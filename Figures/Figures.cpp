#include <iostream>
#include "glut.h"
#include "Test.h"

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

void SKeyboard(int key, int x, int y) {
	if (key == '1')
		exit(1);
	/*if (key == GLUT_KEY_UP) {
		if (ct < vt.size() - 1)
			ct++;
		if (vt[ct].check())
			mt = ct;
	}
	if (key == GLUT_KEY_DOWN)
		ct--;*/
}

bool choiceAnsw(int answ) {
	return answ == YES ? true : false;
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
		if (choiceAnsw(answer)) {
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
		Rectangle q;
		q.draw();
		glFinish();
		break;
	}
	case RHOMBUS:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		Rhombus r;
		r.draw();
		glFinish();
		break;
	}
	case CIRCLE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		Circle c;
		std::cout << "Enter the radius of the circle:" << std::endl;
		int radius;
		std::cin >> radius;
		c.setRadius(radius);
		c.draw();
		glFinish();
		break;
	}
	case ELLIPSE:
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		glPointSize(10);
		Ellipse e;
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