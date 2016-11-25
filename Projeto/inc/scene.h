#ifndef SCENE_H
#define SCENE_H
#include "Object.h"
#include "Dog.h"
#include "Cat.h"
#include "wall.h"
#include "Camera.h"
#include "BMPImage.h"

struct scene {
    Camera currentCam;
    Camera freeCam, staticCam, followDog, followCat, dogEye;
    Dog dog;
    Cat cat;
    Wall wall;
    GLuint texture_id[2];
    BMPImage skyTexture;
    BMPImage grassTexture;
    Pt3D spotPosition[4];
    PObject obj;
};


typedef struct scene * Scene;

Scene CreateScene(CameraMode mode);

void setRandomPositions(Scene scn);

void drawScene(Scene scn , int type);

void freeScene(Scene scn);

void setSceneMode(Scene scn, CameraMode mode );

void resetScene(Scene  scn);

void setCatPos(Scene scn, double fovy, double height, double width, double zNear, double x, double y);

int verifyBounds(Scene  scn, Pt3D position);
#endif //SCENE_H
