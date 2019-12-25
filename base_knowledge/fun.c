#include <stdio.h>

void fun()
{
    printf("fun start\n");
}

static void static_fun()
{
    printf("static_fun() start\n");
}

void test()
{
    fun();
    static_fun();
}
