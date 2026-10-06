/********************************************************************
 *  blend.c
 *  This program draws two overlapping filled polygons
 *  to demonstrate the effect order has on alpha blending results.
 *  Use the 'x' key to change the order of drawing polygons.
 */
#include <stdio.h>

#include <stdlib.h>
#include <GL/freeglut.h>

static int leftFirst = GL_TRUE;
int    height, width;

/*----------------------------------------------------
 * Initialize alpha blending function.
 */
static void init(void)
{
   glEnable (GL_BLEND);      /* Enable blending */

   /* color = src_alpha * src_color + (1-src_alpha) * dst_color */
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glShadeModel (GL_FLAT);
   glClearColor (0.0, 0.0, 0.0, 0.0);
}


/*----------------------------------------------
 * Draw a yellow triangle
 */
static void drawLeftTriangle(void)
{
   /* draw red triangle on left part of screen */

   glBegin (GL_TRIANGLES);
      glColor4f(1.0, 0.0, 0.0, 0.5);
      glVertex3f(0.1*width, 0.9*height, 0.0); 
      glVertex3f(0.1*width, 0.1*height, 0.0); 
      glVertex3f(0.7*width, 0.5*height, 0.0); 
   glEnd();
}

static void drawRightTriangle(void)
{
   /* draw green triangle on RHS of screen */

   glBegin (GL_TRIANGLES);
      glColor4f(0.0, 1.0, 0.0, 0.5);
      glVertex3f(0.9*width, 0.1*height, 0.0); 
      glVertex3f(0.9*width, 0.9*height, 0.0); 
      glVertex3f(0.3*width, 0.5*height, 0.0); 
   glEnd();
}

/*----------------------------
 * Draw a blue rectangle at the center of the window
 */
void drawRectangle(void)
{
  glColor4f(0.0, 0.0, 1.0, 0.333);
  glBegin(GL_POLYGON);
    glVertex3f(0.3*width, 0.3*height, 0.0);
    glVertex3f(0.3*width, 0.7*height, 0.0);
    glVertex3f(0.7*width, 0.7*height, 0.0);
    glVertex3f(0.7*width, 0.3*height, 0.0);
  glEnd();
  glFlush();
}

/*----------------------------------------------
 * Display callback function
 */
void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);

   if (leftFirst) {
      drawLeftTriangle();
      drawRightTriangle();
   }
   else {
      drawRightTriangle();
      drawLeftTriangle();
   }
   glFlush();
}


/*---------------------------------------------
 * Reshape callback function
 */
void reshape(int w, int h)
{
  width = w;
  height = h;

  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D (0.0, (GLfloat) w, 0.0, w);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

/*-----------------------------------------------
 * Keyboard callback function
 */
void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
   case 'x':          /* change drawing order */
   case 'X':
     leftFirst = !leftFirst;
     display();       /*--- Draw the polygons ---*/
     break;
   case 'Q':          /* quit this program */
   case 'q':
     exit(0);
     break;
   case 'D':
   case 'd':
     glDisable(GL_BLEND);
     display();
     break;
   case 'E':
   case 'e':
     glEnable(GL_BLEND);
     display();
     break;
   case 'a':
     display();
     drawRectangle();
     break;
   default:
     break;
   }
}

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize (400, 400);
   glutCreateWindow (argv[0]);
   init();
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keyboard);
   glutDisplayFunc (display);
   glutMainLoop();
}
