#include "apue.h"

//#define BUFFSIZE 1


int main(void)
{
	char 	buf[MAXLINE];

	while (fgets(buf, MAXLINE, stdin) != NULL)
		if (fputs(buf, stdout) == EOF)
			err_sys("output error");
	if (ferror(stdin))
		err_sys("input error");
/*(
	if (n < 0)
		err_sys("read error");
	else if (n == 0)
		printf("read over\n");
*/
	exit(0);
}
