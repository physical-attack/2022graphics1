# 2022graphics1

# week02

## 2-1 茶壺
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

## 2-2 多邊形
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

## 3-1  上傳到github
```c++
把 README.md檔 用 markdown MD語法編輯

#   一井號 => 大標題
##  二井號 => 小標題

```C++

顯現出c++的格式，鍵盤左上角的撇
"```"
```


# week03

## 2-2 移動茶壺
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

## 2-3  四個茶壺

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

## 2-4  滑鼠移動(只限點，押著不行)

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

## 2-5  印出滑鼠座標(按一放一)

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
# week04

## 1-2 rotate teapot

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

## 1-3 mouse rotate teapot(會重置)

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

## 1-4 mouse rotate teapot(不會重置)

```c++
#include <GL/glut.h>
float angle=0,oldx=0;
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
    angle += (x-oldx);
    oldx=x;
    display();///重畫畫面
}

void mouse (int button,int state,int x,int y)
{
    oldx=x;///定錨
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("week04旋轉");

    glutDisplayFunc(display);

    glutMotionFunc(motion);///mouse motion
    glutMouseFunc(mouse);///mouse按下放開
    glutMainLoop();
}
```

# week05
## 2-1.按keyboard，畫面顯示座標
```c++
#include <GL/glut.h>

#include <stdio.h>

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,0);

    glutSolidTeapot(0.5);

    glutSwapBuffers();

}



void keyboard( unsigned char key,int x,int y )

{

    printf("你按下了 %c 在 %d %d 座標\n",key,x,y);

}

int main(int argc,char**argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);

    glutCreateWindow("week keyboard");



    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

}
```
## 2-2把上週、上上週的加進去，但中間空白
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=0,y=0,z=0;
int oldX=0,oldY=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0 , -(y-150)/150.0, z);
        glColor3f(1,1,0);
        glutSolidTeapot(0.5);
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard( unsigned char key,int x,int y )
{

}

void mouse(int button , int state , int x , int y)
{

}

void motion(int x ,int y)
{
    
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
```
## 2-3加入motion並做宣告修改
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=0,y=0,z=0;
int oldX=0,oldY=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0 , -(y-150)/150.0, z);
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

}

void motion(int mouseX ,int mouseY)///按住滑鼠進行移動，會有瞬移情況
{
    x+=(mouseX-oldX) , y+=(mouseY-oldY);
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
```
## 2-4加入mouse使其正常移動，並新增背景顏色
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0;
int oldX=0,oldY=0;

void display()
{
    glClearColor( 0.3 , 0.4 , 0.6 , 1);///R、G、B、A，A為半透明，目前關閉
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0 , -(y-150)/150.0, z);
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
    oldX=mouseX,oldY=mouseY;///解決"瞬移"
}

void motion(int mouseX ,int mouseY)///會有瞬移情況
{
    x+=(mouseX-oldX) , y+=(mouseY-oldY);
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
```
## 2-5原地放大縮小
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;

void display()
{
    glClearColor( 0.1 , 0.7 , 0.5 , 1);///R、G、B、A，A為半透明，目前關閉
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0 , -(y-150)/150.0, z);
        glScalef(scale , scale , scale);///縮放為scale倍
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
    oldX=mouseX,oldY=mouseY;///解決"瞬移"
}

void motion(int mouseX ,int mouseY)///會有瞬移情況
{
    if( mouseX-oldX > 0) scale*=1.1;///放大縮小
    if( mouseX-oldX < 0) scale*=0.9;

    (此行刪除，使其固定原地)

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
```
# week06
## 2-2 3D茶壺
```c++
#include <GL/glut.h>

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        glutSolidTeapot(0.6);
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");


    glutDisplayFunc(display);
    ///程式放在"create window"之後
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 "glutmainloop" 之前
    glutMainLoop();///end here

}
```
## 2-3 上週部分程式植入
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0,scale=1.0;
int oldX=0,oldY=0;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0,z);
        glScalef(scale,scale,scale);
        glColor3f(1,0,0);
        glutSolidTeapot(0.6);
    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button , int state , int mouseX , int mouseY)
{
    oldX=mouseX,oldY=mouseY;
}

void motion(int mouseX ,int mouseY)
{
    if( mouseX-oldX > 0) scale*=1.1;
    if( mouseX-oldX < 0) scale*=0.9;


    oldX=mouseX , oldY=mouseY;
    display();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);


    glutDisplayFunc(display);
    ///程式放在"create window"之後
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 "glutmainloop" 之前
    glutMainLoop();///end here

}
```
2-4 旋轉
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClearColor(0.8,0.2,0.4,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0,z);
        glRotatef(angle, 0,1,0);
        glScalef(scale,scale,scale);
        glColor3f(1,1,1);
        glutSolidTeapot(0.6);
    glPopMatrix();
    glutSwapBuffers();
}

