/*
program: lab4-find-most-character.c
author: stefania omoede ogun
input:
output:
date: 18/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototype
void FindMOstChar(char *string, int lenght); //finds charachter with the most occurence in an array of char

int main(int argc, char *argv[])
{
	char *pString = argv[1]; //pointer to second command line argument
	int lenght = strlen(pString); //get lenght of array
	FindMOstChar(pString, lenght); //calling function created

	return 0;
}


//function definition
void FindMOstChar(char *string, int lenght)
{
	int Occurrence = 0;
	/*
	same as *pChar = &string[0] because array name is adress of first element
    & because you are pointing to the first char in array and not the entire array. 
    if you where pointing to the entire array *pChar = string would be used  as array name has implicit &, 
  
    if you remember we had an exercise where we did *pChar = argv[1] and the ARGV[1] was "a" a single char, so why did we not put %argv[1],
    thats because the argv[1] was an array of only 1 char "a", that "a" wasnt part of a larger array, it was its own thing

	*/

	char *pChar = string;

	for(int i = 0; i < lenght; ++i)
	{                                                                                                                                                    
		int count = 0;
		for (int j = i; j < lenght; ++j)
		{
			//32 is the ascii number of white space, we dont want the occurence of white space to be counted as one of the letters in the array
			if(string[j] != 32 && (string[j] - string[i] == 0))  
			{
				++count; //count increase by 1 if same char and not a space char
			}
	
	if(count >= Occurrence)
	   {
		    Occurrence = count;
		    *pChar = string[i];  //?? why, still dk
	    }	
	
		}


	}
	
   printf("%c\n", *pChar);


}