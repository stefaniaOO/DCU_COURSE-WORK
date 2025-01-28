/* 
program: lab3-leap-year.c
author: stefania omoede ogun
input:
output:
date:
*/

#include <stdlib.h>
#include <stdio.h>

//function prototype

int main(int argc, char const *argv[])
{
	int start, finish;
	start = atoi(argv[1]);
	finish = atoi(argv[2]);

	for(int i = start; i <= finish; ++i)
	{
		if((i % 100 == 0) && (i % 400 == 0))
		{
			printf("%d\n", i );
		}
		else if((i % 100 != 0) && (i % 4 == 0))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}