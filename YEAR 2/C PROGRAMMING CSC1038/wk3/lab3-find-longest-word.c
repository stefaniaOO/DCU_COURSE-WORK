/* 
program:
author:
input:
output:
date:
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//function prototype
char* split_string(char *sentence, int lenght);
void Longest_word(char * array, int lenght);

int main(int argc, char *argv[])
{
	int size = sizeof(argv[1])/sizeof(argv[1][0]);
	char sentence[size];
	strcpy(sentence, argv[1]);

	char phrase[50] = split_string(sentence, size);



	/* code */
	return 0;
}


char* split_string(char *sentence, int lenght)
{
	int i = 0;
	char *phrase = strtok(sentence, " ");
	char *new_array[lenght];
	while(phrase != NULL)
	{
		new_array[i++] = phrase;
		phrase = strtok(NULL, " ");
	}
	return *new_array; 


}
