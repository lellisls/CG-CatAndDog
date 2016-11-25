#ifndef PERNA_H
#define PERNA_H
#include "Object.h"
struct leg {
    float ang1, ang2, ang3;
    float maxAngle, maxAngle2;
    PObject part1, part2, part3;
    float time;
};

typedef struct leg Leg;
//DOG
Leg* createLeg();
Leg* createLeg2();
void drawLeg(Leg* leg, int mode);
void freeLeg(Leg * leg);

//CAT
Leg* createLeg3();
Leg* createLeg4();
void drawLeg2(Leg* leg, int mode);

#endif //PERNA_H
