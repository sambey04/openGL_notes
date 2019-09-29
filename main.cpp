
	
	

#include<GL/glut.h>
#include<stdio.h>

GLint ww=400, wh=400;
GLint count = 0, x1=0, y1=0, x2=0, y2=0;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 //glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 //glColor3f(1.0,0.0,0.0);
 glPointSize(3.0);
 glFlush(); 
}

void plotpoint(GLint x,GLint y)
{
 glColor3f(1.0,0.0,0.0);
 glBegin(GL_POINTS);
  glVertex2i(x,y);
 glEnd();
}

void drawline()
{
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y2);
 glEnd();
}

void mousePtPlot(GLint button, GLint action, GLint xMouse, GLint yMouse)
{
 if(button == GLUT_LEFT_BUTTON && action == GLUT_UP)
 {
  if(!count)
  {
   glClear(GL_COLOR_BUFFER_BIT);
   x1=xMouse;
   y1=wh-yMouse;
   count = 1;
   plotpoint(x1,y1);
   printf("First point %d, %d entered.\n",x1,y1);
  }
  else
  {
   x2=xMouse;
   y2=wh-yMouse;
   printf("Second point %d, %d entered.\n",x2,y2);
   plotpoint(x2,y2);
   drawline();
   count=0;
   printf("Points reset.\n");
  }
 }
 glFlush();
 //printf("%d %d\n",xMouse,yMouse);
}

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 //glutInitWindowPosition(50,100);
 glutInitWindowSize(ww,wh);
 glutCreateWindow("mouse demo1");
 //glClearColor(1.0,1.0,1.0,0.0);

 init();
 glutDisplayFunc(display);
 glutMouseFunc(mousePtPlot);

 glutMainLoop();
 return 0;
}

