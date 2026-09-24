#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <GL/freeglut.h>


#define  SIZEX 1500
#define  SIZEY 1000

int top_m, color_m, file_m, type_m, size_m;
int hight=1024, width=1024;
int mode = 0;
int premode = 1;
/*******************
   0 idle mode
   1 draw mode
   2 line mode
   3 circle mode
   4 polygon mode
   5 text mode
   6 67 mode
********************/
int startposX = 0,startposY = 0;
int thickness = 1;
bool fullfilled = 0;
float color_[3] = {0}; //rgb

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='Q' || key=='q') exit(0);
}

void reshape_(int width, int hight) {

}

void mouse_func(int button, int state, int x, int y) {

}

void motion_func(int x, int y) {

}

void color_func(int value) {
    switch(value) {
        case 0:
            color_[0] = color_[1] = color_[2] = 1.0;
            break; 
        case 1:
            color_[0] = 1.0;color_[1] = color_[2] = 0;
            break;
        case 2:
            color_[0] = 0;color_[1] = 1.0;color_[2] = 0;
            break;
        case 3:
            color_[0] = color_[1] = 0;color_[2] = 1.0;
            break;
    }
}

void file_func(int value) {

}

void draw_type(int value) {
    premode = value;
}
void size_func(int value) {
    thickness = value;
}
void top_menu_func(int value) {}

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
    glutReshapeFunc(reshape_); 
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse_func); 
    glutMotionFunc(motion_func);

    color_m = glutCreateMenu(color_func);
    glutAddMenuEntry("white", 0);
    glutAddMenuEntry("red"  , 1);
    glutAddMenuEntry("green", 2);
    glutAddMenuEntry("blue" , 3);

    file_m = glutCreateMenu(file_func);
    glutAddMenuEntry("save" ,0);
    glutAddMenuEntry("load" ,1);
    glutAddMenuEntry("blend",2);
    glutAddMenuEntry("clear",3);
    glutAddMenuEntry("quit" ,4);

    type_m = glutCreateMenu(draw_type);  
    glutAddMenuEntry("Draw"   , 1);
    glutAddMenuEntry("Line"   , 2);
    glutAddMenuEntry("Circle" , 3);
    glutAddMenuEntry("Polygon", 4);
    glutAddMenuEntry("Text"   , 5);
    glutAddMenuEntry("67"     , 6);

    size_m = glutCreateMenu(size_func);
    for(int i = 0;i < 40;i++) {
        glutAddMenuEntry("0"+i ,i);
    }

    top_m = glutCreateMenu(top_menu_func);
    glutAddSubMenu("colors", color_m);
    glutAddSubMenu("type"  , type_m);
    glutAddSubMenu("Size"  , size_m);
    glutAddSubMenu("file"  , file_m); 
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //end
    glutMainLoop();
    return 0;
}
