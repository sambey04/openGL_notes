#include<GL/glut.h>


void init(void)
{
glClearColor(1.0,1.0,1.0,0.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,150.0);



}



void lineSegment(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(4.0);



glBegin(GL_POINTS);
glVertex2i(180,15);
glVertex2i(80,50);
//glVertex2i(10,15);
glVertex2i(10,145);
glEnd();



//glBegin(GL_LINES);
//glVertex2i(180,15);
//glVertex2i(10,145);
//glEnd();
glFlush();
}


int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(400,300);
glutCreateWindow("Sample programs");

init();
glutDisplayFunc(lineSegment);
glutMainLoop();
return 0;


}

