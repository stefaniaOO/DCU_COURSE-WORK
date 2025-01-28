/*
program: lab6-countries-cities.c
author: stefania omoede ogun
input: command line arguments
output:
date: 11/12/2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct definition
typedef struct Country Country;
typedef struct City City;

struct City
{
	char *city_name[50];
	float size;
};
struct Country
{
	char *name[50];
	City city_list[];
};


//function prototype
void Create_array_of_cities(City *city, int number_of_cities, char *argv[]);
void Create_array_of_countries(Country *c[], int number_of_country, City *city);


int  main(int argc, char *argv[])
{
	int size = (argc - 1) / 7;
	City cities[size];
	City *pCity = cities;
	Country countries[size];
	Country *pCountries = countries;

	Create_array_of_cities(pCity, size, argv);
	Create_array_of_countries(&pCountries, size, pCity);






	return 0;
}

void Create_array_of_cities(City city[], int number_of_cities, char *argv[])
{
	int count = 2;
	for (int i = 0; i < number_of_cities; ++i)
	{
		*(city)[i].city_name = argv[count];
		++count;
		city[i + 1].size = atof(argv[count]);
		++count;
	}

}

void Create_array_of_countries(Country *c[], int number_of_country, City *city)
{
	int count = 1;
	for (int i = 0; i < number_of_country; ++i)
	{
		while()

		/* code */
	}

}
