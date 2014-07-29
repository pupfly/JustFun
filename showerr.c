/*
 * =====================================================================================
 *
 *       Filename:  showerr.c
 *
 *    Description:  code from textbook
 *
 *        Version:  1.0
 *        Created:  2014年07月28日 16时09分26秒
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
#include <string.h>
#include <errno.h>

FILE *openfile(char *filename)
{
	FILE *stream;
	errno = 1;
	stream = fopen(filename, "r");
	if (stream == NULL)
	{
		printf("cannot open the file:%s.reason:%s\n",filename, strerror(errno));
		exit(-1);
	}
	else
	{
		return stream;
	}
}
int main()
{
	char *filename = "test";
	
	openfile (filename);
	return 0;
}

