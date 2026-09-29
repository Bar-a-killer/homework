#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <GL/freeglut.h>


#define  SIZEX 1000
#define  SIZEY 1000


int top_m, color_m, file_m, type_m, size_m;
int hight=1024, width=1024;
int mode = 0;
int uiY = 100,uiX = width;
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
float thickness = 8;
bool fullfilled = 0;
float color_[3] = {1.0f,1.0f,1.0f}; //rgb
std::vector<std::pair<int,int> > _67s;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='Q' || key=='q') exit(0);
}

void reshape_(int new_width, int new_hight) {
    uiX = new_width;
}

void mouse_func(int button, int state, int x, int y) {
    if(button != GLUT_LEFT_BUTTON) return;
    if(state == GLUT_DOWN) {
        mode = premode;
        startposX = x;
        startposY = y;
    } else {
        switch(mode) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                //drawline
                glColor3f(color_[0],color_[1],color_[2]);
                glBegin(GL_LINES);
                    glVertex2f(startposX,startposY);
                    glVertex2f(x,y);
                glEnd(GL_LINES);
                break;
            case 3: {
                int r_out = abs(startposY-y);
                int r_in = r_out - 2*thickness;
                if(r_in <= 0) r_in = 0;
                int midx = abs(startposX-x);
                int midy = abs(startposY-y);
                GLUquadric *q = gluNewQuadric();
                glPushMatrix();
                    glTranslatef(midx,midy,0.0f);
                    gluDisk(q,r_in,r_out,128,8);
                glPopMatrix();
                //drawcircle
                break;
            }
            case 4:
                //drawpoly
                break;
            case 5:
                //texting
                break;
            case 6:
                _67s.push_back(std::make_pair(x,y));
                break;
        }
        mode = 0;
    }
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

bool highlow_67 = 0;
int six_high = 0,seven_high = 0;
void timer(int) {
    if(six_high >= 20) highlow_67 = !highlow_67;
    if(highlow_67) {
        six_high--;
        seven_high++;
    } else {
        six_high++;
        seven_high--;
    }
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}
void top_menu_func(int value) {}

int main(int argc, char **argv) {
    //default 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
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
    for(int i = 1;i < 40;i++) {
        glutAddMenuEntry(std::to_string(i).c_str() ,i);
    }

    top_m = glutCreateMenu(top_menu_func);
    glutAddSubMenu("colors", color_m);
    glutAddSubMenu("type"  , type_m);
    glutAddSubMenu("Size"  , size_m);
    glutAddSubMenu("file"  , file_m); 
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutTimerFunc(16, timer, 0);
    //end
    glutMainLoop();
    return 0;
}
