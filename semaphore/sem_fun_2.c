#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
union semun	//定义semctl使用时的第四个参数的共用体
{
	int value;
	struct semid_ds *buf;
};

int sem_init(int semid)
{
    union semun vlaue = {1};
    return semctl(semid,0,SETVAL,vlaue);
}

int sem_p(int semid)
{
    struct sembuf sop = {0};
    sop.sem_num = 0;
    sop.sem_op = -1;
    sop.sem_flg = 0;
    return semop(semid,&sop,1);
}

int sem_v(int semid)
{
	struct sembuf sop = {0};
	sop.sem_num = 0;
	sop.sem_op = 1;
	sop.sem_flg = 0;

	return semop(semid,&sop,1);
}
int main(void)
{
    key_t key = ftok(".",50);//获取key

    int semid = semget(key,1,IPC_CREAT | 0600);
    system("ipcs -s");

    sem_init(semid);

    int val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after init option : sem val = %d\n",val);

    sem_p(semid);
    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after p option : sem val = %d\n",val);

	sem_v(semid);
    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after v option : sem val = %d\n",val);

	sem_p(semid);
    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after p option : sem val = %d\n",val);

	sem_v(semid);
    val = semctl(semid,0,GETVAL,0);//查询信号量的值
    printf("after v option : sem val = %d\n",val);

	semctl(semid,0,IPC_RMID,0);	//删除信号量数组
	system("ipcs -s");
    
}