void mouse(int button , int state , int mouseX , int mouseY)
{
    oldX=mouseX,oldY=mouseY;
}

void motion(int mouseX ,int mouseY)
{
    angle += (mouseX-oldX);
    ///if( mouseX-oldX > 0) scale*=1.1;
    ///if( mouseX-oldX < 0) scale*=0.9;


    oldX=mouseX , oldY=mouseY;
    display();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);


    glutDisplayFunc(display);
    ///程式放在"create window"之後
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 "glutmainloop" 之前
    glutMainLoop();///end here

}
```
2-5 移、轉、縮
```c++
#include <GL/glut.h>
#include <stdio.h>

float x=150,y=150,z=0,scale=1.0,angle=0.0;
int oldX=0,oldY=0,now=1;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClearColor(0.8,0.2,0.4,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef((x-150)/150.0, -(y-150)/150.0,z);
        glRotatef(angle, 0,1,0);
        glScalef(scale,scale,scale);
        glColor3f(1,1,1);
        glutSolidTeapot(0.6);
    glPopMatrix();
    glutSwapBuffers();
}
void keyboard(unsigned char key,int mouseX,int mouseY)
{
    if(key=='1'||key=='w'||key=='W') now=1;///移
    if(key=='2'||key=='e'||key=='E') now=2;///轉
    if(key=='3'||key=='r'||key=='R') now=3;///縮放
}
void mouse(int button , int state , int mouseX , int mouseY)
{
    oldX=mouseX,oldY=mouseY;
}

void motion(int mouseX ,int mouseY)
{
    if(now==1)
    {
        x+=(mouseX-oldX),y+=(mouseY-oldY);
    }
    else if(now==2)
    {
        angle += (mouseX-oldX);
    }
    else if(now==3)
    {
        if(mouseX-oldX >0 ) scale *= 1.1;
        if(mouseX-oldX <0 ) scale *= 0.9;
    }


    oldX=mouseX , oldY=mouseY;
    display();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week06 light");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);


    glutDisplayFunc(display);
    ///程式放在"create window"之後
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 "glutmainloop" 之前
    glutMainLoop();///end here

}
```

# week08 3D模型

```c++
#include <GL/glut.h>///角括號，系統裡include 的檔案
#include "glm.h"///雙引號，同目錄裡的檔案
GLMmodel* pmodel=NULL;///GLModel模型的指標，NULL表示還沒好

void
drawmodel(void)
{
    if (!pmodel) {
	pmodel = glmReadOBJ("data/Al.obj");
	if (!pmodel) exit(0);
	glmUnitize(pmodel);
	glmFacetNormals(pmodel);
	glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH);
}///用來畫3D模型的程式碼

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f(1,1,0);
        ///glutSolidTeapot(0.6);
        drawmodel();
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08 model");


    glutDisplayFunc(display);
    ///程式放在"create window"之後
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    ///放在 "glutmainloop" 之前
    glutMainLoop();///end here

}
```
# week09
## 3-1 opencv+GL
```c++
#include <GL/glut.h>
#include <opencv/highgui.h>
void myTexture()
{
    IplImage * img = cvLoadImage("724425.png");
    cvShowImage("opencv",img);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BI|GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.6);
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");


    glutDisplayFunc(display);
    myTexture();

    glutMainLoop();
}
```

## 3-2 融合
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);/// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);/// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot(0.6);
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");


    glutDisplayFunc(display);
    myTexture("724425.png");

    glutMainLoop();
}
```

# week10
## 1-3 茶壺改四個邊
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    ///glutSolidTeapot(0.6);
    
    glBegin(GL_POLYGON);
        glTexCoord2f( 0 , 1 ); glVertex2f( -1 , -1 );
        glTexCoord2f( 1 , 1 ); glVertex2f( +1 , -1 );
        glTexCoord2f( 1 , 0 ); glVertex2f( +1 , +1 );
        glTexCoord2f( 0 , 0 ); glVertex2f( -1 , +1 );
    glEnd();
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture");


    glutDisplayFunc(display);
    myTexture("724425.png");

    glutMainLoop();
}
```
## 1-4 畫圓球
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>

GLUquadric * sphere = NULL;///指標，指到二次曲面

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.6);
    gluQuadricTexture(sphere,1);///設好貼圖
    gluSphere(sphere,1,30,30);///畫圓球
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture");


    glutDisplayFunc(display);
    myTexture("123.jpg");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```
## 1-5 旋轉
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>

