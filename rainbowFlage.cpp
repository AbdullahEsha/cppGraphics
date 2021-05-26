#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.5f,0.5f);
	glVertex2f(0.5f,0.5f);
	glVertex2f(-0.5f,0.4f);
	glVertex2f(0.5f,0.4f);

	glColor3f(1.0,0.5,0.0);
	glVertex2f(-0.5f,0.4f);
	glVertex2f(0.5f,0.4f);
	glVertex2f(-0.5f,0.3f);
	glVertex2f(0.5f,0.3f);

	glColor3f(1.0,1.0,0.0);
	glVertex2f(-0.5f,0.3f);
	glVertex2f(0.5f,0.3f);
	glVertex2f(-0.5f,0.2f);
	glVertex2f(0.5f,0.2f);

	glColor3f(0.0,1.0,0.0);
	glVertex2f(-0.5f,0.2f);
	glVertex2f(0.5f,0.2f);
	glVertex2f(-0.5f,0.1f);
	glVertex2f(0.5f,0.1f);

	glColor3f(0.0,1.0,1.0);
	glVertex2f(-0.5f,0.1f);
	glVertex2f(0.5f,0.1f);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.5f,0.0f);

	glColor3f(0.0,0.0,1.0);
	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(-0.5f,-0.1f);
	glVertex2f(0.5f,-0.1f);

	glColor3f(0.73,0.16,0.96);
	glVertex2f(-0.5f,-0.1f);
	glVertex2f(0.5f,-0.1f);
	glVertex2f(-0.5f,-0.2f);
	glVertex2f(0.5f,-0.2f);

	glEnd();

	glBegin(GL_LINES);
	glColor3f (0.0, 0.0, 0.0);
	glVertex2f(-0.5f,0.5f);
	glVertex2f(0.5f,0.5f);

	glVertex2f(-0.5f,0.4f);
	glVertex2f(0.5f,0.4f);

	glVertex2f(-0.5f,0.3f);
	glVertex2f(0.5f,0.3f);

	glVertex2f(-0.5f,0.2f);
	glVertex2f(0.5f,0.2f);

	glVertex2f(-0.5f,0.1f);
	glVertex2f(0.5f,0.1f);

	glVertex2f(-0.5f,0.0f);
	glVertex2f(0.5f,0.0f);

	glVertex2f(-0.5f,-0.1f);
	glVertex2f(0.5f,-0.1f);

	glVertex2f(-0.5f,-0.2f);
	glVertex2f(0.5f,-0.2f);

    glVertex2f(-0.5f,0.5f);
	glVertex2f(-0.5f,-0.2f);

	glVertex2f(0.5f,0.5f);
	glVertex2f(0.5f,-0.2f);

	glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Rainbow Flag");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}