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
glVertex2i(10,145);
glEnd();



glBegin(GL_LINES);
glVertex2i(180,15);
glVertex2i(10,145);
glEnd();



glFlush();



}

void output(int x, int y, int font, char *string)
{
  glColor3f( 1.0, 0, 0 );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
  }    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string);
}


int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(50,100);
glutInitWindowSize(400,300);
glutCreateWindow("Sample programs");
glutFullScreen();
init();
output(0.,0.,)
//glutDisplayFunc(lineSegment);

glutMainLoop();
return 0;


}


