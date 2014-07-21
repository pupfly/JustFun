// =====================================================================================
// 
//       Filename:  processimage.c
//
//    Description:  test from textbook
//
//        Version:  1.0
//        Created:  2014年07月21日 20时38分59秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[],char **environ)
{
	int i;
	printf("I am a prpcess image!\n");
	printf("my pid = %d,parentpid = %d\n",getpid(),getppid());
	printf("uid = %d,gid = %d\n",getuid(),getgid());

	for (i = 0;i < argc;i++)
		printf("argv[%d]:%s\n",i,argv[i]);
	return 0;
}

