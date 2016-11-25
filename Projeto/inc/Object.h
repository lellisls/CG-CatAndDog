#ifndef OBJECT_H
#define OBJECT_H
#include <GL/gl.h>
#include <GL/glut.h>
#include "3DTransforms.h"

struct SObject {
    int currentSlice;
    int currentVertex;
    int nSlices;
    int nVertex;
    struct sPt3D **polygon;
    Pt3D sliceCtr;
} TObject;

typedef struct SObject *PObject;

PObject CreateObject(int nVertices, int nSlices);

PObject CreateCircleObject(int nVertex, int nSlices);

void AddVertex(PObject obj, GLfloat x, GLfloat y);

void Extrude(PObject obj);

void FinalizeObject(PObject obj);

void DrawObject(PObject obj, int type);

void TranslateSlice(PObject obj, GLfloat dx, GLfloat dy, GLfloat dz);

void TranslateSlice2(PObject obj, GLfloat dx, GLfloat dy, GLfloat dz);

void ScaleSlice(PObject obj, GLfloat sx, GLfloat sy);

void RotateSlice(PObject obj, GLfloat ax, GLfloat ay, GLfloat az);

void freeObj(PObject obj);

#endif // OBJECT_H
