#include<GL/glut.h>
#include<iostream>
#include<math.h>

int n;
int tx,ty,sx,sy;
double o;// for angle


void init(void)
{
 glClearColor(1.0,1.0,1.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-200,200,-200,200.0);
}

void shape(void)
{glClear(GL_COLOR_BUFFER_BIT);

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
int x[] ={20,85,75};
int y[] ={55,55,85};

//normal triangle
glColor3f(1.0,1.0,0.0);
 glBegin(GL_POLYGON);
 glVertex2i(20,55);
 glVertex2i(85,55);
 glVertex2i(75,85);
 glEnd();

if(n==1)
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i<3;i++)
{glVertex2i(x[i]+tx,y[i]+ty);
}
glEnd();
}
else if(n==2)
{

glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i<3;i++)
{glVertex2i(x[i]*sx,y[i]*sy);
}
glEnd();
}

else if(n==3)
{
double oo= (o*22)/(7*180);
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i<3;i++)
{glVertex2i(((x[i]*cos(oo))-(y[i]*sin(oo))),((x[i]*sin(oo))+(y[i]*cos(oo))));
}
glEnd();
}
else if(n==4)
{
glColor3f(0.0,0.0,1.0);
glBegin(GL_POLYGON);
for(int i=0;i<3;i++)
{glVertex2i(x[i],-y[i]);
}
glEnd();
}

glFlush();
}


int main(int argc, char** argv)
{
printf("enter  1 for translation \n 2 for scaling \n 3 for rotation \n 4 for reflection along x-axis \n");
scanf("%d",&n);
if(n==1){
printf("enter translation factor for x and y");
scanf("%d %d",&tx,&ty);
}
else if(n==2)
{
printf("enter scaling factor for x and y");
scanf("%d %d",&sx,&sy);
}
else if(n==3)
{
printf("enter the degree to be rotated");
scanf("%lf",&o);
}
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,100);
 glutInitWindowSize(400,300);
 glutCreateWindow("Sample Programs");
 
 init();
 glutDisplayFunc(shape);
 glutMainLoop();
 return 0;
}
