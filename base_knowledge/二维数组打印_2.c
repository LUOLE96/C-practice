#include <stdio.h>
#define M 3
#define N 4

//void print_arr(int (*p)[N],int m,int n)
void print_arr(int p[][N],int m,int n)
{
    int i,j;
    for(i = 0;i < m;i++){
        for(j = 0;j < n;j++){
            //printf("%4d ",*(*(p + i) + j));
            printf("%d ",p[i][j]);
        }
    }
    printf("\n");

    return ;
}

//求平均值
int average_score(int *p,int n)
{
    float sum = 0;
    int i;

    for(i = 0;i < n;i++){
        sum += p[i];
    }
    return sum/n;
}

//找第二个学生的成绩
int find_num(int (*p)[N],int num)
{
    int i;

    for(i = 0;i < N;i++){
        printf("%d ",*(*(p+num)+i));
    }
    printf("\n");

    return 0;
}

//只找学生成绩
int *find_num_only(int (*p)[N],int num)
{
    if(num > M - 1){
        return NULL;
    }
    return *(p + num);
}

int main(void)
{
    int a[M][N] = {1,2,3,4,5,6,7,8,9,10,11,12};

    //print_arr(a,M,N);
    float average;
    int num;

    average = average_score(*a,M * N);
    printf("%f\n",average);

    printf("请输入查看的学生：\n");
    scanf("%d",&num);

    int *res;
    int i;
    res = find_num_only(a,num);
    if(res != NULL){
        for(i = 0;i < N;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
    else
    {
        printf("can not find\n");
    }
    
    return 0;
}