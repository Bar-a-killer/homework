#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <GL/freeglut.h>
#include <cstring>

#define  PI   3.141592653

#define Step  0.1
#define Gravity  0.02
#define JumpSpeed  0.35
#define Body_R  1.2
#define Floor_Size  50
#define MAX_CHILD  6

GLUquadricObj  *sphere=NULL,*cylind=NULL;

typedef enum { SHAPE_NONE,SHAPE_BOX,SHAPE_SPHERE,SHAPE_CYLINDER } ShapeType;
struct DOF {
    int    enabled;
    float  cur,min,max;
};
struct Node {
    const char   *name;
    float         joint_pos[3];
    DOF           rot[3];
    ShapeType     shape;
    float         shape_off[3];
    float         size[3];
    /* BOX: x,y,z
     * SPHERE: size[0]=radius
       CYLINDER: size[0]=radius, size[1]=length */
    float         color[3];
    std::vector<Node*>  child;
};
enum {
    WORLD,FLOOR,AXES,
    OBS_0,OBS_1,OBS_2,OBS_3,OBS_4,OBS_5,OBS_6,OBS_7,
    BALL,ROBOT,
    AXIS_X,AXIS_Y,AXIS_Z,
    PELVIS,TORSO,NECK,HEAD,
    L_SHOULDER,L_ELBOW,L_HAND,
    R_SHOULDER,R_ELBOW,R_HAND,
    L_HIP,L_KNEE,L_FOOT,
    R_HIP,R_KNEE,R_FOOT,
    C_BLAZER,C_SHIRT,C_RIBBON,C_SKIRT,C_COLLAR,
    C_HAIR,C_HAIR_BACK,C_HAIR_LONG,
    C_L_SLEEVE,C_L_CUFF,C_R_SLEEVE,C_R_CUFF,
    C_L_SOCK,C_L_SHOE,C_R_SOCK,C_R_SHOE,
    N_PARTS
};
Node  parts[N_PARTS];

float  &self_ang = parts[ROBOT].rot[1].cur;
/*0 = face +z */
float  *position = parts[ROBOT].joint_pos;

float  fall_speed=0.0;
float  walk_phase=0.0,walk_amp=0.0,jump_amp=0.0;
float  run_amp=0.0,crouch_amp=0.0;
int    walk_dir=1,walk_cnt=0;
int    running=0,crouching=0;
int    posing=0;

#define Ball_R  0.5
int    held=-1;

int width=1000,height=1000;


void make_node(int id  ,const char *name,
               float jx,float jy,float jz,
               ShapeType shape,
               float ox,float oy,float oz,
               float sx,float sy,float sz,
               float r ,float g ,float b ) {
    Node  *n = &parts[id];
    int    i;

    n->name = name;
    n->joint_pos[0] = jx;
    n->joint_pos[1] = jy;
    n->joint_pos[2] = jz;
    n->shape = shape;
    n->shape_off[0] = ox;
    n->shape_off[1] = oy;
    n->shape_off[2] = oz;
    n->size[0] = sx;
    n->size[1] = sy;
    n->size[2] = sz;
    n->color[0] = r;
    n->color[1] = g;
    n->color[2] = b;
    for(i=0;i<3;i++) {
        n->rot[i].enabled = 0;
    }
}

void set_dof(int id,int axis,float min
            ,float max,float init) {
    DOF  *d = &parts[id].rot[axis];

    d->enabled = 1;
    d->min = min;
    d->max = max;
    d->cur = init;
}

