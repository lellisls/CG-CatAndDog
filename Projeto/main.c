//Joás Gonçalves Sanches e Lucas Santana Lellis
#include <stdio.h>
#include "inc/scene.h"
#include "inc/Light.h"
#include <GL/glx.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "math.h"
#include "time.h"
Scene scn;
void display();
void teclado(unsigned char key, int x, int y);
void processSpecialKeys(int key, int xx, int yy);
void mouse(int button, int state, int x, int y);
void passiveMouse(int x, int y);
void mouseWheel(int button, int dir, int x, int y);
void animate();
void SetUpOpengl();
void SetUpPerspective();
void SetUpOrtographic();
void reshape(GLsizei w, GLsizei h);
void ProcessMenu(int value);

GLdouble fov = 45, zNear = 0.01, zFar = 200;
int windowWidth = 800;
int windowHeight = 800;
float aspectRatio = 1;

int pause = 0;
enum MENU { PAUSE = 123, ORTOGRAPHIC, PERSPECTIVE, LINE, SOLID, INSERTCAT, INSERTDOG };
int projectionMode = PERSPECTIVE;
int drawType = GL_POLYGON;

//Funções
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("PROJETO CG");
    srand(time(NULL));
    scn = CreateScene(FREE);
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutFullScreen();
    glutIdleFunc(animate);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passiveMouse);
    glutMouseFunc(mouse);
    setupLighting();

    // Cria um Menu
    int submenuCamera,submenuMode, subMenuProjection;

    submenuCamera = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Free (1)",FREE);
    glutAddMenuEntry("Static (2)",STATIC);
    glutAddMenuEntry("Follow Cat (3)",FOLLOWCAT);
    glutAddMenuEntry("Follow Dog (4)",FOLLOWDOG);
    glutAddMenuEntry("Dog GoPro (5)",DOGEYE);

    submenuMode = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Solid",SOLID);
    glutAddMenuEntry("Wire",LINE);

    subMenuProjection = glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("Perspective",PERSPECTIVE);
    glutAddMenuEntry("Ortographic",ORTOGRAPHIC);

    glutCreateMenu(ProcessMenu);
    glutAddMenuEntry("PAUSE", PAUSE);
    glutAddMenuEntry("Insert Cat (G)", INSERTCAT);
    glutAddMenuEntry("Insert Dog (C)", INSERTDOG);
    glutAddSubMenu("Camera ( 1 - 5 )",submenuCamera);
    glutAddSubMenu("Polygon mode ( A )",submenuMode);
    glutAddSubMenu("Projection mode ( P )",subMenuProjection);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);

    glutMainLoop();
    freeScene(scn);
    return 0;
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawScene(scn, drawType);
    glutSwapBuffers();
}

void teclado(unsigned char key, int x, int y)
{
    switch (key) {
    case 27: //Sai do programa
        exit(1);
        break;
    case 'l':
    case 'L':
        resetScene(scn);
        break;
    case 'G':
    case 'g':
        scn->cat->position->x = rand() % 26 - 13;
        scn->cat->position->z = rand() % 26 - 13;
        resetCat(scn->cat);
        break;
    case 'C':
    case 'c':
        scn->dog->position->x = rand() % 26 - 13;
        scn->dog->position->z = rand() % 26 - 13;
        scn->dog->angle = rand() % 360;
        scn->dog->enabled = 1;
        scn->dog->time = 0;
        scn->cat->stop = 0;
        break;
    case 't':
        scn->cat->translation->y -=2;
        scn->dog->translation->y -=2;
        break;
    case 'T':
        scn->cat->translation->y +=2;
        scn->dog->translation->y +=2;
        break;
    case'x' :
        scn->cat->rotation->x -=2;
        scn->dog->rotation->x -=2;
        break;
    case'X' :
        scn->cat->rotation->x +=2;
        scn->dog->rotation->x +=2;
        break;
    case'y' :
        scn->cat->rotation->y -=2;
        scn->dog->rotation->y -=2;
        break;
    case'Y' :
        scn->cat->rotation->y +=2;
        scn->dog->rotation->y +=2;
        break;
    case'z' :
        scn->cat->rotation->z -=2;
        scn->dog->rotation->z -=2;
        break;
    case'Z' :
        scn->cat->rotation->z +=2;
        scn->dog->rotation->z +=2;
        break;
    case's' :
        if( scn->dog->scale > 0.2 ){
            scn->dog->scale -= 0.1;
            scn->cat->scale -= 0.1;
        }
        break;
    case'S' :
        scn->dog->scale += 0.1;
        scn->cat->scale += 0.1;
        break;
    case '1':
        setSceneMode(scn, FREE);
        break;
    case '2':
        setSceneMode(scn, STATIC);
        break;
    case '3':
        setSceneMode(scn, FOLLOWCAT);
        break;
    case '4':
        setSceneMode(scn, FOLLOWDOG);
        break;
    case '5':
        setSceneMode(scn, DOGEYE);
        break;
    case 'a':
    case 'A':
        if (drawType == GL_LINE_LOOP) {
            drawType = GL_POLYGON;
        } else {
            drawType = GL_LINE_LOOP;
        }
        break;
    case 'p':
    case 'P':
        if( projectionMode == PERSPECTIVE ) {
            projectionMode = ORTOGRAPHIC;
        } else {
            projectionMode = PERSPECTIVE;
        }
        SetUpOpengl();
        break;
    }
    glutPostRedisplay();
    return;
    printf("Pt(%d,%d)\n", x, y);
}

