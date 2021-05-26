#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;



float _move = 0.0f;
float _move2=0.0f;



void box1(){
    glColor3d(0,0.5,0.5);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move2, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.2f);
        glVertex2f(0.6f, 0.2);
    glEnd();
    glPopMatrix();
}
void box2(){
    glColor3d(0,0.5,0.5);
    glLoadIdentity(); //Reset the drawing perspective
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-1.0f, 0.6);
    glEnd();
    glPopMatrix();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
     box1();
     box2();
    glutSwapBuffers();
}

void update(int value) {
    _move += .01;
    if(_move > 1.7)
    {
        _move = -1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
}
void update2(int value) {
    _move2 -= .01;
    if(_move2 < -1.7)
    {
        _move2 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, update2, 0); //Notify GLUT to call update again in 25 milliseconds
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Transformation Example");
    glutDisplayFunc(display);
    glutTimerFunc(20, update, 0); //Add a timer
    glutTimerFunc(20, update2, 0); //Add a timer
    glutMainLoop();
    return 0;
}