void set_angle(int id,int axis,float deg) {
    DOF  *d = &parts[id].rot[axis];

    if(!d->enabled) {
        return;
    }
    if(deg<d->min) {
        deg = d->min;
    }
    if(deg>d->max) {
        deg = d->max;
    }
    d->cur = deg;
}
void build_things() {
    /*        id          name          joint_pos     shape           shape_off    size         color */
    make_node(WORLD,      "world",      0,0,0,        SHAPE_NONE,     0,0,0,       0,0,0,       0,0,0);
    make_node(FLOOR,      "floor",      25,0,25,      SHAPE_BOX,      0,-0.05,0,   50,0.1,50,   0.28,0.3,0.33);
    make_node(AXES,       "axes",       0,0,0,        SHAPE_SPHERE,   0,0,0,       1.0,0,0,     0.9,0.9,0.9);
    make_node(AXIS_X,     "axis_x",     0,0,0,        SHAPE_CYLINDER, 0,3.0,0,     0.3,6.0,0,   0.95,0.95,0.0);
    make_node(AXIS_Y,     "axis_y",     0,0,0,        SHAPE_CYLINDER, 0,3.0,0,     0.3,6.0,0,   0.95,0.0,0.95);
    make_node(AXIS_Z,     "axis_z",     0,0,0,        SHAPE_CYLINDER, 0,3.0,0,     0.3,6.0,0,   0.0,0.95,0.95);
    parts[AXIS_X].rot[2].cur = -90.0;
    parts[AXIS_Z].rot[0].cur = 90.0;

    make_node(OBS_0,      "obs_box",    12,0,12,      SHAPE_BOX,      0,1.0,0,     4.0,2.0,4.0, 0.9,0.6,0.2);
    make_node(OBS_1,      "obs_box",    36,0,14,      SHAPE_BOX,      0,0.75,0,    6.0,1.5,3.0, 0.2,0.8,0.8);
    make_node(OBS_2,      "obs_box",    14,0,38,      SHAPE_BOX,      0,2.0,0,     3.0,4.0,3.0, 0.8,0.2,0.7);
    make_node(OBS_3,      "obs_box",    38,0,38,      SHAPE_BOX,      0,1.25,0,    5.0,2.5,5.0, 0.7,0.8,0.2);
    make_node(OBS_4,      "obs_sphere", 25,0,10,      SHAPE_SPHERE,   0,1.5,0,     1.5,0,0,     0.9,0.3,0.2);
    make_node(OBS_5,      "obs_cylind", 10,0,25,      SHAPE_CYLINDER, 0,1.0,0,     1.5,2.0,0,   0.3,0.9,0.3);
    make_node(OBS_6,      "obs_cylind", 40,0,25,      SHAPE_CYLINDER, 0,3.0,0,     1.0,6.0,0,   0.6,0.4,0.9);
    make_node(OBS_7,      "obs_sphere", 25,0,42,      SHAPE_SPHERE,   0,2.0,0,     2.0,0,0,     0.2,0.6,0.9);

    make_node(BALL,       "ball",       30,Ball_R,30, SHAPE_SPHERE,   0,0,0,       Ball_R,0,0,  1.0,0.9,0.0);
    make_node(ROBOT,      "robot",      25,0,25,      SHAPE_NONE,     0,0,0,       0,0,0,       0,0,0);

    make_node(PELVIS,     "pelvis",     0,4.4,0,      SHAPE_NONE,     0,0,0,       0,0,0,       0,0,0);
    make_node(TORSO,      "torso",      0,0,0,        SHAPE_BOX,      0,1.5,0,     2.3,2.9,1.1, 1.0,0.85,0.75);
    make_node(NECK,       "neck",       0,3.0,0,      SHAPE_CYLINDER, 0,0.1,0,     0.3,0.2,0,   1.0,0.85,0.75);
    make_node(HEAD,       "head",       0,0.2,0,      SHAPE_BOX,      0,0.6,0,     1.2,1.2,1.2, 1.0,0.85,0.75);

    make_node(L_SHOULDER, "l_upperarm", 1.5,2.8,0,    SHAPE_BOX,      0,-0.9,0,    0.5,1.7,0.5, 1.0,0.85,0.75);
    make_node(L_ELBOW,    "l_forearm",  0,-1.8,0,     SHAPE_BOX,      0,-0.8,0,    0.4,1.5,0.4, 1.0,0.85,0.75);
    make_node(L_HAND,     "l_hand",     0,-1.6,0,     SHAPE_SPHERE,   0,-0.3,0,    0.35,0,0,    1.0,0.85,0.75);

    make_node(R_SHOULDER, "r_upperarm", -1.5,2.8,0,   SHAPE_BOX,      0,-0.9,0,    0.5,1.7,0.5, 1.0,0.85,0.75);
    make_node(R_ELBOW,    "r_forearm",  0,-1.8,0,     SHAPE_BOX,      0,-0.8,0,    0.4,1.5,0.4, 1.0,0.85,0.75);
    make_node(R_HAND,     "r_hand",     0,-1.6,0,     SHAPE_SPHERE,   0,-0.3,0,    0.35,0,0,    1.0,0.85,0.75);

    make_node(L_HIP,      "l_thigh",    0.6,0,0,      SHAPE_BOX,      0,-1.0,0,    0.8,2.0,0.8, 1.0,0.85,0.75);
    make_node(L_KNEE,     "l_shin",     0,-2.0,0,     SHAPE_BOX,      0,-1.0,0,    0.65,2.0,0.65,1.0,0.85,0.75);
    make_node(L_FOOT,     "l_foot",     0,-2.0,0,     SHAPE_BOX,      0,-0.2,0.25, 0.75,0.35,1.25,1.0,0.85,0.75);

    make_node(R_HIP,      "r_thigh",    -0.6,0,0,     SHAPE_BOX,      0,-1.0,0,    0.8,2.0,0.8, 1.0,0.85,0.75);
    make_node(R_KNEE,     "r_shin",     0,-2.0,0,     SHAPE_BOX,      0,-1.0,0,    0.65,2.0,0.65,1.0,0.85,0.75);
    make_node(R_FOOT,     "r_foot",     0,-2.0,0,     SHAPE_BOX,      0,-0.2,0.25, 0.75,0.35,1.25,1.0,0.85,0.75);

    make_node(C_BLAZER,   "blazer",     0,0,0,        SHAPE_BOX,      0,1.5,0,     2.4,3.0,1.2, 0.52,0.46,0.43);
    make_node(C_SHIRT,    "shirt",      0,0,0,        SHAPE_BOX,      0,2.4,0.61,  0.6,1.2,0.06,0.95,0.95,0.97);
    make_node(C_RIBBON,   "ribbon",     0,0,0,        SHAPE_BOX,      0,2.75,0.66, 0.35,0.25,0.06,0.8,0.1,0.15);
    make_node(C_SKIRT,    "skirt",      0,0,0,        SHAPE_BOX,      0,-0.5,0,    2.6,1.4,1.5, 0.25,0.35,0.62);
    make_node(C_COLLAR,   "collar",     0,0,0,        SHAPE_BOX,      0,0.1,0,     0.65,0.2,0.65,0.95,0.95,0.97);
    make_node(C_HAIR,     "hair",       0,0,0,        SHAPE_BOX,      0,1.0,-0.05, 1.3,0.6,1.35, 0.35,0.2,0.45);
    make_node(C_HAIR_BACK,"hair_back",  0,0,0,        SHAPE_BOX,      0,0.55,-0.4, 1.3,1.1,0.5, 0.35,0.2,0.45);
    make_node(C_HAIR_LONG,"hair_long",  0,0,0,        SHAPE_BOX,      0,1.65,-0.8, 1.4,3.1,0.4, 0.35,0.2,0.45);
    make_node(C_L_SLEEVE, "l_sleeve",   0,0,0,        SHAPE_BOX,      0,-0.9,0,    0.6,1.8,0.6, 0.52,0.46,0.43);
    make_node(C_L_CUFF,   "l_cuff",     0,0,0,        SHAPE_BOX,      0,-0.8,0,    0.5,1.6,0.5, 0.52,0.46,0.43);
    make_node(C_R_SLEEVE, "r_sleeve",   0,0,0,        SHAPE_BOX,      0,-0.9,0,    0.6,1.8,0.6, 0.52,0.46,0.43);
    make_node(C_R_CUFF,   "r_cuff",     0,0,0,        SHAPE_BOX,      0,-0.8,0,    0.5,1.6,0.5, 0.52,0.46,0.43);
    make_node(C_L_SOCK,   "l_sock",     0,0,0,        SHAPE_BOX,      0,-1.6,0,    0.7,0.8,0.7, 0.95,0.95,0.97);
    make_node(C_L_SHOE,   "l_shoe",     0,0,0,        SHAPE_BOX,      0,-0.2,0.25, 0.8,0.4,1.3, 0.3,0.2,0.15);
    make_node(C_R_SOCK,   "r_sock",     0,0,0,        SHAPE_BOX,      0,-1.6,0,    0.7,0.8,0.7, 0.95,0.95,0.97);
    make_node(C_R_SHOE,   "r_shoe",     0,0,0,        SHAPE_BOX,      0,-0.2,0.25, 0.8,0.4,1.3, 0.3,0.2,0.15);

    for(int i=FLOOR;i<=ROBOT;i++) {
        parts[WORLD].child.push_back(&parts[i]);
    }
    parts[AXES].child.push_back(&parts[AXIS_X]);
    parts[AXES].child.push_back(&parts[AXIS_Y]);
    parts[AXES].child.push_back(&parts[AXIS_Z]);
    parts[ROBOT].child.push_back(&parts[PELVIS]);
    parts[PELVIS].child.push_back(&parts[TORSO]);
    parts[TORSO].child.push_back(&parts[NECK]);
    parts[NECK].child.push_back(&parts[HEAD]);
    parts[TORSO].child.push_back(&parts[L_SHOULDER]);
    parts[L_SHOULDER].child.push_back(&parts[L_ELBOW]);
    parts[L_ELBOW].child.push_back(&parts[L_HAND]);
    parts[TORSO].child.push_back(&parts[R_SHOULDER]);
    parts[R_SHOULDER].child.push_back(&parts[R_ELBOW]);
    parts[R_ELBOW].child.push_back(&parts[R_HAND]);
    parts[PELVIS].child.push_back(&parts[L_HIP]);
    parts[L_HIP].child.push_back(&parts[L_KNEE]);
    parts[L_KNEE].child.push_back(&parts[L_FOOT]);
    parts[PELVIS].child.push_back(&parts[R_HIP]);
    parts[R_HIP].child.push_back(&parts[R_KNEE]);
    parts[R_KNEE].child.push_back(&parts[R_FOOT]);

    parts[TORSO].child.push_back(&parts[C_BLAZER]);
    parts[TORSO].child.push_back(&parts[C_SHIRT]);
    parts[TORSO].child.push_back(&parts[C_RIBBON]);
    parts[PELVIS].child.push_back(&parts[C_SKIRT]);
    parts[NECK].child.push_back(&parts[C_COLLAR]);
    parts[HEAD].child.push_back(&parts[C_HAIR]);
    parts[HEAD].child.push_back(&parts[C_HAIR_BACK]);
    parts[TORSO].child.push_back(&parts[C_HAIR_LONG]);
    parts[L_SHOULDER].child.push_back(&parts[C_L_SLEEVE]);
    parts[L_ELBOW].child.push_back(&parts[C_L_CUFF]);
    parts[R_SHOULDER].child.push_back(&parts[C_R_SLEEVE]);
    parts[R_ELBOW].child.push_back(&parts[C_R_CUFF]);
    parts[L_KNEE].child.push_back(&parts[C_L_SOCK]);
    parts[L_FOOT].child.push_back(&parts[C_L_SHOE]);
    parts[R_KNEE].child.push_back(&parts[C_R_SOCK]);
    parts[R_FOOT].child.push_back(&parts[C_R_SHOE]);

    set_dof(TORSO,     1, -90.0, 90.0,0.0);
    set_dof(TORSO,     0, -10.0, 60.0,0.0);
    set_dof(NECK,      1, -80.0, 80.0,0.0);
    set_dof(NECK,      0, -30.0, 40.0,0.0);
    set_dof(L_SHOULDER,0,-180.0, 60.0,0.0);
    set_dof(L_SHOULDER,2,   0.0,120.0,0.0);
    set_dof(L_ELBOW,   0,-140.0,  0.0,0.0);
    set_dof(L_HAND,    0, -60.0, 60.0,0.0);
    set_dof(R_SHOULDER,0,-180.0, 60.0,0.0);
    set_dof(R_SHOULDER,2,-120.0,  0.0,0.0);
    set_dof(R_ELBOW,   0,-140.0,  0.0,0.0);
    set_dof(R_HAND,    0, -60.0, 60.0,0.0);
    set_dof(L_HIP,     0,-100.0, 45.0,0.0);
    set_dof(L_HIP,     2,   0.0, 45.0,0.0);
    set_dof(L_KNEE,    0,   0.0,140.0,0.0);
    set_dof(L_FOOT,    0, -60.0, 60.0,0.0);
    set_dof(R_HIP,     0,-100.0, 45.0,0.0);
    set_dof(R_HIP,     2, -45.0,  0.0,0.0);
    set_dof(R_KNEE,    0,   0.0,140.0,0.0);
    set_dof(R_FOOT,    0, -60.0, 60.0,0.0);
}

