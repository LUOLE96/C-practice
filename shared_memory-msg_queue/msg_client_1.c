#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#define MSGSIZE 512

typedef struct msgbuf
{
	int type;	//消息类型
	char mess[MSGSIZE];
}msg_t;

int main()
{
	key_t key = ftok(".",100);
	if(key < 0)
	{
		perror("ftok eror");
		return -1;
	}

	int msgid = msgget(key,IPC_CREAT | 0666);
	if(msgid < 0)
	{
		perror("msgget error");
		return -1;
	}

#if 1
	msg_t temp = {0};
	int res = msgrcv(msgid,temp.mess,sizeof(temp.mess),0,0);
	printf("msgrcv res = %d,temp.mess = %s\n",res,temp.mess);
#endif

#if 1
	if(msgctl(msgid,IPC_RMID,NULL) < 0)
	{
		perror("msgctl error");
		return -1;
	}
#endif
}
