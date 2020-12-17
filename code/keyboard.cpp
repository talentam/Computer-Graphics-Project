#include <stdio.h>
#include <gl/glut.h>
#include "main.h"
#include "monitor.h"
#include "animation.h"
#include <math.h>
float update_x = 0.0f, update_y = 0.0f, update_z = -1.0f;
float angle1 = 0;
float angle2 = 0;

// record the coordinate of x and y when user press mouse
GLfloat oldx_leftkey;
GLfloat oldy_leftkey;
GLfloat oldx_rightkey;
GLfloat oldy_rightkey;

// camera moves forward and backward
void camera_forward_backward(int direction){
    glLoadIdentity();
    eye_x = eye_x + direction * (update_x) * cameraSpeed;
    eye_z = eye_z + direction * (update_z) * cameraSpeed;
    gluLookAt(eye_x, eye_y, eye_z, eye_x + update_x, eye_y + update_y, eye_z + update_z, 0.0f, 1.0f, 0.0f);
}

// camera moves left and right
void camera_left_right(int direction){
    glLoadIdentity();
    eye_x = eye_x + direction * (update_z) * cameraSpeed;
    eye_z = eye_z - direction * (update_x) * cameraSpeed;
    gluLookAt(eye_x, eye_y, eye_z, eye_x + update_x, eye_y + update_y, eye_z + update_z, 0.0f, 1.0f, 0.0f);
}

// camera moves up and down
void camera_up_down(int direction){
    glLoadIdentity();
    eye_y = eye_y + direction * cameraSpeed;
    gluLookAt(eye_x, eye_y, eye_z, eye_x + update_x, eye_y + update_y, eye_z + update_z, 0.0f, 1.0f, 0.0f);
}

// detect mouse, 1 for leftkey 0 for rightkey
int left = 1;
void Mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN){
            oldx_leftkey = x;
            oldy_leftkey = y;
            left = 1;
        }
    }
    if (button == GLUT_RIGHT_BUTTON){
        if (state == GLUT_DOWN){
            oldx_rightkey = x;
            oldy_rightkey = y;
            left = 0;
        }
    }
}

//capture the motion of the mouse
void motion(int x, int y){
    glLoadIdentity();
    if(left == 1){
        GLint deltax = -(oldx_leftkey - x);
        GLint deltay = (oldy_leftkey - y);

        oldx_leftkey = x;
        oldy_leftkey = y;

        angle1 += deltax * 0.01;
        update_x = sin(angle1);
        update_z = -cos(angle1);

        angle2 += deltay * 0.01;
        update_y = sin(angle2);
    }
    if(left == 0){
        GLint deltax2 = -(oldx_rightkey - x);
        GLint deltay2 = -(oldy_rightkey - y);
        oldx_rightkey = x;
        oldy_rightkey = y;

        eye_x += deltax2*0.12;
        eye_z += deltay2 * 0.12;
    }
    gluLookAt(eye_x, eye_y, eye_z, eye_x + update_x, eye_y + update_y, eye_z + update_z, 0.0f, 1.0f, 0.0f);
}

// camera movement
void SpecialKey(GLint key,GLint x,GLint y){
    switch (key){
        case GLUT_KEY_UP:
            camera_forward_backward(1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            camera_forward_backward(-1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            camera_left_right(1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            camera_left_right(-1);
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

void KeyBoards(unsigned char key,int x,int y){
    switch (key){
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
            camera_up_down(1);
            glutPostRedisplay();
            break;
        case '2':
            camera_up_down(-1);
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

