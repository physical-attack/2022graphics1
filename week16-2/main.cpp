#include <GL/glut.h>

void reshape(int w,int h)
{
    float ar=(float)w/(float)h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);///3D=>2D
    glLoadIdentity();
    gluPerspective(60,ar,1,10);

    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity();
    gluLookAt(1,0,3,///eye
              0,1,0,///center看哪裡
              0,0,2);///up向量
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(1);
    glutSwapBuffers();
}

void motion(int x,int y)
{
    glMatrixMode(GL_MODELVIEW);///3D Model+View
    glLoadIdentity();
    gluLookAt( (x-150)/150.0 , (y-150)/150.0 , 3 ,///eye
              0,1,0,///center看哪裡
              0,0,2);///up向量
    glutPostRedisplay();
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Week16 camera");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);///範例用resize
    glutMainLoop();
}
