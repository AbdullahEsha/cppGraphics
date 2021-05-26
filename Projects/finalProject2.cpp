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

bool rainday = false;
GLfloat position_bird = 0.0f;
GLfloat speed_bird = 0.03f;
bool birdCtrl = false;
GLfloat rotatei = 0.0f;
GLfloat rotatei2 = 0.0f;

GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.01f;

bool boat_frd=false;
GLfloat boat_position=0.0f;
bool rt = false;


float day3 = 0.0f;
float nytground = 0.3;
float treeCtrl = 0.5;
float hillCtrl = 0.27;
float skyCtrl1 = 0.2;
float skyCtrl2 = 0.2;
float skyCtrl3 = 0.2;
float waterCtrl1 = 0.4;
float waterCtrl2 = 0.5;
float moonCtrl = 0.2;
float cloudCtrl = 0.7;
float moveShip = 0.0;
float moveballoon = 0.82;
float moveCar = 0.0;
float moveCarJ = 0.0;
bool carCtrl = false;
bool shipCtrl = false;
bool balloonCtrl = false;
bool nyt = true;
float str1 = 1.0f;
float str2 = 1.0f;
float str3 = 1.0f;


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
void Rain(){
if(rainday){
    glPushMatrix();
    glTranslatef(0.0, 0.5f, 0.0f);

    glPushMatrix();
    glTranslatef(0.0, -positionRain, 0.0f);
    glLineWidth(1.0);
    GLfloat xR= -1.05;
    GLfloat yR = 2.05;

    glBegin(GL_LINES);
    glColor3ub(18, 18, 18);
    for(int i=0;i<=105;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02,yR-.022);

    xR += .03;
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
    glVertex2f(xR-.02,yR-.022);

    xR += .03;
    }
    glEnd();
    }
    glPopMatrix();
    }
}
void ground(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(-1.0,1.1);
       glVertex2f(1.0,1.1);
       glVertex2f(1.0,0.8);
       glVertex2f(-1.0,0.8);
       glEnd();

    glBegin(GL_QUADS);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(1.0,0.82);
       glVertex2f(1.0,0.8);
       glVertex2f(-0.2,0.8);
       glVertex2f(-0.2,0.85);
       glEnd();
}

void groundleft(){
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(-1.0,0.5);
       glVertex2f(-0.6,-0.15);
       glVertex2f(-1.0,-0.3);
       glEnd();
    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-1.0,-0.3);
       glVertex2f(-1.0,-0.1);
       glVertex2f(-0.95,-0.115);
       glVertex2f(-0.9,-0.115);
       glVertex2f(-0.85,-0.1125);
       glVertex2f(-0.685,0.0);
       glVertex2f(-0.6,-0.15);
       glEnd();
}

void groundleftTop(){
    glBegin(GL_POLYGON);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(-1.0,0.8);
       glVertex2f(-1.0,0.6);
       glVertex2f(-0.8,0.55);
       glVertex2f(-0.6,0.4);
       glVertex2f(-0.4,0.3);
       glVertex2f(-0.25,0.25);
       glVertex2f(-0.1,0.23);
       glVertex2f(0.11,0.3);
       glVertex2f(0.2,0.4);
       glVertex2f(0.1,0.6);
       glVertex2f(0.0,0.7);
       glVertex2f(-0.2,0.8);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-1.0,0.65);
       glVertex2f(-1.0,0.6);
       glVertex2f(-0.8,0.55);
       glVertex2f(-0.85,0.62);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-0.85,0.62);
       glVertex2f(-0.8,0.55);
       glVertex2f(-0.6,0.4);
       glVertex2f(-0.6,0.45);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-0.6,0.45);
       glVertex2f(-0.6,0.4);
       glVertex2f(-0.4,0.3);
       glVertex2f(-0.4,0.35);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-0.4,0.35);
       glVertex2f(-0.4,0.3);
       glVertex2f(-0.25,0.245);
       glVertex2f(-0.25,0.295);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-0.25,0.295);
       glVertex2f(-0.25,0.245);
       glVertex2f(-0.1,0.23);
       glVertex2f(-0.1,0.28);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(-0.1,0.28);
       glVertex2f(-0.1,0.23);
       glVertex2f(0.12,0.3);
       glVertex2f(0.12,0.35);
       glEnd();

    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(0.12,0.35);
       glVertex2f(0.12,0.3);
       glVertex2f(0.2,0.4);
       glVertex2f(0.183,0.43);
       glEnd();
}

void groundright(){
    glBegin(GL_QUADS);
    glColor3f(0.0f, nytground, 0.0f);
       glVertex2f(1.0,0.5);
       glVertex2f(0.9,0.5);
       glVertex2f(0.5,-0.15);
       glVertex2f(1.0,-0.3);
       glEnd();
    glBegin(GL_POLYGON);
    glColor3f(nytground, 0.4f, 0.0f);
       glVertex2f(1.0,-0.3);
       glVertex2f(1.0,-0.1);
       glVertex2f(0.95,-0.115);
       glVertex2f(0.9,-0.115);
       glVertex2f(0.85,-0.1125);
       glVertex2f(0.585,0.0);
       glVertex2f(0.5,-0.15);
       glEnd();
}

