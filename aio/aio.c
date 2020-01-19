#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <aio.h>
#include <signal.h>

#define errExit(msg) {do {perror(msg);exit(EXIT_FAILURE);} while (0);}

#define errMsg(msg) {do {perror(msg);} while(0);}

struct ioRequest
{
	int reqNum;
	int status;
	struct aiocb *aiocbp;
};

int main(int argc,char *argv[])
{
    struct ioRequest *ioList;
    struct aiocb *aiocbList;
    struct sigaction sa;
    int numReqs;

    if(argc < 2){
        fprintf(stderr,"Usage : %s <pathname> <pathname>....\n",argv[0]);
        exit(EXIT_FAILURE);
    }

    numReqs = argc - 1;

    ioList = calloc(numReqs,sizeof(struct ioRequest));
    if(ioList == NULL){
        errExit("calloc");
    }
    aiocbList = calloc(numReqs, sizeof(struct aiocb));
	if(aiocbList == NULL)
		errExit("calloc");

    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    sa.sa_handler = quitHandler;
    if(sigaction(SIGQUIT, &sa, NULL) == -1)
		errExit("sigaction");
    
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = aioSigHandler;
	if (sigaction(IO_SIGNAL, &sa, NULL) == -1)
		errExit("sigaction");
    
    
}