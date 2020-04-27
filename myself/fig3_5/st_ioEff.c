#include "apue.h"

//#define BUFFSIZE 1


int main(void)
{
	int		n;
//	char 	buf[BUFFSIZE];

	while ((n = fgetc(stdin)) != EOF)
		if (fputc(n, stdout) == EOF)
			err_sys("write error");
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
