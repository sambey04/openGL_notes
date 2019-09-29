#include<GL/glut.h>
//#include <GLFW/glfw3.h>
#include<stdio.h>
GLint ww=640, wh=480;
GLint count = 0, x1=0, y1=0, x2=0, y2=0;

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
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

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);

	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}


void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);


	}
	return;
}

void drawline()
{
 glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(x1,y1);
  glVertex2i(x2,y1);
 glEnd();

glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(x2,y1);
  glVertex2i(x2,y2);
 glEnd();

glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(x2,y2);
  glVertex2i(x1,y2);
 glEnd();

glColor3f(0.0,0.0,1.0);
 glBegin(GL_LINES);
  glVertex2i(x1,y2);
  glVertex2i(x1,y1);
 glEnd();

Color newColor = {0.0f, 0.0f, 1.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};

floodFill(x1+5, y1, oldColor, newColor);


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
   count =1;
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
 printf("%d %d\n",xMouse,yMouse);
}





int main(int argc, char** argv)
{
 glutInit(&argc,argv);
 //glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
 glutCreateWindow("flood algorithm");
 
 init();
 
glutMouseFunc(mousePtPlot);

 glutMainLoop();  
 return 0;
}
