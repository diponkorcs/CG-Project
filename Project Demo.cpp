#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <windows.h>
#include <math.h>
using namespace std;

float _moveA = 0.0f;
float _moveB = 0.0f;
float _moveC = 0.0f;
float _angle1 = 0.0f;
float speed = 0.02f;

void drawScene()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity(); //Reset the drawing perspective
    gluOrtho2D(-12,38,-19,14);//range
    glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(1500, 1000);
    glutCreateWindow("Transformation");


    init();
    glutSpecialFunc(SpecialInput);


    glutDisplayFunc(drawScene);
    glutTimerFunc(20, update1, 0); //Add a timer
    glutTimerFunc(20, update2, 0); //Add a timer

    glutTimerFunc(10, update3, 0);
    glutTimerFunc(20, update4, 0);
    glutKeyboardFunc(handleKeypress);

    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
