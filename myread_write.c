#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define _LINE_ 1
void myerror(const char *errstr,int line)
{
	fprintf(stderr,"line:%d ",line);
	perror(errstr);
	exit(1);
}
int myread(int fd)
{
	int len;
	int ret;
	int i;
	char buf[64];
	if (lseek(fd,0,SEEK_END)==-1)
	{
		myerror("lseek",__LINE__);
	}
	if ((len=lseek(fd,0,SEEK_CUR))==-1)
	{
		myerror("lseek",__LINE__);
	}
	if (lseek(fd,0,SEEK_SET)==-1)
	{
		myerror("lseek",__LINE__);
	}
	printf("len:%d",len);
	if (ret=read(fd,buf,len)<0)
	{
		myerror("read",__LINE__);
	}
	for (i=0;i<len;i++)
	{
		printf("%c",buf[i]);
	}
	printf("\n");
	return ret;
}
int main()
{
	int fd,len;
	char buf[32]="hello world!";
	if ((fd=open("test",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU))==-1)
	{
		myerror("open",__LINE__);
	}
	else
	{
		printf("creat file successfully\n");
	}
	if (write(fd,buf,strlen(buf))!=strlen(buf))
	{
		myerror("write",__LINE__);
	}
	myread(fd);
	printf("---------\n");
	if (lseek(fd,10,SEEK_END)==-1)
	{
		myerror("lseek",__LINE__);
	}
	if (write(fd,buf,strlen(buf))!=strlen(buf))
	{
		myerror("write",__LINE__);
	}
	myread(fd);
	close(fd);
	return 0;
}
