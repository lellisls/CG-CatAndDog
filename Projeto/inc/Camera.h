#ifndef CAMERA_H
#define CAMERA_H
#include "Cat.h"
#include "Dog.h"

enum cameraMode { FOLLOWDOG, FOLLOWCAT, FREE, STATIC, DOGEYE };
typedef enum cameraMode CameraMode;

struct camera {
    Pt3D pos; //Camera position
    Pt3D dir; //Camera direction
    Pt3D up; //Up direction
    CameraMode mode; //Camera mode
};
typedef struct camera * Camera;

Camera createCamera(GLfloat x, GLfloat y, GLfloat z , CameraMode mode);

Camera fDogCamera(GLfloat x, GLfloat y, GLfloat z, Dog dog);

Camera fCatCamera(GLfloat x, GLfloat y, GLfloat z, Cat cat);

Camera dogEyeCamera(Dog dog);

void setCamera(Camera cam);

void rotateCamera(Camera cam, int dx, int dy);

void moveCameraFront(Camera cam);

void moveCameraBack(Camera cam);

Pt3D getDir( Camera cam );

Pt3D getPos( Camera cam );

void freeCamera(Camera cam);

void freeDogEyeCamera( Camera cam );

void freeFCamera( Camera cam );

#endif // CAMERA_H
