

#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;


void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}

void setPixel(GLfloat x,GLfloat y)
{
 glPointSize(2);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
}

void circleMidpoint(GLint r)
{
 //drawing axes
 glColor3f(1.0,1.0,0.0);
 glBegin(GL_LINES);
  glVertex2i(-200,0);
  glVertex2i(200,0);
  glVertex2i(0,-200);
  glVertex2i(0,200);
 glEnd();

 //plot origin
 glColor3f(0.1,1.0,0.1);
 glPointSize(6);
 glBegin(GL_POINTS);
  glVertex2i(0,0);
 glEnd();
 glColor3f(1.0,0.0,0.0);

 //
 GLint x=0,y=r,p=1-r;
 while(x<=y)
 {

  if(p<0)
  p=p+2*x+3;
  else
  {
   p=p+2*(x-y)+5;
   y--;
  }
  x++;

glFlush();
  setPixel(x,y);
  setPixel(-x,-y);
  setPixel(-x,y);
  setPixel(x,-y);
  setPixel(y,x);
  setPixel(-y,x);
  setPixel(y,-x);
  setPixel(-y,-x);
  //glFlush();
 }
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 
 
 
}



void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {

cout << x << " " << y << "\n";		
circleMidpoint(sqrt(x*x+y*y));

}}


int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,400);
 glutCreateWindow("Circle : Midpoint");
	glutMouseFunc(myMouseFunc); 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();
 return 0;
}


