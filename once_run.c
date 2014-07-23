/*
 * =====================================================================================
 *
 *       Filename:  once_run.c
 *
 *    Description:  
 *
 *    test code from textbook in thread creation
 *
 *        Version:  1.0
 *        Created:  2014年07月23日 19时14分22秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_once_t once = PTHREAD_ONCE_INIT;


void run(void)
{
	printf("FUNCTION RUN IS RUNNING IN THREAD %u\n",pthread_self());
}

void *thread1(void *arg)
{
	pthread_t thid = pthread_self();
	printf("Current thread's ID is %u\n",thid);
	pthread_once(&once,run);
	printf("thread1 ends\n");
}

void *thread2(void *arg)
{
	pthread_t thid = pthread_self();
	printf("Current thread's ID is %u\n",thid);
	pthread_once(&once,run);
	printf("thread2 ends\n");
}


int main(int argc, char *argv[])
{
	pthread_t thid1,thid2;

	pthread_create(&thid1,NULL,thread1,NULL);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(3);
	printf("main thread exit !\n");
	
	exit(0);
}

