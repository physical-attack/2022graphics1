#include "CMP3_MCI.h"
#include <stdio.h>
CMP3_MCI mp3;///�ŧi�ܼ�
int main()
{
    mp3.Load("Hurry_Up.mp3");
    mp3.Play();

    printf("�п�J�Ʀr: ");
    int n;
    scanf("%d",&n);
}
