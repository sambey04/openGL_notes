#include <GL/glut.h>
//#include<dos.h>
#include <chrono>
#include <thread>
#include <unistd.h>

void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,600,0,400);
}

void boat(void)
{
glClear(GL_COLOR_BUFFER_BIT);

glBegin(GL_QUADS);
	glColor3f(0.0,1.0,1.0);
	glVertex2i(0,0);
	glVertex2i(600,0);
	glVertex2i(600,150);
	glVertex2i(0,150);
glEnd();

glBegin(GL_QUADS);
	glColor3f(0.647059,0.164706,0.164706);
	glVertex2i(200,150);
	glVertex2i(400,150);
	glVertex2i(450,200);
	glVertex2i(150,200);
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(0.0,1.0,0.0);
	glVertex2i(280,200);
	glVertex2i(320,200);
	glVertex2i(300,240);
glEnd();

glBegin(GL_LINES);
	glColor3f(0.647059,0.164706,0.164706);
	glVertex2i(300,239);
	glVertex2i(300,290);
glEnd();

glBegin(GL_TRIANGLES);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(300,290);
	glVertex2i(300,270);
	glVertex2i(320,280);
glEnd();
glFlush();

//func1();


//}
while(1){
int i,j;
for(i=20;i<600;i+=40)
{	for(j=130;j>0;j-=60)
	{
	glBegin(GL_LINES);
		glColor3f(0,0,1.0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}
}

for(i=0;i<580;i+=40)
{	for(j=100;j>0;j-=60)
	{
	glBegin(GL_LINES);
		glColor3f(0,0,1.0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}

}
glFlush();
//void delay(100);
usleep(3000);
  //  sleep_for(nanoseconds(10));
  //
//      sleep_for(10ns);
for(i=20;i<600;i+=40)
{	for(j=130;j>0;j-=60)
	{
	glBegin(GL_LINES);
		glColor3f(1.0,0,0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}
}

for(i=0;i<580;i+=40)
{	for(j=100;j>0;j-=60)
	{
	glBegin(GL_LINES);
	glLineWidth(5);
		glColor3f(1.0,0,0);
		glVertex2i(i,j);
		glVertex2i(i+20,j);
	glEnd();
	}
}
glFlush();

usleep(3000);
}
//glFlush();
}



int main(int argc,char** argv)
{
	    using namespace std::this_thread; // sleep_for, sleep_until
    using namespace std::chrono; // nanoseconds, system_clock, seconds


glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(600,400);
glutCreateWindow("Boat Program");

init();
glutDisplayFunc(boat);

//glutDisplayFunc(func1);
glutMainLoop();

return 0;

}