void hill(){
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
    glBegin(GL_QUAD_STRIP); //water
    glColor3f(0.0f, waterCtrl1, waterCtrl2);
       glVertex2f(1.0,1.0);
       glVertex2f(1.0,-0.7);
       glVertex2f(-1,1.0);
       glVertex2f(-1.0,-0.7);
       glEnd();
}

void tree1(){
    glPushMatrix();
	glTranslatef(-0.3f, 0.1f, 0.0f);
	glScalef(0.5f, 0.5f, 0.0f);
    glLineWidth(7.0);
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

    glPushMatrix();
	glTranslatef(-0.67f, 0.37f, 0.0f);
	glScalef(0.5f, 0.5f, 0.0f);
    glLineWidth(7.0);
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

    glPushMatrix();
	glTranslatef(-1.0f, 0.37f, 0.0f);
	glScalef(0.5f, 0.5f, 0.0f);
    glLineWidth(7.0);
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

    glPushMatrix();
	glTranslatef(-1.35f, 0.4f, 0.0f);
	glScalef(0.5f, 0.5f, 0.0f);
    glLineWidth(7.0);
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
	glTranslatef(-0.9f, -0.2f, 0.0f);
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
	glTranslatef(-1.2f, -0.3f, 0.0f);
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
	glTranslatef(-1.58f, -0.2f, 0.0f);
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
	glTranslatef(-1.2f, -0.3f, 0.0f);
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
	glTranslatef(-1.0f, -0.4f, 0.0f);
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
	glColor3f(skyCtrl1, skyCtrl2, skyCtrl3);
	glVertex2f(-1.0f, 1.1f);
	glVertex2f(-1.0f, 2.8f);
	glVertex2f(1.0f, 2.8f);
	glVertex2f(1.0f, 1.1f);
	glEnd();

	if(nyt){
	glPointSize(2.0);
	glBegin(GL_POINTS);//star2
	glColor3f(str1, str1, str1);
    glVertex2f(-0.97f,2.0f);
    glVertex2f(-0.9f,1.81f);
    glVertex2f(-0.72f,2.3f);
    glVertex2f(-0.72f,2.3f);
    glVertex2f(-0.75f,1.6f);
    glVertex2f(-0.56f,2.0f);
    glVertex2f(-0.25f,2.35f);
    glVertex2f(-0.2f,1.5f);
    glVertex2f(0.05f,2.3f);
    //
    glVertex2f(0.97f,2.0f);
    glVertex2f(0.9f,1.81f);
    glVertex2f(0.72f,2.3f);
    glVertex2f(0.72f,2.3f);
    glVertex2f(0.75f,1.6f);
    glVertex2f(0.56f,2.0f);
    glVertex2f(0.25f,2.35f);
    glVertex2f(0.2f,1.5f);
    glVertex2f(-0.05f,2.1f);
    glVertex2f(0.2f,1.85f);
    glEnd();

	glPointSize(3.0);
	glBegin(GL_POINTS);//star2
	glColor3f(str2, str2, str2);
    glVertex2f(-0.8f,2.2f);
    glVertex2f(-0.85f,2.05f);
    glVertex2f(-0.98f,1.6f);
    glVertex2f(-0.84f,1.65f);
    glVertex2f(-0.67f,1.75f);
    glVertex2f(-0.5f,1.7f);
    glVertex2f(-0.4f,2.2f);
    glVertex2f(-0.14f,2.2f);
    glVertex2f(-0.1f,1.7f);
    //glVertex2f(0.14f,2.31f);
    //glVertex2f(0.25f,2.15f);

    glVertex2f(0.8f,2.2f);
    glVertex2f(0.85f,2.05f);
    glVertex2f(0.98f,1.6f);
    glVertex2f(0.84f,1.65f);
    glVertex2f(0.67f,1.75f);
    glVertex2f(0.5f,1.7f);
    glVertex2f(0.4f,2.2f);
    glVertex2f(0.14f,2.2f);
    glVertex2f(0.04f,1.7f);
    glEnd();

    glPointSize(4.0);
	glBegin(GL_POINTS);//star3
	glColor3f(str3, str3, str3);
    glVertex2f(-0.95f,2.25f);
    glVertex2f(-0.7f,2.1f);
    glVertex2f(-0.55f,2.3f);
    glVertex2f(-0.34f,1.75f);
    //
    glVertex2f(0.95f,2.25f);
    glVertex2f(0.7f,2.1f);
    glVertex2f(0.55f,2.3f);
    glVertex2f(0.34f,1.75f);
    glEnd();
	}
}
void moon(){
    if(nyt){
    glColor3f(0.9f, 0.9f, 0.9f);
    circle(-0.75f, 1.9f, 0.1f);
    }
    glColor3f(moonCtrl, moonCtrl, 0.2f);
    circle(-0.73f, 1.91f, 0.09f);
}
void clouds(){
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
}

