#include "../inc/Dog.h"
#include "stdlib.h"
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "math.h"
Dog  CreateDog()
{
    Dog dog = (Dog) malloc(sizeof(struct dog));
    dog->time = 0;
    dog->position = ZeroPt3D();
    dog->translation = ZeroPt3D();
    dog->rotation = ZeroPt3D();
    dog->direction = CreatePt3D(0,0,1);
    dog->scale = 1;
    dog->speed = 0;
    dog->enabled = 0;
    dog->maxSpeed = 0.08;
    dog->sit = 0;
    dog->angle2 = 0;
    //Pernas da frente
    //Direita
    dog->leg2 = createLeg();
    dog->leg2->time = 0.0;
    //Esquerda
    dog->leg4 = createLeg();
    dog->leg4->time = 0.2;
    //Pernas de trás
    //Direita
    dog->leg1 = createLeg2();
    dog->leg1->time = 1.2;
    //Esquerda
    dog->leg3 = createLeg2();
    dog->leg3->time = 1.5;

    dog->body = CreateObject(15, 5);
    //BODY
    AddVertex(dog->body,  0.0 , -0.75);
    AddVertex(dog->body,  0.50, -0.9);
    AddVertex(dog->body,  0.90, -0.5);
    AddVertex(dog->body,  1.0 , -0.0);
    AddVertex(dog->body,  0.90,  0.5);
    AddVertex(dog->body,  0.50,  0.9);
    AddVertex(dog->body,  0.00,  1.0);
    AddVertex(dog->body, -0.50,  0.9);
    AddVertex(dog->body, -0.90,  0.5);
    AddVertex(dog->body, -1.0 , -0.0);
    AddVertex(dog->body, -0.90, -0.5);
    AddVertex(dog->body, -0.50, -0.9);
    AddVertex(dog->body,  0.0 , -0.75);
    //Transformations
    ScaleSlice(dog->body, 0.5, 0.5);
    TranslateSlice(dog->body, 0.0, 0.0, -1);
    Extrude(dog->body);
    ScaleSlice(dog->body, 2 * .75, 2 * .75);
    TranslateSlice(dog->body, 0.0, 0.0, 0.5);
    Extrude(dog->body);
    TranslateSlice(dog->body, 0.0, 0.0, 0.5);
    ScaleSlice(dog->body, 1 / 0.75 * .65, 1 / 0.75 * .65);
    Extrude(dog->body);
    ScaleSlice(dog->body, 1 / .65 * .75, 1 / .65 * .75);
    TranslateSlice(dog->body, 0.0, 0.0, .5);
    Extrude(dog->body);
    TranslateSlice(dog->body, 0.0, 0.0, 0.5);
    ScaleSlice(dog->body, 1 / 0.75 * .5, 1 / 0.75 * .5);
    FinalizeObject(dog->body);

    //NECK
    dog->neck = CreateObject(9, 2);
    AddVertex(dog->neck,  0.0 ,  0.5);
    AddVertex(dog->neck,  0.4 ,  0.4);
    AddVertex(dog->neck,  0.5 ,  0.0);
    AddVertex(dog->neck,  0.4 , -0.4);
    AddVertex(dog->neck,  0.0 , -0.5);
    AddVertex(dog->neck, -0.4 , -0.4);
    AddVertex(dog->neck, -0.5 ,  0.0);
    AddVertex(dog->neck, -0.4 ,  0.4);
    AddVertex(dog->neck,  0.0 ,  0.5);
    //Transformations
    Extrude(dog->neck);
    ScaleSlice(dog->neck, 0.9, 0.9);
    TranslateSlice(dog->neck, 0.0, 0, 1.2);
    FinalizeObject(dog->neck);

    //HEAD
    dog->head = CreateObject(9, 3);
    AddVertex(dog->head,  0.0 ,  0.39);
    AddVertex(dog->head,  0.4 ,  0.4);
    AddVertex(dog->head,  0.5 ,  0.0);
    AddVertex(dog->head,  0.4 , -0.4);
    AddVertex(dog->head,  0.0 , -0.5);
    AddVertex(dog->head, -0.4 , -0.4);
    AddVertex(dog->head, -0.5 ,  0.0);
    AddVertex(dog->head, -0.4 ,  0.4);
    AddVertex(dog->head,  0.0 ,  0.39);
    //Transformations
    TranslateSlice(dog->head, 0.0, 0, .1);
    ScaleSlice(dog->head, 0.7, 0.7);
    Extrude(dog->head);
    ScaleSlice(dog->head, 1 / 0.7, 1 / 0.7);
    TranslateSlice(dog->head, 0.0, 0, .2);
    Extrude(dog->head);
    ScaleSlice(dog->head, 0.5, 0.5);
    TranslateSlice(dog->head, 0.0, 0, .9);
    FinalizeObject(dog->head);

    //EAR
    dog->ear = CreateObject(6, 3);
    AddVertex(dog->ear,  0.0 ,  0.5);
    AddVertex(dog->ear, -0.15,  0.3);
    AddVertex(dog->ear, -0.20,  0.0);
    AddVertex(dog->ear,  0.20,  0.0);
    AddVertex(dog->ear,  0.15,  0.3);
    AddVertex(dog->ear,  0.0 ,  0.5);
    //Transformations
    TranslateSlice(dog->ear, 0.0, 0, -0.1);
    Extrude(dog->ear);
    TranslateSlice(dog->ear, 0.0, 0, 0.1);
    ScaleSlice(dog->ear, 1.2, 1.2);
    Extrude(dog->ear);
    TranslateSlice(dog->ear, 0.0, 0, -0.05);
    ScaleSlice(dog->ear, 0.6, 0.6);
    FinalizeObject(dog->ear);

    //TAIL
    dog->tail = CreateObject(9, 3);
    AddVertex(dog->tail,  0.0 ,  0.5);
    AddVertex(dog->tail,  0.4 ,  0.4);
    AddVertex(dog->tail,  0.5 ,  0.0);
    AddVertex(dog->tail,  0.4 , -0.4);
    AddVertex(dog->tail,  0.0 , -0.5);
    AddVertex(dog->tail, -0.4 , -0.4);
    AddVertex(dog->tail, -0.5 ,  0.0);
    AddVertex(dog->tail, -0.4 ,  0.4);
    AddVertex(dog->tail,  0.0 ,  0.5);
    //Transformations
    ScaleSlice(dog->tail, 0.3, 0.3);
    Extrude(dog->tail);
    TranslateSlice(dog->tail, 0.0, 0, 0.3);
    ScaleSlice(dog->tail, 0.8, 0.8);
    Extrude(dog->tail);
    TranslateSlice(dog->tail, 0.0, 0, 0.7);
    ScaleSlice(dog->tail, 0.7, 0.7);
    FinalizeObject(dog->tail);

    return dog;
}

