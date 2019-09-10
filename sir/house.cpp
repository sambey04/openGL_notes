#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0,600,0,550);
}
void house(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 
 glPointSize(4.0);
/*
glBegin(GL_QUADS);
	glColor3f(1.0,1.0,0.0);
	glVertex2i(150,20);
	glVertex2i(450,20);
	glVertex2i(450,250);
	glVertex2i(150,250);
glEnd();
*/
glBegin(GL_QUADS);
	glColor3f(0.5,0.35,0.05);
	glVertex2i(80,250);
	glVertex2i(520,250);
	glVertex2i(430,380);
	glVertex2i(170,380);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.8,0.0,0.0);
	glVertex2i(200,20);
	glVertex2i(270,20);
	glVertex2i(270,165);	
	glVertex2i(200,165);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(330,130);
	glVertex2i(400,130);
	glVertex2i(400,200);	
	glVertex2i(330,200);
glEnd();

glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2i(365,130);
	glVertex2i(365,200);
glEnd();

glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2i(330,165);
	glVertex2i(400,165);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.3,0.3,0.3);
	glVertex2i(380,380);
	glVertex2i(400,380);
	glVertex2i(400,400);
	glVertex2i(380,400);
glEnd();
 glFlush(); 
}


int count=0;


void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP ) {
{
glBegin(GL_QUADS);
//if(count%2==0)
	glColor3f(1.0,1.0,0.0);
//count++;
//else

	//glColor3f(1.0,1.0,0.0);

glVertex2i(150,20);
	glVertex2i(450,20);
	glVertex2i(450,250);
	glVertex2i(150,250);
//	count++;
glEnd();
glFlush();
//count++;
//cout<< count;
}
}}

int main(int argc, char** argv)
{

	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,300);
 glutCreateWindow("House Design");
	glutMouseFunc(myMouseFunc);  
 init();
 glutDisplayFunc(house);
 glutMainLoop();
 return 0;
}
