//
// Created by GIGABYTE on 2020/11/25.
//
#include <gl/glut.h>

void drawRoom(void){
    glPushMatrix();
        glColor3ub(255, 255, 255);
        glTranslatef(-100, 23.5-100, -10);
        glTranslatef(-50, 0, 0);
        // back
        glBegin(GL_POLYGON);
        glNormal3d(0.0f, 0.0f, 1.0f);
        glColor3ub(190, 190, 190);
        glVertex3f(0, 0, 0);
        glVertex3f(200, 0, 0);
        glVertex3f(200, 200, 0);
        glVertex3f(0, 200, 0);
        glEnd();
        // bottom
        glBegin(GL_POLYGON);
        glNormal3d(0.0f, 0.0f, 1.0f);
        glColor3ub(250, 250, 250);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 200);
        glVertex3f(200, 0, 200);
        glVertex3f(200, 0, 0);
        glEnd();
        glPopMatrix();
//    printf("eye_x: %d, eye_y %d eye_z %d\n", eye_x, eye_y, eye_z);
}

