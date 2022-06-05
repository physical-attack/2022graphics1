#include <stdio.h>
#include <windows.h>
int main()
{
    PlaySound("07071104.wav",NULL,SND_ASYNC);
    while(1)
    {

        printf("½Ð¿é¤J¼Æ¦r: ");
        int n;
        scanf("%d",&n);
        if(n==1) PlaySound("do.wav",NULL,SND_SYNC);
        if(n==2) PlaySound("re.wav",NULL,SND_SYNC);
        if(n==3) PlaySound("mi.wav",NULL,SND_SYNC);
    }
}
