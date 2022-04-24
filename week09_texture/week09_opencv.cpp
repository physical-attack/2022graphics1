#include <opencv/highgui.h>

int main()

{

    IplImage * img = cvLoadImage("724425.png");

    cvShowImage("week09",img);

    cvWaitKey(0);

}
