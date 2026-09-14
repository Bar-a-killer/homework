/*-----------------------------------------------------
 * This program illustrate the usage of pixel I/O in OpenGL
 */

#include <stdio.h>
#include <GL/freeglut.h>

#define SIZE   200

/*---Declare a 2D array to store images in the frame buffer
     [4] = RGBA 4 bytes
     */

unsigned char  image[SIZE][SIZE][4];
int            pos_x, pos_y;

/*-------------------------------------------------------------
 * Procedure to dump a square area of the window(frame buffer)
 * into an array image[][][4]
 */
void read_pixel()
{
  int  i, j;

  fprintf(stderr,"Read pixels at (%d, %d)\n", pos_x, pos_y);
  glReadBuffer(GL_FRONT);             /* select front buf to read */
  glPixelStorei(GL_PACK_ALIGNMENT, 1);/* define alighment */
  /*---Read the front buffer and store its contents in image[][][] 
   * (pos_x,pos_y) is the lower-left corner. The size is SIZE X SIZE
   */
  glReadPixels(pos_x, 500-pos_y, SIZE, SIZE, 
	       GL_RGBA, GL_UNSIGNED_BYTE, 
	       image);
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINE_LOOP);
    glVertex2i(pos_x, 500-pos_y);
    glVertex2i(pos_x, 500-pos_y+SIZE);
    glVertex2i(pos_x+SIZE, 500-pos_y+SIZE);
    glVertex2i(pos_x+SIZE, 500-pos_y);
  glEnd();
  glFinish();
}

/*--------------------------------------------------------------
 * Procedure to write an image to the window.
 */
void write_pixel()
{
  fprintf(stderr,"Write pixels at (%d, %d)\n", pos_x, pos_y);
  glClearColor(0.1, 0.1, 0.1, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);        /*Clear color buffer */

  glDrawBuffer(GL_FRONT);              /*Select front buf as destination*/
  glPixelStorei(GL_PACK_ALIGNMENT, 1);
  glRasterPos2i(pos_x, 500-pos_y);     /*define upper-left corner position */

  /*--- Write image[][][] to the front buffer ---*/
  glDrawPixels(SIZE, SIZE, 
	       GL_RGBA, GL_UNSIGNED_BYTE, 
	       image);
  glFlush();
}


/*----------------------------------------------------
 * Reshape callback function
 *  make a 2D drawing projection matrix
 */
void myreshape()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 500.0, 0.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}


/*--------------------------------------
 * Display callback function
 */
void display()
{
  /* clear window to white */
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 1.0, 0.0);
  glBegin(GL_POLYGON);
   glVertex3f(100.0, 100.0, 0.0);
   glVertex3f(100.0, 400.0, 0.0);
   glVertex3f(300.0, 200.0, 0.0);
  glEnd();

  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_POLYGON);
   glVertex3f(300.0, 300.0, 0.0);
   glVertex3f(200.0, 250.0, 0.0);
   glVertex3f(300.0, 450.0, 0.0);
  glEnd();
  glFlush();
}

/*------------------------------------
 * keyboard callback func
 */
void mykeyboard(unsigned char key, int x, int y)
{
  switch(key){
  case 'Q': case 'q': exit(0);
  case 'W': case 'w':
    pos_x = x; pos_y = y;
    write_pixel();
    break;
  case 'R': case 'r':
    pos_x = x; pos_y = y;
    read_pixel();
    break;
  default:
    break;
  }
}


int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("square");
    glutDisplayFunc(display);
    glutReshapeFunc(myreshape);
    glutKeyboardFunc(mykeyboard);
    glutMainLoop();
}
