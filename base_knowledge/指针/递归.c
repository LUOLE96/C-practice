#include <stdio.h>

//求n的阶层（递归循环调用注意栈空间的溢出）
int func(int n)
{
    if(n < 0){
        return -1;
    }

    if(n == 0 || n == 1){
        return 1;
    }
    return n * func(n-1);
}

int fib(int n)
{
    
}

int main(void)
{
#if 1
    int n,res;
    scanf("%d",&n);

    res = func(n);
    printf("%d! = %d\n",n,res);
#endif

    return 0;
}