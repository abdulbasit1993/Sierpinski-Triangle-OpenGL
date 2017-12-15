#include <Windows.h>
#include <gl/GL.h>
#include <glut.h>

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

class GLintPoint {
	public:
		GLint x, y;
};

int random(int m) {
	return rand() % m;
}

void drawDot(GLint x, GLint y)
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void Sierpinski(void) {
	GLintPoint T[3] = {{ 10, 10 }, {300, 30}, {200, 300}};

	int index = random(3);
	GLintPoint point = T[index];
	for (int i = 0; i < 1000; i++)
	{
		index = random(3);
		point.x = (point.x + T[index].x) / 2;
		point.y = (point.y + T[index].y) / 2;
		drawDot(point.x, point.y);
	}
	glFlush();
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Sierpinski Gasket");
	glutDisplayFunc(Sierpinski);
	myInit();
	glutMainLoop();
}