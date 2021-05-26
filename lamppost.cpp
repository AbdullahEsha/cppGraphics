#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(-2.1f, 2.5f);
    glVertex2f(-1.5f, 2.4f);
    glEnd();

	glLineWidth(10.0);
	glBegin(GL_LINES);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(-2.0f, 2.5f);
    glVertex2f(-2.0f, -1.5f);
    glEnd();

	glLineWidth(20.0);
	glBegin(GL_LINES);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(-2.0f, -1.5f);
    glVertex2f(-2.0f, -3.0f);
    glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex2f(-1.5f, 2.5f);
    glVertex2f(-1.0f, 2.5f);
    glVertex2f(-0.5f, 2.0f);
    glVertex2f(-1.5f, 2.0f);

    glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, 2.0f);
    glVertex2f(-1.5f, 2.0f);
    glVertex2f(-1.5f, 0.0f);
    glVertex2f(1.0f, 0.0f);
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