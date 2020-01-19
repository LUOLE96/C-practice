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

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        return -1;
    }
    else if(pid == 0){    
        const char *str = "hello fifo";
        int len = write(fd,str,strlen(str));
        printf("child process write len = %d\n",len);
    }
    else if(pid > 0){
        char buf[128] = "";
        int len = read(fd,buf,sizeof(buf) - 1);
        printf("parent read len = %d,buf = %s\n",len,buf);
    }

    close(fd);
    unlink(argv[1]);
    return 0;
}