void freeDog(Dog  dog)
{
    freeObj(dog->body);
    freeObj(dog->ear);
    freeObj(dog->head);
    freeObj(dog->neck);
    freeLeg(dog->leg1);
    freeLeg(dog->leg2);
    freeLeg(dog->leg3);
    freeLeg(dog->leg4);
    free(dog);
}

void drawDog(Dog  dog, int mode)
{

    if (!dog->enabled)
        return;
    glPushMatrix();
    glTranslatef(dog->translation->x, dog->translation->y, dog->translation->z );
    glTranslatef(dog->position->x, dog->position->y, dog->position->z);
    glRotatef(dog->angle, 0, 1, 0);
    glRotatef(dog->angle2, 0, 0, 1);
    glRotatef(5 * sin(dog->time), 0, 0, 1);
    glScalef(1.3,1.3,1.3);

    glRotatef(dog->rotation->x,1,0,0);
    glRotatef(dog->rotation->y,0,1,0);
    glRotatef(dog->rotation->z,0,0,1);
    glScalef(dog->scale,dog->scale,dog->scale);
    glTranslatef(0, 0.38, 0 );


    //TAIL
    glPushMatrix();
    glTranslatef(-0.23, 0.1, 0);
    glRotatef(sin(2 * dog->time) * 90, 0, 1, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(-170, 0, 1, 0);
    glScalef(0.15, 0.15, 0.15);
    DrawObject(dog->tail, mode);
    glPopMatrix();

    //HEAD
    glPushMatrix();
    //EARS
    glPushMatrix();
    glTranslatef(0.27, 0.22, 0.05);
    glRotatef(90, 0, 1, 0);
    glRotatef(15, 0, 0, 1);
    glRotatef(-15, 0, 1, 0);
    glScalef(0.15, 0.15, 0.15);
    DrawObject(dog->ear, mode);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.27, 0.22, -0.05);
    glRotatef(90, 0, 1, 0);
    glRotatef(-15, 0, 0, 1);
    glRotatef(15, 0, 1, 0);
    glScalef(0.15, 0.15, 0.15);
    DrawObject(dog->ear, mode);
    glPopMatrix();

    glTranslatef(0.2, 0.17, 0);
    glRotatef(90, 0, 1, 0);
    glScalef(0.2, 0.2, 0.2);
    DrawObject(dog->head, mode);
    glPopMatrix();

    //NECK
    glPushMatrix();
    glTranslatef(0.2, 0.1, 0);
    glRotatef(60, 0, 0, 1);
    glRotatef(90, 0, 1, 0);
    glScalef(0.1, 0.1, 0.1);
    DrawObject(dog->neck, mode);
    glPopMatrix();

    //BODY
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, 0);
    glScalef(0.15, 0.2, 0.25);
    DrawObject(dog->body, mode);
    glPopMatrix();

    //LEGS
    glPushMatrix();
    glTranslatef(-0.18, -0.03, 0.1);
    drawLeg(dog->leg1, mode);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.18, -0.03, -0.1);
    drawLeg(dog->leg3, mode);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.03, 0.1);
    drawLeg(dog->leg2, mode);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2, -0.03, -0.1);
    drawLeg(dog->leg4, mode);
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void animateDog(Dog  dog)
{
    dog->leg1->time += 2 * dog->speed;
    dog->leg3->time += 2 * dog->speed;
    dog->leg2->time += 2 * dog->speed;
    dog->leg4->time += 2 * dog->speed;
    dog->time += 0.15;
}

