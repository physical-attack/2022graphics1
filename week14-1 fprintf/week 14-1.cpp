#include <stdio.h>
int main()
{
    FILE * fout = fopen("file.txt","w+");
    printf("Hello\n");
    fprintf(fout,"Hello\n");
    fclose(fout);
}