void  myinit() {
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glEnable(GL_DEPTH_TEST);
    if(sphere==NULL) {
        sphere = gluNewQuadric();
        gluQuadricDrawStyle(sphere,GLU_FILL);
        gluQuadricNormals(sphere,GLU_SMOOTH);
    }
    if(cylind==NULL) {
        cylind = gluNewQuadric();
        gluQuadricDrawStyle(cylind,GLU_FILL);
        gluQuadricNormals(cylind,GLU_SMOOTH);
    }
}

void draw_shape(Node *n) {
    static const float  points[][3] = {{-0.5,-0.5,-0.5},{0.5 ,-0.5,-0.5},
                                       {0.5 ,0.5 ,-0.5},{-0.5,0.5 ,-0.5},
                                       {-0.5,-0.5,0.5 },{0.5 ,-0.5,0.5 },
                                       {0.5 ,0.5 ,0.5 },{-0.5,0.5 ,0.5 }};
    static const int    face[][4] = {{0,3,2,1},{0,1,5,4},{1,2,6,5},
                                     {4,5,6,7},{2,3,7,6},{0,4,7,3}};
    static const float  shade[6] = {0.6,0.8,0.7,1.0,0.9,0.7};

    glPushMatrix();
    glTranslatef(n->shape_off[0],n->shape_off[1],
                 n->shape_off[2]);
    if(n->shape==SHAPE_BOX) {
        glScalef(n->size[0],n->size[1],n->size[2]);
        for(int i=0;i<6;i++) {
            glColor3f(n->color[0]*shade[i],n->color[1]*shade[i]
                    ,n->color[2]*shade[i]);
            glBegin(GL_POLYGON);
                glVertex3fv(points[face[i][0]]);
                glVertex3fv(points[face[i][1]]);
                glVertex3fv(points[face[i][2]]);
                glVertex3fv(points[face[i][3]]);
            glEnd();
        }
    } else if(n->shape==SHAPE_SPHERE) {
        glColor3fv(n->color);
        gluSphere(sphere,n->size[0],16,16);
    } else if(n->shape==SHAPE_CYLINDER) {
        glColor3fv(n->color);
        glTranslatef(0.0,n->size[1]/2.0,0.0);
        glRotatef(90.0,1.0,0.0,0.0);
        gluCylinder(cylind,n->size[0],n->size[0],
                    n->size[1],16,2);
        gluDisk(cylind,0.0,n->size[0],16,1);
        glTranslatef(0.0,0.0,n->size[1]);
        gluDisk(cylind,0.0,n->size[0],16,1);
    }
    glPopMatrix();
}

