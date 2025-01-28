/*
program: lab3-findMax.c
author: stefania omoede ogun
input: command line, integers
output: largest number
date: 16/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

//function prototype
int Max(int *array, int length); // takes in 2 arguments, an int array and the length of the array


int main(int argc, char *argv[])
{

  int number[argc - 1]; //initialize int array to zero with size of number of arguments

  for(int i = 0; i < argc - 1; ++i)
  {
    number[i] = atoi(argv[i + 1]); //iterate over array
  }
  int biggest_num = Max(number, argc -1);
  printf("%d\n", biggest_num);

  
  return 0;
}

int Max(int *array, int length) // find largest number in the int of array
{
  int max = 0; //initialize int to zero
  for(int i = 0; i < length; ++i) // iterate througt the whole array
  {
    if(array[i] > max)
    {
      max = array[i];
    }
    else
    {
      max = max;
    }


  }
return max;


}
