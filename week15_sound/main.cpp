#include <stdio.h>
#include <windows.h>
int main()
{
    printf("playsound()���e\n");
    PlaySound("07071104.wav",NULL,SND_SYNC);
    printf("playsound()����\n");
}
