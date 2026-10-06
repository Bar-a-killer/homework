/******************************************************************
 * This program illustrates the fundamental instructions for handling 
 * mouse and keyboeard events
 */
#include <stdio.h>
#include <stdlib.h>

#include <GL/freeglut.h>

int        height=512, width=512;
int        pos_x=-1, pos_y=-1;

void my_reshape(int w, int h);


/*-------------------------------------------------------------
 * reshape callback function for parent window.
 */
void my_reshape(int new_w, int new_h)
{
  height = new_h;
  width = new_w;

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (double) width, 0.0, (double) height);
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
  
  if(pos_x<=0||pos_y<=0){ pos_x = x;  pos_y = y;}
  glRasterPos2i(pos_x, height - pos_y);
  glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int) key);
  pos_x += 10;
  glFinish();
}


/*-------------------------------------------------------
 * Callback func for special key events
 *  key= the special key, predefined in glut lib.
 *  x, y: position of cursor.
 */
void special_key(int key, int x, int y)
{
  switch(key){
  case GLUT_KEY_LEFT:
    fprintf(stderr,"move left\n");
    break;
  case GLUT_KEY_RIGHT:
    fprintf(stderr,"move right\n");
    break;
  case GLUT_KEY_UP:
    fprintf(stderr,"move up\n");
    break;
  case GLUT_KEY_DOWN:
    fprintf(stderr,"move down\n");
    break;
  default:
    break;
  }
}



/*------------------------------------------------------------
 * Callback function handling mouse-press events
 * button: button of mouse,
 * state: status of mouse button, up or down
 * x, y: position of cursor in the window
 */
void mouse_func(int button, int state, int x, int y)
{
  switch(button){
  case GLUT_LEFT_BUTTON:
    if(state==GLUT_UP)
      fprintf(stderr,"left button up\n");
    else if(state==GLUT_DOWN)
      fprintf(stderr,"left button down\n");
    pos_x = x; pos_y = y;
    break;

  case GLUT_MIDDLE_BUTTON:
    if(state==GLUT_DOWN) fprintf(stderr,"middle button is acting\n");
    break;

  case GLUT_RIGHT_BUTTON:
    if(state==GLUT_UP) fprintf(stderr,"right button is up\n");
    else exit(0);
    break;

  default:
    break;
  }
}

    
/*-------------------------------------------------------------
 * motion callback function. The mouse is pressed and moved.
 */
void motion_func(int  x, int y)
{
  glRasterPos2i(x, height - y);
  glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int) '$');
  glFinish();
}


/*-----------------------------------------------------------
 * Passive motion callback function
 */
void passive_motion(int x, int y)
{
  glRasterPos2i(x, height - y);
  glutBitmapCharacter(GLUT_BITMAP_8_BY_13, (int) '.');
}


/*--------------------------------------------------------
 * procedure to clear window
 */
void clear_window(void)
{
  /*Do nothing else but clear window to black colored*/
  glClearColor(0.0, 0.0, 0.0,1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
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
  glutCreateWindow("MouseKeyboard"); 

  glutDisplayFunc(clear_window);    /* Associate display event callback func */
  glutReshapeFunc(my_reshape);  /* Associate reshape event callback func */

  glutKeyboardFunc(keyboard);   /* Callback func for keyboard event */
  glutSpecialFunc(special_key); /* Callback func for special keys */

  glutMouseFunc(mouse_func);  /* Mouse Button Callback func */
  glutMotionFunc(motion_func);/* Mouse motion event callback func */
 /* glutPassiveMotionFunc(passive_motion);*/
  /*Passive motion event func */

  /*---Enter the event loop ----*/
  glutMainLoop();       
}
