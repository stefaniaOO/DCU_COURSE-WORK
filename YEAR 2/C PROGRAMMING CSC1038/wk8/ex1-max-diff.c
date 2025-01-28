/*
program: ex1-max-diff.c
author: stefania omoede ogun
input: command line input, integers
output: max difference of command line integers
date: 25/11/2024
*/

//function prototype
void make_array(int* array, int argc, char *argv[]); //function to create int array
int max_number(int *array, int length); //function to find max number in an array
int min_number(int* array, int length); //function to find min number in an array
void difference(int* number1, int* number2); //function for integer difference

//main driver function
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int length = argc - 1;   //declaring variable length to argc - 1
	int numbers[length]; //initialazing an int array
	make_array(numbers, length, argv); //calling make_array function
	int MAX = max_number(numbers, length); //decaring variable max to value returned by function max_number
	int MIN = min_number(numbers, length); //declaring variable min to value returned by function min_number

	difference(&MAX, &MIN); //calling function difference to print difference


	return 0;
}




//function declaration

void make_array(int* array, int argc, char *argv[])
{
	//loops trought argv and converts elements of argv into intgers
	for (int i = 0; i < argc; ++i) 
	{
		array[i] = atoi(argv[i + 1]);
	}

}

int max_number(int* array, int length)
{
	int max = 0; //initlializing max variable to 0
	for (int i = 0; i < length; ++i)
	{
		if(array[i] > max) //looping through array to find the biggest number 
		{
			max = array[i]; //setting  max to biggest number in array
		}
		
	}
	return max; //returning max
}

int min_number(int* array, int length)
{
	int min = array[0]; //initializing min variable to 0
	for (int i = 0; i < length; ++i) 
	{
		if(array[i] < min) //looping through array to find the biggest number
		{
			min = array[i]; //setting min to smallest number in array
		}
		
	}

	return min; //returning min
}

void difference(int* number1, int* number2)
{
	printf("%d\n", *number1 - *number2 ); //printing difference between two numbers
}