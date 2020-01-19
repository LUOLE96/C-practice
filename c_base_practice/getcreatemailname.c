#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

char *getcreatemailname(const char *username,char *filename)
{
    if(NULL == username || NULL == filename)
        return NULL;

    char name[128] = "";
    strcat(name,username);
    strcat(name,"_0.mail");
    printf("%s\n",name);

    int i;
    for(i = 0;i < 10;i++){
        if(access(name,F_OK)){
            strcpy(filename,name);
            return filename;
        }
        name[9] = i + 48;
    }
    filename[9] = 0 + 48;

    return filename;
}

int main(void)
{
    char *username = "zhangsan";
    char filename[128] = "";
    printf("filename = %s\n",getcreatemailname(username,filename));


    return 0;
}