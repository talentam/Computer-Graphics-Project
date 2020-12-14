//
// Created by GIGABYTE on 2020/11/25.
//

#include <gl/glut.h>
#include "Texture.h"

extern float drawerZ = 0;

void drawBoard(float x, float y, float z){
//    原始代码
//    glPushMatrix();
//    glScalef(x, y, z);
//    glutSolidCube(1);
//    glPopMatrix();

//    加入texture代码
//    glPushMatrix();
//    glScalef(x, y, z);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_TEXTURE_2D);
//
//    int textId = GetTexture("C:/Users/GIGABYTE.000/Desktop/water.bmp");
//    glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
//    glEnable(GL_TEXTURE_GEN_T);
//    glEnable(GL_TEXTURE_GEN_R);
//    glBindTexture(GL_TEXTURE_2D, textId);
//    glutSolidCube(1);
//    glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
//    glDisable(GL_TEXTURE_GEN_T);
//    glDisable(GL_TEXTURE_GEN_R);
//
//    glBindTexture(GL_TEXTURE_2D, 0);
//    glDisable(GL_TEXTURE_2D);
//    glDisable(GL_COLOR_MATERIAL);
//    glPopMatrix();


    glPushMatrix();
    glScalef(x, y, z);

//    int textId = GetTexture("C:/Users/GIGABYTE.000/Desktop/wood.bmp");
    int textId = GetTexture("../../image/wood.bmp");
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

void drawHandle(void){
    glPushMatrix();
        glColor3ub(200, 200, 200);
        glTranslatef(-4.75, 0, 1);
        drawBoard(0.5, 0.5, 2);
        glTranslatef(9.5, 0, 0);
        drawBoard(0.5, 0.5, 2);
        glTranslatef(-4.75, 0, 0.75);
        drawBoard(9, 0.5, 0.5);
    glPopMatrix();
}

void drawDrawer(float x, float y, float z, float width){
    glPushMatrix();
        // draw front board
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(x/2, -y/2, -width/2);
            drawBoard(x, y, width);
        // draw back board
            glColor3ub(255,245,225);
            glTranslatef(0, y/2-width-(y-width)/2, -(z-width));
            drawBoard(x-(2*width), y-width, width);
        glPopMatrix();
        // draw left board
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(1.5*width, -width-(y-width)/2, -z/2);
            drawBoard(width, y-width, z-2*width);
        // draw right board
            glColor3ub(255,245,225);
            glTranslatef(x-3*width, 0, 0);
            drawBoard(width, y-width, z-2*width);
        glPopMatrix();
        // draw bottom board
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(x/2, -(y-width/2), -z/2);
            drawBoard(x-4*width, width, z-2*width);
        glPopMatrix();
    glPopMatrix();
}

void drawBottom(void){
    glPushMatrix();
        // draw desk surface
        glPushMatrix();
            glTranslatef(45, -1.5/2, 28);
//            glColor3ub(128, 128, 128);
//            glColor3ub(255,245,225);
            glColor3ub(255,253,249);
            drawBoard(90, 1.5, 56);
        glPopMatrix();
        glTranslatef(0, -1.5, 0);
        // draw vertical boards
        glPushMatrix();
            // draw vertical board left
            glTranslatef(0.75, -75/2.0, (56-1.5)/2.0);
            glColor3ub(255,245,225);
            glPushMatrix();
                drawBoard(1.5, 75, 56-1.5);
            glPopMatrix();
            // draw vertical board middle
            glTranslatef(33.5, 0, 0);
            glPushMatrix();
                drawBoard(1.5, 75, 56-1.5);
            glPopMatrix();
            // draw vertical board right
            glTranslatef(55, 0, 0);
            glPushMatrix();
                drawBoard(1.5, 75, 56-1.5);
            glPopMatrix();
        glPopMatrix();

        // draw horizontal boards
        glPushMatrix();
            // left top horizontal board
            glColor3ub(255,245,225);
            glTranslatef(1.5+32/2, -14, (56-1.5)/2.0);
            drawBoard(32, 1.5, 56-1.5);
            // left bottom horizontal board
            glPushMatrix();
                glTranslatef(0, -(47), 0);
                drawBoard(32, 1.5, 56-1.5);
            glPopMatrix();
            // right horizontal board
            glTranslatef(32/2+1.5+53.5/2, 0, 0);
            drawBoard(53.5, 1.5, 56-1.5);
        glPopMatrix();

        // draw vertical back boards
        glPushMatrix();
            glTranslatef(32/2.0+1.5, -75/2.0, 0.75);
            glColor3ub(255,245,225);
            drawBoard(32, 75, 1.5);
        glPopMatrix();

        // draw drawers
        glPushMatrix();
            glTranslatef(0, 0, 56);
            //left top drawer
            glPushMatrix();
                glTranslatef(0, 0, drawerZ);
                drawDrawer(35, 14, 56, 1.5);
                glTranslatef(35.0/2, -14.0/2, 0);
                drawHandle();
            glPopMatrix();

            //left bottom drawer
            glPushMatrix();
//                glTranslatef(0, -14.5, 0);
//                drawDrawer(35, 47, 56, 1.5);
                glTranslatef(35.0/2, -14.5-47.0/2-0.35, -1.5/2);
                glColor3ub(255,245,225);
                drawBoard(35, 47, 1.5);
//                glTranslatef(35.0/2, -47.0/8*5, 0);
//                glRotatef(90, 0, 0, 1);
//                glTranslatef(10, -10, 0);
                glRotatef(90, 0, 0, 1);
                glTranslatef(0, -10, 0);
                drawHandle();
            glPopMatrix();

            // right drawer
            glTranslatef(0, 0, drawerZ);
            glTranslatef(35.5, 0, 0);
            drawDrawer(54.5, 14, 56, 1.5);
            glTranslatef(54.5/2, -14.0/2, 0);
            drawHandle();
        glPopMatrix();
    glPopMatrix();
}



void drawTop(void){
    glPushMatrix();
        // vertical boards
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(1.5/2, 103.5/2, 12);
            // vertical board left
            glPushMatrix();
                drawBoard(1.5, 103.5, 24);
            glPopMatrix();
            // vertical board middle
            glTranslatef(33.5, 0, 0);
            glPushMatrix();
                drawBoard(1.5, 103.5, 24);
            glPopMatrix();
            // vertical board right
            glTranslatef(55, 0, 0);
                glPushMatrix();
                drawBoard(1.5, 103.5, 24);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
        // horizontal boards
            glColor3ub(255,245,225);
            glTranslatef(17.5, 29.75, 24/2);
            // horizontal board bottom
            glPushMatrix();
                drawBoard(32, 1.5, 24);
            glPopMatrix();
            // horizontal board middle-left
            glTranslatef(0, 36.5, 0);
            glPushMatrix();
                drawBoard(32, 1.5, 24);
            glPopMatrix();
            // horizontal board top-left
            glTranslatef(0, 36.5, 0);
            glPushMatrix();
                drawBoard(32, 1.5, 24);
            glPopMatrix();
            // horizontal board top-right
            glTranslatef(16+53.5/2+1.5, 0, 0);
            glPushMatrix();
                drawBoard(53.5, 1.5, 24);
            glPopMatrix();
            // horizontal board middle-right
            glTranslatef(0, -36.5, 0);
            glPushMatrix();
                drawBoard(53.5, 1.5, 24);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void drawCube(string bitmap[], float x, float y, float z){
    // bitmap[]: 0: front | 1: back | 2: top | 3: bottom | 4: left | 5: right
    glPushMatrix();
    glScalef(x, y, z);
    glEnable(GL_TEXTURE_2D);
    int textId;


    // FRONT
    textId = GetTexture(bitmap[0]);
    glBindTexture(GL_TEXTURE_2D, textId);

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
    textId = GetTexture(bitmap[1]);
    glBindTexture(GL_TEXTURE_2D, textId);

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
    textId = GetTexture(bitmap[2]);
    glBindTexture(GL_TEXTURE_2D, textId);

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
    textId = GetTexture(bitmap[3]);
    glBindTexture(GL_TEXTURE_2D, textId);

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
    textId = GetTexture(bitmap[4]);
    glBindTexture(GL_TEXTURE_2D, textId);

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
    textId = GetTexture(bitmap[5]);
    glBindTexture(GL_TEXTURE_2D, textId);

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

void drawBooks(){
    glPushMatrix();
        string bookCover[6] = {"../../image/window.bmp", "../../image/window.bmp", "../../image/window.bmp",
                               "../../image/window.bmp", "../../image/window.bmp", "../../image/window.bmp"};
        glTranslatef(85, 79, 9);
        drawCube(bookCover, 4, 24, 18);
        glTranslatef(-6, 3, 0);
        drawCube(bookCover, 4, 30, 18);
        glTranslatef(-6, -2, 0);
        drawCube(bookCover, 4, 26, 18);
        glPushMatrix();
            glTranslatef(-30, -0.9, 0);
            glRotatef(30, 0, 0, 1);
            drawCube(bookCover, 4, 26, 18);
        glPopMatrix();

    glPopMatrix();
}

void drawSockets(void){
    glPushMatrix();
        string bookCover[6] = {"../../image/socket.bmp", "../../image/white.bmp", "../../image/white.bmp",
                               "../../image/white.bmp", "../../image/white.bmp", "../../image/white.bmp"};
        glTranslatef(18, 6, 0.5);
        drawCube(bookCover, 6, 6, 1);
    glPopMatrix();
}

void drawDesk(void){
    glPushMatrix();
        glTranslatef(-100, 0, 0);
        //draw upper part of the desk
        drawTop();
        //draw bottom part of the desk
        drawBottom();
        //draw books
        drawBooks();
        //draw socket
        drawSockets();
    glPopMatrix();
}

