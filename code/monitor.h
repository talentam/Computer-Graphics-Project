#ifndef PROJECT_MONITOR_H
#define PROJECT_MONITOR_H

extern GLint width;
extern GLint height;
extern GLint backSpace;
extern GLint currentLetter_X;
extern GLint currentLetter_Y;
extern GLint currentDisplay;
extern GLint currentLetter;
extern GLint currentLetter_num;
extern GLint letterList[20][15];
//extern struct box;
//extern struct boxes;

void initMonitor(void);
void drawMonitor(void);
void drawBoxes(void);
void drawLetter(void);
void drawBlank(void);



#endif //PROJECT_MONITOR_H
