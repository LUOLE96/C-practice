#include <stdio.h>
#include <string.h>
//将命令运行的结果转到程序中，可以程序中处理运行结果
int main()
{
	FILE *fp = popen("wc","w");	//使用w模式时,使用的命令必须管道右边的命令
	if(NULL == fp)
	{
		perror("popen error");
		return -1;
	}

	const char *str = "hello popen\n";
	fwrite(str,strlen(str),1,fp);

	pclose(fp);
}
