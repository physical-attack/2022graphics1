#include <GL/glut.h> ///�ϥ�GLUT�~��²�Ƶ{��

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);///��m

    glBegin(GL_POLYGON); ///�h���
        glColor3f(1,0,1); ///�C��
        glVertex2f(-1,1); ///�y��

        glColor3f(1,1,0);
        glVertex2f(1,-1);

        glColor3f(0,1,1);
        glVertex2f(1,1);
    glEnd();

    glutSwapBuffers(); ///�e�n�洫�X��
}

int main(int argc, char *argv[]) ///�D�禡 �i����
{
    glutInit(&argc, argv); ///�Ѽưe�� glut ��l��
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///���w�İ�+3D�`�ץ\��

    glutCreateWindow("week02�m�T��"); ///�} glut ����

    glutDisplayFunc(display); ///�Ψ���ܪ��禡

    glutMainLoop(); ///�D�{���j��
}
