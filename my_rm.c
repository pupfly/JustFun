// =====================================================================================
// 
//       Filename:  my_rm.c
//
//    Description:  test from textbook
//
//        Version:  1.0
//        Created:  2014年07月19日 17时00分04秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void my_error(const char *err_str ,int line)
{
	fprintf(stderr, "line:%d ", line);
	perror(err_str);
	exit(1);
}

int my_read(int fd)
{
	int len;
	int ret;
	int i;
	char read_buf[64];

	if (lseek(fd, 0, SEEK_END) == -1)
	{
		my_error("lseek", __LINE__);
		exit(1);
	}
	if ((len = lseek(fd, 0 ,SEEK_CUR)) == -1)
	{
		my_error("lseek", __LINE__);
		exit(1);
	}

	if (lseek(fd, 0, SEEK_SET) == -1)
	{
		my_error("lseek", __LINE__);
		exit(1);
	}
	printf("length:%d\n",len);
	if ((ret = read(fd, read_buf, len)) < 0)
	{
		my_error("read", __LINE__);
		exit(1);
	}
	for (i = 0;i < len;i++)
	{
		printf("%c",read_buf[i]);
	}
	printf("\n");
	return ret;
}
int main(int argc, char **argv)
{
	int fd;
	char write_buf[strlen(argv[1] + 1)];
	strncpy(write_buf, argv[1], strlen(argv[1]));

	if ((fd = open("example.c", O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1)
	{
		my_error("open",__LINE__);
	}
	else
	{
		printf("creat file successfully !\n");
	}
	if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))
	{
		my_error("write", __LINE__);
	}
	my_read(fd);
	printf("--------------\n");
	if (lseek(fd, 10, SEEK_END) == -1)
	{
		my_error("lseek",__LINE__);
	}
	if (write(fd, write_buf, strlen(write_buf)) != strlen(write_buf))
	{
		my_error("write", __LINE__);
	}
	my_read(fd);
	close(fd);
	return 0;
}

