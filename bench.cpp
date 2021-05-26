#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

    glBegin(GL_QUAD_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);

    glVertex2f(-1.5f, 0.0f);
    glVertex2f(1.5f, 0.0f);
    glVertex2f(-2.0f, -0.4f);
    glVertex2f(2.0f, -0.4f);

    glVertex2f(-2.0f, -0.4f);
    glVertex2f(2.0f, -0.4f);
    glVertex2f(-2.0f, -0.6f);
    glVertex2f(2.0f, -0.6f);
    glEnd();

    glBegin(GL_LINES);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.0f, -0.4f);
    glVertex2f(2.0f, -0.4f);

    glEnd();



    glBegin(GL_QUAD_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2f(-1.5f, 1.0f);
    glVertex2f(1.5f, 1.0f);
    glVertex2f(-1.5f, 0.7f);
    glVertex2f(1.5f, 0.7f);

    glEnd();

    glBegin(GL_QUAD_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-1.5f, 0.5f);
    glVertex2f(1.5f, 0.5f);
    glVertex2f(-1.5f, 0.2f);
    glVertex2f(1.5f, 0.2f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-1.2f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.2f, 1.1f);
    glVertex2f(-1.0f, 1.1f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(1.2f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.2f, 1.1f);
    glVertex2f(1.0f, 1.1f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-1.8f, -0.4f);
    glVertex2f(-1.5f, -0.4f);
    glVertex2f(-1.8f, -1.5f);
    glVertex2f(-1.5f, -1.5f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(1.8f, -0.4f);
    glVertex2f(1.5f, -0.4f);
    glVertex2f(1.8f, -1.5f);
    glVertex2f(1.5f, -1.5f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(-1.3f, -0.4f);
    glVertex2f(-1.1f, -0.4f);
    glVertex2f(-1.3f, -1.2f);
    glVertex2f(-1.1f, -1.2f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(1.3f, -0.4f);
    glVertex2f(1.1f, -0.4f);
    glVertex2f(1.3f, -1.2f);
    glVertex2f(1.1f, -1.2f);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-2.0f, -0.6f);
    glVertex2f(2.0f, -0.6f);

    glVertex2f(-2.0f, 0.0f);
    glVertex2f(2.0f, 0.0f);
    glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(520, 520);
	glutCreateWindow("Bench");
	gluOrtho2D(-4,4,-4,4);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}