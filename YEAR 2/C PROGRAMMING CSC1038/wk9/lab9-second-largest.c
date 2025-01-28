/*
program: lab9-dot-product-two-vector.c
author: stefania omoede ogun
input: command line arguments, array of integers 
output: sum of the integers
date: 26/12/2024
took: 40 minutes
*/

#include <stdio.h>
#include <stdlib.h>

//function prototype
void Creat_Array(float* array, int length, char* argv[]);
float Largest_num(float* array, int length);



//main driven function
int main(int argc, char *argv[])
{
	float *pArray = NULL; //initialise pointer
	float *pResult = NULL;
	pArray = (float*)malloc(argc*(sizeof(float)));
	pResult = (float*)malloc(sizeof(float));

	if((!pArray) || (!pResult)) //handling lack of memory
	{
		puts("failed to allocate memory!");
		return 0;
	}

	Creat_Array(pArray, argc - 1, argv);
	*pResult = Largest_num(pArray, argc - 1);
	printf("%.1f\n", *pResult);

	free(pArray); //ALWAYS FREE THE MEMORY
	pArray = NULL;
	free(pResult);
	pResult = NULL;



	return 0;
}

//function definition

void Creat_Array(float* array, int length, char* argv[])
{
	for (int i = 0; i < length; ++i)
	{
		array[i] = atof(argv[i + 1]);
		
	}

}

float Largest_num(float* array, int length)
{
	float temp = 0;
	float second_largest;
	
	for (int i = 0; i < length; ++i)  //sort the array in descending order
	{

		for (int j = 0; j < length; ++j)
		{
			if(array[j] < array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] =  temp;

			}

			
		}
		
	}

	int i = 1; //initialise variable to one,
	while(array[i] == array[0]) //goes on till the previous number is the same as the first num
	{
		++i; //aumenta di uno
	}
	second_largest = array[i]; //second largest number in the array



	return second_largest; //returns float



}
