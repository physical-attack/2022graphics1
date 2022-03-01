#include <GL/glut.h> ///使用GLUT外掛簡化程式

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,1);///色彩

    glBegin(GL_POLYGON); ///多邊形
        glColor3f(1,0,1); ///顏色
        glVertex2f(-1,1); ///座標

        glColor3f(1,1,0);
        glVertex2f(1,-1);

        glColor3f(0,1,1);
        glVertex2f(1,1);
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
