/*
program: lab2-count-odd-number.c
author: stefania omoede ogun
input: command line argument: integers
output: number of odd integers
date: 11/11/2024
*/


#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
  int length = 10;
  int array[length];
  int count = 0;

  for(size_t i = 0; i < argc - 1; ++i)
    {
      array[i] = atoi(argv[i + 1]);
    }

  for(size_t i = 0; i < argc; ++i)
    {
      if((array[i] % 2) != 0)
      {
        ++count;
      }
    }
  printf("%d\n", count);

  return(0);
}
                                                                  
