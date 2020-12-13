//
// Created by GIGABYTE on 2020/12/12.
//
#include <gl/glut.h>
#include "room.h"
#include "main.h"
void clockAni(int value)
{
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    Hour = sys.wHour;
    Minute = sys.wMinute;
    Second = sys.wSecond;

//    Second += 1/float(50);
//    int carry1 = 0;
//    if (Second >= 60)
//    {
//        Second = 0;
//        carry1 = 1;
//    }
//    Minute += carry1/float(50);
//    int carry2 = 0;
//    if (Minute > 60)
//    {
//        Minute = 0;
//        carry2 = 1;
//    }
//    Hour += carry2/float(50);
//    if (Hour > 24)
//        Hour = 0;

    glutPostRedisplay(); // 重画

    glutTimerFunc(1000/60, clockAni, 1); // 每一秒中执行一次
}
