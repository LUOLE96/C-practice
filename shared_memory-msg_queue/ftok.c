/*************************************************************************
    > File Name: ftok.c
    > Author: luole
    > Mail: 708920807@qq.com 
    > Created Time: 2019年12月25日 星期三 20时42分47秒
 ************************************************************************/

#include<stdio.h>
#include <sys/sem.h>
#include<stdlib.h>

/*在共享内存、消息队列、信号量使用某种介质来通信时，用来区分这种介质
 */
int main(void){
	key_t semkey;
	if((semkey = ftok("./test",1)) < 0){
		printf("ftok failed\n");
		exit(EXIT_FAILURE);
	}
	printf("ftok ok,semkey = %d\n",semkey);
	return 0;
}
