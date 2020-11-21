//
// Created by GIGABYTE on 2020/11/19.
//

#include <gl/glut.h>
#include <stdio.h>

GLint width = 20;         //number of boxes in one row
GLint height = 15;        //number of boxes in one column
const GLfloat boxSideLen = 1.2;   //the side length of one box
const GLfloat pixelSideLen = 0.2; //the side length of one pixel
GLint backSpace = 0;
GLint currentLetter_X = 0;  //record the current letter X coordinate
GLint currentLetter_Y = 0;  //record the current letter Y coordinate
GLint currentLetter_num = 0;
GLint currentDisplay = 0;   //record the current letter display or not
GLint currentLetter = 0;    //record what is the current letter
GLint letterList[20][15];
//struct box
//{
//    int display = 0;
//    int alphabet = 0;
//}boxes[width][height];

GLint Blank[6][6] = {{0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0}};

GLint A[6][6] = {{0, 0, 1, 0, 0},
                 {0, 1, 0, 1, 0},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}};

GLint B[6][6] = {{1, 1, 1, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 1, 1, 1, 0},
                 {0, 1, 0, 0, 1},
                 {1, 1, 1, 1, 0}};

GLint C[6][6] = {{0, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {0, 1, 1, 1, 1}};

GLint D[5][5] = {{0, 1, 1, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 1, 0, 0, 1},
                 {0, 1, 0, 0, 1},
                 {0, 1, 1, 1, 0}};

GLint E[6][6] = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1}};

GLint F[6][6] = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0}};

GLint G[6][6] = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 0},
                 {1, 0, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1}};

GLint H[6][6] = {{1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}};

GLint I[6][6] = {{0, 1, 1, 1, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 1, 1, 1, 0}};

GLint J[6][6] = {{1, 1, 1, 1, 0},
                 {0, 0, 0, 1, 0},
                 {0, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0}};

GLint K[6][6] = {{1, 0, 0, 0, 1},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 0, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1}};

GLint L[6][6] = {{1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 0, 0, 0, 0},
                 {1, 1, 1, 1, 0}};

GLint M[6][6] = {{1, 0, 0, 0, 1},
                 {1, 1, 0, 1, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1}};

GLint N[6][6] = {{1, 0, 0, 0, 1},
                 {1, 1, 0, 0, 1},
                 {1, 0, 1, 0, 1},
                 {1, 0, 0, 1, 1},
                 {1, 0, 0, 0, 1}};

GLint O[6][6] = {{0, 1, 1, 1, 0},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 0}};

GLint P[6][6] = {{1, 1, 1, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 1, 1, 1, 0},
                 {0, 1, 0, 0, 0},
                 {0, 1, 0, 0, 0}};

GLint Q[6][6] = {{1, 1, 1, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 0, 0, 1, 0},
                 {1, 1, 1, 1, 1}};

GLint R[6][6] = {{1, 1, 1, 1, 0},
                 {0, 1, 0, 0, 1},
                 {0, 1, 1, 1, 0},
                 {0, 1, 0, 1, 0},
                 {0, 1, 0, 0, 1}};

GLint S[6][6] = {{1, 1, 1, 1, 1},
                 {1, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1},
                 {0, 0, 0, 0, 1},
                 {1, 1, 1, 1, 1}};

GLint T[6][6] = {{1, 1, 1, 1, 1},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0},
                 {0, 0, 1, 0, 0}};

