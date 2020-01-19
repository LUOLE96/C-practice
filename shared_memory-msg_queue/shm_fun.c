/*************************************************************************
    > File Name: ftok.c
    > Author: luole
    > Mail: 708920807@qq.com 
    > Created Time: 2019年12月25日 星期三 20时42分47秒
 ************************************************************************/

#include<stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<stdlib.h>
#define SHMSIZE 1024
/*在共享内存、消息队列、信号量使用某种介质来通信时，用来区分这种介质
 * 向共享内存写入数据时出现段错误
 */
int main(void)
{
	key_t semkey;
	if((semkey = ftok(".",77)) < 0){
		printf("ftok failed\n");
		exit(EXIT_FAILURE);
	}
	printf("ftok ok,semkey = %d\n",semkey);
	system("ipcs -m");

	int shmid = shmget(semkey,SHMSIZE,IPC_CREAT | 0600);//创建或获取共享内存
	if(shmid < 0){
		perror("shmget error");
		return -1;
	}
	printf("shmid = %d\n",shmid);
	system("ipcs -m");

	void *addr = shmat(shmid,NULL,0);//建立共享内存的映射关系
	if(NULL == addr){
		perror("shmat error");
		return -1;
	}

	char *src = "hello shmat\n";
	memcpy(addr,src,strlen(src));//向共享内存写入数据

	char buf[SHMSIZE] = {0};
	memcpy(buf,addr,SHMSIZE);//从共享内存读出数据
	printf("buf = %s\n",buf);
	
	struct shmid_ds temp = {0};
	shmctl(shmid,IPC_STAT,&temp);
	printf("temp.shm_atime = %ld,temp.shm_cpid = %d,getpid = %d\n",temp.shm_atime,temp.shm_cpid,getpid());

	char *errmsg = NULL;
	if(shmdt(addr) < 0){//解除映射关系
		perror("shmdt error");
		return -1;
	}
	
	if(shmctl(shmid,IPC_RMID,NULL)){//删除共享内存
		perror("shmctl error");
		return -1;
	}
	system("ipcs -m");

	return 0;
}
