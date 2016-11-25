#include "../inc/Light.h"


void setupLighting() {

    GLfloat white[] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat cyan[] = {0.f, .8f, .8f, 1.f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan);
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    GLfloat shininess[] = {50};
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);


    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glShadeModel(GL_FLAT);
}

//Standard
void light( int lightNbr) {
    GLfloat light_position[] = { 0,1,0,1};
    GLfloat light_ambient[] = { 0.7, 0.7, 0.5, 0.1 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 0.5, 1.0 };
    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glLightfv(lightNbr, GL_AMBIENT, light_ambient);
    glLightfv(lightNbr, GL_DIFFUSE, light_diffuse);
    glLightfv(lightNbr, GL_SPECULAR, light_specular);
    glLightfv(lightNbr, GL_POSITION, light_position);
    glEnable(lightNbr);
}

//SPOT
void spot(int lightNbr, Pt3D pos, Pt3D target ) {

    Pt3D dir = subtractPt3D(target,pos);
    normalizePt3D(dir);

    GLfloat light1_position[] = { pos->x,pos->y,pos->z,1};
    GLfloat spot_direction[] = { dir->x,dir->y,dir->z,1 };
    GLfloat light1_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat light1_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat light1_specular[] = { 1.0, 0.0, 0.0, 1.0 };

    glLightfv(lightNbr, GL_POSITION, light1_position);
    glLightfv(lightNbr, GL_AMBIENT, light1_ambient);
    glLightfv(lightNbr, GL_DIFFUSE, light1_diffuse);
    glLightfv(lightNbr, GL_SPECULAR, light1_specular);
    glLightf(lightNbr, GL_CONSTANT_ATTENUATION, 0.5);
    glLightf(lightNbr, GL_LINEAR_ATTENUATION, 0.01);
    glLightf(lightNbr, GL_QUADRATIC_ATTENUATION, 0.2);

    glLightf(lightNbr, GL_SPOT_CUTOFF, 10.0);
    glLightfv(lightNbr, GL_SPOT_DIRECTION, spot_direction);
    glLightf(lightNbr, GL_SPOT_EXPONENT, 2.0);
    glEnable(lightNbr);

    glColor3f(1, 1, 1);
    glBegin(GL_LINES);
    glVertex3f(pos->x, pos->y, pos->z);
    addToPt3D(dir, pos);
    glVertex3f(dir->x, dir->y, dir->z);
    glEnd();

    freePt3D(dir);
}

//AMBIENT
void ambient( ) {
    GLfloat ambient[4] = {0.7, 0.6, 0.6, 1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
}
