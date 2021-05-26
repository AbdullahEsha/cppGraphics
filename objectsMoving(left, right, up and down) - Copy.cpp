#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;

float _move = 0.0f;
float _move1 = 0.0f;
float _move3 = 0.0f;

void update1(int value) {
    _move -= .02;
    if(_move< -1.3)
    {
        _move = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update2(int value) {
    _move1 -= .02;
    if(_move1< -1.3)
    {
        _move1 = 1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, update2, 0); //Notify GLUT to call update again in 25 milliseconds
}

void update3(int value) {
     _move3 += .02;
    if(_move3> 1.3)
    {
        _move3 = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, update3, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void update4(int value) {
    _move -= .02;
    if(_move>1.3)
    {
        _move = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, update1, 0); //Notify GLUT to call update again in 25 milliseconds
}

void box1(){
    glPushMatrix();
	glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(0,0.5,0.5);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.1f, 0.2);
	glEnd();
    glPopMatrix();
    glFlush();
}
void box2(){
    glPushMatrix();
	glTranslatef(0.0f, _move1, 0.0f);
    glBegin(GL_QUADS);
    glColor3d(1,0.5,0.5);
        glVertex2f(0.1f, 0.0f);
        glVertex2f(0.5f, 0.0f);
        glVertex2f(0.5f, 0.2f);
        glVertex2f(0.1f, 0.2);
	glEnd();
    glPopMatrix();
    glFlush();
}

void box3(){
   glPushMatrix();
   glTranslatef(0.0f,_move3, 0.0f);
   glBegin(GL_QUADS);
   glColor3d(0,0.0,0.5);
       glVertex2f(-0.2f, -0.2f);
       glVertex2f( 0.2f, -0.2f);
       glVertex2f( 0.2f, 0.2f);
       glVertex2f(-0.2f, 0.2f);
   glEnd();
   glPopMatrix();
   glFlush();
}

void box4(){
   glPushMatrix();
   glTranslatef(_move3,0.0f,  0.0f);
   glBegin(GL_QUADS);
   glColor3d(0,0.5,0.0);
       glVertex2f(-0.1f, -0.1f);
       glVertex2f( 0.1f, -0.1f);
       glVertex2f( 0.1f, 0.1f);
       glVertex2f(-0.1f, 0.1f);
   glEnd();
   glPopMatrix();
   glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    box1();
    box2();
    box3();
    box4();
}

int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitWindowSize(620, 620);
glutInitWindowPosition(50, 50);
glutCreateWindow("Four Object");
glutDisplayFunc(display);
glutTimerFunc(50, update1, 0);
glutTimerFunc(50, update2, 0);
glutTimerFunc(50, update3, 0);
glutTimerFunc(50, update4, 0);
glutMainLoop();
return 0;
}