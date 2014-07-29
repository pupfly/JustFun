// =====================================================================================
// 
//       Filename:  fork1.c
//
//    Description:  test of textbook
//
//        Version:  1.0
//        Created:  2014年07月21日 13时00分03秒
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
#include <unistd.h>

int main(void)
{
	pid_t pid;
	int k,flag;
	char *msg;

	printf("process creat study\n");
	pid = fork();
	switch(pid)
	{
		case 0:
			msg = "child process is running";
			k = 5;
			flag = 1;
			break;
		case -1:
			perror("process creat failed\n");
			break;
		default:
			msg = "parent process is running";
			k = 3;
			flag = 2;
			break;
	}
	switch(flag)
	{
		case 1:
			while (k > 0)
				{
					puts(msg);
					sleep(1);
					k--;
				}
			exit(0);
			break;
		case 2:
			while (k > 0)
				{
					puts(msg);
					sleep(0.5);
					k--;
				}
	}
	exit(0);
}

