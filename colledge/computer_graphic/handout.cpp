#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <GL/freeglut.h>
#include <cstring>

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
float color_[3] = {0.0f,0.0f,0.0f}; //rgb
struct Six_seven {
    std::pair<int,int> pos;
    float color[3] = {0,0,0};
    float scale = 0.4;
    float thickness = 8;
};
std::vector<Six_seven > _67s;
bool highlow_67 = 1;
int six_high = 0,seven_high = 0;
std::vector<GLubyte> canva;
int curx = 0,cury = 0;
void drawing(int x,int y) {
    glColor3fv(color_);
    glLineWidth(thickness);
    switch(mode) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            //drawline
            glBegin(GL_LINES);
                glVertex2f(startposX,startposY);
                glVertex2f(x,y);
            glEnd();
            break;
        case 3: {
            //drawcircle
            int r_out = (int)(hypot(x - startposX, y - startposY) / 2);
            int r_in = r_out - thickness;
            if(r_in <= 0) r_in = 0;
            int midx = (startposX+x)/2;
            int midy = (startposY+y)/2;
            GLUquadric *q = gluNewQuadric();
            glPushMatrix();
                glTranslatef(midx,midy,0.0f);
                gluDisk(q,r_in,r_out,128,8);
            glPopMatrix();
            gluDeleteQuadric(q);
            break;
        }
        case 4:
            //drawpoly
            break;
        case 5:
            //texting
            break;            
    }
}
 
// main memory -> back buffer
void restoreCanvas() {
    glRasterPos2i(0, 0);
    glDrawPixels(width, hight, GL_RGBA, GL_UNSIGNED_BYTE, canva.data());
}
 
// back buffer -> main memory
void saveCanvas() {
    glReadBuffer(GL_BACK);
    glReadPixels(0, 0, width, hight, GL_RGBA, GL_UNSIGNED_BYTE, canva.data());
}

void drawStroke(float x, float y, const char *s, float scale) {
    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(scale, scale, 1);
        for (; *s; ++s) glutStrokeCharacter(GLUT_STROKE_ROMAN, *s);
    glPopMatrix();
}

void draw67_() {
    for(auto i:_67s) {
        glLineWidth(i.thickness);
        glColor3fv(i.color);
        float cw = 104.76f * i.scale; 
        drawStroke(i.pos.first-cw-5,i.pos.second+six_high,"6",i.scale);
        drawStroke(i.pos.first+5,i.pos.second+seven_high,"7",i.scale);
    }
}
void bakecanva(int x,int y) {
    glDrawBuffer(GL_BACK);
    glClear(GL_COLOR_BUFFER_BIT);
    restoreCanvas();
    drawing(x,y);
    saveCanvas();
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    restoreCanvas();
    if(mode > 0 && mode < 4)
        drawing(curx,cury);
    draw67_();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if(key=='Q' || key=='q') exit(0);
}

void reshape_(int new_width, int new_hight) {
    uiX = new_width;
    int old_h = hight,old_w = width;
    hight = new_hight;width = new_width;
    std::vector<GLubyte> old = canva;

    canva.assign((size_t)hight*width*4,255);
    for (int y = 0; y < old_h; ++y) {
        if (y < 0 || y >= hight) continue;
        memcpy(&canva[(size_t)y * width * 4], &old[(size_t)y * old_w * 4],
               (size_t)std::min(old_w, width) * 4);
    }

    glViewport(0, 0, width, hight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, hight);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse_func(int button, int state, int x, int y) {
    y = hight-1-y;
    if(button != GLUT_LEFT_BUTTON) return;
    if(state == GLUT_DOWN) {
        mode = premode;
        startposX = curx = x;
        startposY = cury = y;
    } else {
        switch(mode) {
            case 1: case 2: case 3: case 4: 
                bakecanva(x,y);
                break;
            case 6:
                _67s.push_back({std::make_pair(x,y),
                    {color_[0],color_[1],color_[2]},thickness/8.0f*0.4f,thickness});
                break;
        }
        mode = 0;
    }
}

void motion_func(int x, int y) {
    curx = x;
    cury = hight-1-y;
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
    switch (value) {
        case 3: canva.assign((size_t)hight*width*4,255); _67s.clear(); glutPostRedisplay(); break;
        case 4: exit(0);
    }
}

void draw_type(int value) {
    premode = value;
}
void size_func(int value) {
    thickness = value;
}

void timer(int) {
    if(six_high >= 30) highlow_67 = 1;
    if(six_high <= -30) highlow_67 = 0;
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
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    canva.assign((size_t)hight*width*4,255);
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