void ship(){
	glPushMatrix();
	glTranslatef(moveShip,-0.5f,0.0f);
    glBegin(GL_QUAD_STRIP);
       glColor3f(0.0f, 0.3f, 0.7f);
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
    circle(0.68f, 0.05f, 0.015f);

    glColor3f(1.0f, 1.0f, day3);
    circle(0.69f, -0.03f, 0.01f);

    glColor3f(1.0f, 1.0f, day3);
    circle(0.66f, -0.03f, 0.01f);

    glColor3f(1.0f, 1.0f, day3);
    circle(0.63f, -0.03f, 0.01f);

    glColor3f(1.0f, 1.0f, day3);
    circle(0.6f, -0.03f, 0.01f);

    glColor3f(1.0f, 1.0f, day3);
    circle(0.57f, -0.03f, 0.01f);

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
    glTranslatef(-position_bird, -0.45f, 0.0f);
    glScalef(0.5f, 0.5f, 0.0f);
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

void car(){
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(0.0,moveCarJ,0);

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(moveCar,-0.1,0);

    glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 0.7f);
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
	rotatei -=0.08f;
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
	rotatei -=0.08f;
	}
	glPopMatrix();
	glPopMatrix();
}
void bridge(){
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.34f,0.6f);
    glVertex2f(0.73f,0.2f);

    glVertex2f(0.34f,0.6f);
    glVertex2f(0.63f,0.2f);

    glVertex2f(0.34f,0.6f);
    glVertex2f(0.53f,0.2f);

    glVertex2f(0.34f,0.6f);
    glVertex2f(0.43f,0.2f);

    glVertex2f(0.31f,0.6f);
    glVertex2f(0.23f,0.2f);

    glVertex2f(0.31f,0.6f);
    glVertex2f(0.13f,0.2f);

    glVertex2f(0.31f,0.6f);
    glVertex2f(0.03f,0.2f);

    glVertex2f(0.31f,0.6f);
    glVertex2f(-0.1f,0.2f);

    glVertex2f(-0.51f,0.6f);
    glVertex2f(-0.1f,0.2f);

    glVertex2f(-0.51f,0.6f);
    glVertex2f(-0.2f,0.2f);

    glVertex2f(-0.51f,0.6f);
    glVertex2f(-0.3f,0.2f);

    glVertex2f(-0.51f,0.6f);
    glVertex2f(-0.4f,0.2f);

    glVertex2f(-0.543f,0.6f);
    glVertex2f(-0.6f,0.2f);

    glVertex2f(-0.543f,0.6f);
    glVertex2f(-0.7f,0.2f);

    glVertex2f(-0.543f,0.6f);
    glVertex2f(-0.8f,0.2f);

    glVertex2f(-0.543f,0.6f);
    glVertex2f(-0.88f,0.2f);
    glEnd();


    glPushMatrix();
    glTranslatef(-0.05f, 0.1f, 0.0f);
    glBegin(GL_QUADS);//pillar right
    glColor3f(0.7f, 0.0f, 0.2f);
    glVertex2f(0.39f,0.1f);
    glVertex2f(0.39f,0.5f);
    glVertex2f(0.36f,0.5f);
    glVertex2f(0.36f,0.1f);
    glEnd();

    glBegin(GL_QUADS);//pillar right
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.41f,0.1f);
    glVertex2f(0.41f,0.04f);
    glVertex2f(0.34f,0.04f);
    glVertex2f(0.34f,0.1f);
    glEnd();

    glBegin(GL_QUADS); //pillar
    glColor3f(0.0f, 0.3f, 0.4f);
    glVertex2f(0.4f,0.05f);
    glVertex2f(0.4f,-0.1f);
    glVertex2f(0.35f,-0.1f);
    glVertex2f(0.35f,0.05f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.05f, 0.1f, 0.0f);
    glBegin(GL_QUADS);//pillar right
    glColor3f(0.7f, 0.0f, 0.2f);
    glVertex2f(-0.49f,0.1f);
    glVertex2f(-0.49f,0.5f);
    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.46f,0.1f);
    glEnd();

    glBegin(GL_QUADS);//pillar right
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.51f,0.1f);
    glVertex2f(-0.51f,0.04f);
    glVertex2f(-0.44f,0.04f);
    glVertex2f(-0.44f,0.1f);
    glEnd();

    glBegin(GL_QUADS); //pillar
    glColor3f(0.0f, 0.3f, 0.4f);
    glVertex2f(-0.5f,0.05f);
    glVertex2f(-0.5f,-0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(-0.45f,0.05f);
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(-0.8f,0.05f);
    glVertex2f(0.85f,0.05f);
    glVertex2f(0.75f,0.2f);
    glVertex2f(-0.9f,0.2f);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES); //side bar
    glColor3f(0.8f, 0.0f, 0.2f);
    glVertex2f(0.775f,0.18f);
    glVertex2f(-0.885f,0.18f);
    glEnd();

    car();

    glLineWidth(10.0);
    glBegin(GL_LINES); //side bar
    glColor3f(0.8f, 0.0f, 0.2f);
    glVertex2f(-0.8f,0.07f);
    glVertex2f(0.84f,0.07f);
    glEnd();

    glBegin(GL_QUADS);//pillar
    glColor3f(0.0f, 0.3f, 0.4f);
    glVertex2f(-0.5f,0.05f);
    glVertex2f(-0.5f,-0.1f);
    glVertex2f(-0.45f,-0.1f);
    glVertex2f(-0.45f,0.05f);
    glEnd();

    glBegin(GL_QUADS); //pillar
    glColor3f(0.0f, 0.3f, 0.4f);
    glVertex2f(0.4f,0.05f);
    glVertex2f(0.4f,-0.1f);
    glVertex2f(0.35f,-0.1f);
    glVertex2f(0.35f,0.05f);
    glEnd();

    glBegin(GL_QUADS);//pillar left
    glColor3f(0.7f, 0.0f, 0.2f);
    glVertex2f(-0.49f,0.1f);
    glVertex2f(-0.49f,0.5f);
    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.46f,0.1f);
    glEnd();

    glBegin(GL_QUADS);//pillar left
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(-0.51f,0.1f);
    glVertex2f(-0.51f,0.04f);
    glVertex2f(-0.44f,0.04f);
    glVertex2f(-0.44f,0.1f);
    glEnd();

    glBegin(GL_QUADS);//pillar right
    glColor3f(0.7f, 0.0f, 0.2f);
    glVertex2f(0.39f,0.1f);
    glVertex2f(0.39f,0.5f);
    glVertex2f(0.36f,0.5f);
    glVertex2f(0.36f,0.1f);
    glEnd();

    glBegin(GL_QUADS);//pillar right
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(0.41f,0.1f);
    glVertex2f(0.41f,0.04f);
    glVertex2f(0.34f,0.04f);
    glVertex2f(0.34f,0.1f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(-0.49f,0.5f);// lines
    glVertex2f(-0.77f,0.08f);

    glVertex2f(-0.49f,0.5f);
    glVertex2f(-0.67f,0.08f);

    glVertex2f(-0.49f,0.5f);
    glVertex2f(-0.57f,0.08f);

    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.37f,0.08f);

    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.27f,0.08f);

    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.17f,0.08f);

    glVertex2f(-0.46f,0.5f);
    glVertex2f(-0.07f,0.08f);

    glVertex2f(0.36f,0.5f);
    glVertex2f(-0.07f,0.08f);

    glVertex2f(0.36f,0.5f);
    glVertex2f(0.07f,0.08f);

    glVertex2f(0.36f,0.5f);
    glVertex2f(0.17f,0.08f);

    glVertex2f(0.36f,0.5f);
    glVertex2f(0.27f,0.08f);

    glVertex2f(0.39f,0.5f);
    glVertex2f(0.47f,0.08f);

    glVertex2f(0.39f,0.5f);
    glVertex2f(0.57f,0.08f);

    glVertex2f(0.39f,0.5f);
    glVertex2f(0.67f,0.08f);

    glVertex2f(0.39f,0.5f);
    glVertex2f(0.77f,0.08f);
    glEnd();
}

