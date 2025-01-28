/*
program: sequence.c
author: stefania omoede ogun
input: sequence of integer
output: sum of all the integers
date: 11/11/2024
*/

#include <stdlib.h>
#include <stdio.h>

int main(void)
{

int sequence = 0;
scanf("%d",&sequence);
int total = 0;

for (size_t i = 0; i < sequence; ++i)
{
	int number = 0;
	scanf("%d", &number);
	total += number;

}
printf("The sum of all the integer in the sequence is %d\n",total );

}