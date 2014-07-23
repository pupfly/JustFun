/*
 * =====================================================================================
 *
 *       Filename:  create_thread.c
 *
 *    Description:  test code from textbook
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 18时11分49秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int *thread(void *arg)
{
	pthread_t newthid;
	newthid = pthread_self();
	printf("this is a new thread ,thread ID is %u\n",newthid);
	return NULL;

}
int main(int argc, char *argv[])
{
	pthread_t thid;
	printf("main thread,ID is %u\n",pthread_self());
	if (pthread_create(&thid,NULL,(void *)thread,NULL) != NULL)
	{
		printf("thread creation fsiled\n");
		exit(1);
	}
	sleep(1);
	exit(0);
}

