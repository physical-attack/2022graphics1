#include <GL/glut.h>
float angle[20],oldX=0;
int angleid=0;///0�k�� 1�k�����` 2���� 3�������`
void key(unsigned char key,int x,int y)
{
    if(key=='0') angleid=0;
    if(key=='1') angleid=1;
    if(key=='2') angleid=2;
    if(key=='3') angleid=3;
}
void mouse(int button,int state,int x,int y)
{
    oldX=x;
}
void motion(int x,int y)
{
    angle[angleid]+=(x-oldX);
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///���u���^����
        glRotatef(angle[0],0,0,1);///��z�b����
        glTranslatef(-0.3,-0.4,0);///���u����b�񤤤�
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///���u���^����
            glRotatef(angle[1],0,0,1);///��z�b����
            glTranslatef(-0.7,-0.4,0);///���u����b�񤤤�
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///�U��y
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///���u���^����
        glRotatef(angle[2],0,0,1);///��z�b����
        glTranslatef(0.3,-0.4,0);///���u����b�񤤤�
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///���u���^����
            glRotatef(angle[3],0,0,1);///��z�b����
            glTranslatef(0.7,-0.4,0);///���u����b�񤤤�
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.0,0.3);///�U��y
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13 rectangle");

    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
