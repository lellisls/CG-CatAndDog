#ifndef WALL_H
#define WALL_H
#include "Object.h"
struct wall {
    PObject obj1, obj2;
};

typedef struct wall * Wall;

Wall CreateWall();
void DrawWall(Wall w, int mode);
void freeWall(Wall w);
#endif // WALL_H
