/*
program: ex2-array-degree.c
author: stefania omoede ogun
input: command line argument, array of integers
output: degree of the list of integers
date: 28/11/2024
*/

#include<stdio.h>
#include<stdlib.h>

/*Declare a structure of Values */
typedef struct Values Values;

struct Values {  //struct has two member a value and a count
	int Val; //stores the value
	int Count; //stores the number of appearences
	Values *next; //points to the next node
};


/*Functional prototype */
Values* add_value(Values *start, int n); //adds a value to a node
Values* new_value(int n); //adds a new node
void max_count(Values *start, int *max);
void print_value(Values *start);
void get_value(Values **start, int length, char **input);

int main(int argc, char* argv[])
{
	Values *start = NULL; //initializing pointer of type value to zero
	int MAX = 0; //initializing variable max of type int to zero
	int length = argc -1; //initializing variable length of type int to argc - 1
	get_value(&start, length, argv + 1); //calling function created
	max_count(start, &MAX);
	printf("%d\n", MAX); //calling print function to print degree of array
	return 0;
}


//function definition

Values* add_value(Values *start, int n)
{
		if(!start)
		{
			return new_value(n);
		}
		Values *lvalue = start;
		Values *prev = NULL;
		while((lvalue != NULL) && (lvalue -> Val != n))
		{
			prev = lvalue;
			lvalue = lvalue -> next;

		}
		if(lvalue != NULL)
		{
        lvalue -> Count += 1;
        return start;
        }

        else{
        prev -> next = new_value(n);
    }
    
    return start;


	
}


Values* new_value(int n)
{
    Values* result = (Values*)malloc(sizeof(Values));
    if(!result)
    {
    	printf("Not enough memory!");
    	exit(0);
    }
    
    result -> Val = n;
    result -> Count = 1;
    result -> next = NULL;
    return result;
}


void max_count(Values *start, int *max)
{
	if(start)
	{
		if(start -> Count > *max)
			*max = start -> Count;
		max_count(start -> next, max);
	}

}

void print_value(Values *start)
{
	if(start)
	{
		printf("%d %d\n", start -> Val, start -> Count);
		print_value(start -> next);

	}

}
void get_value(Values **start, int length, char **input)
{
	for (int i = 0; i < length; ++i)
	{
		*start = add_value(*start, atoi(*(input + i)));

	}

}