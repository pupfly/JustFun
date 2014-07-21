#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	int fd;
	int i;
	int len;
	char buf[200];
	
	if ((fd = open("test1", O_RDWR | O_CREAT | O_TRUNC)) == -1)
	{
		perror("open");
		exit(0);
	}
	if (write(fd,"qwert",5)!=5)
	{
		perror("write");
		exit(0);
	}
/*	close(fd);
	if (fd=open("test1",O_RDONLY)==-1)
	{
		perror("open");
		exit(0);
	}
	else
	  printf("打开\n");*/
	if (lseek(fd,0,SEEK_END)==-1)
	{
		perror("lseek");
		exit(0);
	}
	if ((len=lseek(fd,0,SEEK_CUR))==-1)
	{
		perror("lseek");
		exit(0);
	}
	if (lseek(fd,0,SEEK_SET)==-1)
	{
		perror("lseek");
		exit(0);
	}
	if (read(fd,buf,len)<0)
	{
		perror("read");
		exit(0);
	}
	for (i=0;i<len;i++)
	  printf("%c",buf[i]);
	printf("读取成功\n");
	close(fd);
	return 0;
}
