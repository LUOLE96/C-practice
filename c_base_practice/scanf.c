/*************************************************************************
    > File Name: scanf.c
    > Author: luole
    > Mail: 708920807@qq.com 
    > Created Time: 2019年12月23日 星期一 17时49分50秒
 ************************************************************************/

#include<stdio.h>

int main(void)
{
	int a;
	char x;

	printf(">");
	scanf("%d",&a);
	scanf("%c",&x);

	printf("%d:%c:%d\n",a,x,x);
	printf("%d\n",'\n');

	return 0;
}
