/*
program: lab9-dot-product-two-vector.c
author: stefania omoede ogun
input: command line arguments, array of integers 
output: sum of the integers
date: 26/12/2024
approach:
*/

#include <stdio.h>
#include <stdlib.h>

//function prototype

void Create_vectors(int* Vector1, int* Vector2, int argc, char* argv[]);
int dot_product(int *Vector1, int *Vector2, int length); 


//main driven function
int main(int argc, char *argv[])
{
	int *pVector1 = NULL; //need to initialize pointer first
	int *pVector2 = NULL;


	pVector1 = (int*)calloc(argc, sizeof(int)); //then assign memory to pointer array
	//pVector1 = (int*)malloc(argc* (sizeof(int))); //doing the same thing but with malloc
	pVector2 = (int*)calloc(argc, sizeof(int));


    // code to deal with memory allocation faliure
	if((!pVector1)||(!pVector2))
	{
		puts("Failed to allocate memory!");
		free(pVector2); 
		free(pVector1);
		exit(0);
	}

	Create_vectors(pVector1, pVector2, argc, argv);
	printf("%d\n", dot_product(pVector1, pVector2, atoi(argv[1])));
	



	return 0;
}



void Create_vectors(int* Vector1, int* Vector2, int argc, char* argv[])
{
	int arraysize = atoi(argv[1]);
	for (int i = 0; i < arraysize; ++i)
	{
		Vector1[i] = atoi(argv[i + 2]);
		
	}
	for (int i = 0; i < arraysize; ++i)
	{
		Vector2[i] = atoi(argv[arraysize + 2 + i]);
	
	}
}


int dot_product(int *Vector1, int *Vector2, int length)
{
	int DotProduct = 0;
	int temp = 0;
	for (int i = 0; i < length; ++i)
	{
		temp = Vector1[i] * Vector2[i];
		DotProduct += temp;
	}

return DotProduct;

}