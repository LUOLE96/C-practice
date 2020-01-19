#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = NULL;
    p = malloc(sizeof(int));
    if(p == NULL){
        printf("malloc() error!\n");
        exit(1);
    }
    *p = 10;
    printf("%p-->%d\n",p,*p);
    free(p);
    p = NULL;//free掉后立马学成NULL，再写该段地址会出现段错误

    *p = 123;
    printf("%p-->%d\n",p,*p);
    return 0;
}