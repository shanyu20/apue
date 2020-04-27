#include <sys/types.h>
#include <sys/wait.h>
#include "apue.h"

#ifdef SOLARIS
#define PSCMD	"ps -a -o pid,ppid,s,tty,comm"
#else
#define PSCMD	"ps -o pid,ppid,state,tty,command"
#endif

int main(void)
{
	pid_t	pid;
	
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid == 0) {
		printf("sub program exit!\n");
		exit(0);
	}
	
	//waitpid(pid, NULL, 0);
	sleep(4);
	system(PSCMD);
	printf("father program exit!\n");
	exit(0);
}