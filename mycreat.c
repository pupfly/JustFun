#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
int main()
{
	int fd;
	if (fd=open("example.c",(O_CREAT|O_WRONLY|O_TRUNC))==-1)
	{
		perror("open");
		exit(1);
	}
	else
	  printf("file has been created successfully !\n");
	close(fd);
	return 0;
}
