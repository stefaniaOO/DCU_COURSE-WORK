/* 
program: gas.c
author: stefania omoede ogun
intput:
output:
date: 11/11/2024
*/

/*
 psudo code:

 enter gallons
 enter amount of miles driven
 output mile / gallon 
 repeat till -1 is inserted to stop the loop
 */

//wrong: doesnt stop after -1, it asks for miles too, also avarage is


#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int miles = 0;
	float gallons = 0;
	size_t counter = 1;
	size_t total = 0;
	
   while(gallons != -1)
   {


   printf("%s","Enter the gallons used (-1.0 to end): ");
   scanf("%f",&gallons);

   printf("%s","Enter the miles driven: ");
   scanf("%d", &miles);

   	printf("The miles/gallons for this tank was %f\n", miles/gallons);

   	counter++;
   	size_t miles_gallons = miles/gallons;
   	total = total + miles_gallons;



   }

   printf("the overall avarage miles/gallon was %ld\n %ld %ld",total/counter, total, counter );
}
