#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;///宣告變數
int main()
{
    mp3.Load("Hurry_Up.mp3");
    mp3.Play();

    printf("請輸入數字: ");
    int n;
    scanf("%d",&n);
}
