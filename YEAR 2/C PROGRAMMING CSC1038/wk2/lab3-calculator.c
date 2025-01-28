/* 
program: lab3-calculator.c
author: stefania omoede ogun
input: command line argument
output: float or invalid
date: 14/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	float firstfloat = atof(argv[2]);
	float secondfloat = atof(argv[3]);

	if(strcmp(argv[1], "multiply") == 0)
	{
		printf("%f\n", firstfloat * secondfloat );
	}
	else if((strcmp(argv[1], "divide") == 0)&& secondfloat != 0)
	{
		printf("%f\n", firstfloat/secondfloat );
	}
	else
	{
		puts("invalid" );
	}


	return 0;
}