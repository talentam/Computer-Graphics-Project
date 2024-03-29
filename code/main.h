#include <gl/glut.h>

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

extern GLfloat eye_x;
extern GLfloat eye_y;
extern GLfloat eye_z;
extern GLfloat lookAt_x;
extern GLfloat lookAt_y;
extern GLfloat lookAt_z;
extern GLfloat up_x;
extern GLfloat up_y;
extern GLfloat up_z;
extern GLfloat cameraSpeed;

extern float Hour;
extern float Minute;
extern float Second;

void display(void);
void init(void);
int main(int argc,char* argv[]);

#endif //PROJECT_MAIN_H
