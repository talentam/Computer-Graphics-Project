#include <stdio.h>
#include <gl/glut.h>
#include "monitor.h"
#include "keyboard.h"
//#include "camera.h"

GLfloat eye_x = 0;
GLfloat eye_y = 0;
GLfloat eye_z = 50;
GLfloat lookAt_x = 0;
GLfloat lookAt_y = 0;
GLfloat lookAt_z = 0;
GLfloat up_x = 0;
GLfloat up_y = 1;
GLfloat up_z = 0;
GLfloat cameraSpeed = 0.5;
int frameRate = 60;
int roundTime = 5;


void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(1, 1, 2, 0, 0, 0, 0, 1, 0);
    drawMonitor();
    glutSwapBuffers();
}

//void reshape(int w, int h){
//    GLfloat aspect = (GLfloat)w / (GLfloat)h;
//    GLfloat nRange = 20.0f;
//    glViewport(0,0,w,h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    if (w<=h)
//    {   glOrtho(-nRange, nRange, -nRange * aspect, nRange * aspect, -10, 10);  }
//    else
//    {  glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -10, 10);  }
//    glMatrixMode(GL_MODELVIEW);
//}

void init(void)
{
    glEnable(GL_DEPTH);
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glColor4f(0,0,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,1,1,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z,lookAt_x,lookAt_y,lookAt_z,up_x,up_y,up_z);
    initMonitor();
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_DEPTH_TEST);
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Windmill");
    init();
    glutKeyboardFunc(&KeyBoards);
    glutSpecialFunc(&SpecialKey);
    ////////////////////
//    int A1[6][6] = {{1, 0, 0, 0, 1, 0},
//                     {0, 1, 0, 1, 0, 0},
//                     {0, 0, 1, 0, 0, 0},
//                     {0, 0, 1, 0, 0, 0},
//                     {0, 0, 1, 0, 0, 0},
//                     {0, 0, 0, 0, 0, 0}};
//
//    int A2[6][6] = {{1, 1, 1, 1, 1, 0},
//                     {0, 0, 0, 1, 0, 0},
//                     {0, 0, 1, 0, 0, 0},
//                     {0, 1, 0, 0, 0, 0},
//                     {1, 1, 1, 1, 1, 0},
//                     {0, 0, 0, 0, 0, 0}};
//
//    int *p = &A1[0][0]; //指向A1[0][0]的指针
//    int *k = &A2[0][0];
//    int *q[2];
//
//    q[0] = &A1[0][0];
//    q[1] = &A2[0][0];
//    for(int i = 0; i < 6; i++){
//        for(int j = 0; j < 6; j++){
//            printf("%d ", *(q[1]+i*6+j));
//        }
//        printf("\n");
//    }


    //////////////////////
    glutDisplayFunc(&display);
//    glutReshapeFunc(reshape);
//    glutTimerFunc(1000/frameRate, timer, 0);
    glutMainLoop();
}
