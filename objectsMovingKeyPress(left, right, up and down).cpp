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


float _move1 = 0.0f;
float _move2 = 0.0f;
float _move3 = 0.0f;
float _move4 = 0.0f;

float _m1 = 0.0f;
float _m2 = 0.0f;
float _m3 = 0.0f;
float _m4 = 0.0f;

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void box1(){
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(_move1,_m1,0.0f);
    glBegin(GL_QUADS);
    glColor3d(0,0.5,0.5);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.3f, 0.5);
        glVertex2f(0.3f, 0.4f);
    glEnd();
    glPopMatrix();
}

void box2(){
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(_move2,_m2,0.0f);
    glBegin(GL_QUADS);
    glColor3d(0,0.0,0.8);
        glVertex2f(-0.4f, 0.3f);
        glVertex2f(-0.4f, 0.4);
        glVertex2f(-0.1f, 0.4f);
        glVertex2f(-0.1f, 0.3f);
    glEnd();
    glPopMatrix();
}

void box3(){
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(_m3,_move3,0.0f);
    glBegin(GL_QUADS);
    glColor3d(0.5,0.0,0.0);
        glVertex2f(-0.4f, 0.5f);
        glVertex2f(-0.4f, 0.6);
        glVertex2f(-0.1f, 0.6f);
        glVertex2f(-0.1f, 0.5f);
    glEnd();
    glPopMatrix();
}

void box4(){
    glLoadIdentity();
    glPushMatrix();
    glTranslatef(_m4,_move4,0.0f);
    glBegin(GL_QUADS);
    glColor3d(0,0.5,0.0);
        glVertex2f(0.0f, 0.2f);
        glVertex2f(0.0f, 0.3f);
        glVertex2f(0.3f, 0.3);
        glVertex2f(0.3f, 0.2f);
    glEnd();
    glPopMatrix();
}

void update1(int value) {
     _m1 += .02;
    if(_m1> 1.3)
    {
        _m1 = -1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(50, update1, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void update2(int value) {
     _m2 -= .02;
    if(_m2< -1.3)
    {
        _m2 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(50, update2, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void update3(int value) {
     _m3 += .02;
    if(_m3> 1.3)
    {
        _m3 = -1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(50, update3, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void update4(int value) {
     _m4 -= .02;
    if(_m4< -1.3)
    {
        _m4 = 1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed

    glutTimerFunc(50, update4, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}


void display(){
    glClearColor(0.0f,0.0f,0.0f,0.0f);
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glTranslatef(0.0f, -0.55f, 0.0f);
    glScalef(1.0f, 0.65f, 0.0f);
    box1();
    box2();
    box3();
    box4();
    Idle();
    glFlush();  // Render now
}
void handleKeypress(unsigned char key, int x, int y){
    glutPostRedisplay();
    switch (key){
        case 'a':
            _move1 = 0.7;
            break;
        case 'b':
            _move2 = -0.6;
            break;
        case 'c':
            _move3 = 0.35;
            break;
        case 'd':
            _move4 = -0.5;
            break;
       default:
            break;
            }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Four Boxes...");
    glutDisplayFunc(display);
    glutTimerFunc(50, update1, 0);
    glutTimerFunc(50, update2, 0);
    glutTimerFunc(50, update3, 0);
    glutTimerFunc(50, update4, 0);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}