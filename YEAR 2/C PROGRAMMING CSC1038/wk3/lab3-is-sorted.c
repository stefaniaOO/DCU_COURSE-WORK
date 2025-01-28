/*
program: lab3-is-sorted.c
author: stefania omoede ogun
input: command line arguments, integers
output: sorted integers
date: 16/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

//function prototype
void Sorted_numbers(int *array, int length);

int main(int argc, char *argv[])
{
	int length = argc - 1;
	int numbers[length]; //intialize array

	for(int i = 0; i < length; ++i)
	{
		numbers[i] = atoi(argv[i + 1]);  //iterating over array
		
	}

	Sorted_numbers(numbers, length); //calling created function 

	return 0;
}



//defining function

void Sorted_numbers(int *array, int length)
{
	for(int i = 0; i < length; ++i)
	{

	    
		for(int j = 0; j < length; ++j)
		{
		    int temp; 
	        temp = array[i]; //current value of array at position i

			if(array[i] < array[j])
			{
				array[i] = array[j]; // value of array at position i becomes value of array at position j
				array[j] = temp; //value of array at position j becomes previous value of array at positiom i stored in temp
			}
		}
	}


	for(int i = 0; i < length; ++i)
	{
		printf("%d\n", array[i] );

	}


}