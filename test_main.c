// =====================================================================================
// 
//       Filename:  test_main.c
//
//    Description:  test for main's environment
//
//        Version:  1.0
//        Created:  2014年07月21日 20时23分08秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:  pupengfei, 
//        Company:  
// 
// =====================================================================================

#include <stdio.h>



int main(int argc, char *argv[],char **envp)
{
	int i;
	for (i = 0;envp[i] != NULL;i++)
	{
		printf("%s\n",envp[i]);
	}

	return 0;
}

