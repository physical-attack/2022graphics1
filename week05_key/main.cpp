#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;

void display()
{
    glClearColor( 0.1 , 0.7 , 0.5 , 1);///R�BG�BB�BA�AA���b�z���A�ثe����
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0 , -(y-150)/150.0, z);
        glScalef(scale , scale , scale);///�Y��scale��
        glColor3f(1,1,0);
        glutSolidTeapot(0.5);
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard( unsigned char key,int mouseX,int mouseY )
{

}

void mouse(int button , int state , int mouseX , int mouseY)
{
    oldX=mouseX,oldY=mouseY;///�ѨM"����"
}

void motion(int mouseX ,int mouseY)///�|���������p
{
    if( mouseX-oldX > 0) scale*=1.1;///��j�Y�p
    if( mouseX-oldX < 0) scale*=0.9;
    oldX=mouseX , oldY=mouseY;
    display();
}

int main(int argc,char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week keyboard");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///this week
    glutMouseFunc(mouse);///last last week
    glutMotionFunc(motion);///last week
    glutMainLoop();
}
