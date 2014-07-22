/*
 * =====================================================================================
 *
 *       Filename:  studyuid.c
 *
 *    Description:  test from textbook
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 11时39分20秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

int main()
{
	int fd;

	printf("uid study:\n");
	printf("process'uid: = %d,euid = %d\n",getuid(),geteuid());

	if ((fd = open ("1.c",O_RDWR)) == -1)
	{
		printf("Open failed,errno is %d : %s\n",errno,strerror(errno));
		exit(1);
	}
	else
	{
		printf("Open successfully!\n");
	}
	close(fd);
	return EXIT_SUCCESS;
}

