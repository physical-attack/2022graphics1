# 2022graphics1

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
