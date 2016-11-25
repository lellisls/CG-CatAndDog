#include "../inc/Object.h"
#include "stdio.h"
#include "math.h"
PObject CreateObject(int nVertex, int nSlices)
{
    PObject obj = (PObject) malloc(sizeof(TObject));
    obj->currentSlice = 0;
    obj->currentVertex = 0;
    obj->nVertex = nVertex;
    obj->nSlices = nSlices;
    obj->sliceCtr = ZeroPt3D();
    obj->polygon = (struct sPt3D**) malloc(nSlices * sizeof(struct sPt3D*));
    int slice;
    for (slice = 0; slice < nSlices; ++slice)
        obj->polygon[slice] = (struct sPt3D*) malloc(nVertex * sizeof(struct sPt3D));
    resetTransformMatrix();
    return obj;
}

void AddVertex(PObject obj, GLfloat x, GLfloat y)
{
    if (obj->currentVertex == obj->nVertex) {
        printf("ERROR: In Object.c at function AddVertex: Cannot add Vertex, currentVertex is out of bounds!\n");
        exit(1);
    }
    obj->polygon[0][ obj->currentVertex ].x = x;
    obj->polygon[0][ obj->currentVertex ].y = y;
    obj->polygon[0][ obj->currentVertex ].z = 0.0f;
    obj->currentVertex ++;
}

void Extrude(PObject obj)
{
    if (obj->currentSlice == obj->nSlices) {
        printf("ERROR: In Object.c at function Extrude: Cannot extrude, currentSlice is out of bounds!\n");
        exit(1);
    }
    obj->currentSlice ++;
    int vtx;
    for (vtx = 0; vtx < obj->currentVertex; ++vtx) {
        Pt3DTransform(&(obj->polygon[obj->currentSlice - 1][ vtx ]));
        obj->polygon[obj->currentSlice][ vtx ].x = obj->polygon[obj->currentSlice - 1][ vtx ].x;
        obj->polygon[obj->currentSlice][ vtx ].y = obj->polygon[obj->currentSlice - 1][ vtx ].y;
        obj->polygon[obj->currentSlice][ vtx ].z = obj->polygon[obj->currentSlice - 1][ vtx ].z;
    }
    resetTransformMatrix();
}

void TranslateSlice(PObject obj, GLfloat dx, GLfloat dy, GLfloat dz)
{
    translate3D(dx, dy, dz);
    obj->sliceCtr->x += dx;
    obj->sliceCtr->y += dy;
    obj->sliceCtr->z += dz;
}

void TranslateSlice2(PObject obj, GLfloat dx, GLfloat dy, GLfloat dz)
{
    translate3D(dx, dy, dz);
    obj->sliceCtr->x += 0;
}

void ScaleSlice(PObject obj, GLfloat sx, GLfloat sy)
{
    scale3D(sx, sy, 1, obj->sliceCtr);
}

void RotateSlice(PObject obj, GLfloat ax, GLfloat ay, GLfloat az)
{

    Pt3D p1 = CreatePt3D(obj->sliceCtr->x, obj->sliceCtr->y, obj->sliceCtr->z);
    Pt3D p2 = CreatePt3D(obj->sliceCtr->x, obj->sliceCtr->y, obj->sliceCtr->z + 1);
    Pt3D p3 = CreatePt3D(obj->sliceCtr->x, obj->sliceCtr->y, obj->sliceCtr->z);
    Pt3D p4 = CreatePt3D(obj->sliceCtr->x, obj->sliceCtr->y + 1, obj->sliceCtr->z);
    Pt3D p5 = CreatePt3D(obj->sliceCtr->x, obj->sliceCtr->y, obj->sliceCtr->z);
    Pt3D p6 = CreatePt3D(obj->sliceCtr->x + 1, obj->sliceCtr->y, obj->sliceCtr->z);

    rotate3Dv(p1, p2, ax);
    rotate3Dv(p3, p4, ay);
    rotate3Dv(p5, p6, az);

    freePt3D(p1);
    freePt3D(p2);
    freePt3D(p3);
    freePt3D(p4);
    freePt3D(p5);
    freePt3D(p6);
}

void FinalizeObject(PObject obj)
{
    int vtx;
    for (vtx = 0; vtx < obj->currentVertex; ++vtx)
        Pt3DTransform(&(obj->polygon[obj->currentSlice][ vtx ]));
    resetTransformMatrix();
}

void DrawObject(PObject obj, int format)
{
    glPushMatrix();
    int slice, vtx;

    glBegin(format);
    for (vtx = 0; vtx < obj->currentVertex; ++vtx) {
        Pt3D pt = &(obj->polygon[0][vtx]);
        glVertex3d(pt->x, pt->y, pt->z);
    }
    glEnd();
    glBegin(format);
    for (vtx = 0; vtx < obj->currentVertex; ++vtx) {
        Pt3D pt = &(obj->polygon[obj->currentSlice][vtx]);
        glVertex3d(pt->x, pt->y, pt->z);
    }
    glEnd();
    for (vtx = 0; vtx < obj->currentVertex - 1; ++vtx) {
        for (slice = 0; slice < obj->currentSlice; ++slice) {
            glBegin(format);
            Pt3D pt = &(obj->polygon[slice][vtx]);
            glVertex3d(pt->x, pt->y, pt->z);
            pt = &(obj->polygon[slice + 1][vtx]);
            glVertex3d(pt->x, pt->y, pt->z);
            pt = &(obj->polygon[slice + 1][vtx + 1]);
            glVertex3d(pt->x, pt->y, pt->z);
            pt = &(obj->polygon[slice][vtx + 1]);
            glVertex3d(pt->x, pt->y, pt->z);
            glEnd();
        }
    }
    glPopMatrix();
}

void freeObj(PObject obj)
{
    int slice;
    for (slice = 0; slice < obj->currentSlice; ++slice) {
        free(obj->polygon[slice]);
    }
    free(obj->polygon);
    free(obj->sliceCtr);
    free(obj);
}

PObject CreateCircleObject(int nVertex, int nSlices)
{
    PObject obj = CreateObject(nVertex + 1, nSlices);
    float angle, step = 360.0f / (float)nVertex;
    for (angle = 0.0f; angle <= 360.0f; angle += step) {
        float radian = angle / 180.0f * PI;
        AddVertex(obj, sin(radian), cos(radian));
    }
    return obj;
}
