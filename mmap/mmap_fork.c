#include <sys/ipc.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct student
{
	char name[16];
	int age;
}stu_t;

#define MAPSIZE 1023

int main(int argc,char **argv)
{
	pid_t pid = fork();
	if(pid < 0)
	{
		perror("fork error");
		return -1;
	}
	else if(0 == pid)
	{
		getchar();
		int fd = open(argv[1],O_RDONLY);
		if(fd < 0)
		{
			perror("open error");
			exit(0);
		}

		void *addr = mmap(NULL,MAPSIZE,PROT_READ,MAP_SHARED,fd,0);
		if(NULL == addr)
		{
			perror("mmap error");
			return -1;
		}

		stu_t stu = {0};
		memcpy(&stu,addr,sizeof(stu));
		printf("stu name = %s,age = %d\n",stu.name,stu.age);
		munmap(addr,MAPSIZE);
		close(fd);
	}
	else if(pid > 0)
	{
		int fd = open(argv[1],O_RDWR | O_CREAT | O_TRUNC,0600);
		if(fd < 0)
		{
			perror("open error");
			return -1;
		}

		void *addr = mmap(NULL,MAPSIZE,PROT_WRITE,MAP_SHARED,fd,0);
		if(NULL == addr)
		{
			perror("mmap error");
			close(fd);
			return -1;
		}

		stu_t stu = {"zhangsan",22};

		if(ftruncate(fd,sizeof(stu)) < 0)
		{
			perror("ftruncate eror");
			munmap(addr,MAPSIZE);
			close(fd);
			return -1;
		}
		memcpy(addr,&stu,sizeof(stu));
		wait(NULL);
        close(fd);
		munmap(addr,MAPSIZE);		
		unlink(argv[1]);
	}
}
