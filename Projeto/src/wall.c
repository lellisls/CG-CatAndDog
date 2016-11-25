#include "../inc/wall.h"

Wall CreateWall()
{
    Wall w = (Wall) malloc(sizeof(struct wall));
    w->obj1 = CreateObject(5, 2);
    AddVertex(w->obj1, -0.05, 0.1);
    AddVertex(w->obj1, 0.05, 0.1);
    AddVertex(w->obj1, 0.05, -0.1);
    AddVertex(w->obj1, -0.05, -0.1);
    AddVertex(w->obj1, -0.05, 0.1);
    TranslateSlice(w->obj1, 0, 0.5, -16);
    Extrude(w->obj1);
    TranslateSlice(w->obj1, 0, 0, 32);
    FinalizeObject(w->obj1);

    w->obj2 = CreateObject(5, 2);
    AddVertex(w->obj2, -0.1, 0.1);
    AddVertex(w->obj2, 0.1, 0.1);
    AddVertex(w->obj2, 0.1, -0.1);
    AddVertex(w->obj2, -0.1, -0.1);
    AddVertex(w->obj2, -0.1, 0.1);
    RotateSlice(w->obj2, 0, 0, PI / 2);
    Extrude(w->obj2);
    TranslateSlice(w->obj2, 0, 1.5, 0);
    FinalizeObject(w->obj2);



    return w;
}

void DrawWall(Wall w, int mode)
{

    glPushMatrix();

    glTranslatef(-16, 0, 0);

    glPushMatrix();
    DrawObject(w->obj1, mode);
    glTranslatef(0, 0.5, 0);
    DrawObject(w->obj1, mode);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -16);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glTranslatef(0, 0, 4);
    DrawObject(w->obj2, mode);
    glPopMatrix();
    glPopMatrix();
}

void freeWall(Wall w)
{
    freeObj(w->obj1);
    freeObj(w->obj2);
}