void hunt(Dog  dog, Cat cat)
{
    if (cat->enabled) {
        startDog(dog);
    } else {
        if (dog->sit)
            sitDog(dog);
        else
            stopDog(dog);
        return;
    }
    float ang = ((int)dog->angle) % 360;
    dog->angle = (float) ang;
    Pt3D cPOs = cat->position, dPos = dog->position;
    //Vetor entre a posição do gato e do cachorro
    Pt3D dir = subtractPt3D(cPOs, dPos);
    //Vetor da direção da moviemntação do cachorro
    Pt3D dDir = CreatePt3D(cos(PI * ang / 180.0f), 0, - sin(PI * ang / 180.0f));
    //Normalizando os vetores
    normalizedPt3D(dDir);
    normalizedPt3D(dir);
    //Ãngulo de correção da rotação do cachorro
    float theta = acos(dotProduct(dir, dDir) / (normalPt3D(dir) * normalPt3D(dDir)));
    if ((dir->z * dDir->x - dir->x * dDir->z) > 0) {
        theta = -theta;
    }
    //Rotaciona o cachorro na direção do gato
    dog->angle = ang + theta / PI * 15.0f;
    //Multiplica a direção pelo vetor velocidade
    multiplyPt3D(dDir, dog->speed * (2 + sin(dog->time * 7)));
    //Desloca o cachorro
    addToPt3D(dPos, dDir);
    //Copia dDir para o vevtor de direção dentro do cachorro
    copyPt3D(dog->direction, dDir );
    freePt3D(dDir);
    freePt3D(dir);
    animateDog(dog);
    if( distance(dog->position, cat->position) <= 2.0 ) {
        cat->angle += 0.001;
        cat->speed += cat->stamina * cat->stamina * cat->speed * 0.007 * ((rand()%100)/100.0);
        if( cat->stamina < 0.5 )
            cat->stamina += 0.05;
    }

    if (distance(dog->position, cat->position) <= 0.5) {
        cat->enabled = 0;
    }
}

void startDog(Dog dog)
{
    if (dog->angle2 != 0) {
        dog->position->y += 0.008;
        dog->angle2 --;
        //Frente Direita
        dog->leg2->time = 0.0;
        //Frente Esquerda
        dog->leg4->time = 0.2;
        //Trás Direita
        dog->leg1->time = 1.2;
        //Trás Esquerda
        dog->leg3->time = 1.5;
    }
    if (dog->speed < dog->maxSpeed) {
        dog->speed += 0.01;
    }
    dog->stop = 0;
    dog->sit = 0;
}

void sitDog(Dog dog)
{
    if (dog->leg1->ang1 < 35.0f) {
        if( fmod((double)dog->leg1->time, 2 * PI ) < PI/2.0 ){
            dog->leg1->time += 0.1;
            dog->leg3->time += 0.1;
            dog->leg2->time += 0.1;
            dog->leg4->time += 0.1;
        }else{
            dog->leg1->time -= 0.1;
            dog->leg3->time -= 0.1;
            dog->leg2->time -= 0.1;
            dog->leg4->time -= 0.1;
        }
    }
    if (dog->position->y > -0.15) {
        dog->position->y -= 0.008;
        dog->angle2 ++;
    }
}

void stopDog(Dog dog)
{

    if (dog->speed < 0) {
        dog->speed = 0;
    }

    if (!dog->sit) {
        if ((dog->leg1->ang1 > 3.0f || dog->leg1->ang1 < 0.0f)) {
            dog->leg1->time += 0.08;
            dog->leg3->time += 0.08;
            dog->leg2->time += 0.08;
            dog->leg4->time += 0.08;
            if (dog->speed > 0)
                dog->speed -= 0.05 * dog->speed;
        } else {
            if (dog->speed != 0) {
                dog->speed = 0;
            }
            dog->sit = 1;
        }
    }
    dog->stop = 1;
}
