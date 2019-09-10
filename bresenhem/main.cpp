#include<GL/glut.h>
#include<iostream>

GLint x1=0,y1=0,x2=0,y2=0;
GLint count = 0;

void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}

void plotPoint(GLfloat x,GLfloat y)
{
 glPointSize(2);
 glBegin(GL_POINTS);
  glVertex2f(x,y);
 glEnd();
}

void ddaLine(GLint x1,GLint y1,GLint x2,GLint y2)
{
 //drawing axes
 glColor3f(0.0,0.0,1.0);
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

 //drawing intended line using bresenhem
 GLint dx = x2-x1, dy = y2-y1, length;
 float xinc,yinc, x=x1, y=y1;
int dt=2*dy-2*dx; int ds=2*dy;
int d= 2*dy-dx;
if(x1>x2)
{
dx=-dx;
}
if(y1<y2)
{
dy=-dy;
}



while(x<=x2)
{
plotPoint(x,y);
x++;
if(d<0)
	d=d+ds;
else
{
y++;
d=d+dt;

}
glFlush();
}

}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
// ddaLine(-70,-10,-50,90); //m > 1 steep,positive
 ddaLine(-10,-70,90,-50); //m < 1 gentle positive
 //ddaLine(-10,70,90,50);   //m > -1 gentle negative
 //ddaLine(70,-10,50,90);   //m < -1 steep negative
}


//dont use winReshape
/*void winReshape(GLint nw, GLint nh)
{
 glViewport(0,0,nw,nh);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,GLdouble(nw),0.0,GLdouble(nh));
 ww = nw;
 wh = nh;
}*/

int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,400);
 glutCreateWindow("Line Drawing: bres");
 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();
 return 0;
}