void road(){
    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(-0.8f,0.05f);
    glVertex2f(-0.9f,0.2f);
    glVertex2f(-1.0f,0.2f);
    glVertex2f(-1.0f,0.05f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(1.0f,0.05f);
    glVertex2f(0.85f,0.05f);
    glVertex2f(0.75f,0.2f);
    glVertex2f(1.0f,0.2f);
    glEnd();

    glLineWidth(10.0);
    glBegin(GL_LINES);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.84f,0.07f);
    glVertex2f(1.0f,0.07f);

    glVertex2f(0.77f,0.18f);
    glVertex2f(1.0f,0.18f);

    glVertex2f(-0.8f,0.07f);
    glVertex2f(-1.0f,0.07f);

    glVertex2f(-0.77f,0.18f);
    glVertex2f(-1.0f,0.18f);
    glEnd();
}

void balloon(){
    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(moveballoon,0.43,0);

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glTranslatef(0.33,0.88,0);
    glScalef(0.05f, -0.3f, 0.0f);
    glRotatef(rotatei2,0,0.0,0.1);//i=how many degree you want to rotate around an axis
    // T 1
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 1.0f);
    glVertex2f(-0.2, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.2, 0.1);
    glEnd();

    // T 2
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.1, 0.2);
    glVertex2f(0, 0.2);
    glEnd();

    // T 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 0.5f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.2, -0.1);
    glVertex2f(0.2, 0);
    glEnd();

    // T 4
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(-0.1, -0.2);
    glVertex2f(0, -0.2);
    glEnd();
    glPopMatrix();
    rotatei2+=0.7f;


    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.5f);//birthday
    glVertex2f(0.3f, 0.745f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.5f, 0.745f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.5f);//birthday
    glVertex2f(0.5f, 0.7f);
    glVertex2f(0.5f, 0.72f);
    glVertex2f(0.55f, 0.7f);

    glVertex2f(0.5f, 0.74f);
    glVertex2f(0.5f, 0.72f);
    glVertex2f(0.55f, 0.74f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.25f, 0.8f);
    glVertex2f(0.3f, 0.74f);

    glVertex2f(0.305f, 0.71f);
    glVertex2f(0.305f, 0.68f);
    glEnd();

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glScalef(0.3f, 1.0f, 0.0f);
    glColor3f(0.0f, hillCtrl, 0.0f);
    circle(1.0f, 0.71f, 0.028f);
    glPopMatrix();

    /*
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);//birthday
    glVertex2f(0.31f, 0.735f);
    glVertex2f(0.31f, 0.705f);

    glVertex2f(0.315f, 0.72f);
    glVertex2f(0.31f, 0.72f);

    glVertex2f(0.315f, 0.735f);
    glVertex2f(0.315f, 0.705f);

    glVertex2f(0.322f, 0.735f);
    glVertex2f(0.318f, 0.705f);

    glVertex2f(0.322f, 0.735f);
    glVertex2f(0.326f, 0.705f);

    glVertex2f(0.318f, 0.72f);
    glVertex2f(0.326f, 0.72f);

    glVertex2f(0.33f, 0.735f);
    glVertex2f(0.33f, 0.705f);

    glVertex2f(0.33f, 0.72f);
    glVertex2f(0.335f, 0.72f);

    glVertex2f(0.33f, 0.735f);
    glVertex2f(0.335f, 0.735f);

    glVertex2f(0.335f, 0.72f);
    glVertex2f(0.335f, 0.735f);

    glVertex2f(0.34f, 0.735f);
    glVertex2f(0.34f, 0.705f);

    glVertex2f(0.34f, 0.72f);
    glVertex2f(0.345f, 0.72f);

    glVertex2f(0.34f, 0.735f);
    glVertex2f(0.345f, 0.735f);

    glVertex2f(0.345f, 0.72f);
    glVertex2f(0.345f, 0.735f);

    glVertex2f(0.348f, 0.735f);
    glVertex2f(0.352f, 0.72f);

    glVertex2f(0.356f, 0.735f);
    glVertex2f(0.352f, 0.72f);

    glVertex2f(0.352f, 0.72f);
    glVertex2f(0.352f, 0.705f);

    glVertex2f(0.362f, 0.735f);
    glVertex2f(0.362f, 0.705f);

    glVertex2f(0.362f, 0.72f);
    glVertex2f(0.368f, 0.72f);

    glVertex2f(0.362f, 0.735f);
    glVertex2f(0.368f, 0.735f);

    glVertex2f(0.368f, 0.72f);
    glVertex2f(0.368f, 0.735f);

    glVertex2f(0.368f, 0.72f);
    glVertex2f(0.368f, 0.705f);

    glVertex2f(0.368f, 0.7057f);
    glVertex2f(0.362f, 0.7057f);

    glVertex2f(0.375f, 0.735f);
    glVertex2f(0.375f, 0.705f);

    glVertex2f(0.371f, 0.735f);
    glVertex2f(0.378f, 0.735f);

    glVertex2f(0.371f, 0.705f);
    glVertex2f(0.378f, 0.705f);

    glVertex2f(0.382f, 0.735f);
    glVertex2f(0.382f, 0.702f);

    glVertex2f(0.382f, 0.72f);
    glVertex2f(0.388f, 0.72f);

    glVertex2f(0.382f, 0.735f);
    glVertex2f(0.388f, 0.735f);

    glVertex2f(0.388f, 0.72f);
    glVertex2f(0.388f, 0.735f);

    glVertex2f(0.382f, 0.72f);
    glVertex2f(0.39f, 0.705f);

    glVertex2f(0.395f, 0.735f);
    glVertex2f(0.395f, 0.705f);

    glVertex2f(0.391f, 0.735f);
    glVertex2f(0.399f, 0.735f);

    glVertex2f(0.403f, 0.735f);
    glVertex2f(0.403f, 0.705f);

    glVertex2f(0.408f, 0.72f);
    glVertex2f(0.403f, 0.72f);

    glVertex2f(0.408f, 0.735f);
    glVertex2f(0.408f, 0.705f);

    glVertex2f(0.413f, 0.735f);
    glVertex2f(0.413f, 0.705f);

    glVertex2f(0.419f, 0.73f);
    glVertex2f(0.419f, 0.71f);

    glVertex2f(0.413f, 0.735f);
    glVertex2f(0.419f, 0.73f);

    glVertex2f(0.419f, 0.71f);
    glVertex2f(0.413f, 0.705f);

    glVertex2f(0.427f, 0.735f);
    glVertex2f(0.423f, 0.705f);

    glVertex2f(0.427f, 0.735f);
    glVertex2f(0.431f, 0.705f);

    glVertex2f(0.423f, 0.72f);
    glVertex2f(0.431f, 0.72f);

    glVertex2f(0.433f, 0.735f);
    glVertex2f(0.437f, 0.72f);

    glVertex2f(0.441f, 0.735f);
    glVertex2f(0.437f, 0.72f);

    glVertex2f(0.437f, 0.72f);
    glVertex2f(0.437f, 0.705f);

    glVertex2f(0.446f, 0.735f);
    glVertex2f(0.446f, 0.702f);

    glVertex2f(0.446f, 0.72f);
    glVertex2f(0.452f, 0.72f);

    glVertex2f(0.446f, 0.735f);
    glVertex2f(0.452f, 0.735f);

    glVertex2f(0.452f, 0.72f);
    glVertex2f(0.452f, 0.735f);

    glVertex2f(0.446f, 0.72f);
    glVertex2f(0.454f, 0.705f);

    glVertex2f(0.461f, 0.735f);
    glVertex2f(0.461f, 0.705f);

    glVertex2f(0.457f, 0.735f);
    glVertex2f(0.464f, 0.735f);

    glVertex2f(0.457f, 0.705f);
    glVertex2f(0.464f, 0.705f);

    glVertex2f(0.468f, 0.735f);
    glVertex2f(0.468f, 0.705f);

    glVertex2f(0.468f, 0.735f);
    glVertex2f(0.472f, 0.72f);

    glVertex2f(0.476f, 0.735f);
    glVertex2f(0.472f, 0.72f);

    glVertex2f(0.476f, 0.735f);
    glVertex2f(0.476f, 0.705f);

    glVertex2f(0.486f, 0.735f);
    glVertex2f(0.486f, 0.705f);

    glVertex2f(0.482f, 0.735f);
    glVertex2f(0.489f, 0.735f);

    glVertex2f(0.482f, 0.705f);
    glVertex2f(0.489f, 0.705f);
    glEnd(); */


    glColor3f(0.6f, 0.2f, 0.2f);
    circle(0.26, 0.8, 0.03);
    circle(0.26, 0.77, 0.03);
    glColor3f(0.2f, 0.2f, 0.2f);
    circle(0.26, 0.81, 0.023);

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.25f, 0.25f, 0.25f);
    glVertex2f(0.235, 0.818);
    glVertex2f(0.24, 0.75);

    glVertex2f(0.24, 0.75);
    glVertex2f(0.245, 0.8);

    glVertex2f(0.245, 0.8);
    glVertex2f(0.25, 0.74);

    glVertex2f(0.25, 0.74);
    glVertex2f(0.255, 0.795);

    glVertex2f(0.255, 0.795);
    glVertex2f(0.26, 0.74);

    glVertex2f(0.26, 0.74);
    glVertex2f(0.265, 0.795);

    glVertex2f(0.265, 0.795);
    glVertex2f(0.27, 0.74);

    glVertex2f(0.27, 0.74);
    glVertex2f(0.275, 0.8);

    glVertex2f(0.275, 0.8);
    glVertex2f(0.28, 0.74);

    glVertex2f(0.28, 0.74);
    glVertex2f(0.285, 0.82);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.225, 0.88);
    glVertex2f(0.33, 0.88);
    glEnd();

    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glScalef(1.0f, 0.5f, 0.0f); // blade
    circle(0.26, 1.755, 0.032);
    glColor3f(0.0f, hillCtrl, 0.0f);
    circle(0.26, 1.755, 0.025);
    glPopMatrix();

    glLineWidth(1.2);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.323, 0.98);
    glVertex2f(0.286, 0.87);

    glVertex2f(0.3, 0.98);
    glVertex2f(0.28, 0.87);

    glVertex2f(0.27, 0.98);
    glVertex2f(0.27, 0.85);

    glVertex2f(0.24, 0.975);
    glVertex2f(0.26, 0.855);

    glVertex2f(0.2, 0.98);
    glVertex2f(0.23, 0.87);

    glVertex2f(0.23, 0.98);
    glVertex2f(0.25, 0.885);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
    glVertex2f(0.286, 0.87);
    glVertex2f(0.286, 0.8);

    glVertex2f(0.26, 0.86);
    glVertex2f(0.26, 0.8);

    glVertex2f(0.234, 0.87);
    glVertex2f(0.234, 0.8);
    glEnd();


    glPushMatrix(); //glPushMatrix copies the top matrix and pushes it onto the stack, while glPopMatrix pops the top matrix off the stack
    glScalef(0.34f, 1.0f, 0.0f); // balloons
    glColor3f(1.0f, 0.0f, 0.0f);
    circle(0.6, 1.05, 0.07);
    glColor3f(1.0f, 1.0f, 0.0f);
    circle(0.65, 1.1, 0.07);
    glColor3f(1.0f, 0.0f, 0.5f);
    circle(0.75, 1.15, 0.07);
    glColor3f(1.0f, 0.5f, 0.5f);
    circle(0.7, 1.05, 0.07);
    glColor3f(0.0f, 1.0f, 0.0f);
    circle(0.85, 1.1, 0.07);
    glColor3f(1.0f, 0.0f, 1.0f);
    circle(0.9, 1.08, 0.07);
    glColor3f(1.0f, 0.5f, 0.0f);
    circle(0.95, 1.05, 0.07);
    glColor3f(0.5f, 0.5f, 1.0f);
    circle(0.87, 1.05, 0.07);
    glColor3f(0.0f, 0.3f, 1.0f);
    circle(0.75, 1.1, 0.07);
    glColor3f(0.0f, 0.7f, 0.7f);
    circle(0.8, 1.05, 0.07);
    glPopMatrix();

    glPopMatrix();
}

