#ifndef PROJECT_DESK_H
#define PROJECT_DESK_H

#include <string>
using namespace std;

extern float drawerZ;
extern float drawerAngle;

void drawCube(string bitmap[], float x, float y, float z);
void drawHandle(void);
void drawDrawer(float x, float y, float z, float width);
void drawBottom(void);
void drawTop(void);
void drawDesk(void);
void drawBooks(void);
void drawSockets(void);

#endif //PROJECT_DESK_H
