#include<GL/glut.h>
#include<iostream>

GLint x1=0,y1=0,x2=0,y2=0;
GLint count = 0;
GLint cas=0;

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

void setPixel(GLint x,GLint y)
{
 switch(cas)
 {
  case 0://gp
   plotPoint(x,y);
   printf("%d %d\n",x,y);
   printf("case 0\n");
   break;
  case 1://gn
   plotPoint(x,-y);
   printf("%d %d\n",x,-y);
   printf("case 1\n");
   break;
  case 2://sp
   plotPoint(y,x);
   printf("%d %d\n",y,x);
   printf("case 2\n");
   break;
  case 3://sn
   plotPoint(y,-x);
   printf("%d %d\n",y,-x);
   printf("case 3\n");
   break;
 }
}

void bresLine(GLint x1,GLint y1,GLint x2,GLint y2)
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

 //drawing intended line using DDA
 GLint x=x1,y=y1;
 GLint dx = x2-x1, dy = y2-y1, dT=2*dy-2*dx, dS=2*dy;
 GLint d=2*dy-dx;
 GLint tmp;
 float sign=dy/dx;

 if(x1>x2)//switching of the points
 {
  tmp=x1;
  x1=x2;
  x2=tmp;
  tmp=y1;
  y1=y2;
  y2=tmp;
 }
 if((abs(dx)>abs(dy))&& sign<0)//gentle -ve
{
 cas=1;
 y1=-y1,y2=-y2;
}
if((abs(dx)<abs(dy))&& sign>0)//steep +ve
{
 cas=2;
 tmp=x1;
 x1=y1;
 y1=tmp;
 tmp=x2;
 x2=y2;
 y2=tmp;
}
if((abs(dx)<abs(dy))&& sign<0)//steep -ve
{
 cas=3;
 tmp=x1;
 x1=-y1;
 y1=tmp;
 tmp=x2;
 x2=-y2;
 y2=tmp;
}
 while(x<=x2)
 {
  setPixel(x,y);
  x++;
  if(d<0)
   d=d+dS;
  else
  {
   y++;
   d=d+dT;
  }
  glFlush();
 }
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 bresLine(-70,-10,-50,90); //m > 1 steep,positive
 bresLine(-10,-70,90,-50); //m < 1 gentle positive
 bresLine(-10,70,90,50);   //m > -1 gentle negative
 bresLine(70,-10,50,90);   //m < -1 steep negative
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
 glutCreateWindow("Line Drawing: DDA");
 
 init();
 glutDisplayFunc(display);
 //glutReshapeFunc(winReshape);

 glutMainLoop();
 return 0;
}
