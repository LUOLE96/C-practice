#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    char buf[128] = {0};
    int fds[2] = {0};
    if(pipe(fds) < 0){
        perror("pipe error");
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        return -1;
    }
    else if(0 == pid){
        bzero(buf,sizeof(buf));
        fgets(buf,sizeof(buf),stdin);
        int len = write(fds[1],buf,strlen(buf));
        printf("child process write : len = %d,buf = %s\n",len,buf);
    }
    else if(pid > 0){
        bzero(buf,sizeof(buf));
        int len = read(fds[0],buf,sizeof(buf) - 1);
        printf("parent process read : len = %d,buf = %s\n",len,buf);
        wait(NULL);
        close(fds[0]);
        close(fds[1]);

    }
    return 0;
}