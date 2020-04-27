#include "apue.h"
#include <sys/wait.h>

char *env_init[] = {"USER=unknown", "PATH=/tmp", NULL};

int main(void)
{
	pid_t		pid;
	
	if ((pid = fork()) < 0) {
		err_sys("fork error");
		printf("@@@@ only test!\n");
		exit(0);
	} else if (pid == 0) {
		if (execle("/home/cjb/MYD-Y6ULX-devel/test/apue/myself/fig8_17/echoall",
					"echoall", "myarg1", "MY_ARG2", (char *)0, env_init) < 0)
				err_sys("execle error");
	}
	
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");
	
	if ((pid = fork()) < 0) {
		err_sys("fork error");
		printf("#### only test!\n");
		exit(0);
	} else if (pid == 0) {
		if (execlp("echoall", "echoall", "only 1 arg", (char *)0) < 0)
			err_sys("execlp error");
	}
	
	exit(0);
}