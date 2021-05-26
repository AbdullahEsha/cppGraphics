#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

	//++
	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0f, 0.5f, 0.0f);
	glVertex2f(-2.0f, -2.0f);
    glVertex2f(-2.0f, 3.0f);
    glVertex2f(1.0f, -2.0f);
    glVertex2f(1.0f, 3.0f);
	glEnd();

	glLineWidth(30.0);
	glBegin(GL_LINES);
	glColor3f(0.5f, 0.5f, 1.0f );
	glVertex2f(-1.5f, 2.5f);
    glVertex2f(-1.0f, 2.5f);

    glVertex2f(0.5f, 2.5f);
    glVertex2f(0.0f, 2.5f);

    glVertex2f(-1.5f, 1.5f);
    glVertex2f(-1.0f, 1.5f);

    glVertex2f(0.5f, 1.5f);
    glVertex2f(0.0f, 1.5f);

    glVertex2f(-1.5f, 0.5f);
    glVertex2f(-1.0f, 0.5f);

    glVertex2f(0.5f, 0.5f);
    glVertex2f(0.0f, 0.5f);

    glVertex2f(-1.5f, -0.5f);
    glVertex2f(-1.0f, -0.5f);

    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.0f, -0.5f);


    glVertex2f(-0.5f, -2.0f);
    glVertex2f(-0.5f, -1.0f);

    glVertex2f(-2.5f, -2.0f);
    glVertex2f(1.5f, -2.0f);
    glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(520, 520);
	glutCreateWindow("Five storied building");
	gluOrtho2D(-4,4,-4,4);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}