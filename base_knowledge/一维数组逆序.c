#include <stdio.h>

void print_arr(int *p,int nSize)
{
    int i;
    for(i = 0;i < nSize;i++){
        printf("%d\t",*(p + i));
    }
    printf("\n");

    return ;
}

void func(int *p,int nSize)
{
    int i,m,j,tmp;
    m = (nSize - 1)/2;
    for(i = 0;i <= m;i++){
        j = nSize - i - 1;
        tmp = p[j];
        p[j] = p[i];
        p[i] = tmp;
    }

    return ;
}


int main(void)
{
    int a[] = {6,5,4,3,2,1,0};
    int nSize = sizeof(a)/sizeof(*a);
    print_arr(a,nSize);

    func(a,nSize);

    print_arr(a,nSize);

    return 0;
    
}