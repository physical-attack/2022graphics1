#include <GL/glut.h>
float angle=0,oldx=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///�ƥ�
        glRotated(angle, 0,0,1);

        glutSolidTeapot(0.5);
    glPopMatrix();///�٭�
    glutSwapBuffers();
}

void motion(int x,int y)
{
    angle += (x-oldx);
    oldx=x;
    display();///���e�e��
}

void mouse (int button,int state,int x,int y)
{
    oldx=x;///�w��
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week04����");

    glutDisplayFunc(display);

    glutMotionFunc(motion);///mouse motion
    glutMouseFunc(mouse);///mouse���U��}
    glutMainLoop();
}
