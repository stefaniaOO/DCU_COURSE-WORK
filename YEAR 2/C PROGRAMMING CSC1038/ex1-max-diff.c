//author: stefania omoede ogun
//31/10/2024
//finding the maximum difference value


#include <stdlib.h>
#include <stdio.h>

//function prototype

int FindMax(int argc, char*argv[]); //function to find the maximum value in the array
int FindMin(int argc, char*argv[]); // function to find the minimum value in the array
int MaxDiff(int max, int min);// function to find maximum difference

/* main body of the code */

int main(int argc, char * argv[])
{
  char *Array_to_search[100]; //initlialazing array to maximum 100 elements

/* creating an array of integer from elements from the comand line */
  for(int i = 0; i < argc -1; ++i)
  {
    Array_to_search[i] = argv[i];
  }
/* storing value from function created in a variable */

   int max = FindMax(argc, Array_to_search);
   int min = FindMin(argc,Array_to_search);

  printf("%d\n", MaxDiff(max,min));

  return 0;
}


// implementation FindMax function
int FindMax(int argc, char * argv[])
{
  int max = 0;
  for(int i = 0; i < argc -1; ++i)
  {
    if(atoi(argv[i]) > max)
  {
     max = atoi(argv[i]);
  }
}
  return max;
}


//implementation min FindMin function

int FindMin(int argc, char*argv[])
{
  int smallest = 0;
  for(int i = 0; i < argc - 1; ++i)
  {
   if (smallest > atoi(argv[i]))
  {
    smallest = atoi(argv[i]);
  }

}
 return smallest;

}


//implementation of MaxDiff function

int MaxDiff(int max, int min)
{
  return max - (min);
}
