#include<windows.h>
#ifdef __APPLE__
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include<math.h>
#define PI   3.14159265358979323846


void circle(GLfloat x, GLfloat y, GLfloat r){
       int i;
       //GLfloat x1=-0.75f; GLfloat y1=0.88f; GLfloat radius1 =0.045f;
       int triangleAmount = 20; //# of triangles used to draw circle
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


void ground(){
    glBegin(GL_QUADS);
      glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(-1,0.5);
       glVertex2f(1,0.5);
       glVertex2f(1,0.4);
       glVertex2f(-1,0.4);
       glEnd();
}
void water(){
    //water
   // 0.0f, 0.0f, 1.0f
    glBegin(GL_QUADS);
       glColor3f(0.0f, 0.5f, 1.0f);
       glVertex2f(-1,0.4);
       glVertex2f(1,0.4);
       glVertex2f(1,-0.7);
       glVertex2f(-1,-0.7);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
       glColor3ub(255, 255, 255);
       glVertex2f(-0.5,0.3);
       glVertex2f(-0.3,0.3);

       glVertex2f(0.0,0.3);
       glVertex2f(0.2,0.3);

       glVertex2f(0.5,0.3);
       glVertex2f(0.7,0.3);

       glVertex2f(-0.7,0.0);
       glVertex2f(-0.5,0.0);

       glVertex2f(-0.2,0.0);
       glVertex2f(0.0,0.0);

       glVertex2f(0.3,0.0);
       glVertex2f(0.5,0.0);

       glVertex2f(0.7,-0.3);
       glVertex2f(0.9,-0.3);

       glVertex2f(-0.1,-0.3);
       glVertex2f(0.1,-0.3);

       glVertex2f(-0.8,-0.3);
       glVertex2f(-0.6,-0.3);

       glEnd();
}

void sky()
{
    glBegin(GL_QUADS);      //sky
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(-1.0f, -0.3f);
	glVertex2f(1.0f, -0.3f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}
void moon()
{
    glColor3ub(200,215,50);
    circle(-0.75f, 0.6f, 0.15f);
    glColor3f(0.2f, 0.2f, 0.2f);
    circle(-0.7f, 0.62f, 0.13f);

}
void clouds(){
    glColor3ub(255, 255, 255);
    //cloud 1
    circle(0.0f,0.7f,0.1f);
    circle(-0.16f,0.7f,0.15f);
    circle(-0.26f,0.7,0.13f);
    circle(-0.37f,0.7f,0.1f);
}
void tree(){
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.0f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.5f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
}
void banch(){
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.4f, 0.65f);
    glVertex2f(0.6f, 0.65f);
    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.65f, 0.6f);
    glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.39f, 0.5f);
    glVertex2f(0.39f, 0.6f);

    glVertex2f(0.61f, 0.5f);
    glVertex2f(0.61f, 0.6f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.35f, 0.593f);
    glVertex2f(0.65f, 0.593f);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.35f, 0.6f);
    glVertex2f(0.65f, 0.6f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.43f, 0.65f);
    glVertex2f(0.43f, 0.8f);

    glVertex2f(0.57f, 0.65f);
    glVertex2f(0.57f, 0.8f);

    glVertex2f(0.4f, 0.68f);
    glVertex2f(0.6f, 0.68f);

    glVertex2f(0.4f, 0.72f);
    glVertex2f(0.6f, 0.72f);

    glVertex2f(0.4f, 0.76f);
    glVertex2f(0.6f, 0.76f);

    glVertex2f(0.42f, 0.6f);
    glVertex2f(0.42f, 0.52f);

    glVertex2f(0.58f, 0.6f);
    glVertex2f(0.58f, 0.52f);
    glEnd();

}
void lamppost(){
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.2f, 0.65f);
    glVertex2f(0.2f, 0.5f);

    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(0.2f, 0.65f);
    glVertex2f(0.2f, 1.0f);

    glVertex2f(0.2f, 0.65f);
    glVertex2f(0.2f, 1.0f);

    glVertex2f(0.18f, 1.0f);
    glVertex2f(0.25f, 1.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.25f, 1.03f);
    glVertex2f(0.25f, 0.97f);
    glVertex2f(0.26f, 1.03f);
    glVertex2f(0.29f, 0.97f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glColor3ub(200,215,50);
    glVertex2f(0.25f, 0.97f);
    glVertex2f(0.29f, 0.97f);
    glVertex2f(0.25f, 0.7f);
    glVertex2f(0.4f, 0.7f);
    glEnd();

}
void display() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
	sky();
	moon();
	clouds();
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, 0.0f);
	glScalef(1.0f, 0.65f, 0.0f);
	ground();
	water();
	tree();
	banch();
	lamppost();
	glPopMatrix();
	glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Day Night Scene");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}