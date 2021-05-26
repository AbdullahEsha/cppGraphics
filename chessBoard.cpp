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


	glBegin(GL_QUADS);
	glColor3ub(0,0,0); //black

	glVertex2f(0.85f,0.85f);
	glVertex2f(-0.85f,0.85f);
	glVertex2f(-0.85f,-0.85f);
	glVertex2f(0.85f,-0.85f);

	glEnd();

	//First column
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.6f,0.8f);
	glVertex2f(-0.8f,0.8f);
	glVertex2f(-0.8f,0.6f);
	glVertex2f(-0.6f,0.6f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.6f,0.4f);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(-0.8f,0.2f);
             glVertex2f(-0.6f,0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.6f,0.0f);
	glVertex2f(-0.8f,0.0f);
	glVertex2f(-0.8f,-0.2f);
	glVertex2f(-0.6f,-0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.8f,-0.4f);
	glVertex2f(-0.8f,-0.6f);
	glVertex2f(-0.6f,-0.6f);

	glEnd();

	//Second column
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.2f,0.8f);
	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.2f,0.6f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.2f,0.4f);
	glVertex2f(-0.4f,0.4f);
	glVertex2f(-0.4f,0.2f);
	glVertex2f(-0.2f,0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.2f,0.0f);
	glVertex2f(-0.4f,0.0f);
	glVertex2f(-0.4f,-0.2f);
	glVertex2f(-0.2f,-0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.2f,-0.4f);
	glVertex2f(-0.4f,-0.4f);
	glVertex2f(-0.4f,-0.6f);
	glVertex2f(-0.2f,-0.6f);

	glEnd();

	//Third column
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.2f,0.8f);
	glVertex2f(0.0f,0.8f);
	glVertex2f(0.0f,0.6f);
	glVertex2f(0.2f,0.6f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.2f,0.4f);
	glVertex2f(0.0f,0.4f);
	glVertex2f(0.0f,0.2f);
	glVertex2f(0.2f,0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.2f,0.0f);
	glVertex2f(0.0f,0.0f);
	glVertex2f(0.0f,-0.2f);
	glVertex2f(0.2f,-0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.2f,-0.4f);
	glVertex2f(0.0f,-0.4f);
	glVertex2f(0.0f,-0.6f);
	glVertex2f(0.2f,-0.6f);

	glEnd();

	//4th column
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.6f,0.8f);
	glVertex2f(0.4f,0.8f);
	glVertex2f(0.4f,0.6f); //-0.4f,0.2f
	glVertex2f(0.6f,0.6f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.6f,0.4f);
	glVertex2f(0.4f,0.4f);
	glVertex2f(0.4f,0.2f);
	glVertex2f(0.6f,0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.6f,0.0f);
	glVertex2f(0.4f,0.0f);
	glVertex2f(0.4f,-0.2f);
	glVertex2f(0.6f,-0.2f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.6f,-0.4f);
	glVertex2f(0.4f,-0.4f);
	glVertex2f(0.4f,-0.6f);
	glVertex2f(0.6f,-0.6f);

	glEnd();

	//First Row
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.6f,0.6f);
	glVertex2f(-0.6f,0.4f);
	glVertex2f(-0.4f,0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.4f,0.6f);
	glVertex2f(-0.6f,0.6f);
	glVertex2f(-0.6f,0.4f);
	glVertex2f(-0.4f,0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.0f,0.6f);
	glVertex2f(-0.2f,0.6f);
	glVertex2f(-0.2f,0.4f);
	glVertex2f(-0.0f,0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.4f,0.6f);
	glVertex2f(0.2f,0.6f);
	glVertex2f(0.2f,0.4f);
	glVertex2f(0.4f,0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.8f,0.6f);
	glVertex2f(0.6f,0.6f);
	glVertex2f(0.6f,0.4f);
	glVertex2f(0.8f,0.4f);

	glEnd();

	//2nd Row
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.4f,0.2f);
	glVertex2f(-0.6f,0.2f);
	glVertex2f(-0.6f,0.0f);
	glVertex2f(-0.4f,0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.0f,0.2f);
	glVertex2f(-0.2f,0.2f);
	glVertex2f(-0.2f,0.0f);
	glVertex2f(0.0f,0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.4f,0.2f);
	glVertex2f(0.2f,0.2f);
	glVertex2f(0.2f,0.0f);
	glVertex2f(0.4f,0.0f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.8f,0.2f);
	glVertex2f(0.6f,0.2f);
	glVertex2f(0.6f,0.0f);
	glVertex2f(0.8f,0.0f);

	glEnd();

	//3rd Row
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.4f,-0.2f);
	glVertex2f(-0.6f,-0.2f);
	glVertex2f(-0.6f,-0.4f);
	glVertex2f(-0.4f,-0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.0f,-0.2f);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(-0.2f,-0.4f);
	glVertex2f(0.0f,-0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.4f,-0.2f);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.2f,-0.4f);
	glVertex2f(0.4f,-0.4f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.8f,-0.2f);
	glVertex2f(0.6f,-0.2f);
	glVertex2f(0.6f,-0.4f);
	glVertex2f(0.8f,-0.4f);

	glEnd();

	//4th Row
	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(-0.4f,-0.6f);
	glVertex2f(-0.6f,-0.6f);
	glVertex2f(-0.6f,-0.8f);
	glVertex2f(-0.4f,-0.8f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.0f,-0.6f);
	glVertex2f(-0.2f,-0.6f);
	glVertex2f(-0.2f,-0.8f);
	glVertex2f(0.0f,-0.8f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.4f,-0.6f);
	glVertex2f(0.2f,-0.6f);
	glVertex2f(0.2f,-0.8f);
	glVertex2f(0.4f,-0.8f);

	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(255,255,255); //white

	glVertex2f(0.8f,-0.6f);
	glVertex2f(0.6f,-0.6f);
	glVertex2f(0.6f,-0.8f);
	glVertex2f(0.8f,-0.8f);

	glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("8x8 Chess Board");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}