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

float _moveAll = 0.0f;
bool rainday = false;
GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.03f;
bool birdCtrl = false;
GLfloat rotatei = 0.0f;

GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.01f;

float day3 = 0.0f;
float nytground = 0.3;
float treeCtrl = 0.5;
float hillCtrl = 0.27;
float skyCtrl = 0.2;
float moonCtrl = 0.2;
float cloudCtrl = 0.7;
bool nyt = true;
bool stopAll = true;
bool rt = true;


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
void Idle(){
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void windmill(){
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(_moveAll,0.8,0);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3ub(117, 117, 117);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, -0.28);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(_moveAll,0.8,0);
    glScalef(0.5f, 0.5f, 0.0f);
    if(rt){
    glRotatef(rotatei,0,0.0,0.1);//i=how many degree you want to rotate around an axis
    }
    // T 1
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.2, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.2, 0.1);
    glEnd();

    // T 2
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, 0.2);
    glVertex2f(0, 0.2);
    glEnd();

    // T 3
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0);
    glEnd();

    // T 4
    glBegin(GL_TRIANGLES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.2);
    glVertex2f(0, -0.2);
    glEnd();
    glPopMatrix();
    if(rt){
    rotatei+=0.01f;
    }
}
void ground(){
    glBegin(GL_QUADS); // near the road silver ground
    glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(-1,0.5);
       glVertex2f(1,0.5);
       glVertex2f(1,0.4);
       glVertex2f(-1,0.4);
       glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(-1.0,1.1);
       glVertex2f(1,1.1);
       glVertex2f(1,0.5);
       glVertex2f(-1.0,0.5);
       glEnd();
}

