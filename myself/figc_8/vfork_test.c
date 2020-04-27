#include "apue.h"
#include <unistd.h>

static void f1(void), f2(void);

int main(void)
{
	fputs("start to f1\n", stdout);
	f1();
	fputs("f1 to f2\n", stdout);
	f2();
	_exit(0);
}

static void f1(void)
{
	pid_t pid;
	if ((pid = vfork()) < 0)
		err_sys("vfork error");
	else if (pid == 0){
		fputs("output from child\n", stdout);
		fputs("sleep 5s\n", stdout);
		sleep(5);
	}
	else {
		fputs("output from parent\n", stdout);
		fputs("sleep 3s\n", stdout);
		sleep(3);
	}
}

static void f2(void)
{
	char	buf[1000];
	int 	i;
	
	for (i = 0; i < sizeof(buf); i++)
		buf[i] = 0;
}