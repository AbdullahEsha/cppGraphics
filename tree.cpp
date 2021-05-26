#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.1f);
	glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.0f, 2.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.1f);
	glVertex2f(-0.8f, 1.0f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(1.0f, 0.8f);
    glVertex2f(-1.0f, 0.8f);
	glEnd();

	glLineWidth(30.0);
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.0f, 0.2f);
	glVertex2f(0.0f, 0.8f);
    glVertex2f(0.0f, 0.0f);
    glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(520, 520);
	glutCreateWindow("Tree");
	gluOrtho2D(-4,4,-4,4);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}