void hill(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glBegin(GL_TRIANGLES); //it is the most left hill
    glColor3f(0.0f, hillCtrl, 0.0f);
       glVertex2f(-2.2,1.1);
       glVertex2f(-1.7,1.1);
       glVertex2f(-1.9,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.9,1.1);
       glVertex2f(-1.5,1.1);
       glVertex2f(-1.7,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.8,1.1);
       glVertex2f(-1.3,1.1);
       glVertex2f(-1.45,1.7);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.45,1.1);
       glVertex2f(-1.0,1.1);
       glVertex2f(-1.3,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.3,1.1);
       glVertex2f(-0.9,1.1);
       glVertex2f(-1.1,1.7);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-1.1,1.1);
       glVertex2f(-0.6,1.1);
       glVertex2f(-0.9,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-0.9,1.1);
       glVertex2f(-0.5,1.1);
       glVertex2f(-0.7,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-0.75,1.1);
       glVertex2f(-0.35,1.1);
       glVertex2f(-0.5,1.7);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-0.5,1.1);
       glVertex2f(-0.1,1.1);
       glVertex2f(-0.3,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-0.3,1.1);
       glVertex2f(0.05,1.1);
       glVertex2f(-0.15,1.55);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(-0.15,1.1);
       glVertex2f(0.25,1.1);
       glVertex2f(0.1,1.65);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(0.1,1.1);
       glVertex2f(0.45,1.1);
       glVertex2f(0.25,1.8);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(0.2,1.1);
       glVertex2f(0.6,1.1);
       glVertex2f(0.45,1.65);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(0.35,1.1);
       glVertex2f(0.85,1.1);
       glVertex2f(0.65,1.55);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(0.65,1.1);
       glVertex2f(1.15,1.1);
       glVertex2f(0.85,1.75);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(0.85,1.1);
       glVertex2f(1.25,1.1);
       glVertex2f(1.05,1.65);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(1.05,1.1);
       glVertex2f(1.45,1.1);
       glVertex2f(1.25,1.5);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(1.25,1.1);
       glVertex2f(1.65,1.1);
       glVertex2f(1.45,1.75);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(1.45,1.1);
       glVertex2f(1.85,1.1);
       glVertex2f(1.6,1.6);
       glEnd();
    glBegin(GL_TRIANGLES);
       glVertex2f(1.6,1.1);
       glVertex2f(2.2,1.1);
       glVertex2f(1.9,1.7);
       glEnd();
    glPopMatrix();
}
void water(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glBegin(GL_QUAD_STRIP); //water
    glColor3f(0.0f, 0.7f, 1.0f);
       glVertex2f(0.2,0.0);
       glVertex2f(0.2,-0.7);
       glVertex2f(-2,0.0);
       glVertex2f(-2.0,-0.7);
       glEnd();
    glPopMatrix();
}
void ground2(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glBegin(GL_QUAD_STRIP); //ground
    glColor3f(0.0f, 0.3f, 0.0f);
       glVertex2f(0.5,0.0);
       glVertex2f(0.5,-0.7);
       glVertex2f(2,0.0);
       glVertex2f(2.0,-0.7);
       glEnd();
    glPopMatrix();
}
void road(){
    glBegin(GL_QUADS);
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f(-1,0.4);
       glVertex2f(1,0.4);
       glVertex2f(1,0.0);
       glVertex2f(-1,0.0);
       glEnd();

    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

    glLineWidth(8.0);
    glBegin(GL_LINES);
       glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(-2.0,0.2);
       glVertex2f(2.0,0.2);

       glVertex2f(-2.0,0.0);
       glVertex2f(0.2,0.0);

       glVertex2f(0.5,0.0);
       glVertex2f(2.0,0.0);

       glVertex2f(0.2,0.015);
       glVertex2f(0.2,-0.7);

       glVertex2f(0.5,0.015);
       glVertex2f(0.5,-0.7);

       glVertex2f(0.35,-0.15); // road 2 line
       glVertex2f(0.35,-0.7);

       glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
       glColor3f(0.0f, 0.3f, 0.0f);
       glVertex2f(-2.0,0.2);
       glVertex2f(2.0,0.2);

       glVertex2f(0.35,-0.15); //road 2 green line
       glVertex2f(0.35,-0.7);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
       glVertex2f(0.425,-0.2);
       glVertex2f(0.425,-0.4);

       glVertex2f(-1.8,0.1);
       glVertex2f(-2.0,0.1);

       glVertex2f(-1.4,0.1);
       glVertex2f(-1.6,0.1);

       glVertex2f(-1.0,0.1);
       glVertex2f(-1.2,0.1);

       glVertex2f(-0.8,0.1);
       glVertex2f(-0.6,0.1);

       glVertex2f(-0.3,0.1);
       glVertex2f(-0.1,0.1);

       glVertex2f(0.2,0.1);
       glVertex2f(0.4,0.1);

       glVertex2f(0.7,0.1);
       glVertex2f(0.9,0.1);

       glVertex2f(1.1,0.1);
       glVertex2f(1.3,0.1);

       glVertex2f(1.5,0.1);
       glVertex2f(1.7,0.1);

       glVertex2f(1.9,0.1);
       glVertex2f(2.0,0.1);//road lower line

       glVertex2f(-1.6,0.3); // road upper lines
       glVertex2f(-1.8,0.3);

       glVertex2f(-1.2,0.3);
       glVertex2f(-1.4,0.3);

       glVertex2f(-0.8,0.3);
       glVertex2f(-1.0,0.3);

       glVertex2f(-0.6,0.3);
       glVertex2f(-0.4,0.3);

       glVertex2f(-0.1,0.3);
       glVertex2f(0.1,0.3);

       glVertex2f(0.4,0.3);
       glVertex2f(0.6,0.3);

       glVertex2f(0.8,0.3);
       glVertex2f(1.0,0.3);

       glVertex2f(1.2,0.3);
       glVertex2f(1.4,0.3);

       glVertex2f(1.8,0.3);
       glVertex2f(1.6,0.3);


       glVertex2f(0.275,0.1); //road2 lines
       glVertex2f(0.275,-0.1);

       glVertex2f(0.275,-0.4); //road2 lines
       glVertex2f(0.275,-0.6);

       glVertex2f(-1.6,-0.2); //water lines
       glVertex2f(-1.8,-0.2);

       glVertex2f(-1.1,-0.2);
       glVertex2f(-1.3,-0.2);

       glVertex2f(-0.9,-0.2);
       glVertex2f(-0.7,-0.2);

       glVertex2f(-0.3,-0.2);
       glVertex2f(-0.1,-0.2);

       glVertex2f(-1.7,-0.4);
       glVertex2f(-1.9,-0.4);

       glVertex2f(-1.2,-0.4);
       glVertex2f(-1.4,-0.4);

       glVertex2f(-0.8,-0.4);
       glVertex2f(-1.0,-0.4);

       glVertex2f(-0.6,-0.4);
       glVertex2f(-0.4,-0.4);

       glVertex2f(-0.15,-0.4);
       glVertex2f(0.1,-0.4);

       glEnd();
    glPopMatrix();
}
void road2(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	   glVertex2f(0.2f, -0.7f);
       glVertex2f(0.2f, 0.02f);
       glVertex2f(0.5f, 0.02f);
	   glVertex2f(0.5f, -0.7f);
	   glEnd();
    glPopMatrix();
}
void house(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

	glPushMatrix();
	glTranslatef(-0.5,0.0f,0.0f);
    glBegin(GL_QUAD_STRIP);
	glColor3f(0.5f, 1.0f, 0.5f);
       glVertex2f(-0.76f, 0.55f);
       glVertex2f(-0.6f, 0.55f);
	   glVertex2f(-0.76f, 1.2f);
	   glVertex2f(-0.6f, 1.2f);
	   glEnd();

	glLineWidth(10.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.74,1.15);
       glVertex2f(-0.715,1.15);

       glVertex2f(-0.665,1.15);
       glVertex2f(-0.62,1.15);

       glVertex2f(-0.74,1.05);
       glVertex2f(-0.715,1.05);

       glVertex2f(-0.74,0.95);
       glVertex2f(-0.715,0.95);
       glEnd();

    glBegin(GL_QUAD_STRIP);
	glColor3f(0.5f, 0.5f, 1.0f);
	glVertex2f(-0.9f, 0.5f);
	glVertex2f(-0.7f, 0.5f);
	glVertex2f(-0.9f, 0.9f);
	glVertex2f(-0.7f, 0.9f);
	glEnd();

	glLineWidth(10.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.87,0.8);
       glVertex2f(-0.84,0.8);

       glVertex2f(-0.87,0.7);
       glVertex2f(-0.84,0.7);

       glVertex2f(-0.87,0.6);
       glVertex2f(-0.84,0.6);

       glVertex2f(-0.81,0.8);
       glVertex2f(-0.78,0.8);

       glVertex2f(-0.81,0.7);
       glVertex2f(-0.78,0.7);

       glVertex2f(-0.81,0.6);
       glVertex2f(-0.78,0.6);

       glVertex2f(-0.75,0.8);
       glVertex2f(-0.72,0.8);

       glVertex2f(-0.75,0.7);
       glVertex2f(-0.72,0.7);

       glVertex2f(-0.735,0.59);
       glVertex2f(-0.735,0.5);
       glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	   glVertex2f(-0.58f, 0.51f);
	   glVertex2f(-0.58f, 1.1f);
	   glVertex2f(-0.69f, 1.1f);
	   glVertex2f(-0.69f, 0.51f);
	   glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.68,1.0);
       glVertex2f(-0.65,1.0);

       glVertex2f(-0.68,0.9);
       glVertex2f(-0.65,0.9);

       glVertex2f(-0.68,0.8);
       glVertex2f(-0.65,0.8);

       glVertex2f(-0.68,0.7);
       glVertex2f(-0.65,0.7);

       glVertex2f(-0.68,0.6);
       glVertex2f(-0.65,0.6);

       glVertex2f(-0.62,1.0);
       glVertex2f(-0.59,1.0);

       glVertex2f(-0.62,0.9);
       glVertex2f(-0.59,0.9);

       glVertex2f(-0.62,0.8);
       glVertex2f(-0.59,0.8);

       glVertex2f(-0.62,0.7);
       glVertex2f(-0.59,0.7);

       glVertex2f(-0.61,0.61);
       glVertex2f(-0.61,0.51);

       glEnd();

	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.5f);
	   glVertex2f(-0.5f, 0.52f);
	   glVertex2f(-0.5f, 0.75f);
	   glVertex2f(-0.35f, 0.75f);
	   glVertex2f(-0.35f, 0.52f);
	   glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.0f, 0.6f);
	   glVertex2f(-0.6f, 0.5f);
	   glVertex2f(-0.6f, 0.95f);
	   glVertex2f(-0.45f, 0.95f);
	   glVertex2f(-0.45f, 0.5f);
	   glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.525,0.9);
       glVertex2f(-0.47,0.9);

       glVertex2f(-0.525,0.8);
       glVertex2f(-0.47,0.8);

       glVertex2f(-0.525,0.7);
       glVertex2f(-0.47,0.7);

       glVertex2f(-0.525,0.6);
       glVertex2f(-0.47,0.6);

       glVertex2f(-0.55,0.9);
       glVertex2f(-0.58,0.9);

       glVertex2f(-0.55,0.8);
       glVertex2f(-0.58,0.8);

       glVertex2f(-0.55,0.7);
       glVertex2f(-0.58,0.7);

       glVertex2f(-0.5675,0.6);
       glVertex2f(-0.5675,0.5);

       glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.4,0.7);
       glVertex2f(-0.36,0.7);

       glVertex2f(-0.4,0.62);
       glVertex2f(-0.36,0.62);

       glVertex2f(-0.43,0.59);
       glVertex2f(-0.43,0.52);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 0.0f);
       glVertex2f(-0.43,0.74);
       glVertex2f(-0.43,0.62);
       glEnd();

    glPushMatrix();
	glTranslatef(0.55,0.0f,0.0f);
   glBegin(GL_QUAD_STRIP);
	glColor3f(0.5f, 1.0f, 0.5f);
       glVertex2f(-0.76f, 0.55f);
       glVertex2f(-0.6f, 0.55f);
	   glVertex2f(-0.76f, 1.2f);
	   glVertex2f(-0.6f, 1.2f);
	   glEnd();

	glLineWidth(10.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.74,1.15);
       glVertex2f(-0.715,1.15);

       glVertex2f(-0.665,1.15);
       glVertex2f(-0.62,1.15);

       glVertex2f(-0.74,1.05);
       glVertex2f(-0.715,1.05);

       glVertex2f(-0.74,0.95);
       glVertex2f(-0.715,0.95);
       glEnd();

    glBegin(GL_QUAD_STRIP);
	glColor3f(0.5f, 0.5f, 1.0f);
	glVertex2f(-0.9f, 0.5f);
	glVertex2f(-0.7f, 0.5f);
	glVertex2f(-0.9f, 0.9f);
	glVertex2f(-0.7f, 0.9f);
	glEnd();

	glLineWidth(10.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.87,0.8);
       glVertex2f(-0.84,0.8);

       glVertex2f(-0.87,0.7);
       glVertex2f(-0.84,0.7);

       glVertex2f(-0.87,0.6);
       glVertex2f(-0.84,0.6);

       glVertex2f(-0.81,0.8);
       glVertex2f(-0.78,0.8);

       glVertex2f(-0.81,0.7);
       glVertex2f(-0.78,0.7);

       glVertex2f(-0.81,0.6);
       glVertex2f(-0.78,0.6);

       glVertex2f(-0.75,0.8);
       glVertex2f(-0.72,0.8);

       glVertex2f(-0.75,0.7);
       glVertex2f(-0.72,0.7);

       glVertex2f(-0.735,0.59);
       glVertex2f(-0.735,0.5);
       glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.5f, 1.0f);
	   glVertex2f(-0.58f, 0.51f);
	   glVertex2f(-0.58f, 1.1f);
	   glVertex2f(-0.69f, 1.1f);
	   glVertex2f(-0.69f, 0.51f);
	   glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.68,1.0);
       glVertex2f(-0.65,1.0);

       glVertex2f(-0.68,0.9);
       glVertex2f(-0.65,0.9);

       glVertex2f(-0.68,0.8);
       glVertex2f(-0.65,0.8);

       glVertex2f(-0.68,0.7);
       glVertex2f(-0.65,0.7);

       glVertex2f(-0.68,0.6);
       glVertex2f(-0.65,0.6);

       glVertex2f(-0.62,1.0);
       glVertex2f(-0.59,1.0);

       glVertex2f(-0.62,0.9);
       glVertex2f(-0.59,0.9);

       glVertex2f(-0.62,0.8);
       glVertex2f(-0.59,0.8);

       glVertex2f(-0.62,0.7);
       glVertex2f(-0.59,0.7);

       glVertex2f(-0.61,0.61);
       glVertex2f(-0.61,0.51);

       glEnd();

	glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.5f);
	   glVertex2f(-0.5f, 0.52f);
	   glVertex2f(-0.5f, 0.75f);
	   glVertex2f(-0.35f, 0.75f);
	   glVertex2f(-0.35f, 0.52f);
	   glEnd();



	glBegin(GL_QUADS);
	glColor3f(0.5f, 0.0f, 0.6f);
	   glVertex2f(-0.6f, 0.5f);
	   glVertex2f(-0.6f, 0.95f);
	   glVertex2f(-0.45f, 0.95f);
	   glVertex2f(-0.45f, 0.5f);
	   glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.525,0.9);
       glVertex2f(-0.47,0.9);

       glVertex2f(-0.525,0.8);
       glVertex2f(-0.47,0.8);

       glVertex2f(-0.525,0.7);
       glVertex2f(-0.47,0.7);

       glVertex2f(-0.525,0.6);
       glVertex2f(-0.47,0.6);

       glVertex2f(-0.55,0.9);
       glVertex2f(-0.58,0.9);

       glVertex2f(-0.55,0.8);
       glVertex2f(-0.58,0.8);

       glVertex2f(-0.55,0.7);
       glVertex2f(-0.58,0.7);

       glVertex2f(-0.5675,0.6);
       glVertex2f(-0.5675,0.5);

       glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.4,0.7);
       glVertex2f(-0.36,0.7);

       glVertex2f(-0.4,0.62);
       glVertex2f(-0.36,0.62);

       glVertex2f(-0.43,0.59);
       glVertex2f(-0.43,0.52);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, day3);
       glVertex2f(-0.43,0.74);
       glVertex2f(-0.43,0.62);
       glEnd();
    glPopMatrix();
}
void tree(){
    glPushMatrix(); //from the left
	glTranslatef(_moveAll,0.3f,0.0f);
	glScalef(0.5f, 0.5f, 0.0f);

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();

    glColor3f(0.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);

    glPushMatrix();
	glTranslatef(0.2,0.1f,0.0f);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();

    glColor3f(0.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);

    glPushMatrix();
	glTranslatef(0.25,-0.1f,0.0f);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();

    glColor3f(0.0f, treeCtrl, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
    glPopMatrix();
}

void tree2(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

    glPushMatrix();
	glTranslatef(0.0f, -0.2f, 0.0f);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.9f, 1.0f);
    glVertex2f(0.8f, 1.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.72f, 1.08f);
    glVertex2f(0.88f, 1.08f);
    glVertex2f(0.8f, 1.18f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.74f, 1.15f);
    glVertex2f(0.86f, 1.15f);
    glVertex2f(0.8f, 1.25f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
	glTranslatef(_moveAll,-0.02f,0.0f);

    glPushMatrix();
	glTranslatef(0.15f, -0.2f, 0.0f);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.7f, 1.0f);
    glVertex2f(0.9f, 1.0f);
    glVertex2f(0.8f, 1.1f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.72f, 1.08f);
    glVertex2f(0.88f, 1.08f);
    glVertex2f(0.8f, 1.18f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.74f, 1.15f);
    glVertex2f(0.86f, 1.15f);
    glVertex2f(0.8f, 1.25f);
    glEnd();
    glPopMatrix();
}

