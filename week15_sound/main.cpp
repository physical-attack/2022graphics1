#include <stdio.h>
#include <windows.h>
int main()
{
    printf("playsound()之前\n");
    PlaySound("07071104.wav",NULL,SND_SYNC);
    printf("playsound()之後\n");
}