void Boat(){
    glPushMatrix();
    glTranslatef(0.35, 0.55f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex2f(0.0, -0.76);
    glVertex2f(0.26, -0.70);
    glVertex2f(0.25,-0.74);
    glVertex2f(0.23,-0.76);
    glVertex2f(0.17,-0.80);
    glVertex2f(-0.01,-0.80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (209, 204, 192);
    glVertex2f(0.04, -0.752);
    glVertex2f(0.06, -0.68);
    glVertex2f(0.16,-0.686);
    glVertex2f(0.18,-0.70);
    glVertex2f(0.20,-0.72);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,255,255);
    glVertex2f(0.12,-0.68);
    glVertex2f(0.18,-0.686);
    glVertex2f(0.20,-0.718);
    glVertex2f(0.12,-0.738);
    glEnd();
    //boat grill
    //1st
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.03, -0.755);
    glVertex2f(0.035, -0.755);
    glVertex2f(0.035, -0.73);
    glVertex2f(0.03, -0.73);
    glEnd();

    //2nd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.08, -0.745);
    glVertex2f(0.085, -0.745);
    glVertex2f(0.085, -0.72);
    glVertex2f(0.08, -0.72);
    glEnd();

    //3rd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.13, -0.735);
    glVertex2f(0.135, -0.735);
    glVertex2f(0.135, -0.71);
    glVertex2f(0.13, -0.71);
    glEnd();

    //4th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.18, -0.725);
    glVertex2f(0.185, -0.725);
    glVertex2f(0.185, -0.70);
    glVertex2f(0.18, -0.70);
    glEnd();

    //5th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.23, -0.715);
    glVertex2f(0.235, -0.715);
    glVertex2f(0.235, -0.69);
    glVertex2f(0.23, -0.69);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.254, -0.707);
    glVertex2f(0.257, -0.707);
    glVertex2f(0.257, -0.68);
    glVertex2f(0.254, -0.68);
    glEnd();
    //horizontal grill
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.02, -0.73);
    glVertex2f(0.26, -0.685);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.02, -0.735);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(-0.45, 0.5f, 0.0f);
    glScalef(-1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.3f, 0.0f);
    glVertex2f(0.0, -0.76);
    glVertex2f(0.26, -0.70);
    glVertex2f(0.25,-0.74);
    glVertex2f(0.23,-0.76);
    glVertex2f(0.17,-0.80);
    glVertex2f(-0.01,-0.80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (209, 204, 192);
    glVertex2f(0.04, -0.752);
    glVertex2f(0.06, -0.68);
    glVertex2f(0.16,-0.686);
    glVertex2f(0.18,-0.70);
    glVertex2f(0.20,-0.72);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,255,255);
    glVertex2f(0.12,-0.68);
    glVertex2f(0.18,-0.686);
    glVertex2f(0.20,-0.718);
    glVertex2f(0.12,-0.738);
    glEnd();
    //boat grill
    //1st
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.03, -0.755);
    glVertex2f(0.035, -0.755);
    glVertex2f(0.035, -0.73);
    glVertex2f(0.03, -0.73);
    glEnd();

    //2nd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.08, -0.745);
    glVertex2f(0.085, -0.745);
    glVertex2f(0.085, -0.72);
    glVertex2f(0.08, -0.72);
    glEnd();

    //3rd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.13, -0.735);
    glVertex2f(0.135, -0.735);
    glVertex2f(0.135, -0.71);
    glVertex2f(0.13, -0.71);
    glEnd();

    //4th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.18, -0.725);
    glVertex2f(0.185, -0.725);
    glVertex2f(0.185, -0.70);
    glVertex2f(0.18, -0.70);
    glEnd();

    //5th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.23, -0.715);
    glVertex2f(0.235, -0.715);
    glVertex2f(0.235, -0.69);
    glVertex2f(0.23, -0.69);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.254, -0.707);
    glVertex2f(0.257, -0.707);
    glVertex2f(0.257, -0.68);
    glVertex2f(0.254, -0.68);
    glEnd();
    //horizontal grill
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.02, -0.73);
    glVertex2f(0.26, -0.685);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.02, -0.735);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.7, 1.2f, 0.0f);
    glScalef(-0.8f, 0.8f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.3f, 0.0f);
    glVertex2f(0.0, -0.76);
    glVertex2f(0.26, -0.70);
    glVertex2f(0.25,-0.74);
    glVertex2f(0.23,-0.76);
    glVertex2f(0.17,-0.80);
    glVertex2f(-0.01,-0.80);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (209, 204, 192);
    glVertex2f(0.04, -0.752);
    glVertex2f(0.06, -0.68);
    glVertex2f(0.16,-0.686);
    glVertex2f(0.18,-0.70);
    glVertex2f(0.20,-0.72);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (255,255,255);
    glVertex2f(0.12,-0.68);
    glVertex2f(0.18,-0.686);
    glVertex2f(0.20,-0.718);
    glVertex2f(0.12,-0.738);
    glEnd();
    //boat grill
    //1st
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.03, -0.755);
    glVertex2f(0.035, -0.755);
    glVertex2f(0.035, -0.73);
    glVertex2f(0.03, -0.73);
    glEnd();

    //2nd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.08, -0.745);
    glVertex2f(0.085, -0.745);
    glVertex2f(0.085, -0.72);
    glVertex2f(0.08, -0.72);
    glEnd();

    //3rd
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.13, -0.735);
    glVertex2f(0.135, -0.735);
    glVertex2f(0.135, -0.71);
    glVertex2f(0.13, -0.71);
    glEnd();

    //4th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.18, -0.725);
    glVertex2f(0.185, -0.725);
    glVertex2f(0.185, -0.70);
    glVertex2f(0.18, -0.70);
    glEnd();

    //5th
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.23, -0.715);
    glVertex2f(0.235, -0.715);
    glVertex2f(0.235, -0.69);
    glVertex2f(0.23, -0.69);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.254, -0.707);
    glVertex2f(0.257, -0.707);
    glVertex2f(0.257, -0.68);
    glVertex2f(0.254, -0.68);
    glEnd();
    //horizontal grill
    glBegin(GL_POLYGON);
    glColor3ub (114, 176, 129);
    glVertex2f(0.02, -0.73);
    glVertex2f(0.26, -0.685);
    glVertex2f(0.26, -0.68);
    glVertex2f(0.02, -0.735);
    glEnd();
    glPopMatrix();
}
void update_bird(int value){
    if(position_bird <-1.7)
    {
        position_bird = 1.0f;
    }
    position_bird -= speed_bird;

	glutTimerFunc(120, update_bird, 0);
}

