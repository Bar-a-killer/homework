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


int top_m, color_m, file_m, type_m, size_m, full_m, poly_m, font_m, grid_m;
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
   7 eraser
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
std::vector<Six_seven > _67s_copy;
bool highlow_67 = 1;
int six_high = 0,seven_high = 0;
std::vector<GLubyte> canva,canva_copy;
int curx = 0,cury = 0;
std::string text_buffer;
bool texting = 0;
float bgcolor[3] = {255,255,255};
int poly_sides = 4;
void* fonts[] = {
    GLUT_BITMAP_8_BY_13,
    GLUT_BITMAP_9_BY_15,
    GLUT_BITMAP_TIMES_ROMAN_10,
    GLUT_BITMAP_TIMES_ROMAN_24,
    GLUT_BITMAP_HELVETICA_10,
    GLUT_BITMAP_HELVETICA_12,
    GLUT_BITMAP_HELVETICA_18,
};
void* text_font = GLUT_BITMAP_TIMES_ROMAN_24;
bool show_grid = 1;
void drawText(float x, float y, const char *s) {
    glRasterPos2f(x, y);
    for(; *s; ++s) glutBitmapCharacter(text_font, *s);
}

void drawStroke(float x, float y, const char *s, float scale) {
    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(scale, scale, 1);
        for (; *s; ++s) glutStrokeCharacter(GLUT_STROKE_ROMAN, *s);
    glPopMatrix();
}

