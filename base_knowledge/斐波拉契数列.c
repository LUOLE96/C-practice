#include <stdio.h>

int fib(int n)
{
    if(n < 1){
        return -1;
    }
    if(n == 1 || n == 2){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);

}

int main(void)
{
    int n;

    printf("please input 斐波拉契数列的项数：");
    scanf("%d",&n);

    int ret;
    ret = fib(n);
    printf("ret = %d\n",ret);

    return 0;
}