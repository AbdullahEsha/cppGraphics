#include<windows.h>
#ifdef _APPLE_
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include<math.h>
#define PI   3.14159265358979323846

GLfloat rotatei = 0.0f;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void windmill(){
    glBegin(GL_QUAD_STRIP);
    glColor3ub(117, 117, 117);
    glVertex2f(-0.02, -0.5);
    glVertex2f(-0.02, 0);
    glVertex2f(0.02, -0.5);
    glVertex2f(0.02, 0);
    glEnd();

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    //glTranslatef(0.0,0.0,0);
    glRotatef(rotatei,0,0.0,0.1);//i=how many degree you want to rotate around an axis

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.2, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.2, 0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, 0.2);
    glVertex2f(0, 0.2);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.2);
    glVertex2f(0, -0.2);
    glEnd();

    glPopMatrix();
    rotatei+=0.01f;
    glLoadIdentity();
}

void display() {
    glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
	windmill();
	glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Windmill");
    glutDisplayFunc(display);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}