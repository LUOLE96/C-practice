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
	msg_t message = {1,"hello world test"};
	int res = msgsnd(msgid,message.mess,strlen(message.mess),0);
	printf("msgsnd res = %d\n",res);
#endif

}
