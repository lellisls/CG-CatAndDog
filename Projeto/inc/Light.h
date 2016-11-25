#ifndef LIGHT_H
#define LIGHT_H
#include"Pt3D.h"
void setupLighting();
void light(int lightNbr);
void spot( int lightNbr, Pt3D pos, Pt3D target);
void ambient( );
#endif // LIGHT_H
