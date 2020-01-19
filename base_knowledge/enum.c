#include <stdio.h>

typedef enum week
{
    tues = 2,
    wed,
    thur,
    fri,
}wee;


int main(void)
{
    wee weekday = wed;
    printf("%d\n",weekday);
    return 0;
}