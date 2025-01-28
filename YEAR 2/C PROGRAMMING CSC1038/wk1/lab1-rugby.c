/*
program: lab1.rugby.c
author: stefania omoede ogun
input: 4 scoring points
output: total point
data: 07/11/2024
*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
  int try, conversion, penalty,drop_goal, total;

  try = atoi(argv[1]) * 5;
  conversion = atoi(argv[2]) * 2;
  penalty = atoi(argv[3]) * 3;
  drop_goal = atoi(argv[4]) * 3;

total = try + conversion + penalty + drop_goal;

printf("%d\n", total);

  return 0;
}

