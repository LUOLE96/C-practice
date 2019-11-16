#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid = vfork();
	if(pid < 0){
		perror("fork error");
		return -1;	
	}
	else if(0 == pid){
		sleep(1);
		printf("sub process pid : %d\n",getpid());	
	}
	else if(pid > 0)
	{
		printf("parent process pid : %d\n",getpid());
	}
	exit(0);//return是语言级别的，它表示了调用堆栈的返回；而exit是系统调用级别的，它表示了一个进程的结束。
}
