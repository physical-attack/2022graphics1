#include <GL/glut.h> ///�ϥ�GLUT�~��²�Ƶ{��

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);///��m

    glutSolidTeapot(0.6);///��߯���

    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///�D�禡 �i����
{
    glutInit(&argc, argv); ///�Ѽưe�� glut ��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///���w�İ�+3D�`�ץ\��

    glutCreateWindow("week02����"); ///�} glut ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡

    glutMainLoop(); ///�D�{���j��
}