int startX = 0, startY = 0, dragging = 0;

void mouse(int button, int state, int x, int y)
{
    switch (button) {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN) {
            dragging = !dragging;
            startX = x;
            startY = y;
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN) {
            setCatPos(scn, fov, windowHeight, windowWidth, zNear, (double)x, (double) y);
        }
        break;
    case 3:
        if (state == GLUT_UP) {
            moveCameraFront(scn->currentCam);
        }
        break;
    case 4:
        if (state == GLUT_UP) {
            moveCameraBack(scn->currentCam);
        }
        break;
    case 5:
        if (state == GLUT_UP) {
            scn->dog->angle ++;
        }
        break;
    case 6:
        if (state == GLUT_UP) {
            scn->dog->angle --;
        }
        break;
    }
    glutPostRedisplay();
}

void passiveMouse(int x, int y)
{
    if (dragging == 1) {
        rotateCamera(scn->currentCam, x - startX, y - startY);
        startX = x;
        startY = y;
    }
    glutPostRedisplay();
}

void SetUpOpengl()
{
    if (projectionMode == PERSPECTIVE) {
        SetUpPerspective();
    } else {
        SetUpOrtographic();
    }
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glFrontFace(GL_CCW);

    //        glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);

    glShadeModel(GL_SMOOTH);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void SetUpOrtographic()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2 * aspectRatio, 2 * aspectRatio, -2, 2, zNear, zFar);

}

void SetUpPerspective()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fov, aspectRatio, zNear, zFar);
    glViewport(0, 0, windowWidth, windowHeight);
}

void reshape(GLsizei w, GLsizei h)
{
    printf("Reshape: ( %d, %d )\n", w, h);
    windowWidth = w;
    windowHeight = h;
    aspectRatio = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    SetUpOpengl();
}

void animate()
{
    if( pause )
        return;
    if (scn->cat->enabled)
        walkCat(scn->cat, 12);
    if (scn->dog->enabled)
        hunt(scn->dog, scn->cat);
    glutPostRedisplay();
}

void ProcessMenu(int value) {
    switch (value) {
    case PAUSE:
        pause = !pause;
        break;
    case PERSPECTIVE:
        projectionMode = PERSPECTIVE;
        SetUpOpengl();
        break;
    case ORTOGRAPHIC:
        projectionMode = ORTOGRAPHIC;
        SetUpOpengl();
        break;
    case LINE:
        drawType = GL_LINE_LOOP;
        break;
    case SOLID:
        drawType = GL_QUADS;
        break;
    case INSERTCAT:
        scn->cat->position->x = rand() % 26 - 13;
        scn->cat->position->z = rand() % 26 - 13;
        resetCat(scn->cat);
        break;
    case INSERTDOG:
        scn->dog->position->x = rand() % 26 - 13;
        scn->dog->position->z = rand() % 26 - 13;
        scn->dog->angle = rand() % 360;
        scn->dog->enabled = 1;
        scn->dog->time = 0;
        scn->cat->stop = 0;
        break;
    default:
        setSceneMode(scn,value);
        break;
    }
    glutPostRedisplay();
}
