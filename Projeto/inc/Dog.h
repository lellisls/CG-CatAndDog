#ifndef DOG_H
#define DOG_H
#include "Leg.h"
#include "Cat.h"
struct dog {
    Leg * leg1, * leg2, * leg3, * leg4;
    PObject body, neck, head, ear, tail;
    Pt3D position, direction, rotation, translation;
    int stop, sit, enabled;
    float angle, angle2, speed, maxSpeed, scale;
    float time;
};

typedef struct dog * Dog;

Dog  CreateDog();
void freeDog(Dog dog);
void drawDog(Dog dog , int mode);
void animateDog(Dog dog);
void startDog(Dog dog);
void sitDog(Dog dog);
void stopDog(Dog dog);
void hunt(Dog dog, Cat cat);

#endif //DOG_H
