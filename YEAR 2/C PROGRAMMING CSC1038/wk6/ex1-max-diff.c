/*
program: ex1-max-diff.c
author: stefania omoede ogun
input: command line argument, array of int 
output: maximum difference
date: 11/12/2024

approach: i create an array with all command line argument,
then i make two function to get the smallest and largest number in the array
lastly i print thier difference
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//function prototype
void Create_array(int* Array,int argc, char* argv[]); //function creates array of int
int Min_num(int* Array,int argc);//function to get the smallest number in array of int
int Max_num(int* Array,int argc);//function to get the largest number in array of int

//main driven function
int main(int argc, char  *argv[])
{
  int Array_of_int[100]; //initializing array 
  Create_array(Array_of_int, argc, argv); //calling function to create array
  int MIN = Min_num(Array_of_int, argc);//initilising int variable to store result of function call
  int MAX = Max_num(Array_of_int, argc);//initilsinf int variable to store result of function call
  printf("%d\n", MAX - MIN); //printing difference of biggest and smallest number


  
  return 0;
}


//function declaration

void Create_array(int* Array,int argc, char* argv[])
{
  for (int i = 0; i < argc - 1; ++i)
  {
    Array[i] = atoi(argv[i + 1]);
  }
}
int Min_num(int* Array,int argc)
{

    int min = Array[0]; //inilializing min to the first element of the array
    for (int j = 0; j < argc - 1; ++j) //loop thorught array
    {
      if(min >= Array[j]) //checking wether min is smaller than the next element
      {
        min = Array[j]; //changing value of min if array at position j is smaller than min
      }
      
    }
  return min;
}


int Max_num(int* Array,int argc)
{

    int max = Array[0];
    for (int i = 0; i < argc - 1; ++i)
    {
      if(max <= Array[i])
      {
        max = Array[i];

      }

    }
    return max;
}