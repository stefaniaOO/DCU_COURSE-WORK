/*
program: lab5-cal-everything.c
author: stefania omoede ogun
input: command line arguments, two integers
output:  different calculation
date: 19/11/2024
*/

//include
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//function prototype
float Sum(int *a, int *b); 
float Difference(int *a, int *b);
float Product(int *a, int *b);
float Division(int *a, int *b);
float Power(int *a, int*power);
//float Natural_log(float(*log1)(double, double), float(*log2)(double, double)); //arguments are two pointer to two functions
float Natural_log(int *a, int *b);

//main driver function
int main(int argc, char const *argv[])
{
	int number1 = atoi(argv[1]); //initial value for a
	int number2 = atoi(argv[2]); //initial value for b
	float result = 0; //initial value for result

	float(*pFunction)(int* , int*) = NULL; //you initialise a pointer to an function
	pFunction = Sum; //you assign the pointer to a function by writing the name
	result = pFunction(&number1, &number2); //you use the pointer name instead of the function name
	printf("%.2f\n", result);

	pFunction = Difference;
	result = pFunction(&number1, &number2);
	printf("%.2f\n", result);

	pFunction = Product;
	result = pFunction(&number1, &number2);
	printf("%.2f\n", result);

	pFunction = Division;
	result = pFunction(&number1, &number2);
	printf("%.2f\n", result);

	pFunction = Power;
	result = pFunction(&number1, &number2);
	printf("%.2f\n", result );

	pFunction = Natural_log;
	result = pFunction(&number1,&number2);
	printf("%.2f\n", result);



	/* code */
	return 0;
}


//function definition
float Sum(int *a, int *b) //returns sum of two integer as a float
{
	float sum = *a + *b;
	return sum;

}


float Difference(int *a, int *b) //returns difference of two integers as a float
{
	float difference = *a - *b;
	return difference;
}


float Product(int *a, int *b) //returns product of two integers as a float
{
	float product = *a * *b;
	return product;
}


float Division(int *a, int *b) //returns division of two integers as a float
{
	/*float division = *a / *b; //does int division and then converts to float thats whit u get 3.00 instead of 3.33
	return division;*/

	return (float)*a / *b;

	//same as the thing below
	//float ei = *a;
	//float bi = *b;
	//return ei/bi;
}

float Power(int *a, int *power)
{
	float results = 0;
	results = pow(*a, *power);
	return results;
	/*float results = 0; //i dont know why but pow() isnt working

	for(int i = 0; i < *power; ++i)
	{
		results = results + (*a * *a);
		return results;
	}*/
}

float Natural_log(int *a, int *b)
{
	float natural_log = 0;
	natural_log = log(*a) + log(*b); //for some reason will raise an error if you dont put -lm at the end before compiling
	return natural_log;
}