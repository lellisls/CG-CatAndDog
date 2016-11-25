#ifndef CAT_H
#define CAT_H
#include "Leg.h"
struct cat {
    Leg * leg1, * leg2, * leg3, * leg4;
    PObject body, neck, head, earLeft, earRight, tail;
    Pt3D position;
    Pt3D rotation;
    Pt3D translation;
    float angle;
    float time;
    float stamina;
    float speed;
    float scale;
    int enabled;
    int stop;
};


typedef struct cat * Cat;

Cat  CreateCat();
void resetCat( Cat cat );
void freeCat(Cat cat);
void drawCat(Cat cat, int mode);
void walkCat(Cat cat, float bounds);
void animateCat(Cat cat);

#endif //CAT_H
