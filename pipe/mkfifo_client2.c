#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char **argv)
{
    int fd = open(argv[1],O_RDWR);
    if(fd < 0){
        perror("open error");
        return -1;
    }

	const char *str = "hello fifo";
	int len = write(fd,str,strlen(str));
	printf("write len = %d\n",len);

    close(fd);
    return 0;
}