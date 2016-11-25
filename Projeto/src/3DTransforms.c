#include "../inc/3DTransforms.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
void matrix4x4SetIdentity(Matrix4x4 matIdent4x4)
{
    int row, col;
    for (row = 0; row < 4; ++row)
        for (col = 0; col < 4; ++col)
            matIdent4x4 [row][col] = (row == col);
}

void matrix4x4pPrint(Matrix4x4 mtx)
{
    int row, col;
    for (row = 0; row < 4; ++row) {
        for (col = 0; col < 4; ++col) {
            printf("%.2f " , mtx[row][col]);
        }
        printf("\n");
    }
}

void matrix4x4PreMultiply(Matrix4x4 m1, Matrix4x4 m2)
{
    int row, col;
    Matrix4x4 matTemp;
    for (row = 0; row < 4; ++row)
        for (col = 0; col < 4; ++col)
            matTemp[row][col] = m1[row][0] * m2[0][col] + m1[row][1] * m2[1][col]
                                + m1[row][2] * m2[2][col] + m1[row][3] * m2[3][col];
    for (row = 0; row < 4; ++row)
        for (col = 0; col < 4; ++col)
            m2[row][col] = matTemp[row][col];
}

void translate3D(GLfloat tx, GLfloat ty, GLfloat tz)
{
    Matrix4x4 matTransl3D;

    matrix4x4SetIdentity(matTransl3D);

    matTransl3D [0][3] = tx;
    matTransl3D [1][3] = ty;
    matTransl3D [2][3] = tz;

    matrix4x4PreMultiply(matTransl3D, matComposite);
}

void rotateY(Pt3D p1, GLfloat radianAngle)
{
    Matrix4x4 matQuatRot;
    float dx = 0, dy = 1, dz = 0;
    float axisVectLength = sqrt(dx * dx + dy * dy + dz * dz);
    float cosA = cosf(radianAngle);
    float oneC = 1 - cosA;
    float sinA = sinf(radianAngle);
    float ux = (dx) / axisVectLength;
    float uy = (dy) / axisVectLength;
    float uz = (dz) / axisVectLength;

    translate3D(-p1->x, -p1->y, -p1->z);
    matrix4x4SetIdentity(matQuatRot);
    matQuatRot[0][0] = ux * ux * oneC + cosA;
    matQuatRot[0][1] = ux * uy * oneC - uz * sinA;
    matQuatRot[0][2] = ux * uz * oneC + uy * sinA;
    matQuatRot[1][0] = uy * ux * oneC + uz * sinA;
    matQuatRot[1][1] = uy * uy * oneC + cosA;
    matQuatRot[1][2] = uy * uz * oneC - ux * sinA;
    matQuatRot[2][0] = uz * ux * oneC - uy * sinA;
    matQuatRot[2][1] = uz * uy * oneC + ux * sinA;
    matQuatRot[2][2] = uz * uz * oneC + cosA;

    matrix4x4PreMultiply(matQuatRot, matComposite);

    translate3D(p1->x, p1->y, p1->z);
}

void rotate3D( GLfloat radianAngle, GLfloat x, GLfloat y, GLfloat z )
{
    Pt3D ctr = CreatePt3D(0,0,0);
    Pt3D dir = CreatePt3D(x,y,z);
    rotate3Dv(ctr,dir,radianAngle);
    freePt3D(ctr);
    freePt3D(dir);
}

void rotate3Dv(Pt3D p1, Pt3D p2, GLfloat radianAngle)
{
    Matrix4x4 matQuatRot;
    float dx = p2->x - p1->x, dy = p2->y - p1->y, dz = p2->z - p1->z;
    float axisVectLength = sqrt(dx * dx + dy * dy + dz * dz);
    float cosA = cosf(radianAngle);
    float oneC = 1 - cosA;
    float sinA = sinf(radianAngle);
    float ux = (dx) / axisVectLength;
    float uy = (dy) / axisVectLength;
    float uz = (dz) / axisVectLength;

    translate3D(-p1->x, -p1->y, -p1->z);
    matrix4x4SetIdentity(matQuatRot);
    matQuatRot[0][0] = ux * ux * oneC + cosA;
    matQuatRot[0][1] = ux * uy * oneC - uz * sinA;
    matQuatRot[0][2] = ux * uz * oneC + uy * sinA;
    matQuatRot[1][0] = uy * ux * oneC + uz * sinA;
    matQuatRot[1][1] = uy * uy * oneC + cosA;
    matQuatRot[1][2] = uy * uz * oneC - ux * sinA;
    matQuatRot[2][0] = uz * ux * oneC - uy * sinA;
    matQuatRot[2][1] = uz * uy * oneC + ux * sinA;
    matQuatRot[2][2] = uz * uz * oneC + cosA;

    matrix4x4PreMultiply(matQuatRot, matComposite);

    translate3D(p1->x, p1->y, p1->z);
}

void scale3D(GLfloat sx, GLfloat sy, GLfloat sz, Pt3D fixedPt)
{
    Matrix4x4 matScale3D;
    matrix4x4SetIdentity(matScale3D);
    matScale3D[0][0] = sx;
    matScale3D[0][3] = (1 - sx) * fixedPt->x;
    matScale3D[1][1] = sy;
    matScale3D[1][3] = (1 - sy) * fixedPt->y;
    matScale3D[2][2] = sz;
    matScale3D[2][3] = (1 - sz) * fixedPt->z;
    matrix4x4PreMultiply(matScale3D, matComposite);
}

void resetTransformMatrix()
{
    matrix4x4SetIdentity(matComposite);
}

void multiplyPt3DMtx4x4(Pt3D pt, Matrix4x4 mat)
{
    Pt3D res = ZeroPt3D();
    res->x = mat[0][0] * pt->x + mat[0][1] * pt->y + mat[0][2] * pt->z + mat[0][3];
    res->y = mat[1][0] * pt->x + mat[1][1] * pt->y + mat[1][2] * pt->z + mat[1][3];
    res->z = mat[2][0] * pt->x + mat[2][1] * pt->y + mat[2][2] * pt->z + mat[2][3];
    pt->x = res->x;
    pt->y = res->y;
    pt->z = res->z;
    freePt3D(res);
}

void Pt3DTransform(Pt3D pt)
{
    multiplyPt3DMtx4x4(pt, matComposite);
}
