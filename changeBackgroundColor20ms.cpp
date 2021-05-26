#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat colorchange = 0.0f;
GLfloat increment = 0.01f;
GLfloat speed = 0.02f;

void box1(){
    glColor3d(0,0.5,0.5);
    glBegin(GL_QUADS);
        glVertex2f(0.6f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(1.0f, 0.2f);
        glVertex2f(0.6f, 0.2);
    glEnd();
}

void box2(){
    glColor3d(0,0.5,0.5);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, 0.4f);
        glVertex2f(-0.7f, 0.4f);
        glVertex2f(-0.7f, 0.6f);
        glVertex2f(-1.0f, 0.6);
    glEnd();
}

void update(int value) {
    if(position1 <-3.0)
        position1 = 2.0f;
    position1 -= speed;
    if(position2 >3.0)
        position2 = -2.0f;
    position2 += speed;
    if(colorchange >1.0)
        colorchange = 0.0f;
    colorchange += increment;
    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    box2();
    glPopMatrix();

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glClearColor(colorchange, colorchange, 0.0, 1.0f);
    glTranslatef(position1,0.0f, 0.0f);
    box1();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(600, 350);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Box Animation");
   glutDisplayFunc(display);
   glutTimerFunc(100, update, 0);
   glutMainLoop();
   return 0;
}