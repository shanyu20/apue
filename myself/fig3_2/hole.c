#include "apue.h"
#include "sys/stat.h"
#include "fcntl.h"

char	buf1[] = "abcdefghij";
char	buf2[] = "ABCDEFGHIJ";

int main(void)
{
	int fd;

	if ((fd = open("file.hole", O_RDWR | O_CREAT | O_TRUNC, FILE_MODE)) < 0)
		err_sys("create error");

	if (write(fd, buf1, 10) != 10)
		err_sys("buf1 write error");

	if (lseek(fd, 8*1024*1024, SEEK_SET) == -1)
		err_sys("lseek error");

	if (write(fd, buf2, 10) != 10)
		err_sys("buf2 write error");

	exit(0);
}
