#include <stdio.h>

union
{
    struct 
    {
        char a:1;
        char b:2;
        char c:1;
    }x;
    char y;
}w;

int main(void)
{
    w.y = 4;
    printf("%d\n",w.x.a);
    printf("%d\n",w.x.b);

    return 0;
}