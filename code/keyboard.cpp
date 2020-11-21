//
// Created by GIGABYTE on 2020/11/21.
//
#include <gl/glut.h>
#include "main.h"
#include "monitor.h"
#include <stdio.h>

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

void nextPosition1(void){
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

void previousPosition1(void){
    currentLetter_X--;
    if(currentLetter_X < 0 & currentLetter_Y > 0){
        currentLetter_X = width - 1;
        currentLetter_Y--;
    }else if(currentLetter_X < 0 & currentLetter_Y == 0){
        currentLetter_X++;
    }
}

void update(int letter){
    if(letter == 0){     //backspace
        previousPosition1();
        letterList[currentLetter_X][currentLetter_Y] = 0;
    }else{
        letterList[currentLetter_X][currentLetter_Y] = letter;
        nextPosition1();
        //更新letterList
    }
}

void KeyBoards(unsigned char key,int x,int y)
{
    switch (key)
    {
        case 'a':
            currentDisplay = 1;
            currentLetter = 1;  //draw letter "A"
            currentLetter_num++;
            update(currentLetter);
            glutPostRedisplay();
            break;
        case 8: //backspace
            currentLetter = 0;
            backSpace = 1;
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
//        case 'j':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            lookAt_x -= cameraSpeed;
//            lookAt_z += cameraSpeed;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'k':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            lookAt_x += cameraSpeed;
//            lookAt_z += cameraSpeed;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
        case ' ':
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            eye_x = 0;
            eye_y = 0;
            eye_z = 10;
            lookAt_x = 0;
            lookAt_y = 0;
            lookAt_z = 0;
            up_x = 0;
            up_y = 1;
            up_z = 0;
            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);            glutPostRedisplay();
            break;
    }
//    printf("%f %f %f %f %f %f\n", eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z);
}