void drawGrid() {
    int grid_size = 50;
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glLineWidth(1);
    glColor4f(0, 0, 0, 0.1f);
    glBegin(GL_LINES);
    for(int x = 0; x < width; x += grid_size) {
        glVertex2f(x + 0.5f, 0);
        glVertex2f(x + 0.5f, hight);
    }
    for(int y = 0; y < hight; y += grid_size) {
        glVertex2f(0,     y + 0.5f);
        glVertex2f(width, y + 0.5f);
    }
    glEnd();
    glDisable(GL_BLEND);
}
void drawing(int x,int y) {
    glColor3fv(color_);
    glLineWidth(thickness);
    switch(mode) {
        case 0:
            break;
        case 1: {
            glBegin(GL_LINES);
                glVertex2f(startposX,startposY);
                glVertex2f(x,y);
            glEnd();
            GLUquadric *q = gluNewQuadric();
            glPushMatrix();
                glTranslatef(x,y,0.0f);
                gluDisk(q,0,thickness/2,128,8);
            glPopMatrix();
            gluDeleteQuadric(q);
            break;
        }
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
            if(fullfilled) r_in = 0;
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
        case 4: {
            //drawpoly
            float l = std::min(startposX, x), r = std::max(startposX, x);
            float b = std::min(startposY, y), t = std::max(startposY, y);
            std::vector<std::pair<float,float>> v;
            if(poly_sides == 3) {                   
                v = {{l,b}, {r,b}, {(l+r)/2, t}};
            } else if(poly_sides == 4) {
                v = {{l,b}, {r,b}, {r,t}, {l,t}};
            } else {
                float cx = (l+r)/2, cy = (b+t)/2;
                float rx = (r-l)/2, ry = (t-b)/2;
                for(int i = 0; i < poly_sides; i++) {
                    constexpr float pi = 3.14159265358979323846f;
                    float a = pi/2 + 2*pi*i/poly_sides;
                    v.push_back({cx + rx*cos(a), cy + ry*sin(a)});
                }
            }
            glBegin(fullfilled ? GL_POLYGON : GL_LINE_LOOP);
            for(auto &p : v) glVertex2f(p.first, p.second);
            glEnd();
            break;
        }
        case 5:
            //texting
            drawText(startposX, startposY, text_buffer.c_str());
            break;           
        case 7: {
            glColor3fv(bgcolor);
            glBegin(GL_LINES);
                glVertex2f(startposX,startposY);
                glVertex2f(x,y);
            glEnd();
            GLUquadric *q = gluNewQuadric();
            glPushMatrix();
                glTranslatef(x,y,0.0f);
                gluDisk(q,0,thickness/2,128,8);
            glPopMatrix();
            gluDeleteQuadric(q);
            break;
        }

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
    if(show_grid) drawGrid();
    if(mode > 0 && mode < 6)
        drawing(curx,cury);
    draw67_();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    if(texting) {
        if(key < 127 && key >= 32) {
            text_buffer += key;
        } 
        else if(key == 8 || key == 127) {
            if(!text_buffer.empty()) text_buffer.pop_back();
        } 
        else {
            bakecanva(x,y);
            texting = 0;
            mode = 0;
            return;
        }
    }
    else if(key=='Q' || key=='q') exit(0);
}

void reshape_(int new_width, int new_hight) {
    uiX = new_width;
    int old_h = hight,old_w = width;
    hight = new_hight;width = new_width;
    std::vector<GLubyte> old = canva;
    std::vector<GLubyte> old_copy = canva_copy;

    canva.assign((size_t)hight*width*4,255);
    canva_copy.assign((size_t)hight*width*4,255);
    for (int y = 0; y < old_h; ++y) {
        if (y < 0 || y >= hight) continue;
        memcpy(&canva[(size_t)y * width * 4], &old[(size_t)y * old_w * 4],
               (size_t)std::min(old_w, width) * 4);
        memcpy(&canva_copy[(size_t)y * width * 4], &old_copy[(size_t)y * old_w * 4],
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
            case 1: case 2: case 3: case 4: case 7:
                bakecanva(x,y);
                break;
            case 5:
                texting = 1;
                text_buffer.clear();
                return;
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
    if(mode == 1 || mode == 7) {
        bakecanva(curx,cury);
        startposX = curx;
        startposY = cury;
    }
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
        case 4:
            color_[0] = color_[1] = color_[2] = 0;
            break;
    }
}

void file_func(int value) {
    switch (value) {
        case 0: 
            canva_copy = canva;
            _67s_copy = _67s;
            break;
        case 1:
            canva = canva_copy;
            _67s = _67s_copy;
            break;
        case 3:
            canva.assign((size_t)hight*width*4,255); _67s.clear(); glutPostRedisplay(); 
            break;
        case 4: exit(0);
    }
    glLoadIdentity();
}

void draw_type(int value) {
    premode = value;
}
void size_func(int value) {
    thickness = value;
}
void full_func(int value) {
    fullfilled = value;
}
void poly_func(int value) {
    premode = 4;
    poly_sides = value;
}
void font_func(int value) {
    text_font = fonts[value];
}
void grid_func(int value) {
    show_grid = value;
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
    canva_copy.assign((size_t)hight*width*4,255);
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
    glutAddMenuEntry("black", 4);

    file_m = glutCreateMenu(file_func);
    glutAddMenuEntry("save" ,0);
    glutAddMenuEntry("load" ,1);
    glutAddMenuEntry("clear",3);
    glutAddMenuEntry("quit" ,4);

    poly_m = glutCreateMenu(poly_func);
    glutAddMenuEntry("Triangle" , 3);
    glutAddMenuEntry("Rectangle", 4);
    glutAddMenuEntry("Pentagon" , 5);
    glutAddMenuEntry("Hexagon"  , 6);

    type_m = glutCreateMenu(draw_type);  
    glutAddMenuEntry("Draw"   , 1);
    glutAddMenuEntry("Line"   , 2);
    glutAddMenuEntry("Circle" , 3);
    glutAddSubMenu("Polygon", poly_m);
    glutAddMenuEntry("Text"   , 5);
    glutAddMenuEntry("67"     , 6);
    glutAddMenuEntry("Eraser" , 7);

    size_m = glutCreateMenu(size_func);
    for(int i = 5;i < 30;i++) {
        glutAddMenuEntry(std::to_string(i).c_str() ,i);
    }

    full_m = glutCreateMenu(full_func);
    glutAddMenuEntry("On"  ,1);
    glutAddMenuEntry("Off" ,0);

    grid_m = glutCreateMenu(grid_func);
    glutAddMenuEntry("On" , 1);
    glutAddMenuEntry("Off", 0);

    font_m = glutCreateMenu(font_func);
    glutAddMenuEntry("8x13"          , 0);
    glutAddMenuEntry("9x15"          , 1);
    glutAddMenuEntry("Times Roman 10", 2);
    glutAddMenuEntry("Times Roman 24", 3);
    glutAddMenuEntry("Helvetica 10"  , 4);
    glutAddMenuEntry("Helvetica 12"  , 5);
    glutAddMenuEntry("Helvetica 18"  , 6);
    top_m = glutCreateMenu(top_menu_func);
    glutAddSubMenu("colors", color_m);
    glutAddSubMenu("type"  , type_m);
    glutAddSubMenu("Size"  , size_m);
    glutAddSubMenu("file"  , file_m); 
    glutAddSubMenu("Fullfilled",full_m);
    glutAddSubMenu("Grid"  , grid_m);
    glutAddSubMenu("Font"  , font_m);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutTimerFunc(16, timer, 0);
    //end
    glutMainLoop();
    return 0;
}
