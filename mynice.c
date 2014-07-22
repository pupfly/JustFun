/*
 * =====================================================================================
 *
 *       Filename:  mynice.c
 *
 *    Description: test from textbook 
 *
 *        Version:  1.0
 *        Created:  2014年07月22日 12时01分04秒
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
#include <sys/resource.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;
	int stat_val = 0;
	int oldpri,newpri;

	printf("nice study!\n");

	pid = fork();
	switch(pid)
	{
		case 0:
			printf("child is running,curpid = %d,parent pid is %d\n",pid,getppid());
			oldpri = getpriority(PRIO_PROCESS,0);
			printf("old priority = %d\n",oldpri);

			newpri = nice(2);
			printf("new priority = %d\n",newpri);
			exit(0);
		case -1:
			perror("process creation failed\n");
			break;
		default:
			printf("parent is running,child is %d,parentpid is %d\n",pid,getppid());
			break;
	}
	wait(&stat_val);
	exit(0);
}

