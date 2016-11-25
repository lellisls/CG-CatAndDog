#include "../inc/Cat.h"
#include "stdlib.h"
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "math.h"

Cat CreateCat()
{
    Cat cat = (Cat) malloc(sizeof(struct cat));
    cat->position = ZeroPt3D();
    cat->rotation = ZeroPt3D();
    cat->translation = ZeroPt3D();
    cat->stop = 1;
    cat->scale = 1;
    resetCat( cat );
    //HEAD
    cat->head = CreateObject(10, 8);
    AddVertex(cat->head, 0.0, 0.25);
    AddVertex(cat->head, -0.11, 0.25);
    AddVertex(cat->head, -0.3, 0.06);
    AddVertex(cat->head, -0.3, -0.1);
    AddVertex(cat->head, -0.07, -0.27);
    AddVertex(cat->head, 0.07, -0.27);
    AddVertex(cat->head, 0.3, -0.1);
    AddVertex(cat->head, 0.3, 0.06);
    AddVertex(cat->head, 0.11, 0.25);
    AddVertex(cat->head, 0.0, 0.25);
    //TRANSFORMATIONS
    ScaleSlice(cat->head, 0.25, 0.25);
    TranslateSlice(cat->head, 0.0, 0.0, 0.36);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.01, -0.04);
    ScaleSlice(cat->head, 2.0, 1.6);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.02, -0.05);
    ScaleSlice(cat->head, 1.3, 1.5);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.03, -0.08);
    ScaleSlice(cat->head, 1.11, 1.4);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.0, -0.1);
    ScaleSlice(cat->head, 1.13, 1.05);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.0, -0.08);
    ScaleSlice(cat->head, 1.0, 1.00);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.0, -0.05);
    ScaleSlice(cat->head, 0.90, 0.90);
    Extrude(cat->head);
    TranslateSlice(cat->head, 0.0, 0.0, -0.05);
    ScaleSlice(cat->head, 0.80, 0.80);
    FinalizeObject(cat->head);

    //EARS
    cat->earLeft = CreateObject(7, 3);
    AddVertex(cat->earLeft, 0.0, 0.0);
    AddVertex(cat->earLeft, -0.1, 0.0);
    AddVertex(cat->earLeft, -0.12, 0.14);
    AddVertex(cat->earLeft, -0.04, 0.28);
    AddVertex(cat->earLeft, 0.1, 0.14);
    AddVertex(cat->earLeft, 0.1, 0.0);
    AddVertex(cat->earLeft, 0.0, 0.0);
    //TRASFORMATIONS
    Extrude(cat->earLeft);
    ScaleSlice(cat->earLeft, 1.1, 1.3);
    TranslateSlice(cat->earLeft, 0, 0, 0.09);
    Extrude(cat->earLeft);
    ScaleSlice(cat->earLeft, 0.6, 0.6);
    TranslateSlice(cat->earLeft, 0.01, 0, -0.05);
    FinalizeObject(cat->earLeft);

    cat->earRight = CreateObject(7, 3);
    AddVertex(cat->earRight, 0.0, 0.0);
    AddVertex(cat->earRight, 0.1, 0.0);
    AddVertex(cat->earRight, 0.12, 0.14);
    AddVertex(cat->earRight, 0.04, 0.28);
    AddVertex(cat->earRight, -0.1, 0.14);
    AddVertex(cat->earRight, -0.1, 0.0);
    AddVertex(cat->earRight, 0.0, 0.0);
    //TRASFORMATIONS
    Extrude(cat->earRight);
    ScaleSlice(cat->earRight, 1.1, 1.3);
    TranslateSlice(cat->earLeft, 0, 0, 0.09);
    Extrude(cat->earRight);
    ScaleSlice(cat->earRight, 0.6, 0.6);
    TranslateSlice(cat->earRight, -0.01, 0, -0.05);
    FinalizeObject(cat->earRight);

    //BODY
    cat->body = CreateObject(9, 8);
    AddVertex(cat->body, 0.0, 0.58);
    AddVertex(cat->body, -0.55, 0.5);
    AddVertex(cat->body, -0.75, 0.06);
    AddVertex(cat->body, -0.6, -0.3);
    AddVertex(cat->body, 0.0, -0.25);
    AddVertex(cat->body, 0.52, -0.3);
    AddVertex(cat->body, 0.7, 0.06);
    AddVertex(cat->body, 0.56, 0.38);
    AddVertex(cat->body, 0.0, 0.58);
    //TRANSFORMATIONS
    ScaleSlice(cat->body, 1.3, 1.0);
    ScaleSlice(cat->body, 0.24, 0.24);
    TranslateSlice(cat->body, 0, 0.25, 0.12);
    Extrude(cat->body);
    ScaleSlice(cat->body, 1.15, 1.15);
    TranslateSlice(cat->body, 0, 0, -0.03);
    Extrude(cat->body);
    ScaleSlice(cat->body, 1.05, 1.15);
    TranslateSlice(cat->body, 0, 0, -0.05);
    Extrude(cat->body);
    ScaleSlice(cat->body, 1.02, 1.05);
    TranslateSlice(cat->body, 0, 0, -0.04);
    Extrude(cat->body);
    ScaleSlice(cat->body, 0.98, 0.95);
    TranslateSlice(cat->body, 0, 0, -0.04);
    Extrude(cat->body);
    ScaleSlice(cat->body, 0.95, 0.85);
    TranslateSlice(cat->body, 0, 0, -0.05);
    Extrude(cat->body);
    ScaleSlice(cat->body, 0.85, 0.85);
    TranslateSlice(cat->body, 0, 0, -0.03);
    FinalizeObject(cat->body);

    //NECK
    cat->neck = CreateObject(9, 3);
    AddVertex(cat->neck,  0.0 ,  0.5);
    AddVertex(cat->neck,  0.4 ,  0.4);
    AddVertex(cat->neck,  0.5 ,  0.0);
    AddVertex(cat->neck,  0.4 , -0.4);
    AddVertex(cat->neck,  0.0 , -0.5);
    AddVertex(cat->neck, -0.4 , -0.4);
    AddVertex(cat->neck, -0.5 ,  0.0);
    AddVertex(cat->neck, -0.4 ,  0.4);
    AddVertex(cat->neck,  0.0 ,  0.5);

    //TRANSFORMATIONS
    ScaleSlice(cat->neck, 0.15, 0.15);
    Extrude(cat->neck);
    ScaleSlice(cat->neck, 0.85, 0.85);
    TranslateSlice(cat->neck, 0, 0.04, -0.1);
    Extrude(cat->neck);
    ScaleSlice(cat->neck, 0.9, 0.9);
    TranslateSlice(cat->neck, 0, 0.01, -0.1);
    FinalizeObject(cat->neck);

    //TAIL
    cat->tail = CreateCircleObject(9, 6);
    ScaleSlice(cat->tail, 0.1, 0.1);
    Extrude(cat->tail);
    TranslateSlice(cat->tail, 0, 0, 0.2);
    ScaleSlice(cat->tail, 1.1, 1.1);
    Extrude(cat->tail);
    TranslateSlice(cat->tail, 0, 0, 0.3);
    ScaleSlice(cat->tail, 1, 1);
    Extrude(cat->tail);
    TranslateSlice(cat->tail, 0, 0, 0.35);
    ScaleSlice(cat->tail, 0.9, 0.9);
    Extrude(cat->tail);
    TranslateSlice2(cat->tail, 0, 0, 0.5);
    ScaleSlice(cat->tail, 0.8, 0.8);
    RotateSlice(cat->tail, 0, 0, -30.0 / 180.0 * PI);
    Extrude(cat->tail);
    TranslateSlice(cat->tail, 0, 0, 0.58);
    RotateSlice(cat->tail, 0, 0, -60.0 / 180.0 * PI);

    FinalizeObject(cat->tail);

    return cat;
}

