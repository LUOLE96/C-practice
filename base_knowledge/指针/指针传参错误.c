#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
        经典指针传参错误
str传给getmemory(char *p)的时候，传递的是str的副本，不是str本身
传递的副本在getmemory()调用结束，也就回收销毁
*/
// void getMemory(char *p)
// {
//     p = (char *)malloc(100);
//     strcpy(p,"hello world");
//     printf("p:%s\n",p);
// }

void getMemory(char **p)
{
    *p = (char *)malloc(100);
    char *str = "hello world";
    strcpy(*p,str);
    printf("p:%s\n",*p);
}

int main(void)
{
    char *str = NULL;
    printf("%p\n",str);
    //getMemory(str);//错误
    getMemory(&str);

    printf("%s\n",str);

    if(str != NULL)
        free(str);

    return 0;
}