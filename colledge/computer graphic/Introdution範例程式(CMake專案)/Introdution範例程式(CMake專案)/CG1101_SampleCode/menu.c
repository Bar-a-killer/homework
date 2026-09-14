/******************************************************************
 * This program illustrates the fundamental instructions for creating 
 * pop-up menu with glut library. This problem handle
 * mouse and keyboeard events as well as menu buttons.
 */
#include <stdio.h>
#include <stdlib.h>

#include <GL/freeglut.h>

#define    MY_QUIT -1
#define    MY_CLEAR -2

#define    WHITE   1
#define    RED     2
#define    GREEN   3
#define    BLUE    4

typedef    int   menu_t;

menu_t     top_m, color_m, file_m;

int        height=512, width=512;
int        pos_x=-1, pos_y=-1;
float      myColor[3]={0.0,0.0,0.0};

/*------------------------------------------------------------
 * Callback function for display, redisplay, expose events
 */
void display_func(void)
{
  /* define window background color */
  glClearColor(myColor[0], myColor[1], myColor[2], 0.0);
  glClear(GL_COLOR_BUFFER_BIT);  /* clear color buffers, clear window */
  glFlush();
}

/*-------------------------------------------------------------
 * reshape callback function for parent window.
 */
void my_reshape(int new_w, int new_h)
{
  height = new_h;
  width = new_w;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
 
  gluOrtho2D(0.0, (double) width,0.0, (double) height);
  glViewport(0,0,width,height);
  glMatrixMode(GL_MODELVIEW);

  glutPostRedisplay();   /*---Trigger Display event for redisplay window*/
}


/*--------------------------------------------------------------
 * Callback function for keyboard event.
 * key = the key pressed,
 * (x,y)= position in the window, where the key is pressed.
 */
void keyboard(unsigned char key, int x, int y)
{
  if(key=='Q'||key=='q') exit(0);
}


/*------------------------------------------------------------
 * Callback function handling mouse-press events
 */
void mouse_func(int button, int state, int x, int y)
{
  
  if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN){ 
    pos_x = x; pos_y = y;  
	glColor3f(0.1, 0.1, 0.1);

  }else if(button==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN){
	  glPointSize(4.0);

	  glColor3f(0.10, 0.1, 0.10);
	  glBegin(GL_POINTS);
	    glVertex2i(x, height-y);
	  glEnd();	
	  glFinish();
  }
}
    
/*-------------------------------------------------------------
 * motion callback function. The mouse is pressed and moved.
 */
void motion_func(int  x, int y)
{
  glRasterPos2i(x, height-y);

  glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int) '$');
  glFinish();
}

/*--------------------------------------------------------
 * procedure to clear window
 */
void init_window(void)
{
 
/*-- Set Up projection and viewing matrices ---*/
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (double) width, 0.0, (double) height);
  glViewport(0,0,width, height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

 /*Do nothing else but clear window to the background color*/
  glClearColor(myColor[0], myColor[1], myColor[2], 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}



/*-----------------------------------------------------------------
 * Callback function for color menu
 */
void  color_func(int value)
{
  switch(value){
  case WHITE:
    myColor[0] = myColor[1] = myColor[2] = 1.0;
    break;

  case RED:
    myColor[0] = 1.0;
    myColor[1] = myColor[2] = 0.0;
    break;

  case GREEN:
    myColor[0] = myColor[2] = 0.0;
    myColor[1] = 1.0;
    break;
    
  case BLUE:
    myColor[0] = myColor[1] = 0.0;
    myColor[2] = 1.0;
    break;

  default:
    break;
  }
}


/*------------------------------------------------------------
 * Callback function for top menu.
 */
void file_func(int value)
{
  if(value==MY_QUIT) exit(0);
  else if(value==MY_CLEAR) init_window();
}

/*---------------------------------------------------------------
 * Callback function for top menu. Do nothing.
 */
void top_menu_func(int value)
{
}

/*---------------------------------------------------------------
 * Main procedure sets up the window environment.
 */
int main(int argc, char **argv)
{
  glutInit(&argc, argv);    /*---Make connection with server---*/

  glutInitWindowPosition(0,0);  /*---Specify window position ---*/
  glutInitWindowSize(width, height); /*--Define window's height and width--*/

  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA); /*---set display mode---*/
     /* Create parent window */
  glutCreateWindow("Menu"); 

  glutDisplayFunc(display_func); /* Associate display event callback func */
  glutReshapeFunc(my_reshape);  /* Associate reshape event callback func */

  glutKeyboardFunc(keyboard); /* Callback func for keyboard event */
  glutMouseFunc(mouse_func);  /* Mouse Button Callback func */
  glutMotionFunc(motion_func);/* Mouse motion event callback func */

  /*- create sub-menus ----*/
  color_m = glutCreateMenu(color_func); /* Create color-menu */
  glutAddMenuEntry("white", WHITE);
  glutAddMenuEntry("red", RED);
  glutAddMenuEntry("green", GREEN);
  glutAddMenuEntry("blue", BLUE);

  file_m = glutCreateMenu(file_func);   /* Create another sub-menu, file-menu */
  glutAddMenuEntry("clear", MY_CLEAR);
  glutAddMenuEntry("quit", MY_QUIT);

  top_m = glutCreateMenu(top_menu_func);/* Create top menu */
  glutAddSubMenu("colors", color_m);    /* add color-menu as a sub-menu */
  glutAddSubMenu("file", file_m);       /* add file-menu as a sub-menu */
  glutAttachMenu(GLUT_RIGHT_BUTTON);    /* associate top-menu with right but*/

  /*---Enter the event loop ----*/
  glutMainLoop();       
}
