#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(void)
{
	printf("test 1\n");
	pid_t ret = fork();
	printf("test 2\n");
	if(ret < 0){
		perror("fork error");
		return -1;
	}
	else if(0 == ret){
		printf("test 3\n");
	}
	else if(ret > 0){
		sleep(1);
		printf("test 4\n");	
	}
	printf("test 5\n");
	return 0;
}
