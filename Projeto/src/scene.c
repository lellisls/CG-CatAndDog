#include "../inc/scene.h"
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "math.h"
#include "stdio.h"
#include "../inc/Matrix.h"
#include "../inc/Light.h"
float fraction = 0.1;
float ax = 0, ay = 0;
int tex = 1;
Pt3D p1, p2;

Scene CreateScene(CameraMode mode)
{
    Scene  scn = (Scene) malloc(sizeof(struct scene));
    //Spotlight position
    scn->spotPosition[0] = CreatePt3D( 14,2, 14);
    scn->spotPosition[1] = CreatePt3D(-14,2, 14);
    scn->spotPosition[2] = CreatePt3D(-14,2,-14);
    scn->spotPosition[3] = CreatePt3D( 14,2,-14);
    //reading textures
    getBitmapImageData("sky.bmp", &scn->skyTexture);
    getBitmapImageData("Grass.bmp", &scn->grassTexture);
    glGenTextures(2, &scn->texture_id[0]);

    //Setting up texture
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    //Setting up Personages
    scn->dog = CreateDog();
    scn->cat = CreateCat();
    setRandomPositions(scn);

    //Setting up Cameras
    scn->freeCam = createCamera(0, 5, -35, FREE);
    rotateCamera(scn->freeCam,0,100);
    scn->staticCam = createCamera(0, 10, -20, STATIC);
    rotateCamera(scn->staticCam,0,100);
    scn->followCat = fCatCamera(0, 10, -20, scn->cat);
    scn->followDog = fDogCamera(0, 10, -20, scn->dog);
    scn->dogEye = dogEyeCamera(scn->dog);
    scn->currentCam = scn->freeCam;
    //Setting up Scenario
    scn->wall = CreateWall();

    //Setting up current camera
    setSceneMode(scn,mode);

    scn->obj = CreateCircleObject(10,100);
    TranslateSlice2(scn->obj,10,0,0);
    float i, factor = PI/10;
    for( i = 0; i < 2*PI; i+= factor ){
        Extrude(scn->obj);
        RotateSlice(scn->obj,0,factor,0);
    }
    FinalizeObject(scn->obj);


    return scn;
}

void setRandomPositions(Scene scn)
{
    scn->dog->position->x = rand() % 24 - 12;
    scn->dog->position->z = rand() % 24 - 12;
    scn->cat->position->x = rand() % 24 - 12;
    scn->cat->position->z = rand() % 24 - 12;
    scn->cat->angle = rand() % 360;
    scn->dog->angle = rand() % 360;
}

void freeScene(Scene  scn)
{
    freeCamera(scn->freeCam);
    freeCamera(scn->staticCam);
    freeFCamera(scn->followCat);
    freeFCamera(scn->followDog);
    freeDogEyeCamera(scn->dogEye);
    freeDog(scn->dog);
    freeCat(scn->cat);
    freeWall(scn->wall);
    free(scn);
}

void setSceneMode(Scene scn, CameraMode mode)
{
    switch (mode) {
    case FREE:
        scn->currentCam = scn->freeCam;
        break;
    case STATIC:
        scn->currentCam = scn->staticCam;
        break;
    case FOLLOWCAT:
        scn->currentCam = scn->followCat;
        break;
    case FOLLOWDOG:
        scn->currentCam = scn->followDog;
        break;
    case DOGEYE:
        scn->currentCam = scn->dogEye;
        break;
    default:
        break;
    }
}

void textured(Scene scn ) {

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glEnable(GL_TEXTURE_2D);
    /* SKY TEXTURE */
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, scn->texture_id[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, scn->skyTexture.width,scn->skyTexture.height, 0, GL_RGB, GL_UNSIGNED_BYTE,scn->skyTexture.data);

    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
    glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);

    //SKY
    glutSolidSphere(100, 100, 100);
//    glColor3f(0.2, 0.3f, 0.1);
    /* GRASS TEXTURE */

    //GRASS

    glTexImage2D(GL_TEXTURE_2D, 0, 3, scn->grassTexture.width,scn->grassTexture.height, 0, GL_RGB, GL_UNSIGNED_BYTE,scn->grassTexture.data);

    glDepthMask(GL_FALSE);
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);

    glColor3f(0.8,0.8,0.8);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-100, 0, -100);
    glTexCoord2f(100.0f, 0.0f);
    glVertex3f(-100, 0, 100);
    glTexCoord2f(100.0f, 100.0f);
    glVertex3f(100, 0, 100);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(100, 0, -100);
    glEnd();

    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    glDepthMask(GL_TRUE);

    glDisable(GL_TEXTURE_2D);

    /* END TEXTURE */
}

