 /*
 program: lab2-cylinder-area.c
 author: stefania omoede ogun
 input: 2 numbers, a radius and a heigth
 output: 
 date: 11/11/2024
*/


#include <stdlib.h>
#include <stdio.h>
#define PI 3.1415


int main(int argc, char const *argv[])
{
    int radius, height;



    if(argc < 2)
        {
            puts("No input given!");
        }
        

    else if(argc < 3)
        {
            puts("Two arguments needed!");
        }


    radius = atof(argv[1]);
    height = atof(argv[2]);

    if(radius < 0 || height < 0)
    {
        puts("The radius or height cannot be negative!");
    }

    else
    {
       float area = (2 * PI * radius * height) + (2 * PI * radius * radius);
       printf("%.2f\n", area);
    }
    
    return 0;
}