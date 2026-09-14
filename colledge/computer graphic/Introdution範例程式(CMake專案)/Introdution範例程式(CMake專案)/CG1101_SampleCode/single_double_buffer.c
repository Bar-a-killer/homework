/*
 *  single.c
 *  This program demonstrates double/single buffering for 
 *  flicker-free animation.  The left and middle mouse
 *  buttons start and stop the spinning motion of the square.
 */
#include <GL/freeglut.h>
#include <stdlib.h>

static GLfloat spin = 0.0;

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glPushMatrix ();
    glRotatef (spin, 0.0, 0.0, 1.0);
    glRectf (-25.0, -25.0, 25.0, 25.0);
    glPopMatrix ();

    glFlush();
	glutSwapBuffers( );
}

//Callback for the IDLE event
void spinDisplay (void)
{
    spin = spin + 2.0;
    if (spin > 360.0)
	spin = spin - 360.0;
    display();
}

void myinit (void)
{
    glClearColor (0.0, 0.0, 0.0, 1.0);
    glColor3f (1.0, 1.0, 1.0);
    glShadeModel (GL_FLAT);
}

void mouse(int btn, int state, int x, int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)  glutIdleFunc(spinDisplay);
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)   glutIdleFunc(NULL);
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) 
	glOrtho (-50.0, 50.0, -50.0*(GLfloat)h/(GLfloat)w, 
	    50.0*(GLfloat)h/(GLfloat)w, -1.0, 1.0);
    else 
	glOrtho (-50.0*(GLfloat)w/(GLfloat)h, 
	    50.0*(GLfloat)w/(GLfloat)h, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
}

/*  Main Loop
 *  Open window with initial window size, title bar, 
 *  RGBA display mode, and handle input events.
 */
int main(int argc, char** argv)
{

	glutInit(&argc,argv);
	//change the following instruction to show the effects.
	//glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);	
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow(argv[0]);
    myinit ();
	glutDisplayFunc(display);
    glutReshapeFunc (myReshape);
    glutIdleFunc (spinDisplay);
    glutMouseFunc (mouse);

	glutMainLoop();

}

