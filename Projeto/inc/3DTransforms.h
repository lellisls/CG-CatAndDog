#ifndef DTRANSFORMS_H
#define DTRANSFORMS_H
#include <GL/gl.h>
#include "Pt3D.h"

typedef double Matrix4x4 [4][4];

Matrix4x4 matComposite;
void matrix4x4pPrint();
void matrix4x4SetIdentity(Matrix4x4 matIdent4x4);
void matrix4x4PreMultiply(Matrix4x4 m1, Matrix4x4 m2);
void translate3D(GLfloat tx, GLfloat ty, GLfloat tz);
void rotate3D( GLfloat radianAngle, GLfloat x, GLfloat y, GLfloat z );
void rotate3Dv(Pt3D p1, Pt3D p2, GLfloat radianAngle);
void scale3D(GLfloat sx, GLfloat sy, GLfloat sz, Pt3D fixedPt);
void resetTransformMatrix();
void Pt3DTransform(Pt3D pt);
void multiplyPt3DMtx4x4(Pt3D pt, Matrix4x4 mat);
#endif // DTRANSFORMS_H
