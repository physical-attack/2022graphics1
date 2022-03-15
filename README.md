# 2022graphics1

#week02
##2-1 茶壺
```C++
#include <GL/glut.h> ///使用GLUT外掛簡化程式

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);///色彩

    glutSolidTeapot(0.6);///實心茶壺

    glutSwapBuffers();
}

int main(int argc, char *argv[]) ///主函式 進階版
{
    glutInit(&argc, argv); ///參數送給 glut 初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///雙緩衝區+3D深度功能

    glutCreateWindow("week02茶壺"); ///開 glut 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主程式迴圈
}
```

##2-2 多邊形
```c++
#include <GL/glut.h> ///使用GLUT外掛簡化程式

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);///色彩

    glBegin(GL_POLYGON); ///多邊形
        glColor3f(1,0,1); ///顏色
        glVertex2f(-0.5,-0.5); ///座標

        glColor3f(1,1,0);
        glVertex2f(0.5,-0.5);

        glColor3f(0,1,1);
        glVertex2f(0,0.5);
    glEnd();

    glutSwapBuffers(); ///畫好交換出來
}

int main(int argc, char *argv[]) ///主函式 進階版
{
    glutInit(&argc, argv); ///參數送給 glut 初始化
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///雙緩衝區+3D深度功能

    glutCreateWindow("week02彩三角"); ///開 glut 視窗

    glutDisplayFunc(display); ///用來顯示的函式

    glutMainLoop(); ///主程式迴圈
}
```

##3-1  上傳到github
```c++
把 README.md檔 用 markdown MD語法編輯

#   一井號 => 大標題
##  二井號 => 小標題

```C++

顯現出c++的格式，鍵盤左上角的撇
"```"
```


#week03

##2-2 移動茶壺
```c++
#include <GL/glut.h>



void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix(); ///備份舊矩陣位置，因為會修改矩陣，所以移動會累積

    glTranslatef(0.5,0.5,0);///往右上角跑

    glColor3d(1,0,1);///色彩



    glutSolidTeapot(0.6);

    glPopMatrix(); ///還原舊矩陣

    glutSwapBuffers();

}



int main(int argc, char *argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);



    glutCreateWindow("week03 移動茶壺");



    glutDisplayFunc(display);



    glutMainLoop();


}
```

##2-3  四個茶壺

```c++
#include <GL/glut.h>

void myTeapot(float x,float y)

{

    glPushMatrix(); ///備份舊矩陣位置，因為會修改矩陣，所以移動會累積

    glTranslatef(x,y,0);

    glColor3d(1,0,0);///色彩

    glutSolidTeapot(0.3);

    glPopMatrix(); ///還原舊矩陣

}

void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    myTeapot(0.5,0.5);

    myTeapot(-0.5,-0.5);

    myTeapot(-0.5,0.5);

    myTeapot(0.5,-0.5);

    glutSwapBuffers();

}



int main(int argc, char *argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);



    glutCreateWindow("week03 移動茶壺");



    glutDisplayFunc(display);



    glutMainLoop();

}
```

##2-4  滑鼠移動(只限點，押著不行)

```c++
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
```

##2-5  印出滑鼠座標(按一放一)

```c++
#include <GL/glut.h>
#include <stdio.h>///printf用
float mouseX=0,mouseY=0;
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
    myTeapot(  (mouseX-150)/150.0,-(mouseY-150)/150.0  );///視窗預設300*300
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    printf("%d %d %d %d\n",button,state,x,y);///印出滑鼠座標，按一個，放一個
    mouseX=x,mouseY=y;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week03 移動茶壺");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);///滑鼠

    glutMainLoop();
}
```
#week04

##1-2 rotate teapot

```c++
#include <GL/glut.h> 



void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

        glRotated(90, 0,0,1);///旋轉

        glutSolidTeapot(0.5);

    glPopMatrix();

    glutSwapBuffers();

}



int main(int argc, char *argv[]) 

{

    glutInit(&argc, argv); 

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); 



    glutCreateWindow("week04旋轉"); 



    glutDisplayFunc(display); 



    glutMainLoop(); 


}
```

##1-3 mouse rotate teapot

```c++
#include <GL/glut.h>

float angle=0;///angle為0

void display()

{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();///備份

        glRotated(angle, 0,0,1);



        glutSolidTeapot(0.5);

    glPopMatrix();///還原

    glutSwapBuffers();

}



void motion(int x,int y)

{

    angle=x;///angle=x軸?

    display();///重畫畫面

}



int main(int argc, char *argv[])

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);



    glutCreateWindow("week04旋轉");



    glutDisplayFunc(display);



    glutMotionFunc(motion);///mouse motion



    glutMainLoop();

}
```