void draw_node(Node *n) {
    glPushMatrix();
    glTranslatef(n->joint_pos[0],n->joint_pos[1],n->joint_pos[2]);
    glRotatef(n->rot[1].cur,0.0,1.0,0.0);
    glRotatef(n->rot[0].cur,1.0,0.0,0.0);
    glRotatef(n->rot[2].cur,0.0,0.0,1.0);

    draw_shape(n);

    for(int i=0;i<(int)n->child.size();i++) {
        draw_node(n->child[i]);
    }
    glPopMatrix();
}

void get_extent(Node *o,float *hx,float *hz,float *bottom,float *top) {
    float  hy = o->size[1]/2.0;

    *hx = o->size[0];
    *hz = o->size[0];
    if(o->shape==SHAPE_BOX) {
        *hx = o->size[0]/2.0;
        *hz = o->size[2]/2.0;
    } else if(o->shape==SHAPE_SPHERE) {
        hy = o->size[0];
    }
    *bottom = o->shape_off[1]-hy;
    *top = o->shape_off[1]+hy;
}

float ground_height(float x,float z,float r) {
    float  h=0.0,hx,hz,bottom,top;

    for(int i=OBS_0;i<=BALL;i++) {
        Node  *o = &parts[i];
        if(i==held) {
            continue;
        }
        get_extent(o,&hx,&hz,&bottom,&top);
        top += o->joint_pos[1];
        if(fabs(x-o->joint_pos[0])<hx+r &&
           fabs(z-o->joint_pos[2])<hz+r &&
           top>h) {
            h = top;
        }
    }
    return h;
}

