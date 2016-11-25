#ifndef WCPT3D_H
#define WCPT3D_H
#include "GL/gl.h"

#define PI 3.14159265359

struct sPt3D {
    GLfloat x, y, z;
};

typedef struct sPt3D * Pt3D;

Pt3D ZeroPt3D();
Pt3D CreatePt3D(GLfloat cx, GLfloat cy, GLfloat cz);
void freePt3D(Pt3D point);
void subtractFromPt3D(Pt3D p1, Pt3D p2);
Pt3D subtractPt3D(Pt3D p1, Pt3D p2);
Pt3D addPt3D(Pt3D p1, Pt3D p2);
void addToPt3D(Pt3D p1, Pt3D p2);
float distance(Pt3D p1, Pt3D p2);
Pt3D normalizedPt3D(Pt3D pt);
void normalizePt3D(Pt3D pt);
void copyPt3D(Pt3D p1, Pt3D p2);
void printPt3D(Pt3D point);
void multiplyPt3D(Pt3D pt, float s);
Pt3D createCopyPt3D(Pt3D pt);
Pt3D crossProduct(Pt3D p1, Pt3D p2);
float dotProduct(Pt3D p1, Pt3D p2);
float normalPt3D(Pt3D pt);
void setPt3D(Pt3D pt, GLfloat cx, GLfloat cy, GLfloat cz);
#endif // WCPT3D_H
