#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char **argv)
{
    const char *str = "hello world\n";
    int len = write(atoi(argv[1]),str,strlen(str));
    printf("write len = %d,buf = %s\n",len,str);

}