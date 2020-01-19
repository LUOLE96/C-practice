#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define MSGSIZE 512

typedef struct msgbuf
{
    int mtype;//消息类型
    char mtext[MSGSIZE];
}msg_t;

int main(void)
{
    key_t key = ftok(".",100);
    if(key < 0){
        perror("ftok error");
        return -1;
    }

    int msgid = msgget(key,IPC_CREAT | 0666);
    if(msgid < 0){
        perror("msgget error");
        return -1;
    }
    system("ipcs -q");

    msg_t message = {1,"hello world"};
    int res = msgsnd(msgid,message.mtext,strlen(message.mtext),0);//添加消息到队列
    printf("msgsnd res = %d\n",res);
    system("ipcs -q");

    msg_t temp = {0};
    res = msgrcv(msgid,temp.mtext,sizeof(temp.mtext),0,0);//从标识符为msgid的消息队列中接受消息
    printf("msgrcv res = %d,temp.mess = %s\n",res,temp.mtext);
    system("ipcs -q");

    if(msgctl(msgid,IPC_RMID,NULL) < 0)
	{
		perror("msgctl error");
		return -1;
	}
	system("ipcs -q");

    return 0;
}