GLUquadric * sphere = NULL;///指標，指到二次曲面

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float angle=0;///旋轉角度

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.6);
    glPushMatrix();
        glRotatef(angle, 0,0,1);
        gluQuadricTexture(sphere,1);///設好貼圖
        gluSphere(sphere,1,30,30);///畫圓球
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;///每次執行display()加1度
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture");


    glutIdleFunc(display); ///有空idle呼叫display()
    glutDisplayFunc(display);
    myTexture("123.jpg");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```
## 1-6 正轉
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>

GLUquadric * sphere = NULL;///指標，指到二次曲面

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float angle=0;///旋轉角度

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot(0.6);
    glPushMatrix();
        glRotatef(90,1,0,0);///轉正
        glRotatef(angle, 0,0,1);
        gluQuadricTexture(sphere,1);///設好貼圖
        gluSphere(sphere,1,30,30);///畫圓球
    glPopMatrix();
    glutSwapBuffers();
    angle+=1;///每次執行display()加1度
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 texture");


    glEnable(GL_DEPTH_TEST);///開3D深度測試 => 3D效果
    glutIdleFunc(display); ///有空idle呼叫display()
    glutDisplayFunc(display);
    myTexture("724425.png");
    sphere = gluNewQuadric();///準備好二次曲面

    glutMainLoop();
}
```
# week11
## 1-3 有色鋼彈
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel = NULL;///空指標

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ///glutSolidTeapot(0.6);
    if(pmodel == NULL)///如果是空指標表示模型還沒準備好
    {
        pmodel = glmReadOBJ("data/Gundam.obj");///讀模型
        glmUnitize(pmodel); ///換算unit大小
        glmFacetNormals(pmodel); ///重新計算模型面的法向量
        glmVertexNormals(pmodel,90);///重新計算模型頂點的法向量
    }
    glmDraw(pmodel,GLM_TEXTURE);///有模型後畫貼圖
    glutSwapBuffers();
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundan");


    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");

    glutMainLoop();
}
```
## 1-4 3D+轉圈
```c++
#include <GL/glut.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * pmodel = NULL;

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
/// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
 /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
 /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        ///glutSolidTeapot(0.6);
    if(pmodel == NULL)///如果是空指標表示模型還沒準備好
    {
        pmodel = glmReadOBJ("data/Gundam.obj");///讀模型
        glmUnitize(pmodel); ///換算unit大小
        glmFacetNormals(pmodel); ///重新計算模型面的法向量
        glmVertexNormals(pmodel,90);///重新計算模型頂點的法向量
    }
    glPushMatrix();
        glRotatef(angle,0,1,0);
        glmDraw(pmodel,GLM_TEXTURE);///有模型後畫貼圖
    glPopMatrix();
    glutSwapBuffers();
    angle += 0.1;
}

int main(int argc ,char** argv)
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 gundan");


    glEnable(GL_DEPTH_TEST);
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("724425.png");

    glutMainLoop();
}
```
## 1-6 茶壺手臂
```c++
#include <GL/glut.h>
void hand()
{
    glColor3f(0,1,0);
    glutSolidTeapot(0.3);
}
void body()
{
    glColor3f(1,0,1);
    glutSolidTeapot(0.5);
}
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    body();
    glPushMatrix();
        glTranslatef(0.5,0.2,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.3,0,0);
        hand();
    glPopMatrix();
    glutSwapBuffers();
    angle +=0.1;
}
int main(int argc, char**argv)///這裡一定要
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11 TRT");

    glutIdleFunc(display);
    glutDisplayFunc(display);

    glutMainLoop();
}
```
# week12
## 3-4 兩邊茶手
```c++
#include <GL/glut.h>
float angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.8,0.2,0.6);
    glutSolidTeapot(0.6);

    glPushMatrix();
        glTranslatef(0.3,0,0);///移到右邊
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(0.3,0,0);///旋轉軸放中心
        glColor3f(0.9,0.6,0.4);
        glutSolidTeapot(0.3);///第二茶壺(手臂)
        glPushMatrix();
            glTranslatef(0.3,0,0);///移到右邊
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(0.3,0,0);///旋轉軸放中心
            glColor3f(0.9,0.6,0.4);
            glutSolidTeapot(0.3);///第二茶壺(手臂)
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.3,0,0);///移到左邊
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(-0.3,0,0);///旋轉軸放中心
        glColor3f(0.9,0.6,0.4);
        glutSolidTeapot(0.3);///第二茶壺(手臂)
        glPushMatrix();
            glTranslatef(-0.3,0,0);///移到左邊
            glRotatef(-angle,0,0,1);///旋轉
            glTranslatef(-0.3,0,0);///旋轉軸放中心
            glColor3f(0.9,0.6,0.4);
            glutSolidTeapot(0.3);///第二茶壺(手臂)
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
```
# week13
## 1-8 分節旋轉

```c++
1-8 分節旋轉
#include <GL/glut.h>
float angle[20],oldX=0;
int angleid=0;///0右手 1右手關節 2左手 3左手關節
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
    glutCreateWindow("week13 rectangle");

    glutMouseFunc(mouse);
    glutKeyboardFunc(key);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