void update_pose() {
    float  s = sin(walk_phase),c = cos(walk_phase);
    float  l_knee = c<0.0 ? -c : 0.0;
    float  r_knee = c>0.0 ? c : 0.0;
    float  r = run_amp<0.5 ? 0.0 : (run_amp-0.5)*2.0;
    float  w = walk_amp*(1.0-r),ra = walk_amp*r;
    float  bend = 55.0*crouch_amp;

    if(walk_amp==0.0 && jump_amp==0.0 && crouch_amp==0.0) {
        if(!posing) {
            return;    
        }
        posing = 0;
    } else {
        posing = 1;
    }

    parts[PELVIS].joint_pos[1] = 0.4+4.0*cos(bend*PI/180.0);
    set_angle(TORSO,0,20.0*run_amp+20.0*crouch_amp);

    set_angle(L_HIP,0,w*30.0*s+ra*(-30.0+50.0*s)
            -jump_amp*40.0-bend);
    set_angle(R_HIP,0,-w*30.0*s+ra*(-30.0-50.0*s)
            -jump_amp*40.0-bend);
    set_angle(L_KNEE,0,w*45.0*l_knee
            +ra*(30.0+35.0*(1.0-s))+jump_amp*70.0+2.0*bend);
    set_angle(R_KNEE,0,w*45.0*r_knee
            +ra*(30.0+35.0*(1.0+s))+jump_amp*70.0+2.0*bend);
    set_angle(L_FOOT,0,-bend);
    set_angle(R_FOOT,0,-bend);

    set_angle(L_SHOULDER,0,-(w*25.0+ra*60.0)*s
            -jump_amp*30.0-crouch_amp*40.0);
    set_angle(L_ELBOW,0,-w*20.0-ra*90.0);
    if(held<0) {
        set_angle(R_SHOULDER,0,(w*25.0+ra*60.0)*s
                -jump_amp*30.0-crouch_amp*40.0);
        set_angle(R_ELBOW,0,-w*20.0-ra*90.0);
    }
}


