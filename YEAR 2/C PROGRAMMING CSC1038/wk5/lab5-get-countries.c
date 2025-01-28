
/*program: lab5-get-countries.c
author: stefania omede ogun
input: command line argument
output: formatted output of members of struct
date: 23/11/2024
*/

#include <stdlib.h>
#include <stdio.h>

// defining a new type
typedef struct Country Country;

//struct defintion
struct Country
{
	char *name[30];
	char *capital[30];
	float population;
	int size;
};

//function definition
void Add_member(Country *c1, int length, char* argv[]);
void Print_member(Country *c1, int length);

int main(int argc, char *argv[])
{
	int length = (argc - 1) / 4;
	Country country1[length];

	Add_member(country1, length, argv); //no need for * because country1 is an array of type country
	Print_member(country1, length);

	
	return 0;
}



void Add_member(Country *c1, int length, char* argv[])
{
	int count = 1;
	for (int i = 0; i < length; ++i)
	{
		*(c1)[i].name = argv[count];
		++count;
		*(c1)[i].capital = argv[count];
		++count;
		c1[i].population = atof(argv[count]);
		++count;
		c1[i].size = atoi(argv[count]);
		++count;
	}

}

void Print_member(Country *c1, int length)
{
	printf("%s\t\t\t%s\t\t\t%s\t\t\t%s\n","Country", "Capital", "Size", "Population" );
	for (int i = 0; i < length; ++i)
	{
		printf("%s\t\t\t%s\t\t\t%d\t\t\t%.2f\n", *(c1)[i].name, *(c1)[i].capital, c1[i].size, c1[i].population);
	}
}