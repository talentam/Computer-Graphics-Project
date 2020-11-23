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
GLfloat cameraSpeed = 1;
//GLfloat angle = 0;
int frameRate = 60;
int roundTime = 5;


void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
//    glRotatef(angle, 0 ,1, 0);
//    glLoadIdentity();
//    gluLookAt(1, 1, 2, 0, 0, 0, 0, 1, 0);
////    glLoadIdentity();
//    glBegin(GL_POLYGON);
//    glNormal3d(0.0f, 0.0f, 1.0f);
//        glColor3ub(255, 255, 255);
//        glVertex3f(  -10, 10, 10 );
//        glVertex3f(  -10, -10, 10 );
//        glVertex3f(  10, -10, 10 );
//        glVertex3f(  10, 10, 10 );
//    glEnd();
//    glColor3ub(255, 255, 255);
    drawMonitor();
    glutSwapBuffers();
}

void init(void)
{
//    glEnable(GL_DEPTH);
//    glClearDepth (1.0f);
//    glClear (GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glColor4f(0,0,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,1,0.01,200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z,lookAt_x,lookAt_y,lookAt_z,up_x,up_y,up_z);
    initMonitor();
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h){
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    GLfloat nRange = 20.0f;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w<=h)
    {   glOrtho(-nRange, nRange, -nRange * aspect, nRange * aspect, -100, 100);  }
    else
    {  glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -100, 100);  }
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("Windmill");
    init();
    glutKeyboardFunc(&KeyBoards);
    glutSpecialFunc(&SpecialKey);
    glutDisplayFunc(&display);
//    glutReshapeFunc(reshape);
//    glutTimerFunc(1000/frameRate, timer, 0);
    glutMainLoop();
}
