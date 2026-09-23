/******************************************************************
 * This program illustrates the fundamental instructions for handling 
 * mouse and keyboeard events as well as menu buttons.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/freeglut.h>

#define    SIZEX   800
#define    SIZEY   800

#define    MY_QUIT -1
#define    MY_CLEAR -2
#define    MY_SAVE  -3
#define    MY_BLEND -4
#define    MY_LOAD  -5

#define    WHITE   1
#define    RED     2
#define    GREEN   3
#define    BLUE    4

#define    POINT   1
#define    LINE    2
#define    POLYGON 3
#define    CIRCLE  4
#define    CURVE   5

typedef    int   menu_t;
menu_t     top_m, color_m, file_m, type_m;

int        height=512, width=512;
unsigned char  image[SIZEX*SIZEY][4];  /* Image data in main memory */

int        pos_x=-1, pos_y=-1;
float      myColor[3]={0.0,0.0,0.0};
int        obj_type = -1;
int        first=0;      /* flag of initial points for lines and curve,..*/
int        vertex[128][2]; /*coords of vertices */
int        side=0;         /*num of sides of polygon */
float      pnt_size=1.0;

/*------------------------------------------------------------
 * Callback function for display, redisplay, expose events
 * Just clear the window again
 */
void display_func(void)
{
  /* define window background color */
  //glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}


/*-------------------------------------------------------------
 * reshape callback function for window.
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
}


/*---------------------------------------------------------
 * Procedure to draw a polygon
 */
void draw_polygon()
{
  int  i;

  glBegin(GL_POLYGON);
    for(i=0;i<side;i++)
      glVertex2f(vertex[i][0], height-vertex[i][1]);
  glEnd();
  glFinish();
  side = 0;    /* set side=0 for next polygon */
}



/*------------------------------------------------------------
 * Procedure to draw a circle
 */
void draw_circle()
{
  static GLUquadricObj *mycircle=NULL;

  if(mycircle==NULL){
    mycircle = gluNewQuadric();
    gluQuadricDrawStyle(mycircle,GLU_FILL);
  }
  glPushMatrix();
  glTranslatef(pos_x, height-pos_y, 0.0);
  gluDisk(mycircle,
       0.0,           /* inner radius=0.0 */
	  10.0,          /* outer radius=10.0 */
	  16,            /* 16-side polygon */
	   3);
  glPopMatrix();
}


/*------------------------------------------------------------
 * Callback function handling mouse-press events
 */
void mouse_func(int button, int state, int x, int y)
{
  if(button!=GLUT_LEFT_BUTTON||state!=GLUT_DOWN)
    return;

  switch(obj_type){
  case POINT:
    glPointSize(pnt_size);     /*  Define point size */
    glBegin(GL_POINTS);     /*  Draw a point */
       glVertex2f(x, height-y);
    glEnd();
    break;
  case LINE:
    if(first==0){
      first = 1;
      pos_x = x; pos_y = y;
	  glPointSize(pnt_size);
      glBegin(GL_POINTS);   /*  Draw the 1st point */
	    glVertex3f(x, height-y, 0);
      glEnd();
    }else{
      first=0;
      glLineWidth(pnt_size);     /* Define line width */
      glBegin(GL_LINES);    /* Draw the line */
        glVertex2f(pos_x, height - pos_y);
	    glVertex2f(x, height - y);
      glEnd();
    }
    break;
  case POLYGON:  /* Define vertices of poly */
    if(side==0){
      vertex[side][0] = x; vertex[side][1] = y;
      side ++;
    }else{
      if(fabs(vertex[side-1][0]-x) + fabs(vertex[side-1][1]-y)<2)
	    draw_polygon();
      else{
	    glBegin(GL_LINES);
          glVertex2f(vertex[side-1][0], height-vertex[side-1][1]);
	      glVertex2f(x, height-y);
	    glEnd();
	    vertex[side][0] = x; 
		vertex[side][1] = y;
	    side ++;
      }
    }
    break;
  case CIRCLE:
    pos_x = x; pos_y = y;
    draw_circle();
    break;
  default:
      break;
  }
  glFinish();
}


    
/*-------------------------------------------------------------
 * motion callback function. The mouse is pressed and moved.
 */
void motion_func(int  x, int y)
{
  if(obj_type!=CURVE) return;
  if(first==0){
    first = 1;
    pos_x = x; pos_y = y;
  }else{
    glBegin(GL_LINES);
      glVertex3f(pos_x, height-pos_y, 0.0);
      glVertex3f(x, height - y, 0.0);
    glEnd();
    pos_x = x; pos_y = y;
  }
  glFinish();
}

/*--------------------------------------------------------
 * procedure to clear window
 */
void init_window(void)
{
  /*Do nothing else but clear window to black*/

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, (double) width, 0.0, (double) height);
  glViewport(0,0,width, height);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClearColor(0.0, 0.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
}


/*------------------------------------------------------
 * Procedure to initialize data alighment and other stuff
 */
void init_func()
{   glReadBuffer(GL_FRONT);
    glDrawBuffer(GL_FRONT);
	glPixelStorei(GL_PACK_ALIGNMENT, 1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
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
  glColor3f(myColor[0], myColor[1], myColor[2]);
}


/*------------------------------------------------------------
 * Callback function for top menu.
 */
void file_func(int value)
{ 
  int i, j;

  if(value==MY_QUIT) exit(0);
  else if(value==MY_CLEAR) init_window();
  else if(value==MY_SAVE){ /* Save current window */
    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE,
                 image);
	for(i=0;i<width;i++)   /* Assign 0 opacity to black pixels */
	  for(j=0;j<height;j++)
		if(image[i*width+j][0]==0 &&
           image[i*width+j][1]==0 &&
           image[i*width+j][2]==0) image[i*width+j][3] = 0;
		else image[i*width+j][3] = 127; /* Other pixels have A=127*/
  }else if(value==MY_LOAD){ /* Restore the saved image */
	 glRasterPos2i(0, 0);
     glDrawPixels(width, height, 
	       GL_RGBA, GL_UNSIGNED_BYTE, 
	       image);
  }else if(value==MY_BLEND){ /* Blending current image with the saved image */	
	  glEnable(GL_BLEND); 
	  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
      glRasterPos2i(0, 0);
      glDrawPixels(width, height, 
	       GL_RGBA, GL_UNSIGNED_BYTE, 
	       image);
	  glDisable(GL_BLEND);
  }

  glFlush();
}

void size_func(int value)
{
	if(value==1){
	  if(pnt_size<10.0) pnt_size += 1.0;
	}else{
	  if(pnt_size>1.0) pnt_size = pnt_size -1.0;
	}
}

/*---------------------------------------------------------------
 * Callback function for top menu. Do nothing.
 */
void top_menu_func(int value)
{
}


/*-------------------------------------------------------------
 * Callback Func for type_m, define drawing object
 */
void draw_type(int value)
{
  obj_type = value;
  if(value==LINE||value==CURVE)
    first = 0;
  else if(value==POLYGON) side = 0;
}


/*---------------------------------------------------------------
 * Main procedure sets up the window environment.
 */
int main(int argc, char **argv)
{
  int  size_menu;

  glutInit(&argc, argv);    /*---Make connection with server---*/

  glutInitWindowPosition(0,0);  /*---Specify window position ---*/
  glutInitWindowSize(width, height); /*--Define window's height and width--*/

  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA); /*---set display mode---*/
  init_func();

   /* Create parent window */
  glutCreateWindow("Menu"); 
  glClear(GL_COLOR_BUFFER_BIT);

  glutDisplayFunc(display_func); /* Associate display event callback func */
  glutReshapeFunc(my_reshape);  /* Associate reshape event callback func */

  glutKeyboardFunc(keyboard); /* Callback func for keyboard event */

  glutMouseFunc(mouse_func);  /* Mouse Button Callback func */
  glutMotionFunc(motion_func);/* Mouse motion event callback func */

  color_m = glutCreateMenu(color_func); /* Create color-menu */
  glutAddMenuEntry("white", WHITE);
  glutAddMenuEntry("red", RED);
  glutAddMenuEntry("green", GREEN);
  glutAddMenuEntry("blue", BLUE);

  file_m = glutCreateMenu(file_func);   /* Create another menu, file-menu */
  glutAddMenuEntry("save", MY_SAVE);
  glutAddMenuEntry("load", MY_LOAD);
  glutAddMenuEntry("blend", MY_BLEND);
  glutAddMenuEntry("clear", MY_CLEAR);
  glutAddMenuEntry("quit", MY_QUIT);

  type_m = glutCreateMenu(draw_type);   /* Create draw-type menu */
  glutAddMenuEntry("Point", POINT);
  glutAddMenuEntry("Line", LINE);
  glutAddMenuEntry("Poly", POLYGON);
  glutAddMenuEntry("Curve", CURVE);
  glutAddMenuEntry("Circle", CIRCLE);

  size_menu = glutCreateMenu(size_func);
  glutAddMenuEntry("Bigger", 1);
  glutAddMenuEntry("Smaller",2);

  top_m = glutCreateMenu(top_menu_func);/* Create top menu */
  glutAddSubMenu("colors", color_m);    /* add color-menu as a sub-menu */
  glutAddSubMenu("type", type_m);
  glutAddSubMenu("Size", size_menu);
  glutAddSubMenu("file", file_m);       /* add file-menu as a sub-menu */
  glutAttachMenu(GLUT_RIGHT_BUTTON);    /* associate top-menu with right but*/

  /*---Test whether overlay support is available --*/
  if(glutLayerGet(GLUT_OVERLAY_POSSIBLE)){
    fprintf(stderr,"Overlay is available\n");
  }else{
    fprintf(stderr,"Overlay is NOT available, May encounter problems for menu\n");
  }
  /*---Enter the event loop ----*/
  glutMainLoop();       
}
