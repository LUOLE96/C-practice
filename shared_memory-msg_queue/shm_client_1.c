#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
//system v模式的共享内存
#define SHMSIZE 1024

int main(void)
{
    key_t key = ftok(".",77);
    if(key < 0){
        perror("ftok error");
        return -1;
    }

    int shmid = shmget(key,SHMSIZE,IPC_CREAT | 0600);//创建或获取共享内存
    if (shmid < 0)
    {
        perror("shmget error");
        return -1;
    }

    void *addr = shmat(shmid,NULL,0);//建立共享内存的映射关系
    if(NULL == addr){
        perror("shmat error");
        return -1;
    } 

    char buf[SHMSIZE] = {0};
    memcpy(buf,addr,SHMSIZE);//从共享内存中读数据
    printf("read buf = %s\n",buf);

    if(shmdt(addr) < 0){//解除映射关系
        perror("shmdt error");
        return -1;
    }

    if(shmctl(shmid,IPC_RMID,NULL) < 0){
        perror("shmctl error");
        return -1;
    }

}