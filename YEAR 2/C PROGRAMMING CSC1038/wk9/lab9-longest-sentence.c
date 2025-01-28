/*
program: lab9-longest-sentence.c
author: stefania omeode ogun
input: command line argument, array of char
output: longest string
date: 26/12/2024
approach:
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototype
void Make_array(char *sentence, int argc, char* argv[], int* Array_length); //function to make array
void Longest_word(int* pWord_length, char* pSentence, int length); //compare charachter array and print th longest
void Memory_allocation(char** pSentence,int** pWord_length, int capacity); //allocates memory to pointer
//main driven function

int main(int argc, char *argv[])
{
	char *pSentence = NULL; //initializing pointer to null
	int *pWord_length = NULL;
	Memory_allocation(&pSentence,&pWord_length, argc - 1); //allocating memory needed to pointer 
	Make_array(pSentence, argc, argv, pWord_length); //creating an array
	Longest_word(pWord_length, pSentence, argc - 1);


	free(pSentence);
	free(pWord_length);

	return 0;
}







void Memory_allocation(char** pSentence, int** pWord_length, int capacity)
{
	*pSentence = (char*)calloc(capacity, sizeof(char));
	*pWord_length =(int*)calloc(capacity, sizeof(int));

	if(!(*pSentence)||!(*pWord_length)) //handeling memory faliure
	{
		puts("Not enough memory!");
		exit(0);
	}
//(In the function Memory_allocation, the pointers pSentence and pWord_length are local variables. 
	//Any modifications made to them will not affect the pointers in the main function because the memory is being allocated for copies of these pointers,
	// not for the actual pointers themselves.)


}

void Make_array(char *sentence, int argc, char* argv[], int* Array_length)
{
	for (int i = 0; i < argc - 1; ++i)
	{
		sentence[i] = *argv[i + 1];
		Array_length[i] = strlen(argv[i + 1]);
		printf("%s\n", sentence[i]);



	}



}


void Longest_word(int* pWord_length, char* pSentence, int length)
{
	int indices = pWord_length[0];

	for (int i = 0; i < length; ++i)
	{
		if(indices > pWord_length[i])
		{
			indices = pWord_length[i];
		}
	}


	
}

/*

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findMax(int *list, int length);
void printMax(char* argv[], int maxLength, int length);

int main(int argc, char * argv[])
{

	int length = argc - 1;
	int *lengthOfAllStrings = calloc(length, sizeof(int));

	for(int i = 0; i < length; ++i)
	{
		*(lengthOfAllStrings + i) = strlen(argv[i + 1]);
	}

	int maxLength = findMax(lengthOfAllStrings, length);
	printMax(argv, maxLength, length);

	return 0;
}


int findMax(int *list, int length)
{
	int max = *list;
	int position = 0;

	for(int i = 1; i < length; ++i)
	{
		if(max < *(list + i))
		{
			max = *(list + i);
			position = i;
		}
	}

	return max;
}

void printMax(char* argv[], int maxLength, int length)
{
	for(int i = 1; i <= length; ++i)
	{
		if(strlen(argv[i]) == maxLength)
		{
			printf("%s\n", argv[i]);
		}
	}
}