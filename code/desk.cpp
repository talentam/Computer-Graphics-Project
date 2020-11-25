//
// Created by GIGABYTE on 2020/11/25.
//

#include <gl/glut.h>

void drawBoard(float x, float y, float z){
    glPushMatrix();
    glScalef(x, y, z);
    glutSolidCube(1);
    glPopMatrix();
}

void drawHandle(void){
    glPushMatrix();
        glColor3ub(128, 128, 128);
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
            glColor3ub(128, 128,0);
            glTranslatef(0, y/2-width-(y-width)/2, -(z-width));
            drawBoard(x-(2*width), y-width, width);
        glPopMatrix();
        // draw left board
        glPushMatrix();
            glColor3ub(128, 128,128);
            glTranslatef(1.5*width, -width-(y-width)/2, -z/2);
            drawBoard(width, y-width, z-2*width);
        // draw right board
            glColor3ub(128, 128,128);
            glTranslatef(x-3*width, 0, 0);
            drawBoard(width, y-width, z-2*width);
        glPopMatrix();
        // draw bottom board
        glPushMatrix();
            glColor3ub(128, 0,128);
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
            glColor3ub(128, 128, 128);
            drawBoard(90, 1.5, 56);
        glPopMatrix();
        glTranslatef(0, -1.5, 0);
        // draw vertical boards
        glPushMatrix();
            // draw vertical board left
            glTranslatef(0.75, -75/2.0, (56-1.5)/2.0);
            glColor3ub(85, 107, 47);
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
            glColor3ub(128, 128, 128);
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
            glColor3ub(128, 128, 0);
            drawBoard(32, 75, 1.5);
        glPopMatrix();

        // draw drawers
        glPushMatrix();
            glTranslatef(0, 0, 56);
            //left top drawer
            glPushMatrix();
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
            glColor3ub(85, 107, 47);
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
void drawDesk(void){
    glPushMatrix();
        glTranslatef(-100, 0, 0);
        glPushMatrix();
            drawTop();
        glPopMatrix();
        glPushMatrix();
            drawBottom();
        glPopMatrix();
    glPopMatrix();
}

