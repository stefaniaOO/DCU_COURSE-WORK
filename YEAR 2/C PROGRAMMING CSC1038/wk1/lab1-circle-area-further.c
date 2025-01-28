/*
program: lab1-circle-area.c
author: stefania omoede ogun
input: radius
output: area of circle
data: 07/11/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define PI 3.1415
int main(int argc, char *argv[]){
  /*making sure that 2 arguments are given */
  if(argc == 1){
    puts("No input given!");
      }
  else if(argc == 2){
    puts("Two arguments needed!");
      }
  else{
    int radius = 0;
    int height = 0;
    radius = atoi(argv[1]);
    height = atoi(argv[2]);
/*making sure heigth or radius are not negative */

  if((radius < 0)||(height<0)){
    printf("The radious or height cannot be negative!\n");
      }
  else{
    float area;
    area = (2 * PI * radius * height) + (2 * PI * radius * radius);
    printf ("%.2f\n",area);
      }

    }
  return (0);
}
