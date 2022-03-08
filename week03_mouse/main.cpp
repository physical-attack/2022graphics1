#include <GL/glut.h>
float mouseX=0,mouseY=0;///新加
void myTeapot(float x,float y)
{
    glPushMatrix();
    glTranslatef(x,y,0);
    glColor3d(1,0,0);
    glutSolidTeapot(0.3);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    myTeapot(  (mouseX-150)/150.0,-(mouseY-150)/150.0  );///新加
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    mouseX=x,mouseY=y;///新加
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week03 移動茶壺");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///新加，滑鼠

    glutMainLoop();
}
