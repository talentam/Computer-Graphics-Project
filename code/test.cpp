//void drawClock(void){
//    glColor3f(1, 1, 1); //
//
//    int centerX = Width / 2;
//    int centerY = Height / 2;
//    int r = 100;
//    int n = 300;
//    int i;
//
//    // draw clock boundary
//    glPushMatrix();
//    for (i = 0; i<n; i++)
//    {
//        glPushMatrix();
//        glTranslatef(centerX + (r + 10)*cos(2 * PI / n * i), centerY + (r + 10)*sin(2 * PI / n * i), 0);
//        glutSolidSphere(5, 20, 20);
//        glPopMatrix();
//    }
//    glPopMatrix();
//
//
//    // draw the clock dial
//    int gaps = 60;
//    float line1 = 10;
//    float line2 = 5;
//    for (i = 0; i < gaps; i++)
//    {
//        if (i % 5 == 0){     //  long dial
//            glPushMatrix();
//            glTranslatef(centerX + (r - line1) * sin(2 * PI / gaps * i), centerY + (r - line1) * cos(2 * PI / gaps * i), 0);
//            glRotatef(-i*6, 0, 0, 1);
//            glScalef(1, 4, 1);
//            glutSolidCube(3);
//            glPopMatrix();
//
//        }else {             //short dial
//            glPushMatrix();
//            glTranslatef(centerX + (r - line1) * sin(2 * PI / gaps * i), centerY + (r - line1) * cos(2 * PI / gaps * i), 0);
//            glRotatef(-i*6, 0, 0, 1);
//            glScalef(1, 2, 1);
//            glutSolidCube(2);
//            glPopMatrix();
//        }
//    }
//
//    // middle circle
//    glPushMatrix();
//    glTranslatef(centerX, centerY, 0);
//    glutSolidSphere(3, 20, 20);
//    glPopMatrix();
//
//    int h_needle = r - 3 * line1;
//    int m_needle = r - line1;
//
//    float s_angle = Second / 60.0;
//    float m_angle = (Minute * 60 + Second) / 3600.0;
//    float h2 = Hour >= 12 ? (Hour - 12) : Hour;
//    float h_angle = (h2 * 60 * 60 + Minute * 60 + Second) / (12 * 60 * 60);
//
//    // Second
//    glLineWidth(1);
//    glBegin(GL_LINES);
//    glVertex2f(centerX - 2 * line1 * sin(2 * PI * s_angle), centerY - 2 * line1 * cos(2 * PI * s_angle));
//    glVertex2f(centerX + (r - line2) * sin(2 * PI * s_angle), centerY + (r - line2) * cos(2 * PI * s_angle));
//    glEnd();
////    glPushMatrix();
////        glTranslatef(centerX - 2 * line1 * sin(2 * PI * s_angle), centerY - 2 * line1 * cos(2 * PI * s_angle), 0);
////        glRotatef(-s_angle, 0, 0, 1);
////        glScalef(2, 50, 2);
////        glutSolidCube(1);
////    glPopMatrix();
//
//
//    //Minute
//    glLineWidth(3);
//    glBegin(GL_LINES);
//    glVertex2f(centerX, centerY);
//    glVertex2f(centerX + m_needle*sin(2 * PI * m_angle), centerY + m_needle * cos(2 * PI * m_angle));
//    glEnd();
//
//    // Hour
//    glLineWidth(5);
//    glBegin(GL_LINES);
//    glVertex2f(centerX, centerY);
//    glVertex2f(centerX + h_needle * sin(2 * PI * h_angle), centerY + h_needle * cos(2 * PI * h_angle));
//    glEnd();
//
//    glFlush();
//}