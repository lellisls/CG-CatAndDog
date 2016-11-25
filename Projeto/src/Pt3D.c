#include "../inc/Pt3D.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"
Pt3D ZeroPt3D()
{
    Pt3D point = (Pt3D) malloc(sizeof(struct sPt3D));
    point->x = point->y = point->z = 0.0;
    return (point);
}

Pt3D CreatePt3D(GLfloat cx, GLfloat cy, GLfloat cz)
{
    Pt3D point = NULL;
    point = (Pt3D) malloc(sizeof(struct sPt3D));
    if (point == NULL)
        return NULL;
    point->x = cx;
    point->y = cy;
    point->z = cz;
    return (point);
}

void freePt3D(Pt3D point)
{
    free(point);
}

void printPt3D(Pt3D point)
{
    printf("Pt = ( %.2f, %.2f, %.2f );\n", point->x, point->y, point->z);
}

Pt3D subtractPt3D(Pt3D p1, Pt3D p2)
{
    Pt3D point = ZeroPt3D();
    point->x = p1->x - p2->x;
    point->y = p1->y - p2->y;
    point->z = p1->z - p2->z;
    return (point);
}

void subtractFromPt3D(Pt3D p1, Pt3D p2)
{
    p1->x -= p2->x;
    p1->y -= p2->y;
    p1->z -= p2->z;
}

Pt3D addPt3D(Pt3D p1, Pt3D p2)
{
    Pt3D point = ZeroPt3D();
    point->x = p1->x + p2->x;
    point->y = p1->y + p2->y;
    point->z = p1->z + p2->z;
    return (point);
}

void addToPt3D(Pt3D p1, Pt3D p2)
{
    p1->x += p2->x;
    p1->y += p2->y;
    p1->z += p2->z;
}

float distance(Pt3D p1, Pt3D p2)
{
    Pt3D diff = subtractPt3D(p1, p2);
    float res = normalPt3D(diff);
    freePt3D(diff);
    return (res);
}

Pt3D normalizedPt3D(Pt3D pt)
{
    float mod = normalPt3D(pt);
    Pt3D res = CreatePt3D(pt->x / mod, pt->y / mod, pt->z / mod);
    return (res);
}

float normalPt3D(Pt3D pt)
{
    return sqrt(pt->x * pt->x + pt->y * pt->y + pt->z * pt->z);
}

void normalizePt3D(Pt3D pt)
{
    float mod = normalPt3D(pt);
    pt->x /= mod;
    pt->y /= mod;
    pt->z /= mod;
}

void copyPt3D(Pt3D p1, Pt3D p2)
{
    p1->x = p2->x;
    p1->y = p2->y;
    p1->z = p2->z;
}

Pt3D createCopyPt3D(Pt3D pt)
{
    return CreatePt3D(pt->x, pt->y, pt->z);
}

void multiplyPt3D(Pt3D pt, float s)
{
    pt->x *= s;
    pt->y *= s;
    pt->z *= s;
}

Pt3D crossProduct(Pt3D p1, Pt3D p2)
{
    GLfloat a = p1->y * p2->z - p1->z * p2->y;
    GLfloat b = p1->z * p2->x - p1->x * p2->z;
    GLfloat c = p1->x * p2->y - p1->y * p2->x;
    return (CreatePt3D(a, b, c));
}

float dotProduct(Pt3D p1, Pt3D p2)
{
    return (p1->x * p2->x + p1->y * p2->y + p1->z * p2->z);
}

void setPt3D(Pt3D point, GLfloat cx, GLfloat cy, GLfloat cz)
{
    point->x = cx;
    point->y = cy;
    point->z = cz;
}
