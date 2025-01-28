
/*
program: lab5-get-a-country.c
author: stefania omoede ogun
input: command line argument
output: formated output of members of struct
date 23/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Country Country;

struct Country
{
	char *name[30]; //in  questo caso il nomve viene da argv[] visto che dobbiamo tipo rename argv[] lo mettiamo come pointer
	char *capital[30]; //stessa cosa
	float population;
	int size;
	
};

 int main(int argc, char  *argv[])
{
	Country country1 = {
		.name = argv[1],
		.capital = argv[2],
		.population = atof(argv[3]),
	    .size = atoi(argv[4])
	};

printf("%s\n", *country1.name);
printf("%s\n", *country1.capital);
printf("%.2f million people\n", country1.population);
printf("%d km2\n", country1.size);


	



	return 0;
}
