#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>

int value = 1000;

int main()
{
	pid_t ret = fork();
	if(ret < 0){
		perror("fork error");
		return -1;	
	}
	else if(0 == ret){
		value ++;
		printf("sub value = %d\n",value);	
	}
	else if(ret > 0){
		sleep(1);
		value --;
		printf("parent value = %d\n",value);
	}
}