GLint U[6][6] = {{1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {1, 0, 0, 0, 1},
                 {0, 1, 1, 1, 0}};

GLint V[6][6] = {{1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {1, 0, 0, 0, 1, 0},
                 {0, 1, 1, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0}};






// each box contain 6*6 pixels
void drawLetter(void){
    int numOfPixels = int(boxSideLen/pixelSideLen);

    for(int m = 0; m < numOfPixels; m++){
        glPushMatrix();
        glTranslatef(m*pixelSideLen, 0, 0);
        for(int n = 0; n < numOfPixels; n++){
            glTranslatef(0, pixelSideLen,0);
//            glColor3ub(1, 0, 0);
//            glutSolidCube(0.2);
            glBegin(GL_POLYGON);
                glNormal3d(0.0f, 0.0f, 1.0f);
                glColor3f(   1,  1, 1);
                glVertex3f(  0, 0, 0 );
                glVertex3f(  0.2, 0, 0 );
                glVertex3f(  0.2, 0.2, 0 );
                glVertex3f(  0, 0.2, 0 );
            glEnd();
        }
        glPopMatrix();
    }
}

void drawBlank(){
    int numOfPixels = int(boxSideLen/pixelSideLen);
    for(int m = 0; m < numOfPixels; m++){
        glPushMatrix();
        glTranslatef(m*pixelSideLen, 0, 0);
        for(int n = 0; n < numOfPixels; n++){
            glTranslatef(0, pixelSideLen,0);
//            glColor3ub(1, 1, 1);
//            glutSolidCube(0.2);
            glBegin(GL_POLYGON);
                glNormal3d(0.0f, 0.0f, 1.0f);
                glColor3f(   0,  0, 0);
                glVertex3f(  0, 0, 0 );
                glVertex3f(  0.2, 0, 0 );
                glVertex3f(  0.2, 0.2, 0 );
                glVertex3f(  0, 0.2, 0 );
            glEnd();
        }
        glPopMatrix();
    }
}

void initMonitor(void){
    for(int i = 0; i < width; i++){
        for(int j = 0; j < height; j++){
            letterList[i][j] = 0;
        }
    }
}

void nextPosition(void){
    currentLetter_X++;
    if(currentLetter_X/width > 0){
        currentLetter_Y++;
        currentLetter_X = 0;
    }
    if(currentLetter_Y >= height){
        currentLetter_Y--;
        currentLetter_X = width-1;
    }
}

void previousPosition(void){
    currentLetter_X--;
    if(currentLetter_X < 0 & currentLetter_Y > 0){
        currentLetter_X = width - 1;
        currentLetter_Y--;
    }else if(currentLetter_X < 0 & currentLetter_Y == 0){
        currentLetter_X++;
    }
}

void drawBox(int letter){
    int numOfPixels = int(boxSideLen/pixelSideLen);

    for(int m = 0; m < numOfPixels; m++){
        glPushMatrix();
        glTranslatef(m*pixelSideLen, 0, 0);
        for(int n = 0; n < numOfPixels; n++){
            glTranslatef(0, pixelSideLen,0);
//            glColor3ub(1, 0, 0);
//            glutSolidCube(0.2);
            if(Blank[m][n] == 0){
                glBegin(GL_POLYGON);
                glNormal3d(0.0f, 0.0f, 1.0f);
                glColor3f(   0,  0, 0);
                glVertex3f(  0, 0, 0 );
                glVertex3f(  0.2, 0, 0 );
                glVertex3f(  0.2, 0.2, 0 );
                glVertex3f(  0, 0.2, 0 );
                glEnd();
            }else{
                glBegin(GL_POLYGON);
                glNormal3d(0.0f, 0.0f, 1.0f);
                glColor3f(   1,  1, 1);
                glVertex3f(  0, 0, 0 );
                glVertex3f(  0.2, 0, 0 );
                glVertex3f(  0.2, 0.2, 0 );
                glVertex3f(  0, 0.2, 0 );
                glEnd();
            }
        }
        glPopMatrix();
    }
}

// the monitor consists of 20*15 boxes.
void drawBoxes(void){
//    // draw all blank
//    if(currentLetter_num == 0){
//        for(int i = 0; i < width; i++){
//            glPushMatrix();
//            glTranslatef(i*boxSideLen, 0, 0);
//            for(int j = 0; j < height; j++){
//                glTranslatef(0, -boxSideLen,0);
//                drawBlank();
//            }
//            glPopMatrix();
//        }
//        printf("blank\n");
//    // display letter in current position
//    }else{
//        if(backSpace == 1){
//            previousPosition();
//        }
//        glPushMatrix();
//        for(int i = 0; i < width; i++){
//            glPushMatrix();
//            glTranslatef(i*boxSideLen, 0, 0);
//            for(int j = 0; j < height; j++){
//                glTranslatef(0, -boxSideLen,0);
//                // display digit in current box
//                if(currentLetter_X == i & currentLetter_Y == j & backSpace == 0){
//                    drawLetter();
//                // clean digit in current box
//                }else if(currentLetter_X == i & currentLetter_Y == j & backSpace == 1){
//                    drawBlank();
//                }else{
//                    drawBlank();
//                }
//            }
//            glPopMatrix();
//        }
//        // update current position
//        if(backSpace == 0){
//            nextPosition();
//        }else if(backSpace == 1){
//            backSpace = 0;
//        }
//        glPopMatrix();
//    }
    for(int i = 0; i < width; i++){
        glPushMatrix();
        glTranslatef(i*boxSideLen, 0, 0);
        for(int j = 0; j < height; j++){
            glTranslatef(0, -boxSideLen,0);
            drawBox(letterList[i][j]);
        }
        glPopMatrix();
    }
}



void drawMonitor(void){
    printf("backspace: %d\n", backSpace);
    glPushMatrix();
//        glTranslatef(0, 1.5, 0);
//        glutWireTeapot(4);
        // back board for testing
        glBegin(GL_POLYGON);
            glNormal3d(0.0f, 0.0f, 1.0f);
            glColor3f(   1,  1, 0);
            glVertex3f(  -10, 10, -2 );
            glVertex3f(  34, 10, -2 );
            glVertex3f(  34, -28, -2 );
            glVertex3f(  -10, -28, -2 );
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glColor3ub(255, 255, 255);
        drawBoxes();
    glPopMatrix();
}


