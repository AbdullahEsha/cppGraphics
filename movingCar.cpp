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
float _move = 0.0f;

void circle(GLfloat x, GLfloat y, GLfloat r){
       int i;
       //GLfloat x1=-0.75f; GLfloat y1=0.88f; GLfloat radius1 =0.045f;
       int triangleAmount = 100; //# of triangles used to draw circle
       GLfloat twicePi = 2.0f * PI;
       glBegin(GL_TRIANGLE_FAN);
       //glColor3ub(0, 0, 0);
       glVertex2f(x, y); // center of circle
       for(i = 0; i <= triangleAmount;i++) {
       glVertex2f(
          x+(r*cos(i * twicePi / triangleAmount)),
          y+(r*sin(i * twicePi / triangleAmount))
                  );
       }
       glEnd();
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void windmill(){
    glPushMatrix();
    glTranslatef(_move, 0.0f, 0.0f);
    glBegin(GL_POLYGON); // car body
    glColor3f(0.0f, 0.7f, 0.7f);
    glVertex2f(-0.7f,-0.5f);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.65, -0.3);
    glVertex2f(-0.6, -0.1);
    glVertex2f(-0.2, -0.1);
    glVertex2f(0.0, -0.3);
    glVertex2f(0.2, -0.35);
    glVertex2f(0.29, -0.5);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.6f, 0.6f);
    glVertex2f(-0.63, -0.3);
    glVertex2f(-0.58, -0.12);
    glVertex2f(-0.22, -0.12);
    glVertex2f(-0.02, -0.3);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    circle(-0.5,-0.5,0.13);
    circle(0.0,-0.5,0.13);

    glPushMatrix(); //front wheel
    glTranslatef(0.0,-0.5,0);
    glRotatef(rotatei,0,0.0,0.1);//i=how many degree you want to rotate around an axis

    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0,0.0,0.11);

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05, 0.1);
    glVertex2f(0.05, 0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.1, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05, -0.1);
    glVertex2f(0.05,-0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05,0.1);
    glVertex2f(0.1,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05,0.1);
    glVertex2f(-0.1,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05,-0.1);
    glVertex2f(-0.1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05,-0.1);
    glVertex2f(0.1,-0.05);
    glEnd();

    glPopMatrix();
    rotatei-=0.01f;
    glLoadIdentity();

    glPushMatrix(); //back wheel
    glTranslatef(_move, 0.0f, 0.0f);
    glTranslatef(-0.5,-0.5,0);
    glRotatef(rotatei,0,0.0,0.1);//

    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0,0.0,0.11);

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.05);
    glVertex2f(-0.1, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05, 0.1);
    glVertex2f(0.05, 0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, -0.05);
    glVertex2f(0.1, 0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05, -0.1);
    glVertex2f(0.05,-0.1);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05,0.1);
    glVertex2f(0.1,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05,0.1);
    glVertex2f(-0.1,0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.05,-0.1);
    glVertex2f(-0.1,-0.05);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.05,-0.1);
    glVertex2f(0.1,-0.05);
    glEnd();
    glPopMatrix();
    rotatei-=0.01f;
    glLoadIdentity();

}
void update(int value) {
    _move += .01;
    if(_move > 1.3)
    {
        _move = -1.0;
    }
    glutPostRedisplay(); //Notify GLUT that the display has changed
    glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
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
    glutCreateWindow("Car");
    glutDisplayFunc(display);
    glutIdleFunc(Idle);
    glutTimerFunc(20,update,0); //Add a timer
    glutMainLoop();
    return 0;
}