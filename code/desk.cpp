#include <gl/glut.h>
#include "Texture.h"

extern float drawerZ = 0;
extern float drawerAngle = 0;

// basic drawing cube function with texture
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
    glPopMatrix();
}

// draw handle of drawers
void drawHandle(void){
    glPushMatrix();
        string texture[6] = {"../../image/window.bmp", "../../image/window.bmp", "../../image/window.bmp",
                           "../../image/window.bmp", "../../image/window.bmp", "../../image/window.bmp"};
        glColor3ub(200, 200, 200);
        glTranslatef(-4.75, 0, 1);
        drawCube(texture, 0.5, 0.5, 2);
        glTranslatef(9.5, 0, 0);
        drawCube(texture, 0.5, 0.5, 2);
        glTranslatef(-4.75, 0, 0.75);
        drawCube(texture, 9, 0.5, 0.5);
    glPopMatrix();
}

// draw drawers
void drawDrawer(float x, float y, float z, float width){
    glPushMatrix();
        // draw front board
        string texture[6] = {"../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp",
                            "../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp"};
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(x/2, -y/2, -width/2);
            drawCube(texture, x, y, width);
        // draw back board
            glColor3ub(255,245,225);
            glTranslatef(0, y/2-width-(y-width)/2, -(z-width));
            drawCube(texture, x-(2*width), y-width, width);
        glPopMatrix();
        // draw left board
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(1.5*width, -width-(y-width)/2, -z/2);
            drawCube(texture, width, y-width, z-2*width);
        // draw right board
            glColor3ub(255,245,225);
            glTranslatef(x-3*width, 0, 0);
            drawCube(texture, width, y-width, z-2*width);
        glPopMatrix();
        // draw bottom board
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(x/2, -(y-width/2), -z/2);
            drawCube(texture, x-4*width, width, z-2*width);
        glPopMatrix();
    glPopMatrix();
}


// draw the bottom part of the table
void drawBottom(void){
    glPushMatrix();
    string texture[6] = {"../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp",
                         "../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp"};
        // draw desk surface
        glPushMatrix();
            glTranslatef(45, -1.5/2, 28);
            glColor3ub(255,253,249);
            drawCube(texture, 90, 1.5, 56);
        glPopMatrix();
        glTranslatef(0, -1.5, 0);
        // draw vertical boards
        glPushMatrix();
            // draw vertical board left
            glTranslatef(0.75, -75/2.0, (56-1.5)/2.0);
            glColor3ub(255,245,225);
            glPushMatrix();
                drawCube(texture, 1.5, 75, 56-1.5);
            glPopMatrix();
            // draw vertical board middle
            glTranslatef(33.5, 0, 0);
            glPushMatrix();
                drawCube(texture, 1.5, 75, 56-1.5);
            glPopMatrix();
            // draw vertical board right
            glTranslatef(55, 0, 0);
            glPushMatrix();
                drawCube(texture, 1.5, 75, 56-1.5);
            glPopMatrix();
        glPopMatrix();

        // draw horizontal boards
        glPushMatrix();
            // left top horizontal board
            glColor3ub(255,245,225);
            glTranslatef(1.5+32/2, -14, (56-1.5)/2.0);
            drawCube(texture, 32, 1.5, 56-1.5);
            // left bottom horizontal board
            glPushMatrix();
                glTranslatef(0, -(47), 0);
                drawCube(texture, 32, 1.5, 56-1.5);
            glPopMatrix();
            // right horizontal board
            glTranslatef(32/2+1.5+53.5/2, 0, 0);
                drawCube(texture, 53.5, 1.5, 56-1.5);
        glPopMatrix();

        // draw vertical back boards
        glPushMatrix();
            glTranslatef(32/2.0+1.5, -75/2.0, 0.75);
            glColor3ub(255,245,225);
            drawCube(texture, 32, 75, 1.5);
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
                glRotatef(-drawerAngle, 0, 1, 0);
                glTranslatef(35.0/2, -14.5-47.0/2-0.35, -1.5/2);
                glColor3ub(255,245,225);
                    drawCube(texture, 35, 47, 1.5);
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

// draw the top part of the table
void drawTop(void){
    glPushMatrix();
    string texture[6] = {"../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp",
                         "../../image/wood.bmp", "../../image/wood.bmp", "../../image/wood.bmp"};
        // vertical boards
        glPushMatrix();
            glColor3ub(255,245,225);
            glTranslatef(1.5/2, 103.5/2, 12);
            // vertical board left
            glPushMatrix();
                drawCube(texture, 1.5, 103.5, 24);
            glPopMatrix();
            // vertical board middle
            glTranslatef(33.5, 0, 0);
            glPushMatrix();
                drawCube(texture, 1.5, 103.5, 24);
            glPopMatrix();
            // vertical board right
            glTranslatef(55, 0, 0);
                glPushMatrix();
                drawCube(texture, 1.5, 103.5, 24);
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
        // horizontal boards
            glColor3ub(255,245,225);
            glTranslatef(17.5, 29.75, 24/2);
            // horizontal board bottom
            glPushMatrix();
                drawCube(texture, 32, 1.5, 24);
            glPopMatrix();
            // horizontal board middle-left
            glTranslatef(0, 36.5, 0);
            glPushMatrix();
                drawCube(texture, 32, 1.5, 24);
            glPopMatrix();
            // horizontal board top-left
            glTranslatef(0, 36.5, 0);
            glPushMatrix();
                drawCube(texture, 32, 1.5, 24);
            glPopMatrix();
            // horizontal board top-right
            glTranslatef(16+53.5/2+1.5, 0, 0);
            glPushMatrix();
                drawCube(texture, 53.5, 1.5, 24);
            glPopMatrix();
            // horizontal board middle-right
            glTranslatef(0, -36.5, 0);
            glPushMatrix();
                drawCube(texture, 53.5, 1.5, 24);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

// draw books on the bookshelf
void drawBooks(){
    glPushMatrix();
        string bookCover1[6] = {"../../image/book1spine.bmp", "../../image/white.bmp", "../../image/white.bmp",
                               "../../image/white.bmp", "../../image/book1back.bmp", "../../image/book1cover.bmp"};
        string bookCover2[6] = {"../../image/book4spine.bmp", "../../image/white.bmp", "../../image/white.bmp",
                                "../../image/white.bmp", "../../image/book4back.bmp", "../../image/book4cover.bmp"};
        string bookCover3[6] = {"../../image/book2spine.bmp", "../../image/white.bmp", "../../image/white.bmp",
                                "../../image/white.bmp", "../../image/book2back.bmp", "../../image/book2cover.bmp"};
        string bookCover4[6] = {"../../image/book3spine.bmp", "../../image/white.bmp", "../../image/white.bmp",
                                "../../image/white.bmp", "../../image/book3back.bmp", "../../image/book3cover.bmp"};
    glTranslatef(85, 79, 9);
        drawCube(bookCover1, 4, 24, 18);
        glTranslatef(-6, 3, 0);
        drawCube(bookCover2, 4, 30, 18);
        glTranslatef(-6, -2, 0);
        drawCube(bookCover3, 4, 26, 18);
        glPushMatrix();
            glTranslatef(-30, -0.9, 0);
            glRotatef(30, 0, 0, 1);
            drawCube(bookCover4, 4, 26, 18);
        glPopMatrix();
    glPopMatrix();
}

// draw the socket on the wall
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