void notTextured( ) {

    glColor3f(0,0,1);
    glutSolidSphere(100, 100, 100);

    glColor3f(0,1,0);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-100, 0, -100);
    glTexCoord2f(100.0f, 0.0f);
    glVertex3f(-100, 0, 100);
    glTexCoord2f(100.0f, 100.0f);
    glVertex3f(100, 0, 100);
    glTexCoord2f(0.0f, 100.0f);
    glVertex3f(100, 0, -100);
    glEnd();

}

void drawScene(Scene  scn, int mode)
{
    setCamera(scn->currentCam);

    glPushMatrix();
    spot(GL_LIGHT0,scn->spotPosition[0],scn->cat->position);
    spot(GL_LIGHT1,scn->spotPosition[1],scn->cat->position);
    spot(GL_LIGHT2,scn->spotPosition[2],scn->cat->position);
    spot(GL_LIGHT3,scn->spotPosition[3],scn->cat->position);
    ambient();
    light(GL_LIGHT4);

//    DrawObject(scn->obj,GL_LINES);
//    glColor3f(1,0,0);
//    DrawObject(scn->obj,mode);
//    return;

    //    //MOUSE RAY
//    if (p1 != NULL) {
//        glColor3f(1, 1, 1);
//        glBegin(GL_LINES);
//        glVertex3f(p1->x, p1->y, p1->z);
//        glVertex3f(p2->x, p2->y, p2->z);
//        glEnd();
//    }

//    //EIXOS CARTESIANOS
//    glBegin(GL_LINES);
//    glColor3f(.5, 0, 0);
//    glVertex3f(0, 0, 0);
//    glVertex3f(1, 0, 0);
//    glColor3f(0, .5, 0);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0, 1, 0);
//    glColor3f(0, 0, .5);
//    glVertex3f(0, 0, 0);
//    glVertex3f(0, 0, 1);
//    glEnd();

    //WALL
    glColor3f(0.2, .1f, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    DrawWall(scn->wall, mode);
    glRotatef(90, 0, 1, 0);
    DrawWall(scn->wall, mode);
    glRotatef(90, 0, 1, 0);
    DrawWall(scn->wall, mode);
    glRotatef(90, 0, 1, 0);
    DrawWall(scn->wall, mode);
    glPopMatrix();


    if( tex == 1 ) {
        textured(scn);
    } else {
        notTextured();
    }

    //CAT
    glPushMatrix();
    glColor3f(0.3, 0.3, 0.3);
    drawCat(scn->cat, mode);
//    glColor3f(1,1,1);
//    drawCat(scn->cat, GL_LINE_LOOP );
    glPopMatrix();

    //DOG
    glPushMatrix();
    glColor3f(0.4, 0.2, .1);
    drawDog(scn->dog, mode);
//    glColor3f(1, 1, 1);
//    drawDog(scn->dog, GL_LINE_LOOP );
    glPopMatrix();

    glPopMatrix();
}

void resetScene(Scene  scn)
{
    freeScene(scn);
    scn = CreateScene(FREE);
}

void setCatPos(Scene scn, double fovy, double height, double width, double zNear, double x, double y)
{
    Pt3D view = getDir(scn->currentCam);
    normalizePt3D(view);
    Pt3D h = crossProduct(view, scn->currentCam->up);
    normalizePt3D(h);

    Pt3D v = crossProduct(h, view);
    normalizePt3D(v);

    float aspect = (float)width / (float)height;
    double rad = fovy * PI / 180.0;
    float vLength = tan(rad / 2) * zNear;
    float hLenght = vLength * aspect;

    multiplyPt3D(v, vLength);
    multiplyPt3D(h, hLenght);

    x -= width / 2.0;
    y = height - y;
    y -= height / 2.0;
    y /= (height / 2.0);
    x /= (width / 2.0);
    multiplyPt3D(view, zNear);
    multiplyPt3D(h, x);
    multiplyPt3D(v, y);

    Pt3D pos = createCopyPt3D(scn->currentCam->pos);
    addToPt3D(pos, view);
    addToPt3D(pos, h);
    addToPt3D(pos, v);

    Pt3D dir = subtractPt3D(pos, scn->currentCam->pos);
    normalizePt3D(dir);
    printf("Dir: ");
    printPt3D(dir);

    if (dir->y != 0) {
        double t = pos->y / dir->y;
        printf("T = %f\n", t);
        printPt3D(dir);
        multiplyPt3D(dir, -t);

        p1 = createCopyPt3D(pos);
        addToPt3D(pos, dir);

        p2 = createCopyPt3D(pos);
        if (verifyBounds(scn, pos) == 1) {
            copyPt3D( scn->cat->position, pos );
            resetCat(scn->cat);
            scn->cat->angle = rand() % 360;
        }
    }
    freePt3D(h);
    freePt3D(v);
    freePt3D(view);
    freePt3D(pos);
    freePt3D(dir);
}

int verifyBounds(Scene  scn, Pt3D position)
{
    return (abs(position->x) <= 14 && abs(position->z) <= 14);
}
