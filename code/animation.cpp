#include <gl/glut.h>
#include "main.h"
#include "desk.h"

// flag for animation of the drawers
extern int trigger = 0;

// Animation for clock
void clockAnimation(void){
    // keep updating the system time
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    Hour = sys.wHour;
    Minute = sys.wMinute;
    Second = sys.wSecond;
}

// Animation of drawers
void drawerAnimation(void){
    if(trigger == 1 & drawerZ < 40){
        drawerZ += 40/float(60);
        drawerAngle += 90/float(60);
    }
    else if(trigger == -1 & drawerZ > 0){
        drawerZ -= 40/float(60);
        drawerAngle -= 90/float(60);
    }
}

void animation(int value)
{
    // clock animation
    clockAnimation();
    // drawer animation
    drawerAnimation();
    // recall the display function
    glutPostRedisplay();
    // call the animation function in 60 fps
    glutTimerFunc(1000/60, animation, 1);
}