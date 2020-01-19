#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fds[2] = {0};
    if(pipe(fds) < 0){//无名管道不能用于非情缘关系间的进程通信
        perror("pipe error");
        return -1;
    }
    printf("fds[0] = %d,fds[1] = %d\n",fds[0],fds[1]);
    char buf[128] = "";
    int len = read(fds[0],buf,sizeof(buf) - 1);
    printf("read len = %d,buf = %s\n",len,buf);

    close(fds[0]);
    close(fds[1]);
}