#include <stdio.h>
#include <gl/glut.h>
#include "monitor.h"
#include "keyboard.h"
#include "desk.h"
#include "room.h"
#include <windows.h>
#include "animation.h"

GLfloat eye_x = 10;
GLfloat eye_y = 0;
GLfloat eye_z = 350;
GLfloat lookAt_x = 10;
GLfloat lookAt_y = 0;
GLfloat lookAt_z = 0;
GLfloat up_x = 0;
GLfloat up_y = 1;
GLfloat up_z = 0;
GLfloat cameraSpeed = 5;

// clock time
extern float Hour = 0;
extern float Minute = 0;
extern float Second = 0;

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    drawRoom();
    drawMonitor();
    drawDesk();
    glutSwapBuffers();
}

void init(void)
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,1,0.01,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z,lookAt_x,lookAt_y,lookAt_z,up_x,up_y,up_z);
    initMonitor();

    // lighting settings
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 50.0, 250.0, 200, 0.0 };
    GLfloat white_light[] = { 1, 1, 1, 1.0 };
    GLfloat Light_Model_Ambient[] = { 0.9, 0.9, 0.9, 1.0 };

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("CW3");
    init();
    glutKeyboardFunc(&KeyBoards);
    glutSpecialFunc(&SpecialKey);
    glutDisplayFunc(&display);
    glutTimerFunc(1000/60, clockAni, 0);
    glutMainLoop();
}
