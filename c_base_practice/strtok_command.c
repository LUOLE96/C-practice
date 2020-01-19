#include <stdio.h>
#include <string.h>


int main(void)
{
    char buf[128] = "8LED 7 1";

    char *command[3] = {0};
    command[0] = strtok(buf," ");
    printf("%s\n",command[0]);

    char *param = NULL;
    int i = 1;
    while(command[i] = strtok(NULL," "))\
        printf("param = %s\n",command[i++]);

    return 0;
}