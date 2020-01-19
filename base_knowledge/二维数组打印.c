#include <stdio.h>
#define M 3
#define N 4

void print_arr(int *p,int n)
{
    int i;
    for(i = 0;i < n;i++){
        //printf("%d ",*(p + i));
        printf("%d ",p[i]);
        
    }
    printf("\n");

    return ;
}


int main() {
    int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};

    //print_arr(&a[0][0],M*N);
    print_arr(*a,M*N);
    print_arr(a[0],M*N);
    print_arr(*(a + 0),M*N);
    

    return 0;
}

