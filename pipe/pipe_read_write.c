#include <stdio.h>
#include <unistd.h>
//管道：单工  无名管道：使用系统内存某个区域来给两个应用进程通信  命名管道：一种特殊的文件系统，用这个文件系统来进行进程间的通信
//使用规则：无名管道：只适用于有情缘关系的进程间的通信：父子进程
//        命名管道：在任意两个进程间的通信
//int pipe(int fds[2]);会产生两个描述符数组，有两个描述符
//fds[0]: 是固定的读端：read();
//fds[1]: 是固定的写端：write();
int main(void)
{
    int fds[2] = {0};
    int res = pipe(fds);//创建无名管道
    if(res < 0){
        perror("pipe error");
        return -1;
    }

    const char *str = "hello world";
    int len = write(fds[1],str,strlen(str));//向管道写入数据
    printf("write to pipe len = %d,str = %s\n",len,str);

    char buf[128] = {0};
    len = read(fds[0],buf,sizeof(buf) - 1);//从管道读取数据
    printf("read from pipe len = %d,str = %s\n",len,str);

    printf("fds[0] = %d,fds[1] = %d\n",fds[0],fds[1]);
    printf("write or read\n");

    close(fds[0]);
    close(fds[1]);

}