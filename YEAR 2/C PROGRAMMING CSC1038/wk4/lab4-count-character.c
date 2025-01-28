/*
program: lab4-count-character.c
author: stefania omoede ogun
input: command line arguments char
output: integer
date 16/11/2024 */

#include <stdio.h>
#include <stdlib.h>

//function prototype
//input is a pointer to a char and pointer to an array of char
int Count_Characters(char *charachter, char *string_to_search); 

int main(int argc, char *argv[])
{
	/* made a pointer to the command line argument at position 1
	why not char *pCharachter = &argv[1] as that is how you point to an adress?
	that is becuase argv[] is already a pointer(any array name is a pointer), 
	it points to the  arguments in the command line  and as an "&"" implicite at the start
	like any array name so we do not need "&"". 
	so in the example a "abcxyza" argv[] is an array of char with 2 elements: 
	"a" which is an char and "abcxyza" which is another array of chars   */
	
	char *pCharachter = argv[1];
	char *pSentence = argv[2];



    /* we call the function Count_Charachters() that takes 2 pointers as input,
     2 cases:
     we have a pointer variable:
     int num = 8;
     int *pNum = &num;
     int this case we input the pointer like we do in our program;

     we do not have a pointer variable and just point directly:
     int num = 8;
     in this case we give the adress of the thing we are pointing to as input;
     int num =8;
     doublex(&num);
     */

	Count_Characters(pCharachter, pSentence);
	printf("%d\n", Count_Characters(pCharachter, pSentence));
	return 0;
}


int Count_Characters(char *charachter, char *string_to_search)
{
	int i = 0;
	int counter = 0;

	/* why not while(*string_to_search[i])? 
	after all we are asking for the value of the string we are pointing to
	and we learned that you get the adress of the thing we are pointing to
	by putting the pointer name alone without * ;
	this is because string_to_search is ALSO an array remeber? 
	in the function definition you have char *string_to_search that is already pointing to the array
	just like when you define argv in main, you use it in the same way, without the * */ 

	while(string_to_search[i])
	{
		/* while making a comparison here you need to rember to put * before charachter
		without it, it would point to the integer value of charachter (seems to just default to that)
		and not the char value, so you need to point to the value directly.
		you need to always put * in general but it seems that for char it doesnt raise an error just converts it to int type.
		also without it you would be comparing two different types:
		here you are comparing two char
		*/

		if(string_to_search[i] == *charachter)
		{
			++counter;
		}
		++i;
	}
	return counter;
}
