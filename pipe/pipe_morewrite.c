#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
//无名管道写：追加写
int main()
{
	int fds[2] = {0};
	int res = pipe(fds);	//创建无名管道
	if(res < 0)
	{
		perror("pipe error");
		return -1;
	}

	const char *str = "hello";
	int len = write(fds[1],str,strlen(str));	//向管道写入数据
	printf("wirte to pipe len = %d,str = %s\n",len,str);

	str = " abc wrold";
	len = write(fds[1],str,strlen(str));	//向管道写入数据
	printf("wirte to pipe len = %d,str = %s\n",len,str);

	char buf[128] = {0};
	len = read(fds[0],buf,sizeof(buf) - 1);		//从管道读取数据
	printf("read from pipe len = %d,str = %s\n",len,buf);

	close(fds[0]);		//关闭管道
	close(fds[1]);
}
