#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.8,0.2,0.6);
    glutSolidTeapot(0.6);

    glPushMatrix();
        glTranslatef(0.3,0,0);///����k��
        glRotatef(angle,0,0,1);///����
        glTranslatef(0.3,0,0);///����b�񤤤�
        glColor3f(0.9,0.6,0.4);
        glutSolidTeapot(0.3);///�ĤG����(���u)
        glPushMatrix();
            glTranslatef(0.3,0,0);///����k��
            glRotatef(angle,0,0,1);///����
            glTranslatef(0.3,0,0);///����b�񤤤�
            glColor3f(0.9,0.6,0.4);
            glutSolidTeapot(0.3);///�ĤG����(���u)
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,0);///����k��
        glRotatef(-angle,0,0,1);///����
        glTranslatef(-0.3,0,0);///����b�񤤤�
        glColor3f(0.9,0.6,0.4);
        glutSolidTeapot(0.3);///�ĤG����(���u)
        glPushMatrix();
            glTranslatef(-0.3,0,0);///����k��
            glRotatef(-angle,0,0,1);///����
            glTranslatef(-0.3,0,0);///����b�񤤤�
            glColor3f(0.9,0.6,0.4);
            glutSolidTeapot(0.3);///�ĤG����(���u)
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.1;
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);
    glutMainLoop();
}
