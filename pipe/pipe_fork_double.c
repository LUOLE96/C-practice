#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    char buf[128] = {0};
    int fds1[2] = {0};
    int fds2[2] = {0};
    if(pipe(fds1) < 0){
        perror("pipe error");
        return -1;
    }

    if(pipe(fds2) < 0){
        perror("pipe error");
        return -1;
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork error");
        return -1;
    }
    else if(0 == pid){
        int len = -1;
        while(strncmp(buf,"quit",4))
        {
            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            len = write(fds1[1],buf,strlen(buf));
            printf("child process write : len = %d,buf = %s\n",len,buf);

            bzero(buf,sizeof(buf));
            len = read(fds2[0],buf,sizeof(buf) - 1);
            printf("child process read : len = %d,buf = %s\n",len,buf);
        }
    }
    else if(pid > 0){
        int len = -1;
        while(strncmp(buf,"quit",4)){
            bzero(buf,sizeof(buf));
            len = read(fds1[0],buf,sizeof(buf) - 1);
            printf("parent process read : len = %d,buf = %s\n",len,buf);

            bzero(buf,sizeof(buf));
            fgets(buf,sizeof(buf),stdin);
            len = write(fds2[1],buf,strlen(buf));
            printf("parent process write : len = %d,buf = %s\n",len,buf);
        }
        wait(NULL);
        close(fds1[0]);
        close(fds1[1]);
        close(fds2[0]);
        close(fds2[1]);
    }
}