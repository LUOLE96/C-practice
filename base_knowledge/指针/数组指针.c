#include <stdio.h>

int main(void)
{
#if 0
    int *p = (int [3]){1,2,3};
    int i;

    for(i = 0;i < 3;i++)
        printf("%p %p->%d\n",&p[i],p,p[i]);
#endif

#if 1
    int a[2][3] = {1,2,3,4,5,6};
    int i,j;
    int *p;

    //p = &a[0][0];
    p = *a;
    printf("%p %p\n",a,a+1);
    printf("%p %p\n",p,p+1);
    printf("\n\n");

    // for(i = 0;i < 2;i++){
    //     for(j = 0;j < 3;j++){
    //         printf("%p->%d\n",*(a+i)+j,*(*(a+i)+j));
    //     }
    //     printf("\n");
    // }
    for(i = 0;i < 6;i++,p++){
        printf("%p->%d\n",p,*p);
    }
#endif


    return 0;
}