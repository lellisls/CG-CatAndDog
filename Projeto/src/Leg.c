#include "../inc/Leg.h"
#include "stdlib.h"
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "math.h"

//Pernas DOG
Leg* createLeg()
{
    Leg * leg = (Leg *) malloc(sizeof(struct leg));

    leg->ang1 = 0;
    leg->ang2 = 0;
    leg->ang3 = 0;
    leg->maxAngle = 30;
    leg->maxAngle2 = 15;
    leg->time = 0;

    //Top part of the Leg
    //Base 2D shape
    leg->part1 = CreateObject(10, 3);
    AddVertex(leg->part1,  0.0,  0.42);
    AddVertex(leg->part1, -0.2,  0.4);
    AddVertex(leg->part1, -0.3,  0.2);
    AddVertex(leg->part1, -0.3,  0);
    AddVertex(leg->part1, -0.13, -0.5);
    AddVertex(leg->part1,  0.13, -0.5);
    AddVertex(leg->part1,  0.3,  0);
    AddVertex(leg->part1,  0.3,  0.2);
    AddVertex(leg->part1,  0.2,  0.4);
    AddVertex(leg->part1,  0.0,  0.42);
    //3D Transformations
    TranslateSlice(leg->part1, 0, -0.2, -0.1);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 1.2, 1.2);
    TranslateSlice(leg->part1, 0, 0, 0.1);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 1 / 1.2, 1 / 1.2);
    TranslateSlice(leg->part1, 0, 0, 0.1);
    FinalizeObject(leg->part1);

    //Bottom part of the leg
    //Base 2D shape
    leg->part2 = CreateObject(8, 3);
    AddVertex(leg->part2, 0,  0.45);
    AddVertex(leg->part2, -0.15,  0.4);
    AddVertex(leg->part2, -0.15,  0);
    AddVertex(leg->part2, -0.08, -0.65);
    AddVertex(leg->part2, 0.08, -0.65);
    AddVertex(leg->part2, 0.15,  0);
    AddVertex(leg->part2, 0.15,  0.4);
    AddVertex(leg->part2, 0,  0.45);
    //3D Transformations
    TranslateSlice(leg->part2, 0, -0.3, -0.1);
    Extrude(leg->part2);
    ScaleSlice(leg->part2, 1.2, 1.2);
    TranslateSlice(leg->part2, 0, 0, 0.1);
    Extrude(leg->part2);
    ScaleSlice(leg->part2, 1 / 1.2, 1 / 1.2);
    TranslateSlice(leg->part2, 0, 0, 0.1);
    FinalizeObject(leg->part2);

    //Bottom part of the leg
    //Base 2D shape
    leg->part3 = CreateObject(8, 6);
    AddVertex(leg->part3, -0.2, -0.1);
    AddVertex(leg->part3, -0.2, 0.1);
    AddVertex(leg->part3, 0.2, 0.1);
    AddVertex(leg->part3, 0.2, -0.1);
    AddVertex(leg->part3, -0.2, -0.1);
    //3D Transformations
    TranslateSlice(leg->part3, 0, -0.65, -0.85);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 1.4, 1.5);
    TranslateSlice(leg->part3, 0, 0.05, 0.5);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0, 0.3);
    Extrude(leg->part3);
    TranslateSlice2(leg->part3, 0, 0, 0.3);
    RotateSlice(leg->part3, 0, 0, 30);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0.5, 0);
    ScaleSlice(leg->part3, 0.7, 0.7);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0.1, 0);
    ScaleSlice(leg->part3, 0.7, 0.7);
    FinalizeObject(leg->part3);

    return leg;
}

