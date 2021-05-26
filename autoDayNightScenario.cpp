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

float dayNyt = 0.2f;
float cloudCtrl = 0.7f;
float lamp = 1.0f;
bool nyt = true;



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

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.3f, 0.0f);
       glVertex2f(-1.0,0.63);
       glVertex2f(1,0.63);
       glVertex2f(1,0.5);
       glVertex2f(-1.0,0.5);
       glEnd();
}
void road(){
    //water
   // 0.0f, 0.0f, 1.0f
    glBegin(GL_QUADS);
       glColor3f(0.0f, 0.0f, 0.0f);
       glVertex2f(-1,0.4);
       glVertex2f(1,0.4);
       glVertex2f(1,-0.7);
       glVertex2f(-1,-0.7);
       glEnd();

    glBegin(GL_QUAD_STRIP); //ground
    glColor3f(0.0f, 0.3f, 0.0f);
       glVertex2f(0.5,0.0);
       glVertex2f(0.5,-0.7);
       glVertex2f(1,0.0);
       glVertex2f(1.0,-0.7);
       glEnd();

    glBegin(GL_QUAD_STRIP); //water
    glColor3f(0.0f, 0.7f, 1.0f);
       glVertex2f(0.2,0.0);
       glVertex2f(0.2,-0.7);
       glVertex2f(-1,0.0);
       glVertex2f(-1.0,-0.7);
       glEnd();

    glLineWidth(8.0);
    glBegin(GL_LINES);
       glColor3f(0.5f, 0.5f, 0.5f);
       glVertex2f(-1.0,0.2);
       glVertex2f(1.0,0.2);

       glVertex2f(-1.0,0.0);
       glVertex2f(0.2,0.0);

       glVertex2f(0.5,0.0);
       glVertex2f(1.0,0.0);

       glVertex2f(0.2,0.02);
       glVertex2f(0.2,-0.7);

       glVertex2f(0.5,0.02);
       glVertex2f(0.5,-0.7);

       glVertex2f(0.35,-0.1);
       glVertex2f(0.35,-0.7);

       glEnd();

    glLineWidth(4.0);
    glBegin(GL_LINES);
       glColor3f(0.0f, 0.3f, 0.0f);
       glVertex2f(-1.0,0.2);
       glVertex2f(1.0,0.2);

       glVertex2f(0.35,-0.12);
       glVertex2f(0.35,-0.7);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
       glColor3f(1.0f, 1.0f, 1.0f);
       glVertex2f(0.425,-0.2);
       glVertex2f(0.425,-0.4);

       glVertex2f(-0.8,0.1);
       glVertex2f(-0.6,0.1);

       glVertex2f(-0.3,0.1);
       glVertex2f(-0.1,0.1);

       glVertex2f(0.2,0.1);
       glVertex2f(0.4,0.1);

       glVertex2f(0.7,0.1);
       glVertex2f(0.9,0.1);


       glVertex2f(0.275,0.1);
       glVertex2f(0.275,-0.1);

       glVertex2f(0.275,-0.4);
       glVertex2f(0.275,-0.6);

       glVertex2f(-0.6,0.3);
       glVertex2f(-0.4,0.3);

       glVertex2f(-0.1,0.3);
       glVertex2f(0.1,0.3);

       glVertex2f(0.4,0.3);
       glVertex2f(0.6,0.3);

       glVertex2f(-0.9,-0.2);
       glVertex2f(-0.7,-0.2);

       glVertex2f(-0.3,-0.2);
       glVertex2f(-0.1,-0.2);

       glVertex2f(-0.6,-0.4);
       glVertex2f(-0.4,-0.4);

       glVertex2f(-0.15,-0.4);
       glVertex2f(0.1,-0.4);

       glEnd();
}

