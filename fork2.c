// =====================================================================================
// 
//       Filename:  fork2.c
//
//    Description:  test form internet
//
//        Version:  1.0
//        Created:  2014年07月21日 15时07分13秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================
#include<sys/types.h>  
#include<unistd.h>  
#include<stdio.h>  
#include <stdlib.h>
int global = 5;

int main()  
{  
    pid_t pid;  
	int cnt = 0,t = 0;  
    pid = vfork();  
    if(pid<0)  
        printf("error in fork!\n");  
    else if(pid == 0)  
    {  
		t = 0;
		while(t < 4)
		{
	        cnt++;
			global++;
			printf("global = %d\n",global);
	        printf("cnt = %d\n",cnt);  
	        printf("I am the child process,ID is %d\n",getpid());  
			t++;
		}
			exit(0);
	}  
    else  
    {  
		t = 0;
		while(t < 4)
		{
	        cnt++;
			global++;
			printf("global = %d\n",global);
	        printf("cnt = %d\n",cnt);  
	        printf("I am the father process,ID is %d\n",getppid());  
			t++;
		}
	}  
    return 0;  
}
