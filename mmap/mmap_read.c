#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/mman.h>
//共享内存：系统调用mmap(); 对文件进行读操作

#define MAPSIZE 1023

int main(int argc,char **argv)
{
    int fd = open(argv[1],O_RDONLY);
    if(fd < 0){
        perror("open error");
        return -1;
    }

    void *addr = mmap(NULL,MAPSIZE,PROT_READ,MAP_SHARED,fd,0);//建立内存映射
    if(NULL == addr){
        perror("mmap error");
        close(fd);
        return -1;
    }

    char buf[MAPSIZE + 1] = {0};
    memcpy(buf,addr,MAPSIZE);//读文件
    printf("buf = %s\n",buf);

    munmap(addr,MAPSIZE);
    close(fd);
}