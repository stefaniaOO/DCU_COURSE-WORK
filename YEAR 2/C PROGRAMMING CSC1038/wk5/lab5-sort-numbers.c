/*
program: lab5-sort-numbers.c
author: stefania omoede ogun
input: command line numbers
output: sorted numbers
date: 22/11/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//function prototype
int* Make_array(int argc, char* argv[]);
void Desc_sort(int* array, int length);
void Asc_sort(int* array, int length);
void Print_Array(int* array, int length);

//main driven function
int main(int argc, char *argv[])
{
	int length = argc - 3;
	char asc[] = "asc";  //in c double and single quotes are different "" for strings '' for single charachter
	char *Sorting_order = argv[argc - 1];
	int Array[length];

	for (int i = 0; i < argc - 3; ++i)
	{
		Array[i] = atoi(argv[i + 2]);	
    }

    int Ordered_list[argc - 3];

    if(strcmp(Sorting_order, asc) == 0)
    {
    	Asc_sort(Array, argc - 3);

    }
    else
    {
    	Desc_sort(Array, argc - 3);
    }

    Print_Array(Array, argc - 3);


return 0;
}
	
		
//function definition

void Desc_sort(int* array, int length) //bubble sort, takes array and sorts it in decending order
{
    int temp;
    for (int i = 0; i < length - 1; ++i) 
    {
        for (int j = 0; j < length - 1 - i; ++j)
         { 
            if (array[j] < array[j + 1]) 
            {  
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp; 
            }
        }
    }
}

void Asc_sort(int* array, int length) //bubble sort, takes array and sorts it in accending order
{
    int temp;
    for (int i = 0; i < length - 1; ++i) 
    {
        for (int j = 0; j < length - 1 - i; ++j)
         { 
            if (array[j] > array[j + 1]) 
            { 
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp; 
            }
        }
    }
}

void Print_Array(int* array, int length) //prints elements of array
{
	printf("%s", "Sorted numbers:");
	for (int i = 0; i < length; ++i)
	{
		printf(" %d", array[i]);
	}
	puts("");

}