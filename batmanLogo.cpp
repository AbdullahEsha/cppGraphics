#include <windows.h>
#include <GL/glut.h>

void display() {
	glClearColor(1.0f, 1.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(4.0);

	//+-
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, -2.0f);
    glVertex2f(0.1f, -1.85f);
    glVertex2f(0.1f, -0.0f);
    glVertex2f(0.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, -1.85f);
    glVertex2f(0.2f, -1.70f);
    glVertex2f(0.2f, -0.0f);
    glVertex2f(0.1f, -0.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.2f, -1.70f);
    glVertex2f(0.3f, -1.55f);
    glVertex2f(0.3f, -0.0f);
    glVertex2f(0.2f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.3f, -1.55f);
    glVertex2f(0.4f, -1.50f);
    glVertex2f(0.4f, -0.0f);
    glVertex2f(0.3f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.4f, -1.50f);
    glVertex2f(0.5f, -1.45f);
    glVertex2f(0.5f, -0.0f);
    glVertex2f(0.4f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.5f, -1.45f);
    glVertex2f(0.6f, -1.40f);
    glVertex2f(0.6f, -0.0f);
    glVertex2f(0.5f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.6f, -1.40f);
    glVertex2f(0.7f, -1.35f);
    glVertex2f(0.7f, -0.0f);
    glVertex2f(0.6f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.7f, -1.35f);
    glVertex2f(0.8f, -1.30f);
    glVertex2f(0.8f, -0.0f);
    glVertex2f(0.7f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.8f, -1.30f);
    glVertex2f(0.9f, -1.25f);
    glVertex2f(0.9f, -0.0f);
    glVertex2f(0.8f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.9f, -1.25f);
    glVertex2f(1.0f, -1.20f);
    glVertex2f(1.0f, -0.0f);
    glVertex2f(0.9f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.0f, -1.20f);
    glVertex2f(1.1f, -1.15f);
    glVertex2f(1.1f, -0.0f);
    glVertex2f(1.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.1f, -1.15f);
    glVertex2f(1.2f, -1.10f);
    glVertex2f(1.2f, -0.0f);
    glVertex2f(1.1f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.2f, -1.10f);
    glVertex2f(1.3f, -1.05f);
    glVertex2f(1.3f, -0.0f);
    glVertex2f(1.2f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.3f, -1.05f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(1.4f, -0.0f);
    glVertex2f(1.3f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.4f, -1.0f);
    glVertex2f(1.5f, -0.95f);
    glVertex2f(1.5f, -0.0f);
    glVertex2f(1.4f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.5f, -0.95f);
    glVertex2f(1.6f, -0.90f);
    glVertex2f(1.6f, -0.0f);
    glVertex2f(1.5f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.6f, -0.90f);
    glVertex2f(1.7f, -0.85f);
    glVertex2f(1.7f, -0.0f);
    glVertex2f(1.6f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.7f, -0.85f);
    glVertex2f(1.8f, -0.80f);
    glVertex2f(1.8f, -0.0f);
    glVertex2f(1.7f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.8f, -0.80f);
    glVertex2f(1.9f, -0.75f);
    glVertex2f(1.9f, -0.0f);
    glVertex2f(1.8f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.9f, -0.75f);
    glVertex2f(2.0f, -0.70f);
    glVertex2f(2.0f, -0.0f);
    glVertex2f(1.9f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(2.0f, -0.70f);
    glVertex2f(2.1f, -0.65f);
    glVertex2f(2.1f, -0.0f);
    glVertex2f(2.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(2.1f, -0.65f);
    glVertex2f(2.2f, -0.60f);
    glVertex2f(2.2f, -0.0f);
    glVertex2f(2.1f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(2.2f, -0.60f);
    glVertex2f(2.3f, -0.60f);
    glVertex2f(2.2f, -0.0f);
	glEnd();

	//++

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(2.2f, 0.60f);
    glVertex2f(3.0f, 0.60f);
    glVertex2f(2.2f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
    glVertex2f(2.2f, 0.0f);
    glVertex2f(2.2f, 0.6f);
    glVertex2f(1.0f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1f, 0.0f);
    glVertex2f(0.1f, 0.65f);
    glVertex2f(0.0f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.1f, 0.0f);
    glVertex2f(0.2f, 0.0f);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.1f, 0.65f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.2f, 0.0f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(0.2f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.4f, 0.0f);
    glVertex2f(0.6f, 0.0f);
    glVertex2f(0.6f, 0.4f);
    glVertex2f(0.4f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.6f, 0.0f);
    glVertex2f(0.8f, 0.0f);
    glVertex2f(0.8f, 0.4f);
    glVertex2f(0.6f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0.8f, 0.0f);
    glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(0.8f, 0.4f);
	glEnd();

	//-+

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.2f, 0.60f);
    glVertex2f(-3.0f, 0.60f);
    glVertex2f(-2.2f, 0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, 0.0f);
    glVertex2f(-2.2f, 0.0f);
    glVertex2f(-2.2f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.0f, 0.0f);
    glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.1f, 0.65f);
    glVertex2f(-0.0f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.1f, 0.0f);
    glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.2f, 0.6f);
    glVertex2f(-0.1f, 0.65f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, 0.0f);
    glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.4f, 1.0f);
    glVertex2f(-0.2f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.4f, 0.0f);
    glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.4f, 0.6f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.6f, 0.0f);
    glVertex2f(-0.8f, 0.0f);
    glVertex2f(-0.8f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.8f, 0.0f);
    glVertex2f(-1.0f, 0.0f);
    glVertex2f(-1.0f, 0.6f);
    glVertex2f(-0.8f, 0.4f);
	glEnd();

	//--
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.0f, -2.0f);
    glVertex2f(-0.1f, -1.85f);
    glVertex2f(-0.1f, -0.0f);
    glVertex2f(-0.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.1f, -1.85f);
    glVertex2f(-0.2f, -1.70f);
    glVertex2f(-0.2f, -0.0f);
    glVertex2f(-0.1f, -0.0f);
	glEnd();

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.2f, -1.70f);
    glVertex2f(-0.3f, -1.55f);
    glVertex2f(-0.3f, -0.0f);
    glVertex2f(-0.2f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.3f, -1.55f);
    glVertex2f(-0.4f, -1.50f);
    glVertex2f(-0.4f, -0.0f);
    glVertex2f(-0.3f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.4f, -1.50f);
    glVertex2f(-0.5f, -1.45f);
    glVertex2f(-0.5f, -0.0f);
    glVertex2f(-0.4f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.5f, -1.45f);
    glVertex2f(-0.6f, -1.40f);
    glVertex2f(-0.6f, -0.0f);
    glVertex2f(-0.5f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.6f, -1.40f);
    glVertex2f(-0.7f, -1.35f);
    glVertex2f(-0.7f, -0.0f);
    glVertex2f(-0.6f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.7f, -1.35f);
    glVertex2f(-0.8f, -1.30f);
    glVertex2f(-0.8f, -0.0f);
    glVertex2f(-0.7f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.8f, -1.30f);
    glVertex2f(-0.9f, -1.25f);
    glVertex2f(-0.9f, -0.0f);
    glVertex2f(-0.8f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-0.9f, -1.25f);
    glVertex2f(-1.0f, -1.20f);
    glVertex2f(-1.0f, -0.0f);
    glVertex2f(-0.9f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.0f, -1.20f);
    glVertex2f(-1.1f, -1.15f);
    glVertex2f(-1.1f, -0.0f);
    glVertex2f(-1.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.1f, -1.15f);
    glVertex2f(-1.2f, -1.10f);
    glVertex2f(-1.2f, -0.0f);
    glVertex2f(-1.1f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.2f, -1.10f);
    glVertex2f(-1.3f, -1.05f);
    glVertex2f(-1.3f, -0.0f);
    glVertex2f(-1.2f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.3f, -1.05f);
    glVertex2f(-1.4f, -1.0f);
    glVertex2f(-1.4f, -0.0f);
    glVertex2f(-1.3f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.4f, -1.0f);
    glVertex2f(-1.5f, -0.95f);
    glVertex2f(-1.5f, -0.0f);
    glVertex2f(-1.4f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.5f, -0.95f);
    glVertex2f(-1.6f, -0.90f);
    glVertex2f(-1.6f, -0.0f);
    glVertex2f(-1.5f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.6f, -0.90f);
    glVertex2f(-1.7f, -0.85f);
    glVertex2f(-1.7f, -0.0f);
    glVertex2f(-1.6f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.7f, -0.85f);
    glVertex2f(-1.8f, -0.80f);
    glVertex2f(-1.8f, -0.0f);
    glVertex2f(-1.7f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.8f, -0.80f);
    glVertex2f(-1.9f, -0.75f);
    glVertex2f(-1.9f, -0.0f);
    glVertex2f(-1.8f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-1.9f, -0.75f);
    glVertex2f(-2.0f, -0.70f);
    glVertex2f(-2.0f, -0.0f);
    glVertex2f(-1.9f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.0f, -0.70f);
    glVertex2f(-2.1f, -0.65f);
    glVertex2f(-2.1f, -0.0f);
    glVertex2f(-2.0f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.1f, -0.65f);
    glVertex2f(-2.2f, -0.60f);
    glVertex2f(-2.2f, -0.0f);
    glVertex2f(-2.1f, -0.0f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-2.2f, -0.60f);
    glVertex2f(-2.35f, -0.60f);
    glVertex2f(-2.2f, -0.0f);
	glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(320, 320);
	glutCreateWindow("BatMan Logo");
	gluOrtho2D(-5,5,-5,5);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}