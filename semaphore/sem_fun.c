#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
union semun//定义semctl使用时的第四个参数的共用体
{
    int vlaue;
    struct semid_ds *buf;
};

int main(void)
{
    key_t key = ftok(".",50);//获取key
    if(key < 0){
        perror("ftok error");
        return -1;
    }
    printf("key = %d\n",key);

    int semid = semget(key,1,IPC_CREAT | 0600);//创建或获取信号量数组，返回信号量数组id
    if(semid < 0){
        perror("semget error");
        return -1;
    }
    system("ipcs -s");
    printf("semid = %d\n",semid);

    union semun value = {1};
    if(semctl(semid,0,SETVAL,value) < 0){//初始化信号量
        perror("semctl error");
        return -1;
    }

	struct semid_ds temp = {0};
	value.buf = &temp;
	semctl(semid,0,IPC_STAT,value);
	printf("temp %ld,%ld\n",temp.sem_otime,temp.sem_nsems);

    int val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after init sem val = %d\n",val);

    struct sembuf sop = {0};
    sop.sem_num = 0;
    sop.sem_op = -1;//p操作
    sop.sem_flg = 0;

    if(semop(semid,&sop,1) < 0){//进行一次semop操作，是p操作还是v操作由sembuf的sem_op成员决定
        perror("semop p option error");
        return -1;
    }

    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after p option : sem val = %d\n",val);

    printf("read or write data\n");

    sop.sem_op = 1;
    if(semop(semid,&sop,1) < 0){
        perror("semop v option error");
        return -1;
    }
    
    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after vs option : sem val = %d\n",val);

    if(semctl(semid,0,IPC_RMID,0) < 0)	//删除信号量数组
	{
		perror("semctl error");
		return -1;
	}
	system("ipcs -s");

}
