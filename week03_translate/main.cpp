#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///�ƥ��¯x�}��m�A�]���|�ק�x�}�A�ҥH���ʷ|�ֿn
    glTranslatef(0.5,0.5,0);///���k�W���]
    glColor3d(1,0,1);///��m

    glutSolidTeapot(0.6);
    glPopMatrix(); ///�٭��¯x�}
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week03 ���ʯ���");

    glutDisplayFunc(display);

    glutMainLoop();
}
