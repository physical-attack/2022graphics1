#include <GL/glut.h>
#include <stdio.h>
#include <mmsystem.h>
void time(int t)
{
    printf("�_��,�{�b�ɶ�: %d\n",t);
    PlaySound("do.wav",NULL,SND_ASYNC);
    glutTimerFunc(2000,time,t+1);
}
void display()
{

}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14 time");

    glutTimerFunc(5000,time,0);///5���X�{��0��
    glutDisplayFunc(display);
    glutMainLoop();
}
