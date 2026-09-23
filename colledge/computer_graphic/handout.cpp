#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/freeglut.h>


#define  SIZEX 1500
#define  SIZEY 1000

int hight=1024, width=1024;
int mode = 0;
/*
   0 idle mode
   1 draw mode
   2 line mode
   3 circle mode
   4 polygon mode
   5 text mode
   6 67 mode
   */
int premode = 1;
int startposX = 0,startposY = 0;
int thickness = 1;
bool fullfilled = 0;
int color = 0; //rgb

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='Q' || key=='q') exit(0);
}
int main(int argc, char **argv) {
    //default 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);    
    glutInitWindowSize(width, hight);
    glutCreateWindow("handout");
    glutKeyboardFunc(keyboard);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    //self edit stuff
    glutDisplayFunc(display);

    //hierarchial menux
    glutReshapeFunc(my_reshape); 
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse_func); 
    glutMotionFunc(motion_func);

    color_m = glutCreateMenu(color_func);
    glutAddMenuEntry("white", WHITE);
    glutAddMenuEntry("red", RED);
    glutAddMenuEntry("green", GREEN);
    glutAddMenuEntry("blue", BLUE);

    file_m = glutCreateMenu(file_func);
    glutAddMenuEntry("save", MY_SAVE);
    glutAddMenuEntry("load", MY_LOAD);
    glutAddMenuEntry("blend", MY_BLEND);
    glutAddMenuEntry("clear", MY_CLEAR);
    glutAddMenuEntry("quit", MY_QUIT);

    type_m = glutCreateMenu(draw_type);  
    glutAddMenuEntry("Point", POINT);
    glutAddMenuEntry("Line", LINE);
    glutAddMenuEntry("Poly", POLYGON);
    glutAddMenuEntry("Curve", CURVE);
    glutAddMenuEntry("Circle", CIRCLE);

    size_menu = glutCreateMenu(size_func);
    glutAddMenuEntry("Bigger", 1);
    glutAddMenuEntry("Smaller",2);

    top_m = glutCreateMenu(top_menu_func);
    glutAddSubMenu("colors", color_m);
    glutAddSubMenu("type", type_m);
    glutAddSubMenu("Size", size_menu);
    glutAddSubMenu("file", file_m); 
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //end
    glutMainLoop();
    return 0;
}
