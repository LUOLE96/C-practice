#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t ret = fork();//这段程序执行了两次
	if(ret < 0){
		perror("fork error");
		return -1;
	}
	else if(0 == ret){
		printf("fork ok:sub process pid = %d,ret=%d\n",getpid(),ret);
	}
	else if(ret > 0){
		sleep(1);
		printf("fork ok:parent process pid = %d,parent ret = %d\n",getpid(),ret);
	}
	
}
