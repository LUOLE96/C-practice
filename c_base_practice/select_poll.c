#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <stdlib.h>
#include <sys/time.h>

//使用select解决服务器多并发问题
#define MAXCOUNT 50//最多监控描述符数

int main(int argc,char **argv)
{
    int sid = socket(AF_INET,SOCK_STREAM);
    if(sid < 0){
        perror("socket error");
        return -1;
    }

    struct sockaddr_in saddr = {0};
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(atoi(argv[2]));
    saddr.sin_addr.s_addr = inet_addr(argv[1]);

    if(bind(sid,(struct sockaddr *)&saddr,sizeof(saddr)) < 0){
        perror("bind error");
        return -1;
    }

    if(listen(sid,10) < 0){
        perror("listen error");
        return -1;
    }

    int fds[MAXCOUNT] = {0};//描述符数组
    fds[0] = sid;//将sid加入到描述符数组
    fd_set rset = {0};
    struct timeval tim = {0};

    char buf[128] = {0};
    int maxfd,i,cid = -1,count = 1;

    

    return 0;
}
