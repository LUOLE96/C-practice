#include <stdio.h>
#include <string.h>
//将命令运行的结果转到程序中，可以程序中处理运行结果
int main(void)
{
    FILE *fp = popen("cat /etc/passwd","r");//如果使用r模式，则第1个参数的命令必须有输出
    if(NULL == fp){
        perror("popen error");
        return -1;
    }

    char buf[128] = "";
    while(fread(buf,1,sizeof(buf) - 1,fp) > 0){
        printf("%s",buf);
        bzero(buf,sizeof(buf));
    }
    pclose(fp);
}