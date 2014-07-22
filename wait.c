/*
 * =====================================================================================
 *
 *       Filename:  wait.c
 *
 *    Description:  my own test for function wait()
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 10时21分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid_t child_pid;
	int stat_val;
	int i = 0;
	char *msg = "child process rnning,parent process waiting!";
	pid = fork();

	switch(pid)
	{
		case -1:
		    	printf("创建子进程失败\n");
			    exit(0);
		case 0:
			   while(i < 5)
			   {
				   puts(msg);
				   i++;
				   sleep(1);
			   };
			   break;
		default:printf("父进程等待子进程结束!\n");
				pid_t child_pid;
				child_pid = wait(&stat_val);
				printf("child process terminaled,child pid = %d\n",child_pid);
	}

	return EXIT_SUCCESS;
}

