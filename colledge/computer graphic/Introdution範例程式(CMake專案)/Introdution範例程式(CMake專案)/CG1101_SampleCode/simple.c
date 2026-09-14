/**************************************************************
 *  This program opens a window and draws a white rectangle on 
 *  the window. The black background color of the window is black.
 *  This program shows the usage of callback functions for display,
 *  reshape, keyboard, mouse, and motion events
 *  Copyright:  S. K. Ueng
 *              Dept. of Comp. Sci., National Taiwan Ocean Univ.
 *              09/23/2003.
 */
#include <stdio.h>
#include <stdlib.h>           
#include <GL/freeglut.h>              /* glut.h */

/*-- Width and Height of the window ---*/
int width, height;


/*----------------------------------------------------
 * Draw a rectangle with color=r, g, b centered at (x, y)
 */
void draw_polygon(float r, float g, float b, int x, int y)
{
	/*---- Setup color ------*/
	glColor3f(r, g, b);
    /*----- Draw the rectangle -----*/
	glBegin(GL_POLYGON);
	  glVertex2i(x-10, y-10);
	  glVertex2i(x+10, y-10);
	  glVertex2i(x+10, y+10);
	  glVertex2i(x-10, y+10);
	glEnd();

	glFlush();
}

/*------------------------------------------------
 * Callback func of display event
 * When the window shows up this procedure is called.
 */
void display(void)
{
/* set clear color to black and clear window */
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);


  draw_polygon(1.0, 1.0, 1.0, width/2, height/2);
  fprintf(stderr,"display() is called \n");
}


/*-------------------------------------------------
 * Callback function of reshape event
 *   w: new width of the window, 
 *   h: new height of the window
 */
void my_reshape(int w, int h)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 /*---- Record the dimension of the window ---*/ 
  width = w;
  height = h;

  glOrtho(0.0, w, 0.0, h, -1.0, 1.0);

  glViewport(0, 0, w, h);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glutPostRedisplay();     /* trigger a display event */
  fprintf(stderr,"my_reshape() is called \n");
}


/*------------------------------------------------
 * Callback Function for keyboard events
 * key: the key being pressed, x, y: current mouse position
 */
void my_keyboard(unsigned char key, int x, int y)
{
  fprintf(stderr,"%c key is pressed, cursor is at <%d,%d>\n", 
	  key, x, y);
  if(key=='Q'||key=='q') exit(0);
  else if(key=='c')  glClear(GL_COLOR_BUFFER_BIT);
}


/*----------------------------------------------------
 * Callback function for mouse-motion event.
 *  (x, y): current cursor position in the window
 */
void my_motion(int x, int y)
{
	draw_polygon(1.0, 1.0, 0.0, x, height-y);
}


/*--------------------------------------------------
 * Callback function for mouse event.
 * button: GLUT_LEFT_BUTTON, GL_RIGHT_BUTTON, or GLUT_MIDDLE_BUTTON
 * state: GLUT_DOWN or GLUT_UP
 * (x,y): cursor position.
 */
void my_mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON){
		if(state==GLUT_UP) draw_polygon(1.0, 0.0, 0.0, x, height-y);
	}else if(button==GLUT_RIGHT_BUTTON){
        if(state==GLUT_UP) draw_polygon(0.0, 1.0, 0.0, x, height-y);
	}else if(button==GLUT_MIDDLE_BUTTON){
        if(state==GLUT_UP) draw_polygon(0.0, 0.0, 1.0, x, height-y);
	}
	fprintf(stderr,"mouse is pressed\n");
}

/*--------------------------------------------
 * The main procedure
 */
int main(int argc, char** argv)
{

/* Initialize mode and open a window in upper left corner of screen */
  glutInit(&argc,argv);             /* Make a connection to window system */
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); /* Set display mode */

  /*----set window attribute ------*/
  glutInitWindowSize(800,500);      /* window size */
  glutInitWindowPosition(100,50);      /* initial position */

  /*----create the window ---*/
  glutCreateWindow("Too_simple"); 

  /*----Associate callback functions with events--*/
  glutDisplayFunc(display);         /* display event */
  glutReshapeFunc(my_reshape);      /* reshape event */
  glutKeyboardFunc(my_keyboard);    /* keyboad event */ 
  glutMouseFunc(my_mouse);          /* mouse event   */
  glutMotionFunc(my_motion);        /* motion event  */
  /*----Enter an infinite loop, and wait for events---*/
  glutMainLoop();
}
