#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int a[3];
	int *p = a;
	int i; 
	
	for(i = 0;i < sizeof(a)/sizeof(*a);i++){
		printf("%p->%d\n",&a[i],a[i]);
	}
	
	for(i = 0;i < sizeof(a)/sizeof(*a);i++){
		scanf("%d",p++);
	}
	
    p = a;
	for(i = 0;sizeof(a)/sizeof(*a);i++,p++){
		printf("%p->%d\n",p,*p);
	}
	
	return 0;
}