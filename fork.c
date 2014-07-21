// =====================================================================================
// 
//       Filename:  fork.c
//
//    Description:  test of textbook
//
//        Version:  1.0
//        Created:  2014年07月21日 11时46分39秒
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
#include <stdlib.h>

int main()
{
	pid_t pid;
	int flag;
	printf("progress creation study\n");
	pid = fork();
	switch (pid)
	{
		case 0:printf("child process is running,Curpid is :%d,parentpig is %d\n",pid,getppid());break;
		case -1:perror("process creation falied\n");break;
		default:printf("parent process is running,childpid is %d\n",getpid());break;
	}
exit(0);
}

