#include <GL/glut.h>
#include <stdio.h>
float angle[20],oldX=0;

float newangle[20],oldangle[20];

int angleid=0;///0右手 1右手關節 2左手 3左手關節
FILE * fout = NULL , *fin =NULL;
void write()
{
    if(fout == NULL) fout = fopen("file.txt","w+");

    for(int i=0;i<20;i++)
    {
        printf("%.1f",angle[i]);///印出黑視窗
        fprintf(fout,"%.1f",angle[i]);///印出檔案
    }///印出20個數字
    printf("\n");///每呼叫一次，黑視窗跳行
    fprintf(fout,"\n");///每呼叫一次，檔案跳行
}

void read()
{
    if(fout != NULL) { fclose(fout); fout=NULL; }
    if(fin==NULL) fin=fopen("file.txt","r");
    for(int i=0;i<20;i++)
    {
        oldangle[i]=newangle[i];
        fscanf(fin,"%f", &newangle[i]);
    }
    glutPostRedisplay();///重畫畫面
}

void interpolate(float alpha)
{
    for(int i=0;i<20;i++)
    {
        angle[i]=alpha*newangle[i]+(1-alpha)*oldangle[i];
    }
}

///int t=0;

void timer(int t)
{
    if(t%50==0) read();
    interpolate( (t%50)/50.0 );///介於0.0到1.0
    glutPostRedisplay();
    glutTimerFunc(5,timer,t+1);

}

void key(unsigned char key,int x,int y)
{
    if(key=='p')
    {
        read();
        glutTimerFunc(0,timer,0);
        ///if(t%30==0) read();
        ///interpolate( (t%30)/30.0 );///介於0.0到1.0
        ///glutPostRedisplay();
        ///t++;
    }

    if(key=='s') write();///調好動作後存檔
    if(key=='r') read();
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
    ///write();      不再複讀
    oldX=x;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glRectf(0.3,0.5,-0.3,-0.5);
    glPushMatrix();
        glTranslatef(0.3,0.4,0);///手臂掛回身體
        glRotatef(angle[0],0,0,1);///對z軸旋轉
        glTranslatef(-0.3,-0.4,0);///手臂旋轉軸放中心
        glColor3f(1,0,0);
        glRectf(0.3,0.5,0.7,0.3);

        glPushMatrix();
            glTranslatef(0.7,0.4,0);///手臂掛回身體
            glRotatef(angle[1],0,0,1);///對z軸旋轉
            glTranslatef(-0.7,-0.4,0);///手臂旋轉軸放中心
            glColor3f(0,1,0);
            glRectf(0.7,0.5,1.0,0.3);///下手肘
        glPopMatrix();

    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0.4,0);///手臂掛回身體
        glRotatef(angle[2],0,0,1);///對z軸旋轉
        glTranslatef(0.3,-0.4,0);///手臂旋轉軸放中心
        glColor3f(1,0,0);
        glRectf(-0.3,0.5,-0.7,0.3);

        glPushMatrix();
            glTranslatef(-0.7,0.4,0);///手臂掛回身體
            glRotatef(angle[3],0,0,1);///對z軸旋轉
            glTranslatef(0.7,-0.4,0);///手臂旋轉軸放中心
            glColor3f(0,1,0);
            glRectf(-0.7,0.5,-1.0,0.3);///下手肘
        glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week15 trt 2");

    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
