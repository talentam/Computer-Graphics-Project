#ifndef PROJECT_MONITOR_H
#define PROJECT_MONITOR_H

extern GLint width;
extern GLint height;
extern GLint currentLetter_X;
extern GLint currentLetter_Y;
extern GLint currentLetter;
extern GLint currentLetter_num;
extern GLint letterList[15][20];

void initMonitor(void);
void drawMonitor(void);
void drawBox(int letter);
void drawRoom(void);
void drawScreen(void);
void drawSupport(void);



#endif //PROJECT_MONITOR_H
