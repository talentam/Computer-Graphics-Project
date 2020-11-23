//#include <stdio.h>
//#include <gl/glut.h>
//#include <Windows.h>
//
//GLfloat angle=10.0f;
//GLfloat xDirection=0.0f;
//GLfloat yDirection=0.0f;
//GLfloat zDirection=10.0f;
//
//GLfloat eye_x = 0;
//GLfloat eye_y = 0;
//GLfloat eye_z = 10;
//GLfloat lookAt_x = 0;
//GLfloat lookAt_y = 0;
//GLfloat lookAt_z = 0;
//GLfloat up_x = 0;
//GLfloat up_y = 1;
//GLfloat up_z = 0;
//GLfloat step = 0.1;
//
//void InitEnvironment()
//{
//    glEnable(GL_DEPTH);
//    glClearColor(1,1,1,0);
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glColor4f(0,0,1,1);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(65,1,1,50);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(eye_x,eye_y,eye_z,lookAt_x,lookAt_y,lookAt_z,up_x,up_y,up_z);
//}
//
//void KeyBoards(unsigned char key,int x,int y)
//{
//    switch (key)
//    {
//        case 'w':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_z -= step;
//            lookAt_z -= step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 's':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_z += step;
//            lookAt_z += step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'a':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_x -= step;
//            lookAt_x -= step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'd':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_x += step;
//            lookAt_x += step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'q':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_y += step;
//            lookAt_y += step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'e':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_y -= step;
//            lookAt_y -= step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'j':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            lookAt_x -= step;
//            lookAt_z += step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case 'k':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            lookAt_x += step;
//            lookAt_z += step;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);
//            glutPostRedisplay();
//            break;
//        case ' ':
//            glMatrixMode(GL_MODELVIEW);
//            glLoadIdentity();
//            eye_x = 0;
//            eye_y = 0;
//            eye_z = 10;
//            lookAt_x = 0;
//            lookAt_y = 0;
//            lookAt_z = 0;
//            up_x = 0;
//            up_y = 1;
//            up_z = 0;
//            gluLookAt(eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z, up_x, up_y, up_z);            glutPostRedisplay();
//            break;
//    }
////    printf("%f %f %f %f %f %f\n", eye_x, eye_y, eye_z, lookAt_x, lookAt_y, lookAt_z);
//}
//
//void myDisplay(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glutWireTeapot(4);
//    glutSwapBuffers();
//}
//
//void RotateRect()
//{
//    angle+=0.5;
//    if(angle>=360)
//    {
//        angle=0.0f;
//    }
//    Sleep(30);
//    myDisplay();
//}
//
////void OnMouse(int button,int state,int x,int y)
////{
////    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
////    {
////        glutIdleFunc(RotateRect);
////    }
////
////    if(button==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
////    {
////        glutIdleFunc(NULL);
////    }
////}
//
//int main(int argc, char *argv[])
//{
//    glutInit(&argc, argv);   //初始化GLUT
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//    glutInitWindowPosition(500, 200);
//    glutInitWindowSize(500, 500);
//    glutCreateWindow("OpenGL");
//    InitEnvironment();   //初始化显示环境
//    glutKeyboardFunc(&KeyBoards);  //注册键盘事件
//    glutDisplayFunc(&myDisplay);   //回调函数
//    glutMainLoop();    //持续显示，当窗口改变会重新绘制图形
//    return 0;
//}