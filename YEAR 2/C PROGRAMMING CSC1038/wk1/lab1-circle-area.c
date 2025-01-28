/*
program: lab1-circle-area.c
author: stefania omoede ogun
input: radius
output: area
date: 07/11/2024
*/
#include <stdio.h>
#include<stdlib.h>

#define PI 3.1415 /* defining PI as a constant*/

int main(int argc, char *argv[])
{
	int radius = 0;
	float area = 0.0;

	radius = atoi(argv[1]);
	radius = radius*radius;

	area = radius*PI;

	printf("%.2f\n",area );


	return 0;
}