void approach(float *amp,float target,float rate) {
    if(*amp<target) {
        *amp += rate;
        if(*amp>target) {
            *amp = target;
        }
    } else {
        *amp -= rate;
        if(*amp<target) {
            *amp = target;
        }
    }
}


void walk_step() {
    float  step = Step*(1.0+1.5*run_amp);
    float  x = position[0]+walk_dir*step*sin(self_ang*PI/180.0);
    float  z = position[2]+walk_dir*step*cos(self_ang*PI/180.0);

    if(x<Body_R || x>Floor_Size-Body_R || z<Body_R || z>Floor_Size-Body_R) {
        return;
    }
    if(ground_height(x,z,Body_R)>position[1]+0.01) {
        return;
    }
    position[0] = x;
    position[2] = z;
}


void my_timer(int value) {
    float  ground;

    if(walk_cnt>0) {
        walk_cnt--;
        walk_step();
        walk_phase += walk_dir*(0.18+0.12*run_amp);
    }
    approach(&walk_amp,walk_cnt>0 ? 1.0 : 0.0,0.1);
    approach(&run_amp,walk_cnt>0 && running ? 1.0 : 0.0,0.05);
    approach(&crouch_amp,crouching ? 1.0 : 0.0,0.08);

    ground = ground_height(position[0],position[2],Body_R);
    position[1] += fall_speed;
    fall_speed -= Gravity;
    if(position[1]<=ground) {
        position[1] = ground;
        fall_speed = 0.0;
    }
    approach(&jump_amp,position[1]>ground+0.01 ? 1.0 : 0.0,0.08);

    update_pose();
    glutPostRedisplay();
    glutTimerFunc(16,my_timer,0);
}

