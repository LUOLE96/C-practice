#include <sys/mman.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
//共享内存：系统调用mmap(); 对文件进行写操作
#define MAPSIZE 1023

int main(int argc,char **argv)
{
	int fd = open(argv[1],O_RDWR | O_CREAT | O_TRUNC,0666);
	if(fd < 0)
	{
		perror("open error");
		return -1;
	}

	void *addr = mmap(NULL,MAPSIZE,PROT_WRITE,MAP_SHARED,fd,0);	//建立内存映射
	if(NULL == addr)
	{
		perror("mmap error");
		close(fd);
		return -1;
	}

	const char *str = "hello wrld linux abc dddddd\n";
	if(ftruncate(fd,strlen(str)) < 0)	//将文件扩容
	{
		perror("ftruncate error");
		munmap(addr,MAPSIZE);
		close(fd);
		return -1;
	}
	memcpy(addr,str,strlen(str));	//向文件中写入内容

	munmap(addr,MAPSIZE);	//解除内存映射
	close(fd);

    return 0;
}
