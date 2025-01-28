/* 
program: lab3-search-number.c
author: stefania omoede ogun
input: command line: int 
output: int 
date: 16/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

//function prototype
void findNumb(int *array, int length, int num_to_search); // finds number and output position

int main(int argc, char *argv[])
{
  int length = argc - 2; //length of the int array
  int number[length];
  int num_to_search = atoi(argv[1]); //initialize array to zero

  for(int i = 0; i < length; ++i)
  {
    number[i] = atoi(argv[i + 2]); //iterate over array

  }

  findNumb(number, length - 1, num_to_search); //function to find number

  return 0;
}


void findNumb(int *array, int length, int num_to_search)
{
  int i = 0; //initialize int to zero

  while(array[i] != num_to_search) //loops as long as array at postion i is different from number that we are searching
  {
    ++i;
  }
  printf("Found %d at %d\n", num_to_search, i ); //prints new value of i and number searched

}