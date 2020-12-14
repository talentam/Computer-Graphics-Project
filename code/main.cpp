#include <stdio.h>
#include <gl/glut.h>
#include "monitor.h"
#include "keyboard.h"
#include "desk.h"
#include "room.h"
#include <windows.h>
#include "animation.h"
//#include "camera.Hour"

//GLfloat eye_x = 0;
//GLfloat eye_y = 0;
//GLfloat eye_z = 50;
//GLfloat lookAt_x = 0;
//GLfloat lookAt_y = 0;
//GLfloat lookAt_z = 0;
GLfloat eye_x = -50;
GLfloat eye_y = 0;
GLfloat eye_z = 300;
GLfloat lookAt_x = -50;
GLfloat lookAt_y = 0;
GLfloat lookAt_z = 0;


GLfloat up_x = 0;
GLfloat up_y = 1;
GLfloat up_z = 0;
GLfloat cameraSpeed = 5;
//GLfloat angle = 0;
int frameRate = 60;
int roundTime = 5;

extern float Hour = 0;
extern float Minute = 0;
extern float Second = 0;



void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
//    glRotatef(angle, 0 ,1, 0);
//    glLoadIdentity();
//    gluLookAt(1, 1, 2, 0, 0, 0, 0, 1, 0);
////    glLoadIdentity();
//    glBegin(GL_POLYGON);
//    glNormal3d(0.0f, 0.0f, 1.0f);
//        glColor3ub(255, 255, 255);
//        glVertex3f(  -10, 10, 10 );
//        glVertex3f(  -10, -10, 10 );
//        glVertex3f(  10, -10, 10 );
//        glVertex3f(  10, 10, 10 );
//    glEnd();
//    glColor3ub(255, 255, 255);

    drawRoom();
    drawMonitor();
    drawDesk();
    glutSwapBuffers();
}

void init(void)
{
//    glEnable(GL_DEPTH);
//    glClearDepth (1.0f);
//    glClear (GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//    glColor4f(0,0,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65,1,0.01,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eye_x,eye_y,eye_z,lookAt_x,lookAt_y,lookAt_z,up_x,up_y,up_z);
    initMonitor();

    // lighting settings

    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };  //镜面反射参数
    GLfloat mat_shininess[] = { 50.0 };               //高光指数
    GLfloat light_position[] = { 1.0, 1.0, 100, 0.0 };
    GLfloat white_light[] = { 1, 1, 1, 1.0 };   //灯位置(1,1,1), 最后1-开关
    GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 }; //环境光参数

    glClearColor(0.0, 0.0, 0.0, 0.0);  //背景色
    glShadeModel(GL_SMOOTH);           //多变性填充模式

//    材质属性
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

//    灯光设置
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);   //散射光属性
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);  //镜面反射光
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);  //环境光参数

//    glEnable(GL_LIGHTING);   //开关:使用光
//    glEnable(GL_LIGHT0);     //打开0#灯

//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = { 50.0 };
//    GLfloat light_position[] = { 1.0, 1.0, 50, 0.0 };
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glShadeModel(GL_SMOOTH);
//
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_DEPTH_TEST);


    glEnable(GL_DEPTH_TEST); //打开深度测试
//    SYSTEMTIME sys;
//    GetLocalTime(&sys);
//    Hour = sys.wHour;
//    Minute = sys.wMinute;
//    Second = sys.wSecond;

}

void reshape(int w, int h){
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    GLfloat nRange = 20.0f;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w<=h)
    {   glOrtho(-nRange, nRange, -nRange * aspect, nRange * aspect, -100, 100);  }
    else
    {  glOrtho(-nRange, nRange, -nRange / aspect, nRange / aspect, -100, 100);  }
}

int main(int argc,char* argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("CW3");
    init();
    glutKeyboardFunc(&KeyBoards);
    glutSpecialFunc(&SpecialKey);
    glutDisplayFunc(&display);
//    glutReshapeFunc(reshape);
    glutTimerFunc(1000/60, clockAni, 0);
    glutMainLoop();
}