void house(){
    glBegin(GL_QUAD_STRIP);
	glColor3f(0.5f, 1.0f, 0.5f);
       glVertex2f(-0.76f, 0.55f);
       glVertex2f(-0.6f, 0.55f);
	   glVertex2f(-0.76f, 1.2f);
	   glVertex2f(-0.6f, 1.2f);
	   glEnd();

	glLineWidth(10.0);
    glBegin(GL_LINES);
       glColor3f(dayNyt, dayNyt, dayNyt);
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
       glColor3f(dayNyt, dayNyt, dayNyt);
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
    glColor3f(dayNyt, dayNyt, dayNyt);
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
    glColor3f(dayNyt, dayNyt, dayNyt);
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
    glColor3f(dayNyt, dayNyt, dayNyt);
       glVertex2f(-0.4,0.7);
       glVertex2f(-0.36,0.7);

       glVertex2f(-0.4,0.62);
       glVertex2f(-0.36,0.62);

       glVertex2f(-0.43,0.59);
       glVertex2f(-0.43,0.52);
       glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINES);
    glColor3f(0.2f, 0.2f, 0.2f);
       glVertex2f(-0.43,0.74);
       glVertex2f(-0.43,0.62);
       glEnd();
}
void sky()
{
    glBegin(GL_QUADS);      //sky
	glColor3f(dayNyt, dayNyt, dayNyt);
	glVertex2f(-1.0f, -0.3f);
	glVertex2f(1.0f, -0.3f);
	glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
	glEnd();
}
void moon()
{
    glColor3f(0.9f, 0.9f, 0.9f);
    circle(-0.75f, 0.6f, 0.1f);
    glColor3f(dayNyt, dayNyt, 0.2f);
    circle(-0.73f, 0.61f, 0.09f);
}
void clouds(){
    glColor3f(cloudCtrl, cloudCtrl, cloudCtrl);
    //cloud 1
    circle(0.0f,0.7f,0.1f);
    circle(-0.16f,0.7f,0.15f);
    circle(-0.26f,0.7,0.13f);
    circle(-0.37f,0.7f,0.1f);
}
void tree(){
    glLineWidth(20.0);
    glBegin(GL_LINES);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(0.8f, 0.53f);
    glEnd();

    glColor3f(0.0f, 0.5f, 0.0f);
    circle(0.8f,1.15f,0.1f);
    circle(0.75f,1.0f,0.1f);
    circle(0.85f,1.0f,0.1f);
}
void banch(){
    glBegin(GL_QUAD_STRIP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.4f, 0.65f);
    glVertex2f(0.5f, 0.65f);
    glVertex2f(0.37f, 0.63f);
    glVertex2f(0.53f, 0.63f);
    glEnd();

    glLineWidth(2.5);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.385f, 0.55f);
    glVertex2f(0.385f, 0.625f);

    glVertex2f(0.515f, 0.55f);
    glVertex2f(0.515f, 0.625f);
    glEnd();

    glLineWidth(3.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.37f, 0.625f);
    glVertex2f(0.53f, 0.625f);
    glEnd();

    glLineWidth(2.0);
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2f(0.41f, 0.65f);
    glVertex2f(0.41f, 0.75f);

    glVertex2f(0.49f, 0.65f);
    glVertex2f(0.49f, 0.75f);

    glVertex2f(0.4f, 0.68f);
    glVertex2f(0.5f, 0.68f);

    glVertex2f(0.4f, 0.70f);
    glVertex2f(0.5f, 0.70f);

    glVertex2f(0.4f, 0.72f);
    glVertex2f(0.5f, 0.72f);

    glVertex2f(0.4f, 0.65f);
    glVertex2f(0.4f, 0.58f);

    glVertex2f(0.5f, 0.65f);
    glVertex2f(0.5f, 0.58f);
    glEnd();

    glLineWidth(0.5);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(0.37f, 0.63f);
    glVertex2f(0.53f, 0.63f);
    glEnd();

}
void lamppost(){
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
}
void car(){
    glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
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
	glVertex2f(-0.8f, 0.38f);
	glVertex2f(-0.76f, 0.325f);
	glEnd();

	glColor3f(0.4f, 0.4f, 0.4f);
    circle(-0.85f, 0.255f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(-0.85f, 0.255f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(-0.85f, 0.255f, 0.01f);

    glColor3f(0.4f, 0.4f, 0.4f);
    circle(-0.75f, 0.255f, 0.03f);
    glColor3f(1.0f, 1.0f, 1.0f);
    circle(-0.75f, 0.255f, 0.02f);
    glColor3f(0.0f, 0.0f, 0.0f);
    circle(-0.75f, 0.255f, 0.01f);
}



void update3(int value) {
     cloudCtrl += .002;
    if(cloudCtrl> 1.1)
    {
        cloudCtrl = 0.6;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(150, update3, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
}

void update4(int value){
     dayNyt += .005;
     nyt = true;
    if(dayNyt> 1.0)
    {
        dayNyt = 0.1;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(150, update4, 0); //Notify GLUT to call update again in 25 milliseconds //Notify GLUT to call update again in 25 milliseconds
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
	road();
	tree();
	banch();
	lamppost();
	house();
	car();
	glPopMatrix();
	glFlush();  // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900,700);
    glutInitWindowPosition(150,50);
    glutCreateWindow("Night Scene");
    glutDisplayFunc(display);
    glutTimerFunc(150, update4, 0);
    glutTimerFunc(150, update3, 0);
    glutMainLoop();
    return 0;
}