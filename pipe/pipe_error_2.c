#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//关闭读端写:导致进程异常结束
//关闭写端读:导致读不数据，并且不会阻塞
int main()
{
	int fds[2] = {0};
	int res = pipe(fds);	//创建无名管道
	if(res < 0)
	{
		perror("pipe error");
		return -1;
	}

#if 1
	close(fds[0]);
	const char *str = "hello world";
	int len = write(fds[1],str,strlen(str));
	printf("wirte to pipe len = %d,str = %s\n",len,str);
#endif

#if 0
	close(fds[1]);

	char buf[128] = {0};
	int len = read(fds[0],buf,sizeof(buf) - 1);		//从管道读取数据
	printf("read from pipe len = %d,str = %s\n",len,buf);
#endif
}
