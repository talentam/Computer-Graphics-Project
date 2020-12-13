//
// Created by GIGABYTE on 2020/11/25.
//
#include <gl/glut.h>
#include "Texture.h"
#include <string>
#include <time.h>
#include <math.h>
#include "main.h"

const GLfloat PI = 3.141592653f;
const int Width = 600;
const int Height = 600;
// 当前时间，时 分 秒
//extern float Hour = 0;
//extern float Minute = 0;
//extern float Second = 0;


void drawSquare(string texture, int R, int G, int B) {
    glPushMatrix();

    glEnable(GL_COLOR_MATERIAL);
    int textId = GetTexture("../../image/floor.bmp");
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textId);

    // back
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, 0.0f, 1.0f);
    glColor3ub(190, 190, 190);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, 300);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(300, 0, 300);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(300, 0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_COLOR_MATERIAL);

    glPopMatrix();
}

void drawClock(void){
    glColor3f(1, 1, 1); //

    int centerX = Width / 2;
    int centerY = Height / 2;
    int r = 100;
    int n = 300;
    int i;

    // draw clock boundary
    glPushMatrix();
    for (i = 0; i<n; i++)
    {
        glPushMatrix();
        glTranslatef(centerX + (r + 10)*cos(2 * PI / n * i), centerY + (r + 10)*sin(2 * PI / n * i), 0);
        glutSolidSphere(5, 20, 20);
        glPopMatrix();
    }
    glPopMatrix();

    // back circle board
    glPushMatrix();
    glTranslatef(0, 0, -1);
    glColor3f(0, 0, 0); //
    glBegin(GL_TRIANGLE_FAN);
    for (i = 0; i<n; i++)
    {
        glVertex2f(centerX + (r + 10)*cos(2 * PI / n * i), centerY + (r + 10)*sin(2 * PI / n * i));
    }
    glEnd();
    glColor3f(1, 1, 1); //
    glPopMatrix();

    // draw the clock dial
    int gaps = 60;
    float line1 = 10;
    for (i = 0; i < gaps; i++)
    {
        if (i % 5 == 0){     //long dial
            glPushMatrix();
            glTranslatef(centerX + (r - line1) * sin(2 * PI / gaps * i), centerY + (r - line1) * cos(2 * PI / gaps * i), 0);
            glRotatef(-i*6, 0, 0, 1);
            glScalef(1, 4, 1);
            glutSolidCube(3);
            glPopMatrix();

        }else {              //short dial
            glPushMatrix();
            glTranslatef(centerX + (r - line1) * sin(2 * PI / gaps * i), centerY + (r - line1) * cos(2 * PI / gaps * i), 0);
            glRotatef(-i*6, 0, 0, 1);
            glScalef(1, 2, 1);
            glutSolidCube(2);
            glPopMatrix();
        }
    }

    // middle circle
    glPushMatrix();
    glTranslatef(centerX, centerY, 0);
    glutSolidSphere(3, 20, 20);
    glPopMatrix();

    float angleS = Second*6;
    float angleM = Minute*6 + Second / 10;
    float h12 = Hour >= 12 ? (Hour - 12) : Hour;
    float angleH = h12*30 + Minute/2 + Second/2/60;

    // Second needle
    glPushMatrix();
        glTranslatef(centerX, centerY, 0);
        glRotatef(-angleS, 0, 0, 1);
        glTranslatef(0, 35, 0);
        glScalef(1, 110, 1);
        glutSolidCube(1);
    glPopMatrix();

    //Minute needle
    glPushMatrix();
        glTranslatef(centerX, centerY, 0);
        glRotatef(-angleM, 0, 0, 1);
        glTranslatef(0, 35, 0);
        glScalef(2, 70, 2);
        glutSolidCube(1);
    glPopMatrix();

    // Hour needle
    glPushMatrix();
        glTranslatef(centerX, centerY, 0);
        glRotatef(-angleH, 0, 0, 1);
        glTranslatef(0, 27, 0);
        glScalef(3, 54, 3);
        glutSolidCube(1);
    glPopMatrix();

    glFlush();
}
void drawWalls(void){
    glPushMatrix();
        glColor3ub(255, 255, 255);
        glTranslatef(-100, 23.5 - 100, -10);
        glTranslatef(-50, 0, 0);
        string bitmap = "../../image/floor.bmp";
        // bottom floor

        glPushMatrix();
            drawSquare(bitmap, 0, 255, 255);
        glPopMatrix();
        // left wall
        glPushMatrix();
            glRotatef(-90, 0, 0, 1);
            glTranslatef(-300, 0, 0);
            drawSquare(bitmap, 255, 255, 255);
        glPopMatrix();
        // right wall
        glPushMatrix();
            glRotatef(90, 0, 0, 1);
            glTranslatef(0, -300, 0);
            drawSquare(bitmap, 255, 255, 255);
        glPopMatrix();
        // back wall
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glTranslatef(0, 0, -300);
            drawSquare(bitmap, 255, 255, 255);
        glPopMatrix();
        // top roof
        glPushMatrix();
            glRotatef(180, 1, 0, 0);
            glTranslatef(0, -300, -300);
            drawSquare(bitmap, 255, 255, 255);
        glPopMatrix();
    glPopMatrix();
}
void drawRoom(void) {


    drawWalls();

    // draw clock
    glPushMatrix();
        glTranslatef(30, 0, 0);
        glScalef(0.2, 0.2, 0.2);
        drawClock();
    glPopMatrix();



//    glBegin(GL_POLYGON);
//    glNormal3d(0.0f, 0.0f, 1.0f);
//    glTexCoord2f(0.0f, 1.0f);
//    glVertex3f(0, 0, 0);
//    glTexCoord2f(0.0f, 0.0f);
//    glVertex3f(0, 0, 200);
//    glTexCoord2f(1.0f, 0.0f);
//    glVertex3f(200, 0, 200);
//    glTexCoord2f(1.0f, 1.0f);
//    glVertex3f(200, 0, 0);
//    glEnd();
    // bottom

    // Enable texturing

//    glEnable(GL_COLOR_MATERIAL);
////    // Generate a texture buffer
////    int textId = GetTexture("C:/Users/GIGABYTE.000/Desktop/floor.bmp");
//    int textId = GetTexture("../../image/floor.bmp");
//    glEnable(GL_TEXTURE_2D);
////
////    // Bin to buffer
//    glBindTexture(GL_TEXTURE_2D, textId);
//    // Set texture parameters
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//
//    glBegin(GL_POLYGON);
//    glNormal3d(0.0f, 0.0f, 1.0f);
//    glColor3ub(250, 250, 250);
//    glTexCoord2f(0.0f, 1.0f);
//    glVertex3f(0, 0, 0);
//    glTexCoord2f(0.0f, 0.0f);
//    glVertex3f(0, 0, 200);
//    glTexCoord2f(1.0f, 0.0f);
//    glVertex3f(200, 0, 200);
//    glTexCoord2f(1.0f, 1.0f);
//    glVertex3f(200, 0, 0);
//    glEnd();
//
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_COLOR_MATERIAL);


}



