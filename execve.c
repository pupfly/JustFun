// =====================================================================================
// 
//       Filename:  execve.c
//
//    Description:  test from textbook
//
//        Version:  1.0
//        Created:  2014年07月22日 08时57分56秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc,char *argv[],char **environ)
{
	pid_t pid;
	int stat_val;
	printf("executive example!\n");
	pid = fork();
	switch(pid)
	{
		case -1:perror("process creation failed\n");
				exit(1);
		case 0:
				printf("child process is running\n");
				printf("My pid = %d,parent pid = %d\n",getpid(),getppid());
				printf("uid = %d,gid = %d\n",getuid(),getgid());
				execve("processimage",argv,environ);
				printf("process never go to here !\n");
				exit(0);
		default:printf("parent process is running !\n");
				break;
	}
	wait(&stat_val);
	exit(0);
}

