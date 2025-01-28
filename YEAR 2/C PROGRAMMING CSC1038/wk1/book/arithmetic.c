/* 
program: arithmetic.c
author: stefania omoede ogun
input: 3 integers
output: sum, avarage, product, smallest and largest of the integers
date: 07/11/2024
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{

int number_1 = 0;
int number_2 = 0;
int number_3 = 0;

printf("Enter three different integers: ");

scanf("%d %d %d", &number_1, &number_2, &number_3);
 
 int sum = number_1 + number_2 + number_3;
 float avarage = (number_1 + number_2 + number_3) / 3;
 int product = (number_1 * number_2 * number_3);

 int smallest, largest;
 smallest = 0;
 largest = 0;

 if(number_1 > number_2 && number_2 > number_3)
 {
 	smallest = number_3;
 	largest = number_1;
 }

 else if(number_2 > number_3 && number_3 > number_1)
 {
 	smallest = number_1;
 	largest = number_2;
 }
 else
 {
 	smallest = number_2;
 	largest = number_3;
 }


printf("Sum is %d\nAvarage is %.0f\nProduct is %d\nSmallest is %d\nLargest is %d\n",sum, avarage, product,smallest, largest);
}