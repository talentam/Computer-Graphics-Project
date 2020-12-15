#include <gl/glut.h>
#include "main.h"
#include "monitor.h"
#include "animation.h"
#include <stdio.h>

// control the keyboard interaction

// keyboard interaction instruction:
// up: camera goes forward
// down: camera goes backward
// left: camera goes left
// right: camera goes right
// 0: return the camera to original position
// 1: camera goes up
// 2: camera goes down
// a-z: display a-z letters
// ,: display ','
// .: display '.'
// space key: display ' '
// 3: camera turns left
// 4: camera turns right
// 5: camera turns up
// 6: camera turns down
// 7: open drawers
// 8: close drawers



void SpecialKey(GLint key,GLint x,GLint y)
{
    switch (key)
    {
        case GLUT_KEY_UP:
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_z -= cameraSpeed;
            lookAt_z -= cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_z += cameraSpeed;
            lookAt_z += cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x -= cameraSpeed;
            lookAt_x -= cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x += cameraSpeed;
            lookAt_x += cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
    }
}

void nextPosition(void){
    currentLetter_X++;
    if(currentLetter_X/width > 0){
        currentLetter_Y++;
        currentLetter_X = 0;
    }
    if(currentLetter_Y >= height){
        currentLetter_X = 0;
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

// update the screen display
void update(int letter){
    if(letter == 0){     //backspace
        previousPosition();
        letterList[currentLetter_Y][currentLetter_X] = 0;
    }else{              //typing letter
        letterList[currentLetter_Y][currentLetter_X] = letter;
        nextPosition();
    }
}

void KeyBoards(unsigned char key,int x,int y)
{
    switch (key)
    {
        case 'a':
            currentLetter = 1;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'b':
            currentLetter = 2;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'c':
            currentLetter = 3;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'd':
            currentLetter = 4;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'e':
            currentLetter = 5;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'f':
            currentLetter = 6;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'g':
            currentLetter = 7;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'h':
            currentLetter = 8;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'i':
            currentLetter = 9;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'j':
            currentLetter = 10;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'k':
            currentLetter = 11;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'l':
            currentLetter = 12;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'm':
            currentLetter = 13;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'n':
            currentLetter = 14;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'o':
            currentLetter = 15;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'p':
            currentLetter = 16;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'q':
            currentLetter = 17;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'r':
            currentLetter = 18;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 's':
            currentLetter = 19;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 't':
            currentLetter = 20;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'u':
            currentLetter = 21;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'v':
            currentLetter = 22;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'w':
            currentLetter = 23;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'x':
            currentLetter = 24;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'y':
            currentLetter = 25;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 'z':
            currentLetter = 26;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case ' ':
            currentLetter = 27;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case ',':
            currentLetter = 28;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case '.':
            currentLetter = 29;
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 8: //backspace
            currentLetter = 0;
            currentLetter_num--;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case '1':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_y += cameraSpeed;
            lookAt_y += cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '2':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_y -= cameraSpeed;
            lookAt_y -= cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '3':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x += cameraSpeed;
            lookAt_x -= cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '4':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x -= cameraSpeed;
            lookAt_x += cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '5':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_y += cameraSpeed;
            lookAt_y -= cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '6':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_y -= cameraSpeed;
            lookAt_y += cameraSpeed;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
        case '7':
            trigger = 1;
            break;
        case '8':
            trigger = -1;
            break;
        case '0':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x = 10;
            eye_y = 0;
            eye_z = 350;
            lookAt_x = 10;
            lookAt_y = 0;
            lookAt_z = 0;
            up_x = 0;
            up_y = 1;
            up_z = 0;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
            glutPostRedisplay();
            break;
    }
}