void updateRain(int value) {

    if(positionRain >.14)
        {positionRain = 0.0f;}

    positionRain += speedRain;

	glutPostRedisplay();

	glutTimerFunc(100, updateRain, 0);
}

void updateStr1(int value) {
     str1 -= .008;
    if(str1< 0.0)
    {
        str1 = 1.1;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(5, updateStr1, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void updateStr2(int value) {
     str2 -= .005;
    if(str2< 0.0)
    {
        str2 = 1.1;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(5, updateStr2, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}


void updateStr3(int value) {
     str3 -= .002;
    if(str3< 0.0)
    {
        str3 = 1.1;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed
	glutTimerFunc(5, updateStr3, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}
void updateShip(int value) {
    if(shipCtrl){
     moveShip -= .007;
    if(moveShip< -1.7)
    {
        moveShip = 1.0;
    }
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, updateShip, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void updateBalloon(int value) {
    if(balloonCtrl){
     moveballoon -= .002;
    if(moveballoon< -1.7)
    {
        moveballoon = 1.0;
    }
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, updateBalloon, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}


void updateCar(int value) {
    if(carCtrl){
     moveCar += .005;
    if(moveCar> 1.9)
    {
        moveCar = -1.0;
    }
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, updateCar, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}
void updateCarJump(int value) {
    if(carCtrl){
     moveCarJ += .005;
    if(moveCarJ> 0.015)
    {
        moveCarJ = 0.01;
    }
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, updateCarJump, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
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
        shipCtrl = true;
        break;
    case 'd':
        shipCtrl = false;
        break;
    case 'h':
        rt = true;
        carCtrl = true;
        break;
    case 'g':
        rt = false;
        carCtrl = false;
        break;
    case 'b':
        balloonCtrl = true;
        break;
    case 'n':
        balloonCtrl = false;
        break;
    default:
    break;

    }
}
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON){
			    day3 = 0.9f;
			    nytground = 0.5f;
			    treeCtrl = 0.7f;
			    hillCtrl = 0.33;
			    skyCtrl1 = 0.5f;
			    skyCtrl2 = 0.7f;
			    skyCtrl3 = 1.0f;
			    waterCtrl1 = 0.7f;
			    waterCtrl2 = 1.0f;
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
                skyCtrl1 = 0.2;
                skyCtrl2 = 0.2;
                skyCtrl3 = 0.2;
                waterCtrl1 = 0.4f;
			    waterCtrl2 = 0.5f;
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
	water();
	ground();
	groundleftTop();
	groundleft();
	groundright();
	road();
	tree1();
	tree2();
	tree3();
	bridge();
	Boat();
	ship();
	balloon();
	glPopMatrix();
	glPopMatrix();
	Rain();
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
    glutTimerFunc(100, update_bird, 0);
    glutTimerFunc(100, updateRain, 0);
    glutTimerFunc(50, updateShip, 0);
    glutTimerFunc(50, updateBalloon, 0);
    glutTimerFunc(50, updateCar, 0);
    glutTimerFunc(10, updateCarJump, 0);
    glutTimerFunc(250, updateStr1, 0);
    glutTimerFunc(250, updateStr2, 0);
    glutTimerFunc(250, updateStr3, 0);
    glutMainLoop();
    return 0;
}
