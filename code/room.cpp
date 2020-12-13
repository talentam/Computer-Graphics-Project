//
// Created by GIGABYTE on 2020/11/25.
//
#include <gl/glut.h>
#include "Texture.h"
#include <string>
#include <math.h>
#include "main.h"

const GLfloat PI = 3.141592653f;
const int Width = 600;
const int Height = 600;

void drawCube(string bitmap, float x, float y, float z){
    glPushMatrix();
    glScalef(x, y, z);

//    int textId = GetTexture("C:/Users/GIGABYTE.000/Desktop/wood.bmp");
    int textId = GetTexture(bitmap);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textId);


    // FRONT
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 0.5f, -0.5f, 0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( -0.5f, 0.5f, 0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -0.5f, -0.5f, 0.5f);
    glEnd();
    // BACK
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, 0.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(  0.5f, -0.5f, -0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(  0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( -0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -0.5f, -0.5f, -0.5f );
    glEnd();
    // TOP
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, 1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( -0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -0.5f, 0.5f, 0.5f );
    glEnd();
    // BOTTOM
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, -1.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( -0.5f, -0.5f, 0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( -0.5f, -0.5f, -0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 0.5f, -0.5f, -0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 0.5f, -0.5f, 0.5f );
    glEnd();
    // LEFT
    glBegin(GL_POLYGON);
    glNormal3d(-1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( -0.5f, -0.5f, 0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( -0.5f, 0.5f, 0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( -0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( -0.5f, -0.5f, -0.5f );
    glEnd();
    // RIGHT
    glBegin(GL_POLYGON);
    glNormal3d(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f( 0.5f, -0.5f, -0.5f );
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, -0.5f );
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f( 0.5f, 0.5f, 0.5f );
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f( 0.5f, -0.5f, 0.5f );
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_COLOR_MATERIAL);

    glPopMatrix();
}

void drawSquare(string texture, float width, float length) {
    glPushMatrix();

    glEnable(GL_COLOR_MATERIAL);
    int textId = GetTexture(texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textId);

    // back
    glBegin(GL_POLYGON);
    glNormal3d(0.0f, 1.0f, 0.0f);
//    glColor3ub(R, G, B);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0, 0, 0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0, 0, length);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(width, 0, length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(width, 0, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, 0);
    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_COLOR_MATERIAL);

    glPopMatrix();
}

void drawClock(void){
    glPushMatrix();
        glTranslatef(-90, 80, 0);
        glScalef(0.2, 0.2, 0.2);

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
    glPopMatrix();
}
void drawWalls(void){
    glPushMatrix();
        glColor3ub(255, 255, 255);
        glTranslatef(-100, 23.5 - 100, -10);
        glTranslatef(-50, 0, 0);
        string bitmap = "../../image/floor2.bmp";
        // bottom floor

        glPushMatrix();
            drawSquare(bitmap, 300, 300);
        glPopMatrix();
        // left wall
        glPushMatrix();
            bitmap = "../../image/whiteWall.bmp";
            glRotatef(-90, 0, 0, 1);
            glTranslatef(-300, 0, 0);
            drawSquare(bitmap, 300, 300);
        glPopMatrix();
        // right wall
        glPushMatrix();
            glRotatef(90, 0, 0, 1);
            glTranslatef(0, -300, 0);
            drawSquare(bitmap, 300, 300);
        glPopMatrix();
        // back wall
        glPushMatrix();
            glRotatef(90, 1, 0, 0);
            glTranslatef(0, 0, -300);
            drawSquare(bitmap, 300, 300);
        glPopMatrix();
        // top roof
        glPushMatrix();
            glRotatef(180, 1, 0, 0);
            glTranslatef(0, -300, -300);
            drawSquare(bitmap, 300, 300);
        glPopMatrix();
        // skirting line back
        glPushMatrix();
            bitmap = "../../image/skirtingLine.bmp";
            glTranslatef(150, 5, 1);
            drawCube(bitmap, 300, 10, 2);
        glPopMatrix();
        // skirting line left and right
        glPushMatrix();
            bitmap = "../../image/skirtingLine.bmp";
            glTranslatef(1, 5, 151);
            drawCube(bitmap, 2, 10, 298);
            glTranslatef(298, 0, 0);
            drawCube(bitmap, 2, 10, 298);
        glPopMatrix();
    glPopMatrix();
}

void drawPoster(void){
    glPushMatrix();
        string bitmap = "../../image/2077poster.bmp";
        glRotatef(90, 1, 0, 0);
        glRotatef(-90, 0, 0, 1);
        glTranslatef(-100, -149, -50);
//        glScalef(0.3, 0.15, 0.15);
        drawSquare(bitmap, 60, 30);
    glPopMatrix();
}

void drawWindows(void){
    glPushMatrix();
        glTranslatef(70, 20, 10);
        // draw bottom border
        string bitmap = "../../image/window.bmp";
        drawCube(bitmap, 100, 2, 10);

        //draw left, middle and right border
        glPushMatrix();
            glTranslatef(-49, 32.5, -4);
            drawCube(bitmap, 2, 65, 2);
            glTranslatef(49, 0, 0);
            drawCube(bitmap, 2, 65, 2);
            glTranslatef(49, 0, 0);
            drawCube(bitmap, 2, 65, 2);
        glPopMatrix();

        //draw top border
        glPushMatrix();
            glTranslatef(0, 66, -4);
            drawCube(bitmap, 100, 2, 2);
        glPopMatrix();

        // draw view outside the windows
        glPushMatrix();
            bitmap = "../../image/windowView.bmp";
            glTranslatef(-48, 66, -4);
            glRotatef(90, 1, 0, 0);
            drawSquare(bitmap, 96, 65);
        glPopMatrix();
    glPopMatrix();
}

void drawBooks(void){

}

void drawBed(void){
    glPushMatrix();
        glTranslatef(-100, 23.5 - 100, -10);
        glTranslatef(-50, 0, 0);
        glTranslatef(208, 0, 2);
        // draw top left and right bed pillar
        glPushMatrix();
            glTranslatef(1, 10, 1);
            string bitmap = "../../image/window.bmp";
            drawCube(bitmap, 2, 20, 2);
            glTranslatef(88, 0, 0);
            drawCube(bitmap, 2, 20, 2);
        glPopMatrix();
        // draw bottom left and right bed pillar
        glPushMatrix();
            glTranslatef(1, 10, 179);
            drawCube(bitmap, 2, 20, 2);
            glTranslatef(88, 0, 0);
            drawCube(bitmap, 2, 20, 2);
        glPopMatrix();
        //draw bed plank
        glPushMatrix();
            glTranslatef(45, 21, 90);
            drawCube(bitmap, 90, 2, 180);
        glPopMatrix();
        //draw bed top board
        glPushMatrix();
            glTranslatef(45, 51, 1);
            drawCube(bitmap, 90, 60, 2);
        glPopMatrix();
        //draw bed edge board
        glPushMatrix();
            glTranslatef(45, 27, 180);
            drawCube(bitmap, 90, 10, 2);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1, 27, 90);
            drawCube(bitmap, 2, 10, 176);
            glTranslatef(88, 0, 0);
        glPopMatrix();
        //draw bed and bed sheet
        glPushMatrix();
//            bitmap = "../../image/white.bmp";
            glTranslatef(45, 35, 90);
            glPushMatrix();
//                glTranslatef(45, 35, 90);
                glScalef(85, 25, 175);
                glutSolidCube(1);
            glPopMatrix();
            bitmap = "../../image/bedsheet.bmp";
            // bed sheet
            glPushMatrix();
                glTranslatef(0, 13.5, 35);
                glColor3ub(218,218,216);
                glScalef(85, 2, 105);
                glutSolidCube(1);
//                drawCube(bitmap, 85, 2, 105);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(-43, 4.5, 35);
                glScalef(1, 20, 105);
                glutSolidCube(1);
//                drawCube(bitmap, 1, 20, 105);
            glPopMatrix();
            glPushMatrix();
                glTranslatef(43, 4.5, 35);
                glScalef(1, 20, 105);
                glutSolidCube(1);
//                drawCube(bitmap, 1, 20, 105);
            glPopMatrix();

            glTranslatef(0, 4.5, 88);
            glColor3ub(218,218,216);
            glScalef(87, 20, 1);
            glutSolidCube(1);
//            drawCube(bitmap, 87, 20, 1);
        glPopMatrix();
        // draw pillar
        glPushMatrix();
            glTranslatef(45, 50, 25);
            glScalef(60, 10, 20);
            glutSolidCube(1);
        glPopMatrix();

    glPopMatrix();

}

void drawRoom(void) {
    // draw walls
    drawWalls();
    // draw clock
    drawClock();
    // draw windows
    drawWindows();
    // draw poster
    drawPoster();
    // draw books
    drawBooks();
    // draw bed
    drawBed();


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



