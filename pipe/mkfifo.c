#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
    if(mkfifo(argv[1],0666) < 0){
        perror("mkfifo error");
        return -1;
    }

    int fd = open(argv[1],O_RDWR);
    if(fd < 0){
        perror("open error");
        return -1;
    }

    const char *str = "hello fifo";
    int len = write(fd,str,strlen(str));
    printf("write len = %d\n",len);

    char buf[128] = "";
    len = read(fd,buf,sizeof(buf) - 1);
    printf("read len = %d,buf = %s\n",len,buf);

    close(fd);
    unlink(argv[1]);
}