/*
program: lab3-duplicate-number.c
author: stefania
input:
ouput:
date: 15/11/2024
*/

#include <stdio.h>
#include<stdlib.h>

//function prototype
int duplicate(int *array, int length);

int main(int argc, char *argv[])
{
	int length = argc -1;
	int numbers[length];

	for(int i = 0; i < length; ++i)
	{
		numbers[i] = atoi(argv[i + 1]);

	}

    int found = duplicate(numbers, length); // put found = to result of the function that is either the number we found or 0;

    // if statement
    if(found == 0)
    {
    	puts("no duplicated number");
    }
    else
    {
    	printf("%d\n", found );
    }    

	return 0;
}

// function declaration

int duplicate(int *array, int length)
{
	int duplicate = 0;
	for(int i = 0; i < length; ++i)
	{


		for(int j = i + 1; j < length; ++j) // j = i + i and not j = 0 because you already searched backwards, so you dont need to search the previous number again because its definetly not there
		{
			if(array[j] == array[i])
			{
				duplicate = array[i];
				return duplicate;
			}
		}

	}
	return 0;
}