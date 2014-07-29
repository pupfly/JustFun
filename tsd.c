/*
 * =====================================================================================
 *
 *       Filename:  tsd.c
 *
 *    Description:  code from textbokk
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 11时47分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  pupengfei, 792570367@qq.com
 *        Company:  NONE
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_key_t key;

void *thread2(void *arg)
{
	int tsd = 5;
	int a = 10;
	printf("thread %d is running\n",pthread_self());
	pthread_setspecific (key,(void *)tsd);
	printf("thread %d returns %d\n",pthread_self(),pthread_getspecific(key));
	pthread_setspecific (key,(void *) a);
	printf("thread %d returns %d again\n",pthread_self(),pthread_getspecific(key));
}

void *thread1(void *arg)
{
	int tsd = 0;
	pthread_t thid2;
	printf("thread %d is running\n",pthread_self());
	pthread_setspecific (key,(void *) tsd);
	pthread_create(&thid2,NULL,thread2,NULL);
	sleep(2);
	printf("thread %d returns %d\n",pthread_self(),pthread_getspecific(key));
}

int main()
{
	pthread_t thid1;
	printf("main thread begains running\n");
	pthread_key_create(&key,NULL);
	pthread_create(&thid1,NULL,thread1,NULL);
	sleep(3);
	pthread_key_delete(key);
	printf("main thread exit\n");
	return 0;
}

