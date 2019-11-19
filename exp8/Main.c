#include <GL/gl.h>    
#include <GL/glu.h>    
#include <GL/glut.h>    

#include <stdio.h>      
#include <stdlib.h>    
#include <math.h>

#define WIDTH  1000
#define HEIGHT 1000

#define RED   0
#define GREEN 0
#define BLUE  0
#define ALPHA 1

#define KEY_ESC 27
#define KEY_SPC 32

int squares = 0;
float chx,chy,chz;

GLuint square;

void init_scene();
void render_scene();
GLvoid initGL();
GLvoid window_display();
GLvoid window_reshape(GLsizei width, GLsizei height);
GLvoid window_key(unsigned char key, int x, int y);

int main(int argc, char **argv)
{  
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);

  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow("Square");

  initGL();  
  init_scene();

  glutDisplayFunc(&window_display);
  glutReshapeFunc(&window_reshape);
  glutKeyboardFunc(&window_key);

  glutMainLoop();  

  return 1;
}

GLvoid initGL()
{
  glClearColor(RED, GREEN, BLUE, ALPHA);
}

void init_scene()
{
  square = glGenLists(1);
  glNewList(square, GL_COMPILE);
  glBegin(GL_QUADS); // Draw The Cube Using quads
    glColor3f(0.0f,0.5f,0.0f); // Color Blue
    glVertex3f( 0.5f, 0.5f,-0.5f); // Top Right Of The Quad (Top)
    glVertex3f(-0.5f, 0.5f,-0.5f); // Top Left Of The Quad (Top)
    glVertex3f(-0.5f, 0.5f, 0.5f); // Bottom Left Of The Quad (Top)
    glVertex3f( 0.5f, 0.5f, 0.5f); // Bottom Right Of The Quad (Top)
    glColor3f(0.5f,0.5f,0.0f); // Color Orange
    glVertex3f( 0.5f,-0.5f, 0.5f); // Top Right Of The Quad (Bottom)
    glVertex3f(-0.5f,-0.5f, 0.5f); // Top Left Of The Quad (Bottom)
    glVertex3f(-0.5f,-0.5f,-0.5f); // Bottom Left Of The Quad (Bottom)
    glVertex3f( 0.5f,-0.5f,-0.5f); // Bottom Right Of The Quad (Bottom)
    glColor3f(0.5f,0.0f,0.0f); // Color Red
    glVertex3f( 0.5f, 0.5f, 0.5f); // Top Right Of The Quad (Front)
    glVertex3f(-0.5f, 0.5f, 0.5f); // Top Left Of The Quad (Front)
    glVertex3f(-0.5f,-0.5f, 0.5f); // Bottom Left Of The Quad (Front)
    glVertex3f( 0.5f,-0.5f, 0.5f); // Bottom Right Of The Quad (Front)
    glColor3f(0.5f,0.5f,0.0f); // Color Yellow
    glVertex3f( 0.5f,-0.5f,-0.5f); // Top Right Of The Quad (Back)
    glVertex3f(-0.5f,-0.5f,-0.5f); // Top Left Of The Quad (Back)
    glVertex3f(-0.5f, 0.5f,-0.5f); // Bottom Left Of The Quad (Back)
    glVertex3f( 0.5f, 0.5f,-0.5f); // Bottom Right Of The Quad (Back)
    glColor3f(0.0f,0.0f,0.5f); // Color Blue
    glVertex3f(-0.5f, 0.5f, 0.5f); // Top Right Of The Quad (Left)
    glVertex3f(-0.5f, 0.5f,-0.5f); // Top Left Of The Quad (Left)
    glVertex3f(-0.5f,-0.5f,-0.5f); // Bottom Left Of The Quad (Left)
    glVertex3f(-0.5f,-0.5f, 0.5f); // Bottom Right Of The Quad (Left)
    glColor3f(0.5f,0.0f,0.5f); // Color Violet
    glVertex3f( 0.5f, 0.5f,-0.5f); // Top Right Of The Quad (Right)
    glVertex3f( 0.5f, 0.5f, 0.5f); // Top Left Of The Quad (Right)
    glVertex3f( 0.5f,-0.5f, 0.5f); // Bottom Left Of The Quad (Right)
    glVertex3f( 0.5f,-0.5f,-0.5f); // Bottom Right Of The Quad (Right)
  glEnd();
  glEndList();
}

GLvoid window_display()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);
  render_scene();
  glFlush();
}

GLvoid window_reshape(GLsizei width, GLsizei height)
{
  if (height == 0)
    height = 1;
 
  glViewport(0, 0, width, height);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, (GLdouble)width/(GLdouble)height, 1, 10);
  glMatrixMode(GL_MODELVIEW);
}
 
GLvoid window_key(unsigned char key, int x, int y)
{  
  switch (key) {    
  case KEY_ESC:  
    exit(1);                  
    break;

  case KEY_SPC:  
    squares = (squares+1)%4;                
    glutPostRedisplay();
    break;
   
  default:
    printf ("Pressing %d doesn't do anything.\n", key);
    break;
  }
}

void render_scene()
{
  glColor3f(1, 1, 1);
  glCallList(square);

  if (squares == 1) {
    int ch,angle;
    printf("enter rotation direction: 1.X axis 2.Y axis 3.Z axis\n");
    scanf("%d",&ch);
    printf("enter angle :");
    scanf("%d",&angle);
    switch(ch)
    {
    case 1:
    glRotatef(angle, 1, 0, 0);
   
    break;
    case 2:
    glRotatef(angle, 0, 1, 0);
   
    break;
    case 3:
    glRotatef(angle, 0, 0, 1);
   
    break;
  }
   glColor3f(1, 0, 0);
    glCallList(square);
}

  if (squares == 2) {
    printf("enter scaling factors :");
   
    scanf("%f%f%f",&chx,&chy,&chz);
    glScalef(chx,chy,chz);
    glColor3f(0, 1, 0);
    glCallList(square);
   
    }

  if (squares == 3) {
    printf("enter translation factors :");
   
    scanf("%f%f%f",&chx,&chy,&chz);
    glTranslatef(chx,chy,chz);
    glColor3f(0, 0, 1);

    glCallList(square);
  }
}
	
	
	

