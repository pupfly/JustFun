// =====================================================================================
// 
//       Filename:  fcntl.c
//
//    Description:  test of textbook
//
//        Version:  1.0
//        Created:  2014年07月19日 18时08分38秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void my_err(const char *err_str,int line)
{
	fprintf(stderr, "line: %d", line);
	perror(err_str);
	exit(1);
}

int main(int argc, char *argv[])
{
	int ret;
	int access_mode;
	int fd;
	
	if ((fd = open("example.c", O_CREAT | O_TRUNC | O_RDWR,S_IRWXU)) == -1)
	{
		my_err("open",__LINE__);
	}
	if ((ret = fcntl(fd, F_SETFL, O_APPEND)) < 0)
	{
		my_err("fcntl",__LINE__);
	}

	if ((ret = fcntl(fd, F_GETFL, 0)) < 0)
	{
		my_err("fcntl",__LINE__);
	}
	access_mode = ret & O_ACCMODE;
	if (access_mode == O_RDONLY)
	{
		printf("readonly");
	}
	if (access_mode == O_WRONLY)
	{
		printf("writeonly");
	}
	if (access_mode == O_RDWR)
	{
		printf("read+write");
	}
	if (ret & O_APPEND)
	{
		printf(".append");
	}

	if (ret & O_NONBLOCK)
	{
		printf(".nonblock");
	}

	if (ret & O_SYNC)
	{
		printf(".sync");
	}
	printf("\n");
	return;
}
