#include "apue.h"
#include <sys/wait.h>
#define		MAXNUM    6
#define 	MAXLEN	  16

int parseMoreArgv(char *buf, char *argv[])
{
	char *p = buf;
	char *p_prev = buf;
	char *pBuf = NULL;
	int i = 0;
	
	if (NULL == buf)
		return -1;
	
	while ((p = strchr(p_prev, ' ')) != NULL ||
			(p = strchr(p_prev, 0)) != NULL ) {
		pBuf = malloc(p-p_prev+1);
		if (pBuf == NULL)
			break;
		memset(pBuf, 0, p-p_prev+1);
		memcpy(pBuf, p_prev, p - p_prev);
		argv[i++] = pBuf;
		printf("argv[%d]=%s\n", i-1, argv[i-1]);
		if (i > MAXNUM || *p==0)
			break;
		p += 1;
		p_prev = p;
		while(*p_prev == ' ')
			p_prev++;
	}
	
	return 0;
}

int free_arg_buf(char *argv[])
{
	int i;
	
	for (i=0; i<MAXNUM; i++)
		if (argv[i] != NULL)
			free(argv[i]);
	
	return 0;
}

int main(void)
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;
	char	*argv[MAXNUM]={0};
	
	printf("%% ");
	while (fgets(buf, MAXLINE, stdin) != NULL) {
		buf[strlen(buf)-1] = 0;
		printf("buf len = %d: %s\n", (int)strlen(buf), buf);
		if (-1 == parseMoreArgv(buf, argv)) {
			err_ret("parse argv failure");
			exit(-1);
		}
		if ((pid = fork()) < 0)
			err_sys("fork error");
		else if (pid == 0) {
			execvp(argv[0], argv);
			err_ret("couldn't excute: %s", buf);
			exit(127);
		}
		
		/* parent */
		if ((pid = waitpid(pid, &status, 0)) < 0)
			err_sys("waitpid error");
		free_arg_buf(argv);
		memset(argv, 0, MAXNUM*sizeof(char *));
		printf("sub process return %d\n", status);
		printf("%% ");
	}
	
	exit(0);
}