void resetCat( Cat cat )
{
    cat->time = 0;
    cat->enabled = 1;
    cat->stamina = 1.0f;
    cat->speed = 0.08;
    cat->leg1 = createLeg3();
    cat->leg2 = createLeg3();
    cat->leg3 = createLeg3();
    cat->leg4 = createLeg3();

    cat->leg1->time = 1;
    cat->leg3->time = 0;
    cat->leg2->time = 0;
    cat->leg4->time = 1;

}

void freeCat(Cat cat)
{
    freeObj(cat->head);
    freeObj(cat->earLeft);
    freeObj(cat->earRight);
    freeObj(cat->body);
    freeObj(cat->neck);
    freeObj(cat->tail);
    freeLeg(cat->leg1);
    freeLeg(cat->leg2);
    freeLeg(cat->leg3);
    freeLeg(cat->leg4);

    free(cat);
}

void drawCat(Cat cat, int mode)
{
    if (cat->enabled) {

        //CAT
        glPushMatrix();
        glTranslatef(cat->translation->x, cat->translation->y, cat->translation->z);
        glTranslatef(cat->position->x, cat->position->y + 0.1, cat->position->z);
        glRotatef(cat->angle, 0, 1, 0);
        glRotatef(sin(cat->time) * 3, 0, 0 , 1);
        glScalef(1.3,1.3,1.3);

        glRotatef(cat->rotation->x,1,0,0);
        glRotatef(cat->rotation->y,0,1,0);
        glRotatef(cat->rotation->z,0,0,1);
        glScalef(cat->scale,cat->scale,cat->scale);

        //HEAD
        glPushMatrix();
        glTranslatef(0.28, 0.40, 0);
        glRotatef(90, 0, 1, 0);
        glRotatef(sin(cat->time) * 5, 1, 0 , 0);
        glScalef(0.45, 0.45, 0.45);
        DrawObject(cat->head, mode);
        glPopMatrix();

        //EARS
        glPushMatrix();
        glTranslatef(0.26, 0.45, 0.065);
        glScalef(0.4, 0.4, 0.4);
        glRotatef(10, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        DrawObject(cat->earLeft, mode);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.26, 0.45, -0.065);
        glScalef(0.4, 0.4, 0.4);
        glRotatef(-10, 1, 0, 0);
        glRotatef(90, 0, 1, 0);
        DrawObject(cat->earRight, mode);
        glPopMatrix();

        //BODY
        DrawObject(cat->body, mode);

        //Neck
        glPushMatrix();
        glTranslatef(0.17, 0.3, 0);
        glRotatef(30, 0, 0, 1);
        glRotatef(-90, 0, 1, 0);
        DrawObject(cat->neck, mode);
        glPopMatrix();

        //Tail
        glPushMatrix();
        glTranslatef(-0.25, 0.25, 0);
        glRotatef(-80, 0, 0, 1);
        glScalef(0.3, 0.3, 0.3);
        glRotatef(-90, 0, 1, 0);
        glRotatef(180, 0, 0, 1);
        glRotatef(sin(cat->time * 1.1) * 10, 0, 1 , 0);
        glRotatef(sin(cat->time) * -5, 1, 0 , 0);
        DrawObject(cat->tail, mode);
        glPopMatrix();

        //LEGS
        glPushMatrix();
        glTranslatef(0.12, 0.3, 0.1);
        drawLeg2(cat->leg1, mode);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.12, 0.3, -0.1);
        drawLeg2(cat->leg2, mode);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.16, 0.3, 0.1);
        drawLeg2(cat->leg3, mode);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(-0.16, 0.3, -0.1);
        drawLeg2(cat->leg4, mode);
        glPopMatrix();


        glPopMatrix();
    }
}

void walkCat(Cat cat, float bounds)
{
    if ( cat->stop == 0) {

        animateCat(cat);
        if (abs(cat->position->x) > bounds  || abs(cat->position->z) > bounds) {
            cat->angle += 10;
        }
        float ang = ((int)cat->angle) % 360;
        cat->position->x += cat->stamina * cat->speed * cos(PI * ang / 180.0f) * (2 + sin(cat->time * 5));
        cat->position->z -= cat->stamina * cat->speed * sin(PI * ang / 180.0f) * (2 + sin(cat->time * 5));
    }
}
void animateCat(Cat cat)
{

    if (cat->stamina > 0.3) {
        cat->stamina -= 0.0005;
    }
    cat->time += 0.15;
    cat->leg1->time += 2 * cat->speed;
    cat->leg3->time += 2 * cat->speed;
    cat->leg2->time += 2 * cat->speed;
    cat->leg4->time += 2 * cat->speed;
}
