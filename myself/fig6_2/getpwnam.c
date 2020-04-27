#include <pwd.h>
#include <stddef.h>
#include <string.h>
#include "apue.h"

struct passwd *getpwnam(const char *name)
{
	struct passwd *ptr;
	
	setpwent();
	while ((ptr = getpwent()) != NULL)
		if (strcmp(name, ptr->pw_name) == 0)
			break;
	endpwent();
	
	return(ptr);
}

int main(int argc, char *argv[])
{
	struct passwd *ptr;
	
	if (argc < 2) {
		printf("usage: %s pwname\n", argv[0]);
		return -1;
	}
	
	if ((ptr = getpwnam(argv[1])) == NULL) {
		printf("Err: getpwnam failure!\n");
		return -1;
	}
	
	printf("name: %s, passwd:%s, uid:%d, gid:%d, gecos:%s, dir:%s, shell:%s\n",
			ptr->pw_name, ptr->pw_passwd, ptr->pw_uid, ptr->pw_gid,
			ptr->pw_gecos, ptr->pw_dir, ptr->pw_shell);
			
	return 0;
	
}