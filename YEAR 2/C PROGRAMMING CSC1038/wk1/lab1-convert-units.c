/* 
program: lab1-convert-units.c
author: stefania omoede ogun
input: amount in centimeters
output: amount in inches
date: 07/11/2024
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{

  int centimeter;
  float inches;

  centimeter = atoi(argv[1]);
  inches = centimeter/2.54;

  printf("%.2f\n",inches);
  
  return 0;
}