void tree3(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

    glPushMatrix();
	glTranslatef(0.5f, -0.2f, 0.0f);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, treeCtrl, 0.0f);
    glVertex2f(0.74f, 0.9f);
    glVertex2f(0.86f, 0.9f);
    glVertex2f(0.8f, 1.3f);
    glEnd();
    glPopMatrix();
}
void sky(){
    glBegin(GL_QUADS);//sky
	glColor3f(skyCtrl, skyCtrl, skyCtrl);
	glVertex2f(-1.0f, 1.1f);
	glVertex2f(-1.0f, 2.8f);
	glVertex2f(1.0f, 2.8f);
	glVertex2f(1.0f, 1.1f);
	glEnd();
}
void moon(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glColor3f(0.9f, 0.9f, 0.9f);
    circle(-0.75f, 1.9f, 0.1f);
    glColor3f(moonCtrl, moonCtrl, 0.2f);
    circle(-0.73f, 1.91f, 0.09f);
    glPopMatrix();
}
void clouds(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glColor3f(cloudCtrl, cloudCtrl, cloudCtrl);
    circle(0.0f,1.95f,0.1f);
    circle(-0.16f,1.95f,0.15f);
    circle(-0.26f,1.95,0.13f);
    circle(-0.37f,1.95f,0.1f);

    glPushMatrix();
	glTranslatef(0.8f,0.0f,0.0f);
    circle(0.0f,1.95f,0.1f);
    circle(-0.16f,1.95f,0.15f);
    circle(-0.3f,1.95,0.13f);
    glPopMatrix();
}
void banch(){
    glPushMatrix();
	glTranslatef(_moveAll,-1.1f,0.0f);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.9f, 0.65f);
    glVertex2f(1.0f, 0.65f);
    glVertex2f(0.87f, 0.63f);
    glVertex2f(1.03f, 0.63f);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.885f, 0.55f);
    glVertex2f(0.885f, 0.625f);

    glVertex2f(1.015f, 0.55f);
    glVertex2f(1.015f, 0.625f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.87f, 0.625f);
    glVertex2f(1.03f, 0.625f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.91f, 0.65f);
    glVertex2f(0.91f, 0.75f);

    glVertex2f(0.99f, 0.65f);
    glVertex2f(0.99f, 0.75f);

    glVertex2f(0.9f, 0.68f);
    glVertex2f(1.0f, 0.68f);

    glVertex2f(0.9f, 0.70f);
    glVertex2f(1.0f, 0.70f);

    glVertex2f(0.9f, 0.72f);
    glVertex2f(1.0f, 0.72f);

    glVertex2f(0.9f, 0.65f);
    glVertex2f(0.9f, 0.58f);

    glVertex2f(1.0f, 0.65f);
    glVertex2f(1.0f, 0.58f);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.87f, 0.63f);
    glVertex2f(1.03f, 0.63f);
    glEnd();

    glPushMatrix();
	glTranslatef(0.5f,0.1f,0.0f);
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.9f, 0.65f);
    glVertex2f(1.0f, 0.65f);
    glVertex2f(0.87f, 0.63f);
    glVertex2f(1.03f, 0.63f);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.885f, 0.55f);
    glVertex2f(0.885f, 0.625f);

    glVertex2f(1.015f, 0.55f);
    glVertex2f(1.015f, 0.625f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.5f, 0.5f, 0.0f);
    glVertex2f(0.87f, 0.625f);
    glVertex2f(1.03f, 0.625f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.91f, 0.65f);
    glVertex2f(0.91f, 0.75f);

    glVertex2f(0.99f, 0.65f);
    glVertex2f(0.99f, 0.75f);

    glVertex2f(0.9f, 0.68f);
    glVertex2f(1.0f, 0.68f);

    glVertex2f(0.9f, 0.70f);
    glVertex2f(1.0f, 0.70f);

    glVertex2f(0.9f, 0.72f);
    glVertex2f(1.0f, 0.72f);

    glVertex2f(0.9f, 0.65f);
    glVertex2f(0.9f, 0.58f);

    glVertex2f(1.0f, 0.65f);
    glVertex2f(1.0f, 0.58f);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.87f, 0.63f);
    glVertex2f(1.03f, 0.63f);
    glEnd();
    glPopMatrix();
}