void grab_or_drop() {
    float  dx,dz,d,best=3.0,hx,hz,bottom,top;
    std::vector<Node*>  &hand = parts[R_HAND].child,&world = parts[WORLD].child;
    Node  *o;

    if(held>=0) {
        o = &parts[held];
        get_extent(o,&hx,&hz,&bottom,&top);
        d = (Body_R+(hx>hz ? hx : hz))*1.5;
        hand.erase(std::find(hand.begin(),hand.end(),o));
        world.push_back(o);
        o->joint_pos[0] = position[0]+d*sin(self_ang*PI/180.0);
        o->joint_pos[2] = position[2]+d*cos(self_ang*PI/180.0);
        o->joint_pos[1] = ground_height(o->joint_pos[0],o->joint_pos[2],
                                        hx>hz ? hx : hz)-bottom;
        held = -1;
        set_angle(R_SHOULDER,0,0.0);
        set_angle(R_ELBOW,0,0.0);
    } else {
        for(int i=OBS_0;i<=BALL;i++) {
            o = &parts[i];
            get_extent(o,&hx,&hz,&bottom,&top);
            dx = o->joint_pos[0]-position[0];
            dz = o->joint_pos[2]-position[2];
            d = sqrt(dx*dx+dz*dz)-(hx>hz ? hx : hz);
            if(d<best && fabs(o->joint_pos[1]+bottom-position[1])<5.0) {
                best = d;
                held = i;
            }
        }
        if(held>=0) {
            o = &parts[held];
            get_extent(o,&hx,&hz,&bottom,&top);
            world.erase(std::find(world.begin(),world.end(),o));
            hand.push_back(o);
            o->joint_pos[0] = 0.0;
            o->joint_pos[1] = -0.3-parts[R_HAND].size[0]-top;
            o->joint_pos[2] = 0.0;
            set_angle(R_SHOULDER,0,-70.0);
            set_angle(R_ELBOW,0,-20.0);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(45.0,70.0,55.0,25.0,0.0,0.0,0.0,1.0,0.0);

    draw_node(&parts[WORLD]);

    glutSwapBuffers();
    return;
}

void my_reshape(int w,int h) {
    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        glOrtho(-40.0,40.0,-40.0,40.0,0.0,120.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void my_quit(unsigned char key,int x,int y) {
    if(key=='Q'||key=='q') {
        exit(0);
    }
    if(key=='w') {             /* walk forward */
        if(!crouching) {
            walk_dir = 1;
            walk_cnt = 40;
            running = 0;
        }
    } else if(key=='s') {      /* walk backward */
        if(!crouching) {
            walk_dir = -1;
            walk_cnt = 40;
            running = 0;
        }
    } else if(key=='r') {      /* run forward */
        if(!crouching) {
            walk_dir = 1;
            walk_cnt = 40;
            running = 1;
        }
    } else if(key=='c') {      /* crouch down / stand up */
        crouching = !crouching;
        if(crouching) {
            walk_cnt = 0;
        }
    } else if(key=='a') {      /* turn left */
        self_ang += 10.0;
    } else if(key=='d') {      /* turn right */
        self_ang -= 10.0;
    } else if(key==' ') {      /* jump, only from the ground */
        if(position[1]<=ground_height(position[0],position[2],Body_R)+0.01) {
            fall_speed = JumpSpeed;
        }
    } else if(key=='e') {      /* pick up or put down the ball */
        grab_or_drop();
    } else if(key=='h') {      /* left shoulder */
        set_angle(L_SHOULDER,0,parts[L_SHOULDER].rot[0].cur-5.0);
    } else if(key=='H') {
        set_angle(L_SHOULDER,0,parts[L_SHOULDER].rot[0].cur+5.0);
    } else if(key=='k') {      /* right shoulder */
        set_angle(R_SHOULDER,0,parts[R_SHOULDER].rot[0].cur-5.0);
    } else if(key=='K') {
        set_angle(R_SHOULDER,0,parts[R_SHOULDER].rot[0].cur+5.0);
    } else if(key=='n') {      /* left hip */
        set_angle(L_HIP,0,parts[L_HIP].rot[0].cur-5.0);
    } else if(key=='N') {
        set_angle(L_HIP,0,parts[L_HIP].rot[0].cur+5.0);
    } else if(key=='m') {      /* right hip */
        set_angle(R_HIP,0,parts[R_HIP].rot[0].cur-5.0);
    } else if(key=='M') {
        set_angle(R_HIP,0,parts[R_HIP].rot[0].cur+5.0);
    } else if(key=='b') {      /* left knee */
        set_angle(L_KNEE,0,parts[L_KNEE].rot[0].cur+5.0);
    } else if(key=='B') {
        set_angle(L_KNEE,0,parts[L_KNEE].rot[0].cur-5.0);
    } else if(key==',') {      /* right knee */
        set_angle(R_KNEE,0,parts[R_KNEE].rot[0].cur+5.0);
    } else if(key=='<') {
        set_angle(R_KNEE,0,parts[R_KNEE].rot[0].cur-5.0);
    } else if(key=='g') {      /* left elbow */
        set_angle(L_ELBOW,0,parts[L_ELBOW].rot[0].cur-5.0);
    } else if(key=='G') {
        set_angle(L_ELBOW,0,parts[L_ELBOW].rot[0].cur+5.0);
    } else if(key=='l') {      /* right elbow */
        set_angle(R_ELBOW,0,parts[R_ELBOW].rot[0].cur-5.0);
    } else if(key=='L') {
        set_angle(R_ELBOW,0,parts[R_ELBOW].rot[0].cur+5.0);
    } else if(key=='f') {      /* left wrist */
        set_angle(L_HAND,0,parts[L_HAND].rot[0].cur-5.0);
    } else if(key=='F') {
        set_angle(L_HAND,0,parts[L_HAND].rot[0].cur+5.0);
    } else if(key==';') {      /* right wrist */
        set_angle(R_HAND,0,parts[R_HAND].rot[0].cur-5.0);
    } else if(key==':') {
        set_angle(R_HAND,0,parts[R_HAND].rot[0].cur+5.0);
    } else if(key=='u') {      /* turn the head */
        set_angle(NECK,1,parts[NECK].rot[1].cur+5.0);
    } else if(key=='U') {
        set_angle(NECK,1,parts[NECK].rot[1].cur-5.0);
    } else if(key=='j') {      /* bend the waist */
        set_angle(TORSO,0,parts[TORSO].rot[0].cur+5.0);
    } else if(key=='J') {
        set_angle(TORSO,0,parts[TORSO].rot[0].cur-5.0);
    }
    glutPostRedisplay();
}

int main(int argc,char **argv) {
    build_things();
    
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB| GLUT_DEPTH);

    glutInitWindowSize(width,height);
    glutCreateWindow("robot");

    myinit();

    glutDisplayFunc(display);
    glutReshapeFunc(my_reshape);
    glutKeyboardFunc(my_quit);
    glutTimerFunc(16,my_timer,0);

    glutMainLoop();
    return 0;
}