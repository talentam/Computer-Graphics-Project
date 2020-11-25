//
// Created by GIGABYTE on 2020/11/19.
//

/////////////////
//原点translate(1.4, 0.2, 0)可以到屏幕左上角
/////////////////


#include <gl/glut.h>
#include <stdio.h>
#include "main.h"

GLint width = 20;         //number of boxes in one row
GLint height = 15;        //number of boxes in one column
const GLfloat boxSideLen = 1.2;   //the side length of one box
const GLfloat pixelSideLen = 0.2; //the side length of one pixel
GLint currentLetter_X = 0;  //record the current letter X coordinate
GLint currentLetter_Y = 0;  //record the current letter Y coordinate
GLint currentLetter_num = 0;
GLint currentLetter = 0;    //record what is the current letter
GLint letterList[15][20];

GLint *writing[30];         //store how to write one letter pixel by pixel

GLint Blank[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0}};

GLint A[6][6] = {{0, 0, 1, 0, 0, 0},
                 {0, 1, 0, 1, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint B[6][6] = {{1, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {1, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint C[6][6] = {{0, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {0, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint D[6][6] = {{0, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint E[6][6] = {{1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint F[6][6] = {{1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint G[6][6] = {{1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint H[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint I[6][6] = {{0, 1, 1, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint J[6][6] = {{1, 1, 1, 1, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 1, 0, 0},
                 {1, 0, 0, 1, 0, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint K[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0, 0},
                 {1, 1, 1, 0, 0, 0},
                 {1, 0, 0, 1, 0, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint L[6][6] = {{1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint M[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 1, 0, 1, 1, 0},
                 {1, 0, 1, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint N[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 1, 0, 0, 1, 0},
                 {1, 0, 1, 0, 1, 0},
                 {1, 0, 0, 1, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint O[6][6] = {{0, 1, 1, 1, 0, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint P[6][6] = {{1, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint Q[6][6] = {{1, 1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0, 0},
                 {1, 0, 0, 1, 0, 0},
                 {1, 0, 0, 1, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint R[6][6] = {{1, 1, 1, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 1, 0, 1, 0, 0},
                 {0, 1, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint S[6][6] = {{1, 1, 1, 1, 1, 0},
                 {1, 0, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 1, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint T[6][6] = {{1, 1, 1, 1, 1, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint U[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint V[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 1, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint W[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 1, 0, 1, 0},
                 {1, 1, 0, 1, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint X[6][6] = {{1, 0, 0, 0, 1, 0},
                 {0, 1, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 1, 0, 1, 0, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint Y[6][6] = {{1, 0, 0, 0, 1, 0},
                 {0, 1, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint Z[6][6] = {{1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1, 0},
                 {0, 0, 0, 0, 0, 0}};

GLint Space[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0}};

GLint Comma[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 0, 0, 0},
                     {0, 1, 1, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0}};

GLint Period[6][6] = {{0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0}};

void initMonitor(void){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            letterList[i][j] = 0;
        }
    }
    //initialize the way to write letters
    writing[0] = &Blank[0][0];
    writing[1] = &A[0][0];
    writing[2] = &B[0][0];
    writing[3] = &C[0][0];
    writing[4] = &D[0][0];
    writing[5] = &E[0][0];
    writing[6] = &F[0][0];
    writing[7] = &G[0][0];
    writing[8] = &H[0][0];
    writing[9] = &I[0][0];
    writing[10] = &J[0][0];
    writing[11] = &K[0][0];
    writing[12] = &L[0][0];
    writing[13] = &M[0][0];
    writing[14] = &N[0][0];
    writing[15] = &O[0][0];
    writing[16] = &P[0][0];
    writing[17] = &Q[0][0];
    writing[18] = &R[0][0];
    writing[19] = &S[0][0];
    writing[20] = &T[0][0];
    writing[21] = &U[0][0];
    writing[22] = &V[0][0];
    writing[23] = &W[0][0];
    writing[24] = &X[0][0];
    writing[25] = &Y[0][0];
    writing[26] = &Z[0][0];
    writing[27] = &Space[0][0];
    writing[28] = &Comma[0][0];
    writing[29] = &Period[0][0];


}

// draw single box contain one letter
void drawBox(int letter){
    int numOfPixels = int(boxSideLen/pixelSideLen);

    for(int m = 0; m < numOfPixels; m++){
        glPushMatrix();
        glTranslatef(0, -m*pixelSideLen, 0);
        for(int n = 0; n < numOfPixels; n++){
            glTranslatef(pixelSideLen, 0,0);
            // display the letter captured from keyboard
            if(*(writing[letter]+m*6+n) == 1){
                glColor3f(   1,  1, 1);
            }else{
                glColor3f(   0.2,  0.2, 0.2);
            }
            glBegin(GL_POLYGON);
            glNormal3d(0.0f, 0.0f, 1.0f);
            glVertex3f(  0, 0, 0 );
            glVertex3f(  0.2, 0, 0 );
            glVertex3f(  0.2, 0.2, 0 );
            glVertex3f(  0, 0.2, 0 );
            glEnd();
        }
        glPopMatrix();
    }
}

// the monitor consists of 20*15 boxes.
void drawScreen(void){
    glTranslatef(0, 0, 0.5);
    for(int i = 0; i < height+2; i++){
        glPushMatrix();
        glTranslatef(0, -i*boxSideLen, 0);
        for(int j = 0; j < width+2; j++){
            glTranslatef(boxSideLen, 0,0);
            if(i == 0 | j == 0| i == height+1 | j == width+1){
                int a = 27;
                drawBox(a);
            }else{
                drawBox(letterList[i-1][j-1]);
            }
        }
        glPopMatrix();
    }
}

//void drawRoom(void){
//    glColor3ub(255, 255, 255);
////    glPushMatrix();
////        glTranslatef(0, 0, 5);
////        glutSolidSphere(0.1, 20, 20);
////    glPopMatrix();
//
//    glBegin(GL_POLYGON);
//    glNormal3d(0.0f, 0.0f, 1.0f);
//    glColor3ub(255, 255, 255);
//    glVertex3f(  -100, 100, -10 );
//    glVertex3f(  -100, -100, -10 );
//    glVertex3f(  100, -100, -10 );
//    glVertex3f(  100, 100, -10 );
//    glEnd();
////    printf("eye_x: %d, eye_y %d eye_z %d\n", eye_x, eye_y, eye_z);
//}

void drawBoundary(){

    glPushMatrix();
        // back board
        glPushMatrix();
            glColor3ub(0, 0, 0);
            glTranslatef(1.4, 0.2, -0.5);
            glTranslatef(22.0/2*boxSideLen, -17.0/2*boxSideLen, 0);
            glScalef(22, 17, 0.1);
            glutSolidCube(1.2);
        glPopMatrix();

        glColor3ub(0, 0, 0);
        glTranslatef(0.2, 1.4, 0);
        // top boundary
        glPushMatrix();
            glTranslatef(12*boxSideLen, -0.5*boxSideLen, 0);
            glScalef(24, 1, 1);
            glutSolidCube(1.2);
        glPopMatrix();
        // bottom boundary
        glPushMatrix();
            glTranslatef(12*boxSideLen, -18.5*boxSideLen, 0);
            glScalef(24, 1, 1);
            glutSolidCube(1.2);
        glPopMatrix();
        // left boundary
        glPushMatrix();
            glTranslatef(0.5*boxSideLen, -9.5*boxSideLen, 0);
            glScalef(1, 17, 1);
            glutSolidCube(1.2);
        glPopMatrix();
        // right boundary
        glPushMatrix();
            glTranslatef(23.5*boxSideLen, -9.5*boxSideLen, 0);
            glScalef(1, 17, 1);
            glutSolidCube(1.2);
        glPopMatrix();
    glPopMatrix();
}

void drawSupport(void){
    glPushMatrix();
        glTranslatef(0.2, 1.4, 0);
        glTranslatef((width+4)/2*boxSideLen, -(height+4)*boxSideLen, 0);
        glColor3ub(230, 230, 230);
        glTranslatef(0, -3*boxSideLen, 0);
        glPushMatrix();
            glScalef(4*boxSideLen, 6*boxSideLen, boxSideLen);
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
        glTranslatef(0, -3.25*boxSideLen, 3.5/2*boxSideLen);
            glColor3ub(192, 192, 192);
            glScalef(12*boxSideLen, 0.5*boxSideLen, 5*boxSideLen);
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
}

void drawMonitor(void){
//    printf("eye_x: %f, eye_y %f eye_z %f\n", eye_x, eye_y, eye_z);
    glPushMatrix();
        glScalef(1.5, 1.5, 1.5);
        glTranslatef(-40, 29, 10);
//        glPushMatrix();
//            drawRoom();
//        glPopMatrix();
        glPushMatrix();
            drawScreen();
        glPopMatrix();
        glPushMatrix();
            drawBoundary();
        glPopMatrix();
        glPushMatrix();
            drawSupport();
        glPopMatrix();
    glPopMatrix();
}


