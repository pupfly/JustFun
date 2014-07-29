/*
 * =====================================================================================
 *
 *       Filename:  join_thread.c
 *
 *    Description:  test code from textbook
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 09时38分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <pthread.h>

void assistant()
{
	int i = 0;
	printf("this function works as an assistant\n");
	for (; i < 10;i++)
	{
		printf("%d\n",i);
		sleep(1);
	}
	pthread_exit(0);
}
int main()
{
	pthread_t assistantthid;
	int status;
	pthread_create(&assistantthid,NULL,(void *) assistant,NULL);
	pthread_join(assistantthid,(void *) &status);
	printf("assistant thread's exit is caused %d\n",status);
	return 0;
}

