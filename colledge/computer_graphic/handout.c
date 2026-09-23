#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/freeglut.h>


#define  SIZEX 1500
#define  SIZEY 1000

int hight=1024, width=1024;
 
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
	if(key=='Q' || key=='q') exit(0);
}
int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);    
    glutInitWindowSize(width, hight);
    glutCreateWindow("handout");
    glutKeyboardFunc(keyboard);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
