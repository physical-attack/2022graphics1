#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix(); ///備份舊矩陣位置，因為會修改矩陣，所以移動會累積
    glTranslatef(0.5,0.5,0);///往右上角跑
    glColor3d(1,0,1);///色彩

    glutSolidTeapot(0.6);
    glPopMatrix(); ///還原舊矩陣
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week03 移動茶壺");

    glutDisplayFunc(display);

    glutMainLoop();
}
