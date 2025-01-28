 /*
program: lab3-string-reverse.c
author: stefania omoede ogun
input: command line argument: array of char
output:  array of char in reversed order
date: 14/11/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//char phrase[50];
	//strcpy(phrase, argv[1]);
	int lenght = strlen(argv[1]);
	char reverse_phrase[lenght-1];
	
	int j = 0;

	for(int i = lenght; i >= 0; --i)
	{

		reverse_phrase[j] = argv[1][i];
		++j;	
	}
     printf("%s\n", reverse_phrase);
	return 0;
}