void lamppost(){
    glPushMatrix();
	glTranslatef(_moveAll,-1.15f,0.0f);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 0.52f);

    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);

    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);

    glVertex2f(0.68f, 1.0f);
    glVertex2f(0.75f, 1.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.75f, 1.03f);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.76f, 1.03f);
    glVertex2f(0.79f, 0.97f);
    glEnd();

    if(nyt){
        glBegin(GL_QUAD_STRIP);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(0.75f, 0.97f);
        glVertex2f(0.79f, 0.97f);
        glVertex2f(0.75f, 0.7f);
        glVertex2f(0.9f, 0.7f);
        glEnd();
    }

    glPushMatrix();
	glTranslatef(0.5f,0.1f,0.0f);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 0.52f);

    glEnd();
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);

    glVertex2f(0.7f, 0.65f);
    glVertex2f(0.7f, 1.0f);

    glVertex2f(0.68f, 1.0f);
    glVertex2f(0.75f, 1.0f);
    glEnd();

    glBegin(GL_QUAD_STRIP);
    glVertex2f(0.75f, 1.03f);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.76f, 1.03f);
    glVertex2f(0.79f, 0.97f);
    glEnd();
    if(nyt){
    glBegin(GL_QUAD_STRIP);
    glColor3ub(200,215,50);
    glVertex2f(0.75f, 0.97f);
    glVertex2f(0.79f, 0.97f);
    glVertex2f(0.75f, 0.7f);
    glVertex2f(0.9f, 0.7f);
    glEnd();
    }

    glPopMatrix();
}
void lamppost2(){
    glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 1.0f);
       glVertex2f(0.2,-0.2);
       glVertex2f(0.23,-0.17);
       glEnd();

    glLineWidth(13.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.5f, 1.0f);
       glVertex2f(0.23,-0.17);
       glVertex2f(0.33,-0.17);
       glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    circle(0.25f,-0.17f,0.015f);
    glColor3f(0.0f, 1.0f, 0.0f);
    circle(0.279f,-0.17f,0.015f);
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(0.312f,-0.17f,0.015f);
    glPopMatrix();
}
void car(){
    glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.3f, 1.0f);
	glVertex2f(-0.9f, 0.255f);
	glVertex2f(-0.9f, 0.33f);
	glVertex2f(-0.87f, 0.39f);
	glVertex2f(-0.8f, 0.39f);
	glVertex2f(-0.75f, 0.32f);
	glVertex2f(-0.7f, 0.3f);
	glVertex2f(-0.7f, 0.255f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(-0.89f, 0.33f);
	glVertex2f(-0.87f, 0.38f);
	glVertex2f(-0.835f, 0.38f);
	glVertex2f(-0.835f, 0.33f);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(-0.83f, 0.33f);
	glVertex2f(-0.83f, 0.38f);
	glVertex2f(-0.8f, 0.38f);
	glVertex2f(-0.76f, 0.325f);
	glEnd();

	if(nyt){
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 1.0f, 0.2f);
	    glVertex2f(-0.7f, 0.29f);
	    glVertex2f(-0.65f, 0.22f);
	    glVertex2f(-0.53f, 0.22f);
	    glEnd();
	}

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(-0.86,0.25,0);
    if(rt){
    glRotatef(rotatei,0,0.0,0.1);//i=how many degree you want to rotate around an axis
    }

    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);

    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
	glEnd();

	glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}

	glPushMatrix();
	glTranslatef(-0.75,0.25,0);
	if(rt){
    glRotatef(rotatei,0,0.0,0.1);//i=how many degree you want to rotate around an axis
	}

    glColor3f(0.4f, 0.4f, 0.4f);
    circle(0.0f, 0.0f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(0.0f, 0.0f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(0.0f, 0.0f, 0.01f);

    glLineWidth(2.0);
    glBegin(GL_LINES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.03f, 0.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.03f, 0.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.03f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, -0.03f);
	glEnd();
	glPopMatrix();
	if(rt){
	rotatei -=0.05f;
	}
}

void ship(){
    glPushMatrix();
	glTranslatef(_moveAll,-0.5f,0.0f);
	glPushMatrix();
	glTranslatef(_moveAll,0.0f,0.0f);

	glPushMatrix();
	glTranslatef(-1.8,0.0f,0.0f);
    glBegin(GL_QUAD_STRIP);
       glColor3f(0.0f, 0.5f, 0.5f);
       glVertex2f(0.3,0.0);
       glVertex2f(0.75,0.0);
       glVertex2f(0.4,-0.1);
       glVertex2f(0.7,-0.1);

       glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(0.6,0.0);
       glVertex2f(0.7,0.0);
       glVertex2f(0.6,0.1);
       glVertex2f(0.7,0.1);

       glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(0.65,0.1);
       glVertex2f(0.69,0.1);
       glVertex2f(0.65,0.2);
       glVertex2f(0.69,0.2);
       glEnd();

    glLineWidth(5.0);
    glBegin(GL_LINES);
       glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(0.3f, 0.0f);
	   glVertex2f(0.75f, 0.0f);
	   glEnd();

    glColor3f(1.0f, 1.0f, day3);
    circle(0.67f, 0.05f, 0.015f);

    if(nyt){
    glBegin(GL_QUADS);
       glColor3f(1.0f, 1.0f, 0.0f);
       glVertex2f(0.65f,0.17f);
       glVertex2f(0.65,0.15f);
       glVertex2f(0.3,-0.05);
       glVertex2f(0.3,0.23);
       glEnd();
    }

    glPopMatrix();
}

void bird(){
    if(birdCtrl){
    glPushMatrix();
    glTranslatef(-position_bird, -0.6f, 0.0f);
    int i;

	GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
	/////2nd bird////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	/////3rd bird/////
	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
			    nnnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	////4th bird////
	GLfloat mmmmm=-0.518f; GLfloat nnnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(225, 225, 208);
		glVertex2f(mmmmm, nnnnn); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            mmmmm + (radiusmm * cos(i *  twicePi / triangleAmount)),
			    nnnnn + (radiusmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();
    glPopMatrix();
    }
}
void Rain(){
if(rainday){
    glPushMatrix();
    glTranslatef(0.0, 0.5f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0, -positionRain, 0.0f);
    GLfloat xR= -1.05;
    GLfloat yR = 2.05;

    glBegin(GL_LINES);
    glColor3ub(18, 18, 18);
    for(int i=0;i<=105;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.04);

    xR += .02;
    }
    glEnd();

    for(int j=0;j<=150;j++)
    {
    xR = -1.8;
    yR= yR-.05;
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<=250;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.04);

    xR += .02;
    }
    glEnd();
    }
    glPopMatrix();
    }
}

void updateAll(int value){
    if(stopAll){
     _moveAll -= .005;
    if(_moveAll< -1.0)
    {
        _moveAll = 1.0;
    }
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, updateAll, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds

}
void update_bird(int value){
    if(position_bird <-1.8)
    {
        position_bird = 1.2f;
    }
    position_bird -= speed_bird;

	glutTimerFunc(100, update_bird, 0);
}

void updateRain(int value) {

    if(positionRain >.14)
        {positionRain = 0.0f;}

    positionRain += speedRain;

	glutPostRedisplay();

	glutTimerFunc(100, updateRain, 0);
}

void myKeyboard (unsigned char key, int x, int y) {
    glutPostRedisplay();
    switch (key)
    {
    case 'r':
        rainday = true;
        break;
    case 't':
        rainday = false;
        break;
    case 's':
        stopAll = false;
        rt = false;
        break;
    case 'd':
        stopAll = true;
        rt = true;
        break;
    default:
    break;

    }
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			    day3 = 0.9f;
			    nytground = 0.4f;
			    treeCtrl = 0.7f;
			    hillCtrl = 0.33;
			    skyCtrl = 0.9f;
			    moonCtrl = 1.0f;
			    cloudCtrl = 1.0f;
			    nyt = false;
			    birdCtrl = true;
			}
			if (button == GLUT_RIGHT_BUTTON)
            {
                day3 = 0.0f;
                nytground = 0.3;
                treeCtrl = 0.5;
                hillCtrl = 0.27;
                skyCtrl = 0.2;
                moonCtrl = 0.2;
                cloudCtrl = 0.7;
                nyt = true;
                birdCtrl = false;
			}
	glutPostRedisplay();
}
void display() {
    glClearColor(1.0f,1.0f,1.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(0.0f, -0.55f, 0.0f);
	glScalef(1.0f, 0.65f, 0.0f);
	sky();
	moon();
	clouds();
	hill();
	ground();
	water();
	ground2();
	road2();
	road();
	tree();
	tree2();
	tree3();
	banch();
	lamppost();
	lamppost2();
	house();
	Rain();
	ship();
	car();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5f, -0.7f, 0.0f);
	windmill();
	glPopMatrix();
	bird();
	Idle();
	glFlush();  // Render now
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(1100,850);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Night Scene");
    glutDisplayFunc(display);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(handleMouse);
    glutTimerFunc(50, updateAll, 0);
    glutTimerFunc(100, update_bird, 0);
    glutTimerFunc(100, updateRain, 0);
    glutMainLoop();
    return 0;
}