Leg* createLeg2()
{
    Leg * leg = (Leg *) malloc(sizeof(struct leg));

    leg->ang1 = 0;
    leg->ang2 = 0;
    leg->ang3 = 0;
    leg->maxAngle = 45;
    leg->maxAngle2 = 15;
    leg->time = 0;

    //Top part of the Leg
    //Base 2D shape
    leg->part1 = CreateObject(10, 3);

    AddVertex(leg->part1,  0.0,  0.42);
    AddVertex(leg->part1, -0.2,  0.4);
    AddVertex(leg->part1, -0.3,  0.2);
    AddVertex(leg->part1, -0.3,  0);
    AddVertex(leg->part1, -0.13, -0.5);
    AddVertex(leg->part1,  0.13, -0.5);
    AddVertex(leg->part1,  0.3,  0);
    AddVertex(leg->part1,  0.3,  0.2);
    AddVertex(leg->part1,  0.2,  0.4);
    AddVertex(leg->part1,  0.0,  0.42);
    //3D Transformations
    ScaleSlice(leg->part1, 1, 1.2);
    TranslateSlice(leg->part1, 0, -0.2, -0.1);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 1.2, 1.2);
    TranslateSlice(leg->part1, 0, 0, 0.1);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 1 / 1.2, 1 / 1.2);
    TranslateSlice(leg->part1, 0, 0, 0.1);
    FinalizeObject(leg->part1);
    //Bottom part of the leg
    //Base 2D shape
    leg->part2 = CreateObject(8, 3);
    AddVertex(leg->part2, 0,  0.45);
    AddVertex(leg->part2, -0.15,  0.4);
    AddVertex(leg->part2, -0.15,  0);
    AddVertex(leg->part2, -0.08, -0.65);
    AddVertex(leg->part2, 0.08, -0.65);
    AddVertex(leg->part2, 0.15,  0);
    AddVertex(leg->part2, 0.15,  0.4);
    AddVertex(leg->part2, 0,  0.45);
    //3D Transformations
    ScaleSlice(leg->part1, 1, 0.7);
    TranslateSlice(leg->part2, 0, -0.5, -0.1);
    Extrude(leg->part2);
    ScaleSlice(leg->part2, 1.2, 1.2);
    TranslateSlice(leg->part2, 0, 0, 0.1);
    Extrude(leg->part2);
    ScaleSlice(leg->part2, 1 / 1.2, 1 / 1.2);
    TranslateSlice(leg->part2, 0, 0, 0.1);
    FinalizeObject(leg->part2);
    //Base 2D shape
    leg->part3 = CreateObject(8, 6);
    AddVertex(leg->part3, -0.2, -0.1);
    AddVertex(leg->part3, -0.2, 0.1);
    AddVertex(leg->part3, 0.2, 0.1);
    AddVertex(leg->part3, 0.2, -0.1);
    AddVertex(leg->part3, -0.2, -0.1);
    //3D Transformations
    TranslateSlice(leg->part3, 0, -0.7, -0.85);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 1.4, 1.5);
    TranslateSlice(leg->part3, 0, 0.05, 0.5);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0, 0.3);
    Extrude(leg->part3);
    TranslateSlice2(leg->part3, 0, 0, 0.3);
    RotateSlice(leg->part3, 0, 0, 30);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0.5, 0);
    ScaleSlice(leg->part3, 0.7, 0.7);
    Extrude(leg->part3);
    TranslateSlice(leg->part3, 0, 0.1, 0);
    ScaleSlice(leg->part3, 0.7, 0.7);
    FinalizeObject(leg->part3);

    return leg;
}
//Pernas CAT
Leg* createLeg3()
{
    Leg * leg = (Leg *) malloc(sizeof(struct leg));

    leg->ang1 = 0;
    leg->ang2 = 0;
    leg->ang3 = 0;
    leg->maxAngle = 20;
    leg->maxAngle2 = 15;
    leg->time = 0;

    //Top part of the Leg
    //Base 2D shape
    leg->part1 = CreateObject(10, 8);
    AddVertex(leg->part1,  0.0,   0.5);
    AddVertex(leg->part1, -0.25,  0.5);
    AddVertex(leg->part1, -0.5,   0.25);
    AddVertex(leg->part1, -0.5,  -0.25);
    AddVertex(leg->part1, -0.25, -0.5);
    AddVertex(leg->part1,  0.25, -0.5);
    AddVertex(leg->part1,  0.5,  -0.25);
    AddVertex(leg->part1,  0.5,   0.25);
    AddVertex(leg->part1,  0.25,  0.5);
    AddVertex(leg->part1,  0.0,   0.5);
    //3D Transformations
    ScaleSlice(leg->part1, 0.75, 0.4);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 1.2, 1.1);
    TranslateSlice(leg->part1, 0, 0, 0.25);
    Extrude(leg->part1);
    TranslateSlice(leg->part1, 0, 0.0, 0.25);
    Extrude(leg->part1);
    ScaleSlice(leg->part1, 0.5, 0.75);
    TranslateSlice(leg->part1, 0.1, 0, 0.5);
    Extrude(leg->part1);
    TranslateSlice(leg->part1, 0.0, 0, 0.1);
    Extrude(leg->part1);
    TranslateSlice(leg->part1, 0.025, 0, 0.3);
    Extrude(leg->part1);
    TranslateSlice(leg->part1, 0.038, 0, 0.2);
    Extrude(leg->part1);
    TranslateSlice(leg->part1, 0.038, 0, 0.2);
    ScaleSlice(leg->part1, 0.3, 1);
    FinalizeObject(leg->part1);
//    //Bottom part of the leg
//    //Base 2D shape
    leg->part2 = CreateObject(10, 5);
    AddVertex(leg->part2,  0.0,   0.5);
    AddVertex(leg->part2, -0.25,  0.5);
    AddVertex(leg->part2, -0.5,   0.25);
    AddVertex(leg->part2, -0.5,  -0.25);
    AddVertex(leg->part2, -0.25, -0.5);
    AddVertex(leg->part2,  0.25, -0.5);
    AddVertex(leg->part2,  0.5,  -0.25);
    AddVertex(leg->part2,  0.5,   0.25);
    AddVertex(leg->part2,  0.25,  0.5);
    AddVertex(leg->part2,  0.0,   0.5);
//    //3D Transformations
    TranslateSlice(leg->part2, 0, 0, 0 );
    ScaleSlice(leg->part2, 0.35, 0.33);
    Extrude(leg->part2);
    TranslateSlice(leg->part2, 0.011, 0, 0.2);
    ScaleSlice(leg->part2, 1.28, 1.0);
    Extrude(leg->part2);
    TranslateSlice(leg->part2, 0.012, 0, 0.05);
    Extrude(leg->part2);
    TranslateSlice(leg->part2, 0.038, 0, 0.4);
    Extrude(leg->part2);
    ScaleSlice(leg->part2, 0.9, 1);
    TranslateSlice(leg->part2, 0.05, 0, 0.2);
    FinalizeObject(leg->part2);
//    //Bottom part of the leg
//    //Base 2D shape
    leg->part3 = CreateObject(17, 6);
    AddVertex(leg->part3,  0,   -0.2);
    AddVertex(leg->part3, -0.1, -0.2);
    AddVertex(leg->part3, -0.25, 0.0);
    AddVertex(leg->part3, -0.25, 0.1);
    AddVertex(leg->part3, -0.3,  0.3);
    AddVertex(leg->part3, -0.18, 0.4);
    AddVertex(leg->part3, -0.18, 0.5);
    AddVertex(leg->part3, -0.03, 0.55);
    AddVertex(leg->part3,  0,    0.52);
    AddVertex(leg->part3,  0.03, 0.55);
    AddVertex(leg->part3,  0.18, 0.5);
    AddVertex(leg->part3,  0.18, 0.4);
    AddVertex(leg->part3,  0.3,  0.3);
    AddVertex(leg->part3,  0.25, 0.1);
    AddVertex(leg->part3,  0.25, 0.0);
    AddVertex(leg->part3,  0.1, -0.2);
    AddVertex(leg->part3,  0,   -0.2);
//    //3D Transformations
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 1.12, 1.13);
    TranslateSlice(leg->part3, 0, 0.02, 0.1);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 1.08, 1.02);
    TranslateSlice(leg->part3, 0, 0.02, 0.08);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 1.0, 1.0);
    TranslateSlice(leg->part3, 0, 0.01, 0.05);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 0.9, 0.95);
    TranslateSlice(leg->part3, 0, 0.01, 0.08);
    Extrude(leg->part3);
    ScaleSlice(leg->part3, 0.9, 0.9);
    TranslateSlice(leg->part3, 0, 0.01, 0.08);
    FinalizeObject(leg->part3);

    return leg;
}

//DOG
void drawLeg(Leg* leg, int mode)
{
    leg->ang1 = sin(leg->time) * leg->maxAngle;
    leg->ang2 = sin(leg->time) * leg->maxAngle - leg->maxAngle2;
    leg->ang3 = sin(leg->time) * leg->maxAngle2 - leg->maxAngle2;
    glPushMatrix();
    glRotatef(leg->ang1, 0, 0, 1);
    glScalef(0.2, 0.2, 0.2);
    DrawObject(leg->part1, mode);
    glPushMatrix();
    glTranslatef(0, -0.65, 0);
    glRotatef(leg->ang2, 0, 0, 1);
    DrawObject(leg->part2, mode);
    glPushMatrix();
    glTranslatef(0, -1, 0);
    glScalef(0.4, 0.4, 0.4);
    glRotatef(leg->ang3, 0, 0, 1);
    glRotatef(-90, 0, 1, 0);
    DrawObject(leg->part3, mode);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

//CAT
void drawLeg2(Leg* leg, int mode)
{
    leg->ang1 = sin( leg->time ) * leg->maxAngle;
    leg->ang2 = sin( leg->time ) * leg->maxAngle - leg->maxAngle2;
    leg->ang3 = sin( leg->time ) * leg->maxAngle2 - leg->maxAngle2;
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glRotatef(90, 1, 0, 0);
    glRotatef(leg->ang1,0,1,0);
    glScalef(0.5, 0.5, 0.5);
    DrawObject(leg->part1, mode);
    glPushMatrix();
    glTranslatef(0.15,0,1.5);
    glRotatef(leg->ang2,0,1,0);
//    glTranslatef(0.,0,0);
    DrawObject(leg->part2, mode);
    glPushMatrix();
    glTranslatef(0.0, 0, 0.75);
    glScalef(0.85, 0.9, 1);
    glRotatef(-leg->ang3,0,1,0);
    glRotatef(-90, 0, 0, 1);
    DrawObject(leg->part3, mode);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void freeLeg(Leg * leg)
{
    freeObj(leg->part1);
    freeObj(leg->part2);
    freeObj(leg->part3);
    free(leg);
}

