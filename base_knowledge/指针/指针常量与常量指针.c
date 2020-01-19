#include <stdio.h>

int main(void)
{
#if 0
    int i = 1;
    int j = 100;
    const int *p = &i;

    // T i = 10;
    // F *p = 10;
    p = &j;
    printf("%d\n",*p);
#endif
#if 0
    int i = 1;
    int j = 100;

    int *const p = &i;

    // T *p = 10;
    // F p = &j;
    printf("%d\n",*p);
#endif
    int i = 1;
    int j = 100;
    const int *const p = &i;

    // F *p = 10;
    // F p = &j;
    printf("%d\n",*p);
}