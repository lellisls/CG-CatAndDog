#include "../inc/Camera.h"
Camera createCamera(GLfloat x, GLfloat y, GLfloat z, CameraMode mode)
{
    Camera cam = (Camera) malloc(sizeof(struct camera));
    cam->pos = CreatePt3D(x, y, z);
    cam->dir = CreatePt3D(0, 0, 1);
    cam->up = CreatePt3D(0, 1, 0);
    cam->mode = mode;
    return (cam);
}

Camera fDogCamera(GLfloat x, GLfloat y, GLfloat z, Dog dog)
{
    Camera cam = (Camera) malloc(sizeof(struct camera));
    cam->pos = CreatePt3D(x, y, z);
    cam->dir = dog->position;
    cam->up = CreatePt3D(0, 1, 0);
    cam->mode = FOLLOWDOG;
    return (cam);
}

Camera fCatCamera(GLfloat x, GLfloat y, GLfloat z, Cat cat)
{
    Camera cam = (Camera) malloc(sizeof(struct camera));
    cam->pos = CreatePt3D(x, y, z);
    cam->dir = cat->position;
    cam->up = CreatePt3D(0, 1, 0);
    cam->mode = FOLLOWCAT;
    return (cam);
}

Camera dogEyeCamera(Dog dog)
{
    Camera cam = (Camera) malloc(sizeof(struct camera));
    cam->pos = dog->position;
    cam->dir = dog->direction;
    cam->up = CreatePt3D(0, 1, 0);
    cam->mode = DOGEYE;
    return (cam);
}

void setCamera(Camera cam)
{
    switch (cam->mode) {
    case DOGEYE:
        gluLookAt(cam->pos->x, cam->pos->y + 1, cam->pos->z,
                  cam->pos->x + cam->dir->x,
                  cam->pos->y + cam->dir->y + 1,
                  cam->pos->z + cam->dir->z,
                  cam->up->x, cam->up->y, cam->up->z);
        break;
    case FOLLOWCAT:
    case FOLLOWDOG:
        gluLookAt(cam->pos->x, cam->pos->y, cam->pos->z,
                  cam->dir->x, cam->dir->y, cam->dir->z,
                  cam->up->x, cam->up->y, cam->up->z);
        break;
    default:
        gluLookAt(cam->pos->x, cam->pos->y, cam->pos->z,
                  cam->pos->x + cam->dir->x,
                  cam->pos->y + cam->dir->y,
                  cam->pos->z + cam->dir->z,
                  cam->up->x, cam->up->y, cam->up->z);
        break;
    }
}

void rotateCamera(Camera cam, int dx, int dy)
{
    //FIXME Create alternative rotation functions
    if (cam->mode == STATIC) {
        resetTransformMatrix();
        rotate3D(-dx * 0.002, 0, 1, 0);
        rotate3D(dy * 0.002, 1, 0, 0);
        Pt3DTransform(cam->dir);
    } else if (cam->mode == FREE) {
        resetTransformMatrix();
        rotate3D(-dx * 0.002, 0, 1, 0);
        rotate3D(dy * 0.002, 1, 0, 0);
        Pt3DTransform(cam->pos);
        resetTransformMatrix();
        rotate3D(-dx * 0.002, 0, 1, 0);
        rotate3D(dy * 0.002, 1, 0, 0);
        Pt3DTransform(cam->dir);
    }
}

void moveCameraFront(Camera cam)
{
    Pt3D normalized;
    switch (cam->mode) {
    case DOGEYE:

        break;
    case FOLLOWCAT:
    case FOLLOWDOG:
        normalized =  subtractPt3D(cam->dir, cam->pos);
        normalizePt3D(normalized);
//        multiplyPt3D(normalized,0.1);
        addToPt3D(cam->pos, normalized);
        freePt3D(normalized);
        break;
    default:
        normalized = normalizedPt3D(cam->dir);
        addToPt3D(cam->pos, normalized);
        freePt3D(normalized);
        break;
    }
}

void moveCameraBack(Camera cam)
{
    Pt3D normalized;
    switch (cam->mode) {
    case DOGEYE:

        break;
    case FOLLOWCAT:
    case FOLLOWDOG:
        normalized = subtractPt3D(cam->dir, cam->pos);
        normalizePt3D(normalized);
//        multiplyPt3D(normalized,0.1);
        subtractFromPt3D(cam->pos, normalized);
        freePt3D(normalized);
        break;
    default:
        normalized = normalizedPt3D(cam->dir);
        subtractFromPt3D(cam->pos, normalized);
        freePt3D(normalized);
        break;
    }
}

Pt3D getDir(Camera cam)
{
    Pt3D res;
    switch (cam->mode) {
    case FREE:
    case STATIC:
    case DOGEYE:
        return (createCopyPt3D(cam->dir));
        break;
    default:
        res = subtractPt3D(cam->dir, cam->pos);
        normalizePt3D(res);
        return (res);
        break;
    }
}

Pt3D getPos(Camera cam)
{
    switch (cam->mode) {
    case DOGEYE:
        return (CreatePt3D(cam->pos->x, cam->pos->y + 1, cam->pos->z));
        break;
    default:
        return (createCopyPt3D(cam->pos));
        break;
    }
}

void freeCamera(Camera cam)
{
    freePt3D(cam->pos);
    freePt3D(cam->dir);
    freePt3D(cam->up);
    free(cam);
}

void freeDogEyeCamera(Camera cam)
{
    freePt3D(cam->up);
    free(cam);
}

void freeFCamera(Camera cam)
{
    freePt3D(cam->pos);
    freePt3D(cam->up);